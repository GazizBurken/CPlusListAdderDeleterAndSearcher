#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Ошибка выделения памяти\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* addNode(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* deleteNode(Node* head, int key) {
    Node* temp = head, *prev;
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return head;
    prev->next = temp->next;
    free(temp);
    return head;
}

Node* searchNode(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return NULL;
}

int main() {
    Node* head = NULL;
    head = addNode(head, 1);
    head = addNode(head, 2);
    head = addNode(head, 3);
    head = deleteNode(head, 2);
    Node* res = searchNode(head, 3);
    if (res != NULL)
        printf("Узел найден: %d\n", res->data);
    else
        printf("Узел не найден\n");
    return 0;
}
