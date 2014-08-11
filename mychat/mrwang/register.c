/*
 * =====================================================================================
 *
 *       Filename:  register.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月05日 00时47分07秒
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
#include <sys/types.h>
#include <fcntl.h>
#include <curses.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "head.h"


void face(void);
void enter_user(void);
void apply_user(void);
void select_content(void);
void see_friend();
void see_live_friend();
void see_group();
void see_live_group();
void create_client();
void enter_group();
void mod_identify();
void read_data();
void init_info(struct Info *user);



int main(int argc, char *argv[])
{
	init_info(user);
	face();
	read_data();

	return EXIT_SUCCESS;
}

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

	for(i = 0; i < MAX_USER; i++)
	{
		user[i].con_fd = -1;
		user[i].exist = -1;
		user[i].flag = -1;
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



void read_data()
{
	int i,user_num;
	FILE *fp;

	fp = fopen("user_info.txt", "r");

	//读取文件中的数据，用户信息
	for(i = 0; i < MAX_USER; i++)
	{
		//fread(&user[i], sizeof (struct Info), 1, fp);	
		//错误，应该用fscanf读取，读写文件必须用一致的格式，或者是文本，或者是二进制。
	
		fscanf(fp,"%s %s %s %d %s %s %d %d %d %d",user[i].number, user[i].secret,user[i].name, &user[i].age, user[i].sex, user[i].aut, &user[i].attr, &user[i].exist, &user[i].con_fd, &user[i].flag);
	}

	//测试代码
	/*
	for(user_num = 0; user_num < MAX_USER; ++user_num)
	{
		if(user[user_num].exist == -1)
		      break;
		printf("激活一位成员\n");
		sleep(2);
		fflush (stdout);
	}
	printf("user_num = %d\n",user_num);
	sleep(3);
	fflush(stdout);
	for(i = 0; i < user_num; i++)
	{
		printf("%s %s %s %s %d %s %d %d %d %d\n",user[i].number, user[i].secret, user[i].name, user[i].aut, user[i].age, user[i].sex, user[i].attr, user[i].exist,  user[i].con_fd, user[i].flag);
		fflush(stdout);
	}
	*/

	fclose(fp);
}

void face(void)
{
	int a;


	system("clear");
	printf("\n");
	printf("\t\t                      ▁▂▃▄▅▆▇█▇▆▅▄▃▂▁                  \n");
	printf("\t\t                                                       \n");
	printf("\t\t                        easy  聊天室                   \n");
	printf("\t\t                                                       \n");
	printf("\t\t         ╭∞ ━━━╮.oо◎                                   \n");
	printf("\t\t         ┃ ┃            1 登   陆                      \n");
	printf("\t\t         ┃● ● ┃                                        \n");
	printf("\t\t         ┃﹋ε﹋┃                                       \n");
	printf("\t\t         ○ ━━ ━━╯       2 申请账户                     \n");
	printf("\t\t                                                       \n");
	printf("\t\t                                                       \n");
	printf("\t\t                        0 退   出                      \n");
	printf("\t\t                                                       \n");
	printf("\t\t                                                       \n");
	printf("\t\t                                                       \n");

	printf("请选择:");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			system("clear");
			enter_user();
			break;
		case 2:
			system("clear");
			apply_user();
			break;
		case 0:
			system("clear");
			printf("\n\n\n\n\t\t\t\t谢谢使用,再见！！\n\n\n\n\n");
			break;
		default:
			printf("输入错误！请从新输入..\n");
	}

}

void enter_user()
{
	int i = 3, j = 0;
	char ch;
	int oldfd, save_fd;
	char *pass;
	char user[20];
	char secret[20];

	for(i = 3; i >= 0; i--)
	{
		printf("\n\n\n\n\t\t\t  帐号:");
		scanf("%s",user);
		getchar();
		printf("\n\n\t");
		pass = getpass("\t\t\t  密码:");
		if(strcmp(pass, "wangweihao") == 0)
		{
			printf("\n\n\n\n\t\t\t密码正确，欢迎进入...\n");
			sleep(2);
			select_content();
			//break;
		}
		else
		{
			printf("\n\n\n\t\t\t密码错误，请重新输入...\n");
			printf("\t\t\t您还有 %d 次登陆机会..",i);
			sleep(2);
			system("clear");
		}
	}

	printf("\n\n\n\n\t\t\t输入错误次数太多，系统将自动退出...\n\n\n\n\n\n\n\n\n");
	sleep(2);
	exit(0);
}

