#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#define have_back 0               // &
#define have_pipe 1               // |
#define have_redirectIn 2         // >
#define have_redirectOut 3        // <

void explain_order(char *buf);
void do_order(int tflag);

int main(int argc, char *argv[])
{
	char buf[10] = "ls -a &";
	explain_order(buf);

	return EXIT_SUCCESS;
}

void explain_order(char *buf)
{
	int i = 0;
	int flag = 0,tflag = 0;
	int a;

	while(buf[i] != '\0')
	{
		if(buf[i] == '&')        //&是可以兼容其他符号 所以不用break
		{
			flag = 1; 
		}
		if(buf[i] == '<')
		{
			tflag = have_redirectOut;
			break;
		}
		if(buf[i] == '>')
		{
			tflag = have_redirectIn;
			break;
		}
		if(buf[i] == '|')
		{
			tflag = have_pipe;
			break;
		}
		i++;
	}

	if(flag == 1)
	{
	        a = fork();    //创建子进程
		switch(a)
		{
			case -1: 
				printf("background process failed\n");
				exit(-1);
			case 0:                                      //说明是子进程，后台执行接下来的程序。
				printf("i am childprocess\n");
				do_order(tflag);
				flag = 0;
				exit(0);
			default:
				break;
		}
	}
	else    
	{
		printf("i am fatherprocess\n");
		do_order(tflag);
	
	}

}

void do_order(int tflag)
{
	printf("i an making\n");
}
