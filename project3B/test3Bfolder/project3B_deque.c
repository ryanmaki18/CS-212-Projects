#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project3B_deque.h"

void IssueDequeMemoryError(){
    fprintf(stderr, "Error allocating memory for deque.\n");
    exit(EXIT_FAILURE);
}

void IssueNodeMemoryError(){
    fprintf(stderr, "Error allocating memory for node.\n");
    exit(EXIT_FAILURE);
}

void IssueNodeDataMemoryError(){
    fprintf(stderr, "Error allocating memory for node data.\n");
    exit(EXIT_FAILURE);
}

void IssueRemovalError(){
    fprintf(stderr, "You tried to remove data when the deque was empty\n");
    exit(EXIT_FAILURE);
}

Node *newNode(void *data, size_t dataSize){
    Node *node = malloc(sizeof(Node));
    if(node == NULL){ 
        free(node);
        IssueNodeMemoryError(); 
    }

    node->data = malloc(dataSize);
    if(node->data == NULL){ 
        free(node->data);
        IssueNodeDataMemoryError(); 
    }

    memcpy(node->data, data, dataSize);

    node->next = NULL;
    node->prev = NULL;

    return node;
}

Deque *createDeque(){
    Deque *deque = malloc(sizeof(Deque));
    if (deque == NULL){ 
        free(deque);
        IssueDequeMemoryError(); 
    }

    deque->front = NULL;
    deque->back = NULL;
    deque->count = 0;

    return deque;
}

void insertFront(Deque *deque, void *data, size_t dataSize){
    Node *currNode = newNode(data, dataSize);
    
    if (deque->front == NULL){
        // Then the deque is currently empty
        deque->front = currNode;
        deque->back = currNode;
    } else {
        currNode->next = deque->front;
        deque->front->prev = currNode;
        deque->front = currNode;
    }
    deque->count++;
}

void insertBack(Deque *deque, void *data, size_t dataSize){
    Node *currNode = newNode(data, dataSize);
    
    if (deque->front == NULL){
        // Then the deque is currently empty
        deque->front = currNode;
        deque->back = currNode;
    } else {
        currNode->prev = deque->back;
        deque->back->next = currNode;
        deque->back = currNode;
    }
    deque->count++;
}

void removeFront(Deque *deque, void *data, size_t dataSize){
    if (deque->front == NULL){
        // Then the deque is currently empty
        IssueRemovalError();
    }
    if(deque->count == 1){
        Node *removedNode = deque->front;
        memcpy(data, removedNode->data, dataSize);
        
        deque->front = NULL;
        deque->back = NULL;
        free(removedNode->data);
        free(removedNode);
        deque->count--;
    } else {
        Node *removedNode = deque->front;
        memcpy(data, removedNode->data, dataSize);

        deque->front = removedNode->next;
        if(deque->front != NULL){
            deque->front->prev = NULL;
        }
        
        free(removedNode->data);
        free(removedNode);
        deque->count--;
    }
}

void removeBack(Deque *deque, void *data, size_t dataSize){
    if (deque->back == NULL){
        // Then the deque is currently empty
        IssueRemovalError();
    }
    if(deque->count == 1){
        Node *removedNode = deque->back;
        memcpy(data, removedNode->data, dataSize);

        deque->front = NULL;
        deque->back = NULL;
        free(removedNode->data);
        free(removedNode);
        deque->count--;
    } else {
        Node *removedNode = deque->back;
        memcpy(data, removedNode->data, dataSize);

        deque->back = removedNode->prev;
        if(deque->back != NULL){
            deque->back->next = NULL;
        }
        free(removedNode->data);
        free(removedNode);
        deque->count--;
    }
}

void freeDeque(Deque *deque){
    free(deque);
}
 
void printDeque(Deque *deque, printData print){
    // Iterate through nodes in this function
    Node *curr = deque->front;

    while(curr != NULL){
        print(curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void printNum(void *data){
    long *num = (long *)data;
    printf("%ld ", *num);
}

void printStr(void *data){
    char *str = (char *)data;
    printf("%s ", str);
}
