/*
 * =====================================================================================
 *
 *       Filename:  fork3.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月21日 16时06分10秒
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

int main(int argc, char *argv[])
{
	pid_t pid;
	int k = 4;

	pid = fork();
	switch(pid)
	{
		case 0://子进程的返回值
			while(k > 0)
			{
				printf("a background process, PID:%d, parentID:%d\n ",getpid(),getppid());
				sleep(3);
				k--;
			}
		case -1://错误的返回值
			perror("process creation failed\n");
			exit(-1);
		default://父进程的返回值
			printf("parent process, my PID is %d\n",getpid());
			exit(0);

	}

	return EXIT_SUCCESS;
}

