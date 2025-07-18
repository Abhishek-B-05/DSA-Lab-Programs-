#include <stdio.h>

void merge(int a[],int f,int s,int t)
{
	int temp[50],i=f,j=s,k=0;
	while (i<s && j<=t)
	{
		if (a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while (i<s)
		temp[k++]=a[i++];
	while (j<=t)
		temp[k++]=a[j++];
	for(i=f,k=0;i<=t;i++,k++)
		a[i]=temp[k];
	
}

void merge_sort(int a[],int t,int b)
{
	int m;
	if(t<b)
	{
		m=(t+b)/2;
		merge_sort(a,t,m);
		merge_sort(a,m+1,b);
		merge(a,t,m+1,b);
	}
}

int main()
{
	int n;
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements:\n");
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	merge_sort(a,0,n-1);
	printf("Sorted Elements:\n");
	for (int i=0;i<n;i++)
		printf("%d ",a[i]);
}
