/*
 * =====================================================================================
 *
 *       Filename:  getpid.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月22日 13时54分14秒
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

	pid = fork();
	switch(pid)
	{
		case -1:
	      		perror("process creation failed\n");
	      		exit(1);
		case 0:
	      		printf("the process parent ID:%d\n",getppid());
			break;
		default:
	     		printf("the process son ID:%d\n",pid);
			break;
	}
	return EXIT_SUCCESS;
}

