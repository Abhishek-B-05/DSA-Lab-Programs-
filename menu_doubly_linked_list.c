#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int info;
    struct node *next;
};

typedef struct node Node;

Node *head = NULL;
Node *tail = NULL;

Node *newnode()
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = p->prev = NULL;
    return p;
}

int is_empty()
{
    return(head == NULL);
}

void insert_begin(int val)
{
    Node *p = newnode();
    p->info = val;
    if(head == NULL)
    	head = tail = p;
    else
    {
    	p->next = head;
    	head->prev = p;
    	head = p;
    }
}

void insert_end(int val)
{
    Node *p = newnode();
    p->info = val;
    if(head == NULL)
        head = tail = p;
      
    else
    {
        tail->next = p;
        p->prev = tail;
        tail = p;
    }
}

void insert_before(int val1,int val2)
{
    Node *p = newnode();
    Node *q = head;
    p->info = val1;
    while(q != NULL && q->info != val2)
    {
        q = q->next;
    }
    if(q == NULL)
    {
        printf("\nElement %d not found in the list\n", val2);
        free(p);
        return;
    }
    else if(q == head)
    {
        p->next = q;
        q->prev = p;
        p->prev = NULL;
        head = p;
    }
    else
    {
        p->prev = q->prev;
        q->prev->next = p;
        p->next = q;
        q->prev = p;
    }
}

void insert_after(int val1,int val2)
{
    Node *p = newnode();
    Node *q = head;
    p->info = val1;
    while(q != NULL && q->info != val2)
    {
        q = q->next;
    }
    if(q == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    else if(q == head)
    {
        p->next = NULL;
        p->prev = q;
        tail = p;
        q->next = p;
    }
    else
    {
        p->prev = q;
        p->next = q->next;
        q->next = p;
        q->next->prev = p;
    }
}

void delete_first()
{
    if (is_empty())
    {
        printf("\nList is empty\n");
        return;
    }
    Node *p = head;
    if(head == tail)
    {
    	head = tail = NULL;
    }
    else
    {
    	head = head->next;
    	head->prev = NULL;
    }
    free(p);
    printf("\nFirst node deleted successfully.\n");
}

void delete_node(int val)
{
    if (is_empty())
    {
        printf("\nList is empty\n");
        return;
    }
    Node *p = head;
    while (p != NULL && p->info != val)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        printf("\nElement %d not found in the list\n", val);
        return;
    }
    if(p == head)
    {
        head = p->next;
    }
    else if(p == tail)
    {
        tail = p->prev;
        tail->next = NULL;
    }
    else
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
    free(p);
    printf("\nNode with value %d deleted successfully.\n", val);
}

void display()
{
    if (is_empty())
    {
        printf("\nList is empty\n");
        return;
    }
    Node *p = head;
    printf("Queue: ");
    while (p != NULL)
    {
        printf("%d -> ", p->info);
        p = p->next;
    }
    printf("NULL\n");
}

void main()
{
    int choice, val, val1, val2;
    do
    {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert Before a Node\n");
        printf("4. Insert After a Node\n");
        printf("5. Delete First Node\n");
        printf("6. Delete a Node\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert at beginning: ");
            scanf("%d", &val);
            insert_begin(val);
            printf("\nElement inserted successfully\n");
            break;
        case 2:
            printf("\nEnter the value to insert at end: ");
            scanf("%d", &val);
            insert_end(val);
            printf("\nElement inserted successfully\n");
            break;
        case 3:
            printf("\nEnter the value to insert: ");
            scanf("%d", &val1);
            printf("\nEnter the value before which to insert: ");
            scanf("%d", &val2);
            insert_before(val1, val2);
            printf("\nElement inserted successfully\n");
            break;
        case 4:
            printf("\nEnter the value to insert: ");
            scanf("%d", &val1);
            printf("\nEnter the value after which to insert: ");
            scanf("%d", &val2);
            insert_after(val1, val2);
            printf("\nElement inserted successfully\n");
            break;
        case 5:
            delete_first();
            break;
        case 6:
            printf("\nEnter the value of the node to delete: ");
            scanf("%d", &val);
            delete_node(val);
            break;
        case 7:
            display();
            break;
        case 8:
            printf("\nExiting...\n");
            break;
        default:
            printf("\nInvalid choice!\n");
        }
    } while (choice != 8);
}