//申请帐号，ui是第i个user
void apply_user(void)
{
	int fd;
	FILE *fp;
 	char super[20] = "wangweihao";
	char super2[20];
	char *password;

	fp = fopen("user_info.txt","at+");
	if(fp == NULL)
	{
		printf("error\n");
		exit(1);
	}

	printf("帐  号：");
	getchar();
	scanf("%s",user[ui].number);
	getchar();
	printf("\n密  码：");
	scanf("%s",user[ui].secret);
	getchar();
	printf("\n姓  名：");
	scanf("%s",user[ui].name);
	getchar();
	printf("\n年  龄：");
	scanf("%d",&user[ui].age);
	getchar();
	printf("\n性  别：");
	scanf("%s",user[ui].sex);
	getchar();
	printf("\n个 性 签 名：");
	scanf("%s",user[ui].aut);
	getchar();
	printf("\n0 普通用户   1 超级用户\n\n");
	printf("请选择：");
	scanf("%d",&user[ui].attr);
	getchar();
	if(user[ui].attr == 1)
	{
		password = getpass("请输入超级用户验证码:"); 
		if(strncmp(password, super, 20) == 0)
		{
			printf("\n恭喜您成为wechat超级用户\n\n\n");
			user[ui].exist = 0;//用户变为存在
		}
	}
	else
	{
		printf("\n恭喜您成为wechat用户！\n\n\n");
		user[ui].exist = 0;//用户变为存在
	}
	user[ui].flag = -1; //初始都是不在线
	user[ui].con_fd= -1; //初始化通信套接字都是-1
	//fseek(fp, 0, SEEK_END);
	//写入文件
	//依次为账号， 密码， 姓名， 年龄， 性别， 个性签名， 属性， 是否存在， 通信连接套接字， 是否在线。
	fprintf(fp,"%s %s %s %d %s %s %d %d %d %d\n",user[ui].number, user[ui].secret,user[ui].name, user[ui].age, user[ui].sex, user[ui].aut, user[ui].attr, user[ui].exist, user[ui].con_fd, user[ui].flag);
	printf("正在返回主界面，请稍后...\n");
	sleep(2);

	face();

	fclose(fp);
}

//选项
void select_content(void)
{
	int s;

	//initscr();
	//box(stdscr,ACS_VLINE, ACS_HLINE);
	system("clear");
	printf("\n\n");
	printf("\t\t\t     ---------- ---- -----\n");
	printf("\t\t\t     |•ิ.•ัMr wang         |\n");
	printf("\t\t\t     | ◙ ◈ ♫ ♬ ♪ ♩ ♭ ♪   |\n");
	printf("\t\t\t     ---- ------ ---------\n\n");
	printf("\t\t\t\t1 ~我 的 好 友~\n\n\n");
	printf("\t\t\t\t2 ~在 线 好 友~\n\n\n");
	printf("\t\t\t\t3 ~我  的  群 ~\n\n\n");
	printf("\t\t\t\t4 ~聊  天  群 ~\n\n\n");
	printf("\t\t\t\t5 ~  私   聊 ~\n\n\n");
	printf("\t\t\t\t6 ~  群   聊 ~\n\n\n");
	printf("\t\t\t\t7 ~修 改 资 料~\n\n\n");
	printf("\t\t\t\t0 ~  退   出 ~\n\n\n\n");
	printf("\t\t请选择：");
	scanf("%d",&s);
	getchar();
	switch(s)
	{
		case 1:
			see_friend();
			break;
		case 2:
			see_live_friend();
			break;
		case 3:
			see_group();
			break;
		case 4:
			see_live_group();
			break;
		case 5:
			create_client();
			break;
		case 6:
			enter_group();
			break;
		case 7:
			mod_identify();
			break;
		case 0: 
			system("clear");
			printf("\n\n\n\n\n\n\n\n\n\t\t\t\t谢谢使用，再见！！...\n\n\n\n");
			break;
		default:
			printf("\n\n\t\t\t\t输入有误,请重新出入..\n");
			sleep(1);
			system("clear");
			select_content();
			break;
	}
	return;
}

void see_friend()
{
	int s,i;
	char my_friend[10][20];
	FILE *fp;
	char u_number1[20];
	char u_number2[20];

	fp = fopen("friend.txt","r");
	for(i = 0; i < 10; i++)
	{
		fscanf(fp, "%s\n", my_friend[i]);
	}

	system("clear");
	printf("\n\n\n");
	fflush(stdout);
	printf("\n\t\t\t\t   我的好友\n\n\n");
	for(i = 0; i < 10; i++)
	{
		printf("\t\t\t\t%d ☆ ★ %s\n\n",i+1, my_friend[i]);
	}
	printf("  1 添加好友\n");
	printf("  2 删除好友\n\n");
	printf("请选择：");
	scanf("%d",&s);
	switch(s)
	{
		case 1:
			printf("请输入添加号码:");
			scanf("%s",u_number1);
			printf("添加成功!\n");
			break;
		case 2:
			printf("请输入删除号码:");
			scanf("%s",u_number2);
			printf("删除成功!\n");
			break;
		default:
			printf("输入错误，返回上一项...\n");
	}

	fclose(fp);
}

void see_live_friend()
{

}

void see_group()
{
	int s;
	char g_number1[20];
	char g_number2[20];

	printf("  1 添加群\n\n");
	printf("  2 删除群\n");
	switch(s)
	{
		case 1:
			printf("添加群号:\n");
			scanf("%s",g_number1);
			break;
		case 2:
			printf("删除群号:\n");
			scanf("%s",g_number2);
			break;
	}
}

void see_live_group()
{
}

void create_client()
{
	private_chat(0);
}

void enter_group()
{
	private_chat(1);
}

void mod_identify()
{

}
