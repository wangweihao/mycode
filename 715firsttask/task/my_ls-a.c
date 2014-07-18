#include "include.h"

int my_readirt(const char *path, char (*filename)[100])
{
	DIR *dir;
	struct dirent *ptr;
	int i = 0;
	int j = 0;

	if((dir = opendir(path)) == NULL)
	{
		printf("error");
		exit(1);
	}
	while((ptr = readdir(dir)) != NULL)
	{
		if(i % 8 == 0)
		      printf("\n");
		printf("%-16s",ptr->d_name);
		i++;
		strcpy(filename[i], ptr->d_name);
		j++;
	}
	//sort(filename);
	printf("\n");
	closedir(dir);
}
