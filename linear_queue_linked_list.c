#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node Node;

Node *front = NULL;
Node *rear = NULL;

Node *newnode()
{
    Node *p = (Node *)malloc(sizeof(Node));
    return p;
}

int is_empty()
{
    return (front == NULL);
}

void insert_rear(int val)
{
    Node *p = newnode();
    p->info = val;
    p->link = NULL;
    if (is_empty())
    {
        front = rear = p;
    }
    else
    {
        rear->link = p;
        rear = p;
    }
    printf("\nElement inserted successfully.\n");
}

void delete_front()
{
    if (is_empty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    Node *p = front;
    front = front->link;
    if (front == NULL)
        rear = NULL;
    free(p);
    printf("\nFront element deleted successfully.\n");
}

void peek()
{
    if (is_empty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nFront element is: %d\n", front->info);
}

void display()
{
    if (is_empty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    Node *p = front;
    printf("\nQueue: ");
    while (p != NULL)
    {
        printf("%d -> ", p->info);
        p = p->link;
    }
    printf("NULL\n");
}

void main()
{
    int choice, val;
    do
    {
        printf("\nMenu:\n");
        printf("1. Insert at Rear\n");
        printf("2. Delete from Front\n");
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
            insert_rear(val);
            break;
        case 2:
            delete_front();
            break;
        case 3:
            peek();
            break;
        case 4:
            if (is_empty())
            {
                printf("\nQueue is empty\n");
            }
            else
            {
                printf("\nQueue is not empty\n");
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
