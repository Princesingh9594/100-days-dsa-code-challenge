#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    rear++;
    queue[rear] = value;
}

void display() {
    if (rear < front) {
        printf("Queue is Empty\n");
        return;
    }
    
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

int main() {
    int n, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    display();

    return 0;
}
