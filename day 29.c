#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    int value;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

struct node* rotateRight(struct node* head, int k) {
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    struct node *temp = head;
    int count = 1;

    
    while(temp->next != NULL) {
        temp = temp->next;
        count++;
    }

 
    temp->next = head;

    k = k % count;   // Handle k > n
    int steps = count - k;

    temp = head;
    for(int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;

    return head;
}

void printList(struct node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;

    scanf("%d", &n);
    struct node* head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}
