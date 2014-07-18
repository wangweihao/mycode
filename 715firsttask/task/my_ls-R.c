#include "include.h"

int my_ls_r(const char *path)
{
	DIR *dir;
	struct dirent *p;
	struct stat buf;
	int i = 1;

	if((dir = opendir(path)) == NULL)
	{
		printf("path error!");
		exit(1);
	}
	chdir(path);
	while((p = readdir(dir)) != NULL)
	{
		lstat(p->d_name,&buf);

		if(S_ISDIR(buf.st_mode))
		{
			if(strcmp(p->d_name,".") == 0 || strcmp(p->d_name,"..") == 0)
			{
				continue;
			}
			printf("\n");
			printf("%s :",p->d_name);
			printf("\n");
			my_ls_r(p->d_name);
		}
		else
		{
			if(i % 8 == 0)
			{
				printf("\n");
			}
			printf("%-16s",p->d_name);
			i++;
		
		}
	}
	printf("\n");
	chdir("..");
	closedir(dir);
	return 0;
}

