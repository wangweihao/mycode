#include<stdio.h>
int main()
{
	int a = 10,b = -10;
	int c,d;

	c = a >> 31;
	d = b >> 31;
	printf("c = %d, d = %d\n",c,d);

	return 0;
}
