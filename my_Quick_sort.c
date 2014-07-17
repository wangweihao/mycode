#include<stdio.h>

Quick_sort(int *a, int N)
{
	int i = 0, j = N-1;
	int temp =  a[0];

	if(N > 1)
	{
		while(i < j)
		{
			for(; i < j; j--)
			{
				if(a[j] < temp)
				{
					a[i] = a[j];
					break;
				}
			}
			for(; i < j; i++)
			{
				if(a[i] > temp)
				{
					a[j] = a[i];
					break;
				}
			}
		}
		a[i] = temp;
		Quick_sort(a,i);
		Quick_sort(a+i+1, N-i-1);
			
	}
}


int main()
{
	int a[10] = {1,3,5,7,9,0,8,6,4,2};
	int i;
	
	Quick_sort(a,10);
	for(i = 0; i < 10; i++)
	{
		printf("a[%d] = %d\n",i,a[i]);
	}

	return 0;
}
