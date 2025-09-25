#include <stdio.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node Node;

Node *top = NULL;

Node *newnode()
{
    Node *p = (Node *)malloc(sizeof(Node));
    return p;
}

int is_empty()
{
    return (top == NULL);
}

void push(int val)
{
    Node *p = newnode();
    p->info = val;
    if(is_empty())
    {
        top = p;
        p->link = NULL;
    }
    else
    {
        p->link = top;
        top = p;
    }
}

void pop()
{
    if(is_empty())
    {
        printf("Stack is empty\n");
        return;
    }
    Node *p = top;
    top = top->link;
    free(p);
}

void peek()
{
    if(is_empty())
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is: %d\n", top->info);
}
void display()
{
    if(is_empty())
    {
        printf("Stack is empty\n");
        return;
    }
    Node *p = top;
    while(p != NULL)
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
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            printf("Top element popped successfully.\n");
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 5);
}
