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


void explain_order(char *buf)
{
	int i = 0;
	int flag = 0,tflag = -1;
	int a;

	while(buf[i] != '\0')
	{/*
		if(buf[i] == 'l' && buf[i+1] == 's' && buf[i+3] == '\0')
		{
			flag = 0;
			break;
		}*/
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
		//if(buf[i] == 'l' && buf[i+1] == 's' && buf[i+3] != '&' && buf[i+3] !=  '<' && buf[i+3] != '>' && buf[i+3] != '|' )
		i++;
	}
	i = 0;
	while(buf[i] != '\0')
	{
		if(buf[i] == '&')
		{
			flag = 1;
			break;
		}
		i++;
	}
	i = 0;
	if(tflag == -1)
	{
		while(buf[i] == 'l' && buf[i+1] == 's')
		{
			tflag = 8;
			break;
		}
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
				do_order(tflag,buf);
				flag = 0;
				exit(0);
				printf("myshell:");
			default:
				break;
		}
	}
	else    
	{
		printf("i am fatherprocess\n");
		do_order(tflag,buf);
	
	}

}

