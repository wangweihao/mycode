/*
 * =====================================================================================
 *
 *       Filename:  fork.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月21日 15时32分03秒
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
#include <sys/types.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	
	printf("process creat study\n");
	pid = fork();
	switch(pid)
	{
		case 0:
			printf("child process is running, curpid is %d, parentpid is %d\n",pid, getppid());
			break;
		case -1:
			printf("process creat faile\n");
			break;
		default:
			printf("parent process is running , childpid is %d, parentpid is %d\n",pid,getpid());
			break;
	}
	exit(0);
	
	return EXIT_SUCCESS;
}

