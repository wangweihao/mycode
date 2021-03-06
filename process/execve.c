/*
 * =====================================================================================
 *
 *       Filename:  execve.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月22日 10时44分41秒
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

int main(int argc, char *argv[],char ** environ)
{
	pid_t pid;
	int stat_val;

	printf("Exec example!\n");
	pid = fork();
	switch(pid)
	{
		case -1: 
			perror("process creation failed");
		case 0:
			printf("child process is running\n");
			printf("uid = %d, gid = %d\n", getuid(), getgid());
			execve("processimage",argv,environ);
			printf("process never go to here!\n");
			exit(0);
		default:
			printf("parent process is running\n");
			break;
	
	}
	wait(&stat_val);
	exit(0);
	return EXIT_SUCCESS;
}

