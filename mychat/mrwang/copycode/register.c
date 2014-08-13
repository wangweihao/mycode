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
void see_data(struct Info *tmp);
void create_client();
void enter_group();
void mod_identify();
void read_data();
void init_info(struct Info *user);
void init_a(struct Info *a);

char username[20];
int fff = 0;//用户的下标
struct enter_user
{
	char number[20];
	char secret[20];
};

struct enter_user u[10];
struct Info a[10];
int dex;

int main(int argc, char *argv[])
{
	init_info(user);
	init_a(a);
	face();
	read_data();

	return EXIT_SUCCESS;
}

void init_a(struct Info *a)
{
	FILE *p;
	int i;

	p = fopen("user_info.txt", "rt+");
	for(i = 0; i < 10; i++)
	{
		memset(a[i].number, 0, sizeof(a[i].number));
		memset(a[i].secret, 0, sizeof(a[i].secret));
		memset(a[i].name, 0, sizeof(a[i].name));
		memset(a[i].sex, 0, sizeof(a[i].sex));
		memset(a[i].aut, 0, sizeof(a[i].aut));
		a[i].age = -1;
		a[i].con_fd = -1;
		a[i].exist = -1;
		a[i].flag = 0;
		a[i].attr = 0;
	}
	for(i = 0; i < 10; i++)
	{
		fscanf(p, "%s %s %s %d %s %s %d %d %d %d\n", a[i].number, a[i].secret, a[i].name, &a[i].age, a[i].sex, a[i].aut, &a[i].attr, &a[i].exist, &a[i].con_fd, &a[i].flag);
	}
	fclose(p);
}

void init_info(struct Info *user)
{
	int i = 0;
	int j = 0;
	int k = 0;

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
		//user[i].flag = -1;
		for(k = 0; k < 5; k++)
		{
			memset(user[i].group_name[k], 0, 20);
		}
		
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
	printf("\t\t                      mr wang   聊天室                   \n");
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
			sleep(2);
			face();
			break;
	}

}

void enter_user()
{
	int i = 3, j = 0;
	char ch;
	int s;
	char *pass;
	char secret[20];
	FILE *fp;
	int k = 0;

	for(k = 0; k < 10; k++)
	{
		memset(u[k].secret, '\0', sizeof(u[k].secret));
		memset(u[k].number, 0, sizeof(u[k].number));
	}

	fp = fopen("user_secret.txt", "r");
	for(k = 0; k < 10; k++)
	{
		fscanf(fp,"%s %s", u[k].number, u[k].secret);
		//printf("%s  %s\n",u[k].number, u[k].secret);
	}
	fclose(fp);

	for(i = 3; i >= 0; i--)
	{
		printf("\n\n\n\n\t\t\t  帐号:");
		memset(username, '\0', sizeof(username));
		fflush(stdin);
		scanf("%s", username);
		getchar();
		for(j = 0; j < 10; j++,fff++)
		{
			if(strcmp(username, u[j].number) == 0)
			break;
		}
		if(j == 10)
		{
			system("clear");
			printf("\n\n\n\n\n\t\t\t   帐号不存在， 请重新输入");
			sleep(1);
			system("clear");
			continue;
		}
		printf("\n\n\t");
		fflush(stdin);
		pass = getpass("\t\t\t  密码:");
		if(strcmp(pass, u[j].secret) == 0)
		{
			printf("\n\n\n\n\t\t\t密码正确，欢迎进入...\n");
			user[j].flag = 0;
			sleep(2);
			select_content();
			//break;
		}
		else
		{
			printf("\n\n\n\t\t\t密码错误，请重新输入...\n");
			printf("\n\n\t\t\t按0退出,其他任意键继续输入");
			scanf("%d",&s);
			if(s == 0)
			{
				printf("\n\n\n\t\t\t谢谢使用， 再见！！！\n\n\n\n");	
			        exit(0);
			}
			printf("\t\t\t您还有 %d 次登陆机会..",i);
			sleep(2);
			system("clear");
		}
	}
	if(i < 0)
	{
		printf("\n\n\n\n\t\t\t输入错误次数太多，系统将自动退出...\n\n\n\n\n\n\n\n\n");
		sleep(2);
		exit(0);
	}
}

