/*
 * =====================================================================================
 *
 *       Filename:  fork2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月21日 15时45分18秒
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
	char *msg;
	int k;

	pid = fork();
	switch(pid)
	{
		case 0:
			msg = "child process is running";
			k = 3;
			break;
		case -1:
			printf("process creat failed\n");
			break;
		default:
			msg = "parent process is running";
			k = 5;
			break;
	
	}
	while(k > 0)
	{
		puts(msg);
		sleep(1);
		k--;
	}

	exit(0);

	return EXIT_SUCCESS;
}

