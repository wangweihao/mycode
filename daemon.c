/*
 * =====================================================================================
 *
 *       Filename:  daemon.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月21日 21时37分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wangweihao, 578867817@qq.com
 *        Company:  Class 1304 of Communication
 *
 * =====================================================================================
 */

#include <unistd.h>
//编写守护进程实际上就是普通进程改写成守护进程
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <syslog.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/param.h>
int init_daemon(void)
{
	int pid;
	int i;

        /*忽略终端I/O信号， STOP信号*/
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGHUP, SIG_IGN);

	pid = fork();        //fork两个返回值 
	if(pid > 0)          //1.使父进程终止，让子进程在后台运行
		exit(0);
	else if(pid < 0)     //creation failed
	      return -1;

	setsid();            //使之成为会话组组长

	pid = fork();        //在创建一个进程，使原先的进程不再是会话组组长，禁止进程打开终端
	if(pid > 0)
	      exit(0);
	else if(pid < 0)
	      return -1;

	for(i = 0; i < NOFILE; close(i++)) //继承了文件描述符，需要关闭,释放占用的资源，NOFILE是系统能打开文件的最大数量

	chdir("/");        //改变当前目录，一般要改变带根目录
	umask(0);          //重新设置文件屏蔽字
	
	signal(SIGCHLD, SIG_IGN);

	return 0;
}


int main(int argc, char *argv[])
{
	time_t now;
	init_daemon();
	syslog(LOG_USER|LOG_INFO, "测试守护进程！\n");
	while(1)
	{
		sleep(8);
		time(&now);
		syslog(LOG_USER|LOG_INFO,"系统时间：\t%s\t\t\n",ctime(&now));
	}

	return EXIT_SUCCESS;
}

