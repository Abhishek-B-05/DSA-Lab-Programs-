#include <stdio.h>

int search(int *c, int *flag, int *n, int *m, int a[])
{
	for(int i=0;i<*n;i++)
		if (a[i]==*m)
			{
				
				*flag=1;
				*c=i;
			}
}

void main()
{
	int flag=0,c,i,n,m;
	printf("Enter number of elements:\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	i=0;
	printf("Enter the element to be searched:\n");
	scanf("%d",&m);
	search(&c,&flag,&n,&m,a);
	if (!flag)
		printf("The given number doesnot exist");
	else
		printf("%d found at %d position",m,c+1);
}
