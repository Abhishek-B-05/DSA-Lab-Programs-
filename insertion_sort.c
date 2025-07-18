#include <stdio.h>

void sort(int a[],int *n)
{
	int key,i;
	for(int p=0;p<*n;p++)
	{
		key=a[p];
		i=p-1;
		while(i>=0 && key<a[i])
		{
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=key;
	}
}

void main()
{
	int n;
	printf("Enter the number of elements: \n");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,&n);
	printf("Sorted elements:\n");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}	
