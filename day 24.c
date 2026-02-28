#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value, key;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

   
    scanf("%d", &n);

   
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

   
    scanf("%d", &key);

    struct Node *current = head, *prev = NULL;

   
    if(current != NULL && current->data == key) {
        head = current->next;
        free(current);
    } else {
       
        while(current != NULL && current->data != key) {
            prev = current;
            current = current->next;
        }

      
        if(current != NULL) {
            prev->next = current->next;
            free(current);
        }
    }

   
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
