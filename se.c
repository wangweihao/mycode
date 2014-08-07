/*
 * =====================================================================================
 *
 *       Filename:  serve.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月04日 09时12分15秒
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
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <errno.h>
#include "cs.h"
#define SERVPORT 4057
#define BACKLOG 10

struct con_fd
{
	char name[50];
	int confd;
};

struct con_fd people[10];
char tmpname[40];

void recv_user_info(int con_fd, char *info)
{
	if(recv(con_fd, info, sizeof(info), 0) < 0)
	{ 
		perror("recv");
		exit(1);
	}
}

void exe_info(int *con_fd)
{
	int i = 0;
	int flag = 1;
	printf("您要和%s聊天\n",tmpname);
	for(; i < 10; i++)
	{
		if(strcmp(tmpname, people[i].name) == 0)
		      break;
		printf("i = %d",i);
	}
	printf("%s,%sID是%d\n",tmpname,people[i].name,people[i].confd);
	while(flag)
	{
		recv(*con_fd, retu, sizeof(retu), 0);
		printf("服务器收到\n");
		send(people[i].confd, retu, strlen(retu), 0);
		printf("服务器已发送\n");
		if(strcmp(retu, "bye") == 0)
		{
			pthread_exit(0);
		}
		memset(retu, 0, sizeof(retu));
	}
}

void input(char *buf)
{
	int i= 0;
	char ch;
	while((ch = getchar()) != '\n')
	{
		buf[i] = ch;
		i++;
	}
	buf[i] = '\0';
}

int main(int argc, char *argv[])
{
	int sock_fd, con_fd, client_len;
	struct sockaddr_in my_addr,client_addr;
	int i = 0,j;
	char name[256];
	pthread_t thid;


	//初始化结构体套接字
	for(j = 0; j < 10; j++)
	{
		people[j].confd = -1;
		j++;
	}

	//创建套接字
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);

	//初始化
	memset(&my_addr, 0, sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(SERVPORT);
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	//错误：inet_aton(p,&my_addr.sin_addr);

	//绑定到本客户端
	bind(sock_fd, (struct sockaddr*)&my_addr, sizeof(struct sockaddr_in));

	//转化为监听套接字
	if(listen(sock_fd, BACKLOG) < 0)
	{
		perror("listen");
		exit(1);
	}
	client_len = sizeof(struct sockaddr_in);

	while(1)
	{
		con_fd = accept(sock_fd, (struct sockaddr*)&client_addr, &client_len);
		memset(name, 0, sizeof(name));
		recv_user_info(con_fd, name);
		printf("%s加入了\n",name);
		if(people[0].confd == -1)
		{
			printf("聊天室无人,请等待...\n");
			people[0].confd = con_fd;
			strcpy(people[0].name, name);
			printf("you are first people con_fd:%d, name:%s\n",people[0].confd,people[0].name);
			i++;
		}
		else
		{
			people[i].confd = con_fd;
			strcpy(people[i].name, name);
			printf("you are the %d people con_fd:%d, name:%s\n",i,con_fd, name);
			printf("请输入要聊天对方的姓名:");
			input(tmpname);
			pthread_create(&thid, NULL, (void *)exe_info, &con_fd);
			i++;
		}
	}

	

	close(sock_fd);

	return EXIT_SUCCESS;
}

