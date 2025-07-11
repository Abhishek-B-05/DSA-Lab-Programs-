#include <stdio.h>

void sort(int a[],int *n)
{
	int c,p;
	for(p=0;p<*n-1;p++)
		for(c=1;c<*n-1;c++)
			if(a[c]>a[c+1])
			{
				int temp=a[c];
				a[c]=a[c+1];
				a[c+1]=temp;
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
