#include <stdio.h>

void search(int a[], int *t,int *b,int *m,int *num,int *flag)
{
	while(*t<=*b)
	{
		*m=(*t+*b)/2;
		if(a[*m]>*num)
			*b=*m-1;
		else
			if(a[*m]<*num)
				*t=*m+1;
			else
				if(a[*m]==*num)
					{
						*flag=1;
						break;
					}
					
				else			
					*flag=0;
	}
}

					
void main()
{
	int flag,t=0,n,b,num,m;
	printf("Enter number of elements:\n");
	scanf("%d",&n);
	b=n-1;
	int a[n];
	printf("Enter the elements: \n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be searched:\n");
	scanf("%d",&num);
	search(a,&t,&b,&m,&num,&flag);
	if (!flag)
		printf("The given number doesnot exist");
	else
		printf("%d found at %d position",num,m+1);
}	

