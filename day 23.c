#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node dummy;  
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while(head1 != NULL && head2 != NULL) {
        if(head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

   
    if(head1 != NULL)
        tail->next = head1;
    else
        tail->next = head2;

    return dummy.next;
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL, *temp = NULL;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if(head1 == NULL) {
            head1 = newNode;
            temp = head1;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

 
    scanf("%d", &m);
    temp = NULL;
    for(int i = 0; i < m; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if(head2 == NULL) {
            head2 = newNode;
            temp = head2;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    
    struct Node* mergedHead = mergeLists(head1, head2);

   
    temp = mergedHead;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
