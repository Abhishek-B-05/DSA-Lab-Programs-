#include <stdio.h>
#include <ctype.h>

#define size 100
int top = -1;
char stack[size];

void push(char c)
{
    if (top < size - 1)
        stack[++top] = c;
    else
        printf("Stack is full\n");
}

char pop(){
    if (top == -1){
        printf("Stack is empty\n");
        return '\0';
    }
    else {
        return stack[top--];
    }
}

int precedence(char c)
{
    switch (c)
    {
    case '^': return 3;
    case '*':
    case '/': return 2;
    case '+':
    case '-': return 1;
    default: return 0;
    }
}

void main(){
    int i=0,j=0;
    char infix[100];
    char postfix[100];
    char x;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    while(infix[i] != '\0'){
        char c = infix[i];
        if (c == '(')
        {
            push(c);
        }
        else if (isalnum(c))
        {
            postfix[j++] = c;
        }
        else if (c == ')')
        {
            while ((x = pop()) != '(' && x != '\0')
            {
                postfix[j++] = x;
            }
        }
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
            {
                postfix[j++] = pop();
            }
            push(c);
        }
        i++;
    }
    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
}
