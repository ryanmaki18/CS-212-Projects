#include <stdio.h>
#include <stdlib.h>
#include "project3C_hashtable.h"

/* ---- Errors ---- */
void IssueNodeMemoryError(){
    printf("Failed to allocate memory for new node.\n");
    exit(EXIT_FAILURE);
}

void IssueNoFileError(){
    printf("No file entered, exiting program...\n");
    exit(EXIT_SUCCESS);
}

/* ---- Hash Table Implementation ---- */
unsigned int hash(const char *key){
    unsigned int hash = 0;
    for(int i = 0; key[i] != '\0'; i++){
        hash = hash * 31 + key[i];
    }
        return hash % BUCKET_SIZE;
}

void initialize(HashTable *ht){
    for(int i = 0; i < BUCKET_SIZE; i++){
        ht->bucket[i] = NULL;
    }
}

Node *createNode(const char *key, int value){
    Node *node = malloc(sizeof(Node));
    if(node == NULL){ IssueNodeMemoryError(); }

    node->key = strdup(key);
    node->value = value;
    node->next = NULL;

    return node;
}

void insert(HashTable *ht, const char *key, int value){
    Node *newNode = createNode(key, value);
    unsigned int hashKey = hash(key);
    Node *currNode = ht->bucket[hashKey];

    if(currNode == NULL){
       ht->bucket[hashKey] = newNode;
    } else {
        while(currNode->next != NULL){
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
    ht->count++;
}

void get(HashTable *ht, const char *key, int **results, int *count){
    unsigned int hashKey = hash(key);
    Node *currNode = ht->bucket[hashKey];
    while (currNode != NULL){
        if (strcmp(currNode->key, key) == 0){
            *results = realloc(*results, sizeof(int) * (*count + 1));
            (*results)[*count] = currNode->value;
            (*count)++;
        }
        currNode = currNode->next;
    }
}

void freeHashTable(HashTable *ht){
    for(int i = 0; i < BUCKET_SIZE; i++){
        Node *currNode = ht->bucket[i];
        while (currNode != NULL){
            Node *nextNode = currNode->next;
            free(currNode->key);
            free(currNode);
            currNode = nextNode;
        }
    }
}

float calculateLoadFactor(HashTable *ht){
    return (float) ht->count / BUCKET_SIZE;
}

void printHashTable(const HashTable *ht){
    int wordCount = 0;
    for(int i = 0; i < BUCKET_SIZE; i++){
        printf("Bucket #%d: ", i);
        Node *currNode = ht->bucket[i];
        if(currNode == NULL){
            printf("NULL\n");
        } else {
            while (currNode != NULL){
                printf("key = %s, value = %d\n", currNode->key, currNode->value);
                currNode = currNode->next;
                wordCount++;
            }
        }
    }
    printf("\nWords Printed = %d\n", wordCount);
}
