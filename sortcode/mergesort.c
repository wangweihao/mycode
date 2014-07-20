#include <stdio.h>
#include <stdlib.h>

#define N 10

void mergesort(int *a);
void msort(int *a, int *b, int Left, int Right);
void merge(int *a, int *b, int lp, int rp, int RightEnd);

int main()
{
	int a[N];
	int i;

	for(i = 0; i < N; i++)
	      scanf("%d",a+i);
	mergesort(a);
	for(i = 0; i < N; i++)
	      printf("a[%d] = %d\n",i,a[i]);

	return 0;

}

void mergesort(int *a)
{
	int *b;

	b = (int*)malloc(sizeof(int) * N);
	if(b != NULL)
	{
		msort(a, b, 0, N-1);
		free(b);
	}
	else
	{
		printf("memory error!");
		exit(1);
	}
}

void msort(int *a, int *b, int Left, int Right)
{
	int Center;

	if(Left < Right)
	{
		Center = (Left + Right) / 2;
		msort(a, b, Left, Center);
		msort(a, b, Center+1, Right);
		merge(a, b, Left , Center+1, Right);
	}
}

void merge(int *a, int *b, int lp, int rp, int RightEnd )
{
	int i, LeftEnd, numelement, temp;

	LeftEnd = rp -1;
	numelement = RightEnd - lp + 1;
	temp = lp;

	while(lp <= LeftEnd && rp <= RightEnd)
		if(a[lp] <= a[rp])
		      b[temp++] = a[lp++];
		else
		      b[temp++] = a[rp++];

	while(lp <= LeftEnd)
	      b[temp++] = a[lp++];
	while(rp <= RightEnd)
	      b[temp++] = a[rp++];

	for(i = 0; i < numelement; i++, RightEnd--)
	      a[RightEnd] = b[RightEnd];

}
