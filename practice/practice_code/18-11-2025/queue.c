#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1) front = 0;
        queue[++rear] = value;
    }
}

int dequeue()
{
    int val;
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        val = -1;
    }
    else
    {
        val = queue[front++];
    }
    return val;
}

void display()
{
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Dequeued: %d\n", dequeue());
    display();
    return 0;
}
