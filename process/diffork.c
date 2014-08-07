/*
 * =====================================================================================
 *
 *       Filename:  diffork.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月21日 16时37分56秒
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

int globvar = 5;

int main(int argc, char *argv[])
{
	pid_t pid;
	int var = 1, i;

	printf("fork is different with vfork\n");
	printf("var = %d\n",var);
	/*pid = fork();*/
	pid = fork();
	switch(pid)
	{
		case 0:
		     i = 3;
		     while(i-- > 0)
		     {
		     	printf("child process is running\n");
			globvar++;
			var++;
			sleep(1);
		     }
		     printf("child's globvar = %d, var = %d\n",globvar, var);
		     break;
		case -1:
		     perror("process creation failed\n");
		     exit(0);
		default:
		     printf("var = %d\n",var);
		     i = 5;
		     while(i-- > 0)
		     {
		     	printf("parent process is running\n");
			globvar++;
			sleep(1);
		     }
		     printf("parent's globvar = %d, var = %d\n",globvar, var);
		     _exit(0);
	}

	//return EXIT_SUCCESS;
}

