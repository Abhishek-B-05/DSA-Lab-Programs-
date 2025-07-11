#include <stdio.h>

void sort(int a[],int *n)
{
	int small_idx;
	for(int i=0;i<*n;i++)
	{
		small_idx=i;
		for(int j=i+1;j<*n;j++)
			if(a[j]<a[small_idx])
				small_idx=j;
		int temp=a[i];
		a[i]=a[small_idx];
		a[small_idx]=temp;
	}
}

void main()
{
	int n;
	printf("Enter number of elements:\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements: \n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,&n);
	printf("Sorted elements: \n");
	for(int i=0;i<n;i++)
		printf("%d  ",a[i]);
}
