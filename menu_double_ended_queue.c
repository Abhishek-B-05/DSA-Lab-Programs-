#include <stdio.h>
#define size 5

int queue[size], f = -1, r = -1;

int is_empty()
{
    if (f == -1)
        return 1;
    return 0;
}

int is_full()
{
    if ((r + 1) % size == f)
        return 1;
    return 0;
}

void insert_rear(int item)
{

    if (f == -1)
        r = f = 0;
    else
        r = (r + 1) % size;
    queue[r] = item;
}

void insert_front(int item)
{
    if (f == -1)
        f = r = 0;
    else
        f = (f - 1 + size) % size;
    queue[f] = item;
}

int delete_front()
{
    int item = queue[f];
    if (f == r)
        f = r = -1;
    else
        f = (f + 1) % size;
    return item;
}

int delete_rear()
{
    int item = queue[r];
    if (f == r)
        f = r = -1;
    else
        r = (r - 1 + size) % size;
    return item;
}

void peek_front()
{
    printf("Element is : %d\n", queue[f]);
}

void peek_rear()
{
    printf("Element is : %d\n", queue[r]);
}

void main()
{
    int choice, n;
    do
    {
        printf("Menu:\n");
        printf("1. Insert - Front\n");
        printf("2. Insert - Rear\n");
        printf("3. Delete - Front\n");
        printf("4. Delete - Rear\n");
        printf("5. Peek - Front\n");
        printf("6. Peek - Rear\n");
        printf("7. Status\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                if (is_full())
                {
                    printf("Queue is Full!");
                }
                else
                {
                    printf("Enter the element to insert: ");
                    scanf("%d", &n);
                    insert_front(n);
                }
                break;
            case 2:
                if (is_full())
                {
                    printf("Queue is Full!");
                }
                else
                {
                    printf("Enter the element to insert: ");
                    scanf("%d", &n);
                    insert_rear(n);
                }
                break;
            case 3:
                if (is_empty())
                {
                    printf("Queue is Empty!");
                }
                else
                {
                    n = delete_front();
                    printf("Deleted element: %d\n", n);
                }
                break;
            case 4:
                if (is_empty())
                {
                    printf("Queue is Empty!");
                }
                else
                {
                    n = delete_rear();
                    printf("Deleted element: %d\n", n);
                }
                break;
            case 5:
                if (is_empty())
                    printf("Queue is Empty!\n");
                else
                    peek_front();
                break;
            case 6:
                if (is_empty())
                    printf("Queue is Empty!\n");
                else
                    peek_rear();
                break;
            case 7:
                if (is_empty())
                    printf("Queue Empty!\n");
                else if (is_full())
                    printf("Queue Full!\n");
                else
                    printf("Space Available\n");
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);
}
