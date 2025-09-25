#include <stdio.h>

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
}

void delete_front()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return;
    }
    Node *p = front;
    front = front->link;
    if (front == NULL)
        rear = NULL;
    free(p);
}

void peek()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element is: %d\n", front->info);
}

void display()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return;
    }
    Node *p = front;
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
        printf("Menu:\n");
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
            printf("Enter the value to insert: ");
            scanf("%d", &val);
            insert_rear(val);
            break;
        case 2:
            delete_front();
            printf("Front element deleted successfully.\n");
            break;
        case 3:
            peek();
            break;
        case 4:
            if (is_empty())
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 6);
}