//申请帐号，ui是第i个user
void apply_user(void)
{
	int fd;
	FILE *fp;
	FILE *fpp;
 	char super[20] = "wangweihao";
	char super2[20];
	char *password;

	fp = fopen("user_info.txt","a+");
	if(fp == NULL)
	{
		printf("error\n");
		exit(1);
	}
	fpp = fopen("user_secret.txt", "a+");
	if(fpp == NULL)
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
	fflush(stdout);
	fprintf(fp,"%s %s %s %d %s %s %d %d %d %d\n",user[ui].number, user[ui].secret,user[ui].name, user[ui].age, user[ui].sex, user[ui].aut, user[ui].attr, user[ui].exist, user[ui].con_fd, user[ui].flag);
	fprintf(fpp,"%s %s\n",user[ui].number, user[ui].secret);
	fclose(fp);
	fclose(fpp);
	printf("正在返回主界面，请稍后...\n");
	sleep(2);

	face();

}

//选项
void select_content(void)
{
	int s;
	int a;
	struct Info tmp;
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
	printf("\t\t\t\t8 ~个 人 资 料~\n\n\n");
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
			select_content();
			break;
		case 3:
			see_group();
			select_content();
			break;
		case 4:
			see_live_group();
			select_content();
			break;
		case 5:
			create_client();
			break;
		case 6:
			enter_group();
			break;
		case 7:
			mod_identify();
			printf("\n\t\t\t按任意键返回上一项...");
			getchar();
			select_content();
			break;
		case 8:
			see_data(&tmp);
			printf("\n\t\t\t按任意键返回上一项...");
			getchar();
			select_content();
			break;
		case 0: 
			system("clear");
			printf("\n\n\n\n\n\n\t\t\t是否确认退出?\n\n");
			printf("\t\t\t1.不是      0.退出\n\n");
			printf("\t\t\t请选择:");
			scanf("%d",&a);
			switch(a)
			{
				case 1:
					break;
				case 0:
					printf("\n\n\n\t\t\t您选择了退出,谢谢您的使用，再见！！\n\n\n\n\n\n");
					sleep(1);
					exit(0);
				default:
					printf("\n\n\n\t\t\t选择有误，系统将自动返回上一项！！\n\n\n\n\n\n");
					break;
			}
		default:
			//printf("\n\n\t\t\t\t输入有误,请重新出入..\n");
			sleep(1);
			system("clear");
			select_content();
			break;
	}
	return;
}

void see_friend()
{
	int s, b, m;
	int i, j, k, l, temp = 0;
	char my_friend[10][20];
	FILE *fp;
	FILE *pp;
	FILE *ff;
	FILE *pf;
	char u_number1[20];
	char u_number2[20];

	fp = fopen("friend.txt","r");
	pp = fopen("friend.txt", "a+");
	ff = fopen("friend.txt", "rt");
	pf = fopen("oldfriend.txt", "w");
	fflush(stdin);
	for(i = 0; i < 10; i++, temp++)
	{
		if(feof(fp) != 0)   //非0为真，到达了末尾。
			break;
		else
			fscanf(fp, "%s\n", my_friend[i]);
	}
	system("clear");
	printf("\n\n\n");
	fflush(stdout);
	printf("\n\t\t\t\t   我的好友\n\n\n");
	for(j = 0; j < i; j++)
	{
		printf("\t\t\t\t%d ☆ ★ %s\n\n",j+1, my_friend[j]);
	}
	printf("\t  1 添加好友\n");
	printf("\t  2 删除好友\n\n");
	printf("\t  3 返回上一项...\n\n");
	printf("\t  请选择：");
	scanf("%d",&s);
	switch(s)
	{
		case 1:
			printf("\t  请输入添加号码:");
			scanf("%s",u_number1);
			for(i = 0; i < 10; i++)
			{
				if(strcmp(u_number1, a[i].number) == 0)
				      break;
			}
			if(i == 10)
			{
				printf("\n\n\t\t您的输入有误，该用户不存在！！\n");
				break;
			}
			else
			{
				printf("\n\n\t\t查询成功！！,请等待...\n");
				sleep(1);
				printf("\n\n\t\t\tuser:%s\n",a[i].number);
				printf("\t\t\tname:%s\n",a[i].name);
				printf("\t\t\tsex:%s\n",a[i].sex);
				printf("\t\t\tage:%d\n", a[i].age);
				printf("\t\t\taut:%s\n", a[i].aut);
				if(a[i].attr == 0)
				{
					printf("\t\t\tattr:usual user\n");
				}
				else
				{
					printf("\t\t\tattr:super user\n");
				}
			}
			printf("\t是否确认添加%s：\n", u_number1);
			printf("\t0. yes      1. no\n");
			scanf("%d", &b);
			if(b == 0)
			{
				fprintf(pp, "%s\n", a[i].number);
				fclose(pp);
				printf("\t添加成功...即将返回上一项\n");
				sleep(2);
				select_content();
			}
			else
			{
				printf("\t即将返回上一项\n");
				sleep(2);
				select_content();
			}
			printf("\t添加成功!\n");
			break;
		case 2:
			printf("请输入删除号码:");
			scanf("%s",u_number2);
			printf("\n");
			for(k = 0; k < 10; k++)
			{
				if(strcmp(u_number2, my_friend[k]) == 0)
				{
				//	printf("k = %d, temp = %d, my_friend[k] = %s", k, temp, my_friend[k]);
					printf("\t是否确认删除%s：\n\n",u_number2);
					printf("\t0. yes     1. no\n\n");
					printf("\t请选择:");
					scanf("%d",&m);
					if(m == 0)
					{
						printf("\n\t正在删除%s...\n", u_number2);
						sleep(2);
						getchar();
						for(l = 0; l < temp; l++)
						{
							if(strcmp(my_friend[l], u_number2) == 0)
							{
								continue;
							}
							fprintf(pf, "%s\n", my_friend[l]);
							//printf("%s\n", my_friend[l]);
							//fprintf(pf, "%s\n", my_friend[l]);
						}
						fclose(pf);
						remove("friend.txt");
						rename("oldfriend.txt", "friend.txt");
						//rename("oldfriend.txt", "friend.txt");
						printf("\n\t按任意键返回上一项\n");
						getchar();
						select_content();
					}
					else
					{
						printf("\n\t即将返回上一项...\n");
						sleep(2);
						select_content();
					}
				}
			}
			break;
		default:
			printf("\t\t\t正在返回上一项...请稍后...\n\n\n");
			sleep(2);
			select_content();
			break;
	}

	fclose(fp);
}

