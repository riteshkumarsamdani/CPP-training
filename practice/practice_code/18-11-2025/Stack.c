#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top] = value;
    }
}

int pop()
{
    int val;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        val = -1;
    }
    else
    {
        val = stack[top--];
    }
    return val;
}

void display()
{
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();

    printf("Popped: %d\n", pop());
    display();
    return 0;
}
