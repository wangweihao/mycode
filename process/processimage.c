/*
 * =====================================================================================
 *
 *       Filename:  processimage.c
 *
 *    Description:  a
 *
 *        Version:  1.0
 *        Created:  2014年07月22日 10时34分44秒
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

int main(int argc, char *argv[], char ** environ)
{
	int i;

	printf("i an a process image !\n");
	printf("MY pid = %d,parentpid = %d\n", getpid(), getppid());
	printf("uid = %d, gid = %d\n",getuid(),getgid());

	for(i = 0; i < argc; i++)
	      printf("grgv[%d]: %s\n",i,argv[i]);

	return EXIT_SUCCESS;
}

