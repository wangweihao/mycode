#include <stdio.h>

void shellsort(int *a, int N)
{
	int i,j;
	int Increment; //增量
	int temp;

	for(Increment = N/2; Increment > 0; Increment /= 2 )
	{
		for(i = Increment; i < N; i++)
		{
			temp = a[i];
			for(j = i; j >= Increment; j -= Increment)
			{
				if(temp < a[j-Increment])
				      a[j] = a[j-Increment];
				else
				      break;
			}
			a[j] = temp;
		}
	}

}

int main()
{
	int a[10];
	int i;

	for(i = 0; i < 10; i++)
	      scanf("%d",a+i);
	shellsort(a,10);
	for(i = 0; i < 10; i++)
	      printf("a[%d] = %d\n",i,a[i]);
	
	return 0;
}