void see_live_friend()
{
	int i;


	system("clear");
	printf("\n\t\t\t\t在线好友\n\n");
	for(i = 0; i < 10; i++)
	{
		printf("user flag = %d\n", people[i].confd);
		if(people[i].confd != -1)
		{
			printf("\t\t\t %s\n",people[i].name);
		}
	}
	sleep(2);
	printf("\n\n\t\t\t按任意键返回上一项\n\n");
	getchar();
}


void see_group()
{
	int s;
	int i,j;
	int k;
	char g_number1[20];
	char g_number2[20];
	char temp_group[20];
	struct group_info temp;
	FILE *fp;
	FILE *pp;
	FILE *ff;
	fp = fopen("group.txt", "a+");
	pp = fopen("oldgroup.txt", "w");
	ff = fopen("group_info.txt", "a+");

	system("clear");
	printf("\n\n\n\n\t\t\t\t✲ ❈  ✿  ✲ ❈\n");
	printf("\t\t\t\t 我  的  群 \n\n\n");
	for(i = 0; i < 5; i++)  // 最多5个群
	{
		if(feof(fp) != 0)
		{
			break;
		}
		else
		{
			fscanf(fp, "%s\n", user[fff].group_name[i]);
			printf("\t\t\t\t%s \n\n", user[fff].group_name[i]);
		}
	}

	printf("  1 添加群\n\n");
	printf("  2 删除群\n\n");
	printf("  3 创建群\n\n");
	printf("  4 退出\n\n\n");
	printf("    请选择：");
	scanf("%d", &s);
	switch(s)
	{
		case 1:
			printf("\n    添加群号:");
			scanf("%s",g_number1);
			printf("\n");
			getchar();
			printf("\t\t\t  正在添加，请稍后...\n\n");
			fprintf(fp, "%s\n", g_number1);
			sleep(2);
			printf("\t\t\t  添加成功， 按任意键返回上一项\n");
			getchar();
			break;
		case 2:
			printf("    删除群号:");
			scanf("%s",g_number2);
			printf("\n");
			sleep(1);
			for(j = 0; j < i; j++)
			{
				if(strcmp(g_number2, user[fff].group_name[j]) == 0)
				{
					continue;
				}
				fprintf(pp, "%s\n", user[fff].group_name[j]); //fff是此用户
			}
			printf("\t\t\t  正在删除，请稍后...\n\n");
			getchar();
			sleep(2);
			remove("group.txt");
			rename("oldgroup.txt", "group.txt");
			printf("\t\t\t  删除成功， 按任意键返回上一项\n");
			getchar();
			break;
		case 3:
			if(a[fff].attr == 0)
			{
				printf("\n\n\t\t\t抱歉， 您是usual user， 没有该权限\n\n\n");
				getchar();
				sleep(2);
			}
			else if(a[fff].attr == 1)
			{
				printf("\n\n\n\t\t请输入新的群名:");
				scanf("%s", temp.group_name);
				getchar();
				printf("\t\t请输入新的群号:");
				scanf("%s", temp.group_num);
				getchar();
				printf("\t\t请输入新的群公告:");
				scanf("%s", temp.message);
				getchar();
				strcpy(temp.maintain_user, a[fff].name);
				fprintf(fp, "%s\n", temp.group_name);
				fprintf(ff, "%s %s %s %s\n", temp.group_num, temp.group_name, temp.maintain_user, temp.message);
				printf("\an\n\t\t恭喜您创建成功！！\n\n");
				getchar();
				sleep(2);
			}
			break;
		case 4:
			printf("\t\t\t  按任意键返回上一项\n");
			getchar();
			break;
			
	}
	fclose(pp);
	fclose(fp);
	fclose(ff);
}

