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



char name[256];
static int name_i = 0;
static int ppi = 0;

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
	int i;
	int flag = 1;
	char ret[10][256];
	int s = -1;
	int newfd[10];
	int k = -1;

	s++;
	k++;
	printf("you are the %d people, con_fd:%d, name:%s\n",ppi,*con_fd,name);
	//people[ppi].confd = *con_fd;
	//strncpy(people[ppi].name, name, 40);
	//ppi++;
	newfd[k] = *con_fd;
	memset(tmpname[name_i], 0, 40);
	recv(newfd[k], tmpname[name_i], 40, 0);
	printf("接收聊天对象->tmp_name:%s\n",tmpname[name_i]);
	
	printf("您要和%s聊天,con_fd = %d\n",tmpname[name_i],newfd[k]);
	for(i = 0; i < 10; i++)
	{
		if(strcmp(tmpname[name_i], people[i].name) == 0)
		      break;
	}
	if(i == 10)
	{
		printf("\n抱歉！您查找的人不存在！\n您不能和不存在的人聊天\n请重新输入\n");
		return;
	}
	//printf("我:%s,对方:%s,对方:%s,ID是%d\n",people[ppi-1].name,tmpname[name_i],people[i].name,people[i].confd);
	while(flag)
	{
		recv(newfd[k], ret[s], 256, 0);
		printf("s = %d,*con_fd = %d\n",s,newfd[k]);
		printf("服务器收到\n");
		send(people[i].confd, ret[s], strlen(ret[s]), 0);
		printf("s = %d.people[i].confd = %d\n",s,people[i].confd);
		printf("服务器已发送,%s\n",people[i].name);
		if(strcmp(ret[s], "bye") == 0)
		{
			pthread_exit(0);
		}
		memset(ret[s], 0, 256);
	}
	name_i++;
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
	int tmp_confd;
//	char name[256];

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
	
		
		//接收连入的用户信息
		
		recv_user_info(con_fd, name);
		strcpy(people[ppi].name, name);
		people[ppi].confd = con_fd;
		ppi++;
		printf("%s登陆啦！！\n",name);
	/*	//接收用户要聊天的对象

		recv(con_fd, tmpname[name_i], 40, 0);
		printf("tmp_name = %s",tmpname[name_i]);

		people[i].confd = con_fd;
		strcpy(people[i].name, name);
		printf("you are the %d people con_fd:%d, name:%s\n",i,con_fd, name);
	*/	
		pthread_create(&thid, NULL, (void *)exe_info, &con_fd);
		//i++;
	}

	

	close(sock_fd);

	return EXIT_SUCCESS;
}

