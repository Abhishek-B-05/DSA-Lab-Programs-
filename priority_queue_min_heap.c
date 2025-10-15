#include <stdio.h>
#define max 20

int pq[max];
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int is_empty()
{
    return(size == 0);
}

int is_full()
{
    return(size >= max);
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int lc = left(i);
    int rc = right(i);
    if (lc <= n && a[lc] < a[largest])
        largest = lc;
    if (rc <= n && a[rc] < a[largest])
        largest = rc;
    if (i != largest)
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void insert(int val)
{
    if(is_full())
    {
        printf("Queue Full!\n");
        return;
    }
    size++;
    pq[size] = val;
    int curr=size;
    int par=curr/2;
    if(par>=1 && pq[par]>pq[curr])
    {
        while(par>=1 && pq[par]>pq[curr])
        {
            swap(&pq[par],&pq[curr]);
            curr=par;
            par=curr/2;
        }
    }
}

int delete_min()
{
    if(is_empty())
    {
        printf("Queue Empty!\n");
        return;
    }
    int min = pq[1];
    pq[1] = pq[size];   
    size--;
    heapify(pq, size, 1);
    return min;
}

void peek()
{
    if(is_empty())
    {
        printf("Queue Empty!\n");
        return;
    }
    printf("Minimum element is: %d\n", pq[1]);
}

void display()
{
    if(is_empty())
    {
        printf("Queue Empty!\n");
        return;
    }
    printf("Priority Queue: ");
    for(int i = 1; i <= size; i++)
        printf("%d ", pq[i]);
    printf("\n");
}

void main()
{
    int choice, val;
    do
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete Min\n");
        printf("3. Peek\n");
        printf("4. Status\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            val = delete_min();
            if(val)
                printf("\nMinimum element %d deleted successfully.\n", val);
            break;
        case 3:
            peek();
            break;
        case 4:
            if (is_empty())
            {
                printf("\nQueue is empty\n");
            }
            else if (is_full())
            {
                printf("\nQueue is full\n");
            }
            else
            {
                printf("\nSpace available in Queue\n");
            }
            break;
        case 5:
            display();
            break;
        case 6:
            printf("\nExiting...\n");
            break;
        default:
            printf("\nInvalid choice!\n");
        }
    } while (choice != 6);
}
