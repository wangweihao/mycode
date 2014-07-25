/*
 * =====================================================================================
 *
 *       Filename:  do_order.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月25日 00时56分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wangweihao, 578867817@qq.com
 *        Company:  Class 1304 of Communication
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

void do_order(int tflag, char *buf);
void have_pipe(char *buf);
void have_redirectIn(char *buf);
void have_redirectOut(void);
void my_ls(char *path);

int main(int argc, char *argv[])
{
	char buf[256];
	getcwd(buf, 256);
	printf("%s",buf);
//	my_ls(buf, lsflag);
//	have_redirectIn(buf);
	have_redirectOut();
	return EXIT_SUCCESS;
}

void do_order(int tflag ,char *buf)
{
	switch(tflag)
	{
		case 1:
			have_pipe(buf);
			break;
		case 2:
			//have_redirectIn(buf);
			break;
		case 3:
			have_redirectOut();
			break;
	}

}

void have_pipe(char *buf)
{
	//   |  一个文件的输出作为下一个文件的输入
	int fd1,fd2;
	char *arc[5] = {"ls", 0};

	fd1 = open("temp.txt", O_CREAT | O_RDWR | O_APPEND, S_IRWXU);    //  | 前面的输出该为temp.txt 
	if(fd1 == -1)
	{
		printf("open file failed\n");
		exit(-1);
	}
	else
	{
		dup2(fd1,1);
		my_ls(buf);
	}
	fd2 = open("temp.txt", O_CREAT | O_RDWR | O_APPEND, S_IRWXU);   //读取temp.txt里面的东西作为输入
	if(fd2 == -1)
	{
		printf("open file failed\n");
		exit(-1);
	}
	else
	{
		dup2(fd2, 0);
		execvp(arc[0],arc);
	}
	close(fd1);
	close(fd2);
	exit(0);
}

void have_redirectIn(char *buf)      //> 
{
	int oldfd;
	
	oldfd = open("aa.txt", O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
	if(oldfd == -1)
	{
		printf("open file failed\n");
		exit(-1);
	}
	else
	{
		dup2(oldfd, 1);
		my_ls(buf);

	}
	close(oldfd);
	exit(0);
}

void have_redirectOut(void)    //需要传入bb.txt 也就是buf     <
{
	int oldfd; 
	char *arg[5] = {"wc -c", 0};

	oldfd = open("bb.txt", O_CREAT | O_RDWR | O_APPEND, S_IRWXU);   
	if(oldfd == -1)
	{
		printf("open file failed\n");
		exit(-1);
	}
	else
	{
		dup2(oldfd, 0);
		execvp(arg[0],arg);
	}
	close(oldfd);
	exit(0);

}

void my_ls(char *path)
{
	DIR *dir;
	struct dirent *ptr;
	int i = 0;
	
	if((dir = opendir(path)) == NULL)
	{
		printf("error\n");
		exit(-1);
	}
	while((ptr = readdir(dir)) != NULL)
	{
		if(ptr->d_name[0] != '.')
		{
			if(i % 8 == 0)
			      printf("\n");
			printf("%-16s",ptr->d_name);
			i++;
		}	
	}
	printf("\n");
	closedir(dir);
}
