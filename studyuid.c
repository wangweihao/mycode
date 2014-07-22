/*
 * =====================================================================================
 *
 *       Filename:  studyuid.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月22日 16时03分15秒
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
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

extern int errno;

int main(int argc, char *argv[])
{
	int fd;

	printf("uid study: \n");
	printf("process's uid = %d, euid = %d\n",getuid(),geteuid());
	
	//strerror函数获取指南错误码的提示信息
	if((fd = open("test.c",O_RDWR)) == -1)
	{
		printf("open failure, errno is %d: %s \n",errno, strerror(errno));
	      	exit(1);	
	}
	else
	{
		printf("open successfully\n");
	}

	close(fd);
	exit(0);
	//return EXIT_SUCCESS;
}

