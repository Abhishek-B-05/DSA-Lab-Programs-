#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int left(int i)
{
    return(2*i);
}

int right(int i)
{
    return(2*i+1);
}

void heapify(int a[],int n, int i)
{
    int largest = i;
    int lc = left(i);
    int rc = right(i);
    if(lc <= n && a[lc] > a[largest])
        largest = lc;
    if(rc <= n && a[rc] > a[largest])
        largest = rc;
    if(i!= largest)
    {
        swap(&a[i],&a[largest]);
        heapify(a,n,largest);
    }
}

void buildheap(int a[], int n)
{
    for(int i = n/2; i >= 1; i--)
        heapify(a,n,i);
}

void heapsort(int a[], int n)
{
    buildheap(a,n);
    for(int i = n; i >= 2; i--)
    {
        swap(&a[1],&a[i]);
        n=n-1;
        heapify(a,n,1);
    }
}

void main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n+1];
    printf("Enter the elements:\n");
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    heapsort(a,n);
    printf("Sorted elements are:\n");
    for(int i = 1; i <= n; i++)
        printf("%d ",a[i]);
    printf("\n");
}
