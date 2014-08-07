#include<stdio.h>

int mystrlen(char *a)
{
	if(*a == '\0')
	      return 0;
	else
	      return mystrlen(a+1) + 1;
}

int main()
{
	char a[20];
	int res;
	scanf("%s",a);
	res = mystrlen(a);
	printf("%d\n",res);

	return 0;
}
