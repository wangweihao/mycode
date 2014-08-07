#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int Capacity;
	int *array;
};

void exchange(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void Adjustheap(struct Node *a)
{
	int i;

	i = a->Capacity / 2;
	if(a->Capacity %2 == 1)
	{
		while(i != 0)
		{
			if(a->array[2*i] < a->array[2*i+1])
				exchange(a->array+2*i, a->array+2*i+1);
			if(a->array[i] < a->array[2*i])
				exchange(a->array+i, a->array+2*i);
			i--;
		}
	}
	else if(a->Capacity %2 == 0)
	{
		if(a->array[2*i] > a->array[i])
		{
			exchange(a->array+2*i, a->array+i);
		}
		i--;
		while(i != 0)
		{
			if(a->array[2*i] < a->array[2*i+1])
				exchange(a->array+2*i, a->array+2*i+1);
			if(a->array[i] < a->array[2*i])
				exchange(a->array+i, a->array+2*i);
			i--;
		}
	}
	printf("a->array[1] = %d\n",a->array[1]);
	exchange(a->array+1, a->array+(a->Capacity));
	a->Capacity--;
}

int main()
{
	struct Node *a;
	int i;
	int j;

	printf("Capacity:");
	scanf("%d",&a->Capacity);
	j = a->Capacity;
	a->array = (int *)malloc(sizeof(int) * (a->Capacity+1));
	for(i = 1; i <= a->Capacity; i++)
	{
		scanf("%d",a->array+i);	
	}
	while(a->Capacity >= 1)
	{
	        Adjustheap(a);
	}
	for(i = 1; i <= j; i++)
	{
		printf("the value is %d\n",a->array[i]);
	}
		
	return 0;
}
