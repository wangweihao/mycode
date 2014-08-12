/*
 * =====================================================================================
 *
 *       Filename:  client.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月04日 08时44分57秒
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
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <arpa/inet.h>
#include <memory.h>
#include <pthread.h>
#include "head.h"
#define SERVPORT 4057

void input(char *buf)
{
	int i = 0;
	char ch;
	while((ch = getchar()) != '\n')
	{
		buf[i] = ch;
		i++;
	}
	buf[i] = '\0';

}

void send_capacity(int con_fd)
{
	while(1)
	{
		memset(buf, '\0', sizeof(buf));
		printf("我说:");
		fflush(stdin);
		input(buf);
		send(con_fd, buf, strlen(buf), 0);
		if(strcmp(buf,"bye") == 0)
		{
			printf("谢谢使用，再见！\n");
		//	send_data(con_fd, buf);
			exit(0);
		}
	}
}

void recv_thread(int *con_fd)
{
	char recvname[20];

	memset(recvname, 0, sizeof(recvname));
	recv(*con_fd, recvname, sizeof(recvname), 0);
	printf("create a pthread success\n");
	while(1)
	{
		memset(rece, '\0', sizeof(rece));
		printf("\n");
		recv(*con_fd, rece, sizeof(rece), 0);
		printf("%s说:%s",recvname, rece);
	}
	if(strncmp(retu, "bye", 16) == 0)
	{
		printf("%s下线啦\n",name);
	}
}

void send_user_info(int con_fd, const char *info)
{
	if(send(con_fd, info, strlen(info), 0) < 0)
	{
		perror("send");
		exit(1);
	}
}

int private_chat(int goal)
{
	int con_fd, iResult;
	struct sockaddr_in serv_addr;
	fd_set readset, testset;
	char clname[256];
	char tmp_name[256];
	char grp_name[20] = "group";
	int i = 0;
	pthread_t thid;
	char ch;

	//创建通信用的连接套接字
	con_fd = socket(AF_INET, SOCK_STREAM, 0);
	//还是要初始化服务器的端口和地址，我们假设先设定好
	serv_addr.sin_port = htons(SERVPORT);
	//inet_aton(cp, &serv_addr.sin_addr);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	//inet_aton("222.24.51.52",&serv_addr.sin_addr);
	serv_addr.sin_family = AF_INET;//ipv4
	
	//尝试和监听套接字取得联系，从而被"引进"到accept
	connect(con_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr_in));

/*	memset(clname, 0, sizeof(clname));
	printf("请输入用户名:");
	while((ch = getchar()) != '\n')
	{
		clname[i] = ch;
		i++;
	}
	clname[i] = '\0';
	send_user_info(con_fd, clname);
	printf("正在登陆...请稍后...\n");
	sleep(2);
*/

	if(goal == 0)//私聊
	{

		memset(clname, 0, sizeof(clname));
		printf("请输入用户名:");
		while((ch = getchar()) != '\n')
		{
			clname[i] = ch;
			i++;
		}
		clname[i] = '\0';
		send_user_info(con_fd, clname);
		printf("正在登陆...请稍后...\n");
		sleep(2);
		
		
		printf("请输入要聊天对方的姓名:");
		input(tmp_name);
		//tmpname[name_i]我要和谁聊，recv时就是谁的名字
		//strncpy(tmpname[name_i],tmp_name, 40);     
		//发送给服务器自己的姓名.
//		send_user_info(con_fd, name);
		printf("正在连接...请稍后...\n");
		sleep(2);
		//发送给服务器聊天对象的姓名
		send_user_info(con_fd, tmp_name);
		//创建一个子线程来接收信息.
		pthread_create(&thid, NULL, (void*)recv_thread, &con_fd);
		//发送信息
		send_capacity(con_fd);
	}
	else if(goal == 1)//群聊
	{

		memset(clname, 0, sizeof(clname));
	
		printf("要开始群聊啦！！\n");
		strcpy(clname, "group");
		send_user_info(con_fd, clname);
		
		printf("正在连接...请稍后...\n");
		sleep(2);
		//发送消息以用来辨别是群发消息
		send_user_info(con_fd, grp_name);
		//创建子线程来接收数据
		pthread_create(&thid, NULL, (void*)recv_thread, &con_fd);
		//发送信息
		send_capacity(con_fd);
		
	}


	return EXIT_SUCCESS;
}

