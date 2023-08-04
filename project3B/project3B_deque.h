#ifndef DYNAMIC_DEQUE_H
#define DYNAMIC_DEQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define UNUSED __attribute__((unused))

// Used for size of input
#define MAX_STR_LEN 256

typedef struct Node{
    void *data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque{
    Node *front;
    Node *back;
    int count;
} Deque;

// Deque Functions
Node *newNode(void *data, size_t dataSize);
Deque *createDeque();
void insertFront(Deque *deque, void *data, size_t dataSize);
void insertBack(Deque *deque, void *data, size_t dataSize);
void removeFront(Deque *deque, void *data, size_t dataSize);
void removeBack(Deque *deque, void *data, size_t dataSize);
void freeDeque(Deque *deque);

// Print Functions
typedef void (*printData)(void *);
void printDeque(Deque *deque, printData print);
void printNum(void *data);
void printStr(void *data);

// Errors
void IssueDequeMemoryError();
void IssueNodeMemoryError();
void IssueNodeDataMemoryError();
void IssueRemovalError();

#endif //DYNAMIS_DEQUE_H