void see_live_group()
{
	system("clear");
	printf("\n\n\n\t\t\t抱歉没有正在聊天的群...\n\n\n\n\n\n");
	sleep(1);
	printf("\t\t\t正在返回，请等待...\n\n");
	sleep(1);
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
	int select;
	FILE *p;
	struct Info temp;
	size_t count;
//	struct Info a[10];
	int i;

	see_data(&temp);
	p = fopen("user_info.txt", "rt+");
	for(i = 0; i < 10; i++)
	{
		memset(a[i].number, 0, sizeof(a[i].number));
		memset(a[i].secret, 0, sizeof(a[i].secret));
		memset(a[i].name, 0, sizeof(a[i].name));
		memset(a[i].sex, 0, sizeof(a[i].sex));
		memset(a[i].aut, 0, sizeof(a[i].aut));
		a[i].age = -1;
		a[i].con_fd = -1;
		a[i].exist = -1;
		a[i].flag = -1;
		a[i].attr = 0;
	}
	for(i = 0; i < 10; i++)
	{
		fscanf(p, "%s %s %s %d %s %s %d %d %d %d\n", a[i].number, a[i].secret, a[i].name, &a[i].age, a[i].sex, a[i].aut, &a[i].attr, &a[i].exist, &a[i].con_fd, &a[i].flag);
	}
	for(i = 0; i < 10; i++)
	{
		if(strcmp(username, a[i].number) == 0)
		      break;
	}
	printf("\t\t\t请选择你要修改的资料的编号:");
	scanf("%d", &select);
	printf("\n");
	switch(select)
	{
		case 1:
			printf("\n\n\t\t\t抱歉，帐号不能修改！！\n\n");
			break;
		case 2:
			printf("\t\t\told name:%s\n\n", temp.name);
			printf("\t\t\t请输入新的name:");
			scanf("%s",a[i].name);
			break;
		case 3:
			printf("\t\t\told age:%d\n\n", temp.age);
			printf("\t\t\t请输入新的age:");
			scanf("%d", &a[i].age);
			break;
		case 4:
			printf("\t\t\told sex:%s\n\n", temp.sex);
			printf("\t\t\t请输入新的sex:");
			scanf("%s", a[i].sex);
			break;
		case 5: 
			printf("\t\t\told aut%s\n\n",temp.aut);
			printf("\t\t\t请输入新的aut:");
			scanf("%s", a[i].aut);
			break;
		case 6:
			printf("\n\n\n\t\t\t身份不能修改！！\n\n");
			break;

	}
	fseek(p, 0, SEEK_SET);
	for(i = 0; i < 10; i++)
	{
		fprintf(p, "%s %s %s %d %s %s %d %d %d %d\n",a[i].number, a[i].secret, a[i].name, a[i].age, a[i].sex, a[i].aut, a[i].attr, a[i].exist, a[i].con_fd, a[i].flag);
	}
	//printf("index = %d", dex);
	getchar();
	fclose(p);
}


void see_data(struct Info *tmp)
{
	FILE *fp;
	int i;

	fp = fopen("user_info.txt", "r");
	for(i = 0, dex = 0; i < 10; i++, dex++)
	{
		fflush(stdout);
		fscanf(fp,"%s %s %s %d %s %s %d %d %d %d\n",tmp->number, tmp->secret, tmp->name, &tmp->age, tmp->sex, tmp->aut, &tmp->attr, &tmp->exist, &tmp->con_fd, &tmp->flag);
		if(strcmp(username, tmp->number) == 0)
		{
			system("clear");
			printf("\n\n\n\n\n\n\t\t\t1.user:%s\n\n", tmp->number);
			printf("\t\t\t2.name:%s\n\n", tmp->name);
			printf("\t\t\t3.age :%d\n\n", tmp->age);
			printf("\t\t\t4.sex :%s\n\n", tmp->sex);
			printf("\t\t\t5.aut :%s\n\n", tmp->aut);
			if(tmp->attr == 1)
			{
				printf("\t\t\t6.attr:super user\n\n\n\n\n");
			}
			else
			{
				printf("\t\t\t6.attr:usual user\n\n\n\n\n");
			}
			
			break;
		}
	}
	fclose(fp);
}
