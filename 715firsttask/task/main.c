#include "include.h"

int main(int argc, char * argv[])
{
	int i = 0,n;
	char a[6][20] = {"0","0","0","0","0","0"};           //存放命令，解析命令
	char filename[N][100];
//	struct stat buf;
	char name[100];
	char name1[100];
	DIR *dir;
	struct dirent *ptr;
	int j = 0;
	int k = 0;
	int l = 0;

	getcwd(name,100);
	if((dir = opendir(name)) == NULL)
	{
		printf("error\n");
		exit(1);
	}
	while((ptr = readdir(dir)) != NULL)
	{
		strcpy(filename[l], ptr->d_name);
		//printf("filename[%d]: %s",l,filename[l]);
		l++;
	}
	//sort(filename);
	for(i = 1; i < argc; i++)
	{
		strcpy(a[i],argv[i]);
	}
	if(strcmp(a[1],"ls") == 0 && a[2][0] == '0')
	{
		n = my_readir(name,filename);
	}	
	else if(strcmp(a[2],"-l") == 0 && a[3][0] == '0')
	{
		printf("ls -l\n");
		for(i = 0; i < l;i++)
		{
			if(filename[i][0] != '.')
		        	display_attribute(filename[i]);
		}
	}
	else if(strcmp(a[2],"-a") == 0 && a[3][0] == '0')
	{
		printf("ls -a\n");
		n =my_readirt(name,filename);
	}
	else if((strcmp(a[2],"-a") == 0 && strcmp(a[3],"-l") == 0 && a[4][0] == '0') ||
		(strcmp(a[2],"-l") == 0 && strcmp(a[3],"-a") == 0 && a[4][0] == '0') || 
		(strcmp(a[2],"-al") == 0 && a[3][0] == '0') ||
		(strcmp(a[2],"-la") == 0 && a[3][0] == '0'))
	{
		printf("ls -al -la\n");	
		for(i = 0; i < l; i++)
		      display_attribute(filename[i]);
	}
	else if(strcmp(a[2],"-R") == 0 && a[3][0] == '0')
	{

		printf("ls -R\n");
		getcwd(name1,100);
		my_ls_r(name1);
	
	}
	else if(a[2][0] != '0')
	{
		printf("ls <filename>\n");
	}
	else if(strcmp(a[2],"-i") == 0 && a[3][0] == '0')
	{
		n = my_readirt(name,filename);
	}
	else
	{
		printf("error1\n");
	}
	
	return 0;
}

