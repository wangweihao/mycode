/*
 * =====================================================================================
 *
 *       Filename:  wait.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月22日 13时42分21秒
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
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	char *msg;
	int k;
	int exit_code;

	printf("stduy how to gei exit code\n");
	pid = fork();
	switch(pid)
	{
		case -1:
			perror("process creation failed\n");
			exit(1);
		case 0:
			msg = "child process is running";
			k = 5;
			exit_code = 37;
			break;
		default:
			exit_code = 0;
			break;
	}

	if(pid != 0)
	{
		int stat_val;
		pid_t child_pid;

		child_pid = wait(&stat_val);

		printf("child process has exited, pid = %d\n",child_pid);
		if(WIFEXITED(stat_val))
		{
			printf("child exited with code %d\n",WEXITSTATUS(stat_val));
		}
		else
		      printf("child exited abnormally\n");
	}
	else
	{
		while(k-- > 0)
		{
		      puts(msg);
		      sleep(1);
		}
	}

	exit(exit_code);
	//return EXIT_SUCCESS;
}

