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
void have_redirectOut(char *buf);
void my_ls(char *path);


void do_order(int tflag ,char *buf)
{
	char a[256];
	switch(tflag)
	{
		case 1:
			have_pipe(buf);
			break;
		case 2:
			have_redirectIn(buf);
			break;
		case 3:
			have_redirectOut(buf);
			break;
		case 8: 
			my_ls(getcwd(a,256));
			break;
		case -1:
			printf("命令输入错误，请重新输入\n");
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
}

void have_redirectIn(char *buf)      //> 
{
	int oldfd, savefd,ttyfd;
	int i = 0,j = 0;
	char tempbuf[256];
	char bbuf[256];
	fflush(stdout);
	savefd = dup(STDOUT_FILENO);
	while(buf[i++] != '>')
	      ;                        //找到>
	i += 1;    //因为>后面有一个空格
	do
	{
	      tempbuf[j++] = buf[i];
		fflush(stdin);
	}
	while(buf[++i] != '\0');
	tempbuf[j] = '\0';
	fflush(stdin);      
	oldfd = open(tempbuf, O_CREAT | O_RDWR | O_APPEND, 0644);
	if(oldfd == -1)
	{
		printf("open file failed\n");
		exit(-1);
	}
	else
	{
		dup2(oldfd, 1);
		my_ls(tempbuf);

	}
	dup2(savefd, 1);
	ttyfd = open("/dev/tty",O_RDWR);
	dup2(ttyfd, 1);
	close(ttyfd);
	close(oldfd);
	return;
}

void have_redirectOut(char *buf)    //需要传入bb.txt 也就是buf     <
{
	int oldfd; 
	int i = 8,j = 0;
	char *arg[5] = {"wc","-c"};
	char tempbuf[10] = {'0'};

	while(buf[i] != '\0')
	{
	      tempbuf[j] = buf[i];
		i++;
		j++;
	}
	tempbuf[j] = '\0';
	arg[2] = tempbuf;
	fflush(stdin);
	oldfd = open(arg[2], O_RDONLY | O_CREAT |O_APPEND, 0644);   
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

}

void my_ls(char *path)
{
	DIR *dir;
	struct dirent *ptr;
	int i = 0;
	
	getcwd(path, 256);
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
	closedir(dir);
}
