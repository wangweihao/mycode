/*
 * =====================================================================================
 *
 *       Filename:  ismain.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月24日 22时11分54秒
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
#define MaxSize 256

int main(int argc, char *argv[])
{
	char *buf;
	int i = 0;
	

	buf = (char *)malloc(sizeof(char) * MaxSize);//命令最大字符数为256
	
	while(1)//shell是可多次执行的直到用户退出为止
	{
		memset(buf, 0, MaxSize);
		fflush(stdin);
		printf("myshell:");
		i = 0;
		do
		{
			buf[i] = getchar();
		
		}
		while(i < 256 && buf[i++] != '\n');
		if(strncmp(buf,"exit\n",5) == 0 || strncmp(buf, "logout\n", 7) == 0)
		      break;
		printf("%s\n",buf);//要执行的命令
	
	}
	//explain_order(buf);

	free(buf);

	return EXIT_SUCCESS;
}

