#include <stdio.h>

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
    return p;
}

int is_empty()
{
    return(head == NULL);
}

void insert_begin(int val)
{
    Node *p = newnode();
    p->prev = NULL;
    p->info = val;
    p->next = head;
    head = p;
}

void insert_end(int val)
{
    Node *p = newnode();
    p->info = val;
    p->next = NULL;
    if(head == NULL)
    {
        head = tail = p;
        p->prev = NULL;
    }
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
        printf("Element %d not found in the list\n", val2);
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
        printf("List is empty\n");
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
        printf("List is empty\n");
        return;
    }
    Node *p = head;
    head = head->next;
    head->prev = NULL;
    free(p);
}

void delete_node(int val)
{
    if (is_empty())
    {
        printf("List is empty\n");
        return;
    }
    Node *p = head;
    while (p != NULL && p->info != val)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        printf("Element %d not found in the list\n", val);
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
}

void display()
{
    if (is_empty())
    {
        printf("List is empty\n");
        return;
    }
    Node *p = head;
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
        printf("Menu:\n");
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
            printf("Enter the value to insert at beginning: ");
            scanf("%d", &val);
            insert_begin(val);
            break;
        case 2:
            printf("Enter the value to insert at end: ");
            scanf("%d", &val);
            insert_end(val);
            break;
        case 3:
            printf("Enter the value to insert: ");
            scanf("%d", &val1);
            printf("Enter the value before which to insert: ");
            scanf("%d", &val2);
            insert_before(val1, val2);
            break;
        case 4:
            printf("Enter the value to insert: ");
            scanf("%d", &val1);
            printf("Enter the value after which to insert: ");
            scanf("%d", &val2);
            insert_after(val1, val2);
            break;
        case 5:
            delete_first();
            printf("First node deleted successfully.\n");
            break;
        case 6:
            printf("Enter the value of the node to delete: ");
            scanf("%d", &val);
            delete_node(val);
            printf("Node with value %d deleted successfully.\n", val);
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 8);
}
