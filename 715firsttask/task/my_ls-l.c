#include"include.h"

void display_attribute(char *filename)
{
	struct stat buf;
	struct passwd *p;
	struct group *g;

	stat(filename, &buf);
	if(S_ISLNK(buf.st_mode))
	      printf("l");
	else if(S_ISDIR(buf.st_mode))
		printf("d");
	else if(S_ISBLK(buf.st_mode))
		printf("b");
	else 
	      printf("-");

	if(S_IRUSR & buf.st_mode)
	      printf("r");
	else
	      printf("-");
	if(S_IWUSR & buf.st_mode)
	      printf("w");
	else
	      printf("-");
	if(S_IXUSR & buf.st_mode)
	      printf("x");
	else
	      printf("-");

	if(S_IRGRP & buf.st_mode)
	      printf("r");
	else
	      printf("-");
	if(S_IWGRP & buf.st_mode)
	      printf("w");
	else
	      printf("-");
	if(S_IXGRP & buf.st_mode)
	      printf("x");
	else
	      printf("-");

	if(S_IROTH & buf.st_mode)
	      printf("r");
	else
	      printf("-");
	if(S_IWOTH & buf.st_mode)
	      printf("w");
	else
	      printf("-");
	if(S_IXOTH & buf.st_mode)
	      printf("x");
	else
	      printf("-");
	printf(" ");

	printf("%d ",buf.st_nlink);

	p = getpwuid(buf.st_uid);
	g = getgrgid(buf.st_gid);
	printf("%s ",p->pw_name);
	printf("%s ",g->gr_name);

	printf("%6d ",buf.st_size);
	printf("%s ",ctime(&buf.st_atime));
	printf("filename:%s",filename);

	printf("\n");
}

