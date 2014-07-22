#include<stdio.h>
int Insert_sort(int *a,int N)
{
	int i,j;
	int temp;

	for(i = 1; i < N; i ++)
	{
	 	temp = a[i];
		for(j = i; j > 0 && a[j-1] > temp; j--)
			a[j] = a[j-1];
		a[j] = temp;		
	}
	for(i = 0; i < N; i++)
		printf("a[%d] = %d\n",i,a[i]);	

	return 0;
}

int main()
{
	 int a[10] = {1,5,3,7,6,8,2,0,9,4};

       	Insert_sort(a,10);
	return 0;
}
