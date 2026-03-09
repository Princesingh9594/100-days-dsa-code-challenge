#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
int size;


void enqueue(int x)
{
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % size;
        queue[rear] = x;
    }
}


void dequeue()
{
    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
}


void display()
{
    if(front == -1)
        return;

    int i = front;

    while(1)
    {
        printf("%d ", queue[i]);

        if(i == rear)
            break;

        i = (i + 1) % size;
    }
}

int main()
{
    int n, m, i;

    scanf("%d", &n);
    size = n;

    int arr[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        enqueue(arr[i]);
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        dequeue();
    }

    display();

    return 0;
}
