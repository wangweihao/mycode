/*
 * =====================================================================================
 *
 *       Filename:  cs.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月04日 17时43分49秒
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
#include <errno.h>
#define BUF_SIZE 4096
static char buf[BUF_SIZE];
static char retu[BUF_SIZE];
static char rece[BUF_SIZE];
char name[256];
char tmpname[10][40]; //私聊对象，每个人只能有一个
//客户端和服务器共用的数据都写在头文件里
//5个群信息
//10个用户信息

struct group_member
{
	char name[20];    //每个群成员的信息，姓名和套接字，便于群聊
	int con_fd;
};

struct group_info
{
	int flag;         //标记是否存在该群 0为不存在 1为存在
	char group_name[20];//群名字
	char group_num[20];//群号
	char maintain_user[20];//群管理员
	struct group_member member[10];//群成员最多10个
};

struct Info
{
	char number[20];  //帐号
	char secret[20];  //密码
	char name[20];    //姓名
	char aut[100];    //个性签名
	int age;          //年龄
	char sex[4];      //性别
	int attr;         //属性，是普通用户还是管理用户
	int flag;         //是否在线
	char group_name[5][20];   //每个人添加的群，最多5个。
	int con_fd;       //通信用的套接字每个人一个。
};

struct con_fd
{
	char name[50];
	int confd;
};

struct con_fd people[10];

static struct Info user[10];
static struct group_info group[5];
static int ui = 0;//记录账户也就是人数
static int tmp = 0;

void init_info(struct Info *user)
{
	int i = 0;
	int j = 0;

	if(tmp == 0)
	{
		printf("初始化\n");
	}
	else 
	      return;
	
	for(i = 0; i < 10; i++)
	{
		user[i].con_fd = -1;

	}

	for(j = 0; j < 5; j++)
	{
		group[i].flag = 0;
		for(i = 0; i < 10; i++)
		{
			group[j].member[i].con_fd = -1;	
		}
	}
	tmp = -1;

}



