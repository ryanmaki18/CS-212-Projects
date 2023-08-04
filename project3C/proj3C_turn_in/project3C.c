#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "project3C_hashtable.h"
#define UNUSED __attribute__((unused))


int main(UNUSED int argc, UNUSED char *argv[]){

    HashTable *ht = malloc(sizeof(HashTable));
    initialize(ht);

    char file_name[50];
    FILE *input_file = NULL;

    // While Loop to get file name/re-prompt if invalid
    while(input_file == NULL){
        printf("Enter the filename (or leave blank to quit): ");
        fgets(file_name, sizeof(file_name), stdin);
        if (file_name[0] == '\n') { IssueNoFileError(); }
        file_name[strlen(file_name) - 1] = '\0';
        // printf("File Name: %s\n", file_name);   // Uncomment to print out file name

        // Opening file
        input_file = fopen(file_name, "r");
        if (input_file == NULL) {  
            printf("Failed to open file '%s'. Please try again.\n", file_name);
            continue;
        }
    }

    // Tokenizing File and Building Hash Bucket
    printf("Tokenizing file '%s' and building hash bucket...", file_name);
    int lineNum = 0;
    int wordCount = 0;
    char input[200];
    while(fgets(input, sizeof(input), input_file) != NULL){
        if (input[strlen(input) - 1] == '\n'){
            input[strlen(input) - 1] = '\0';
        }
        // printf("Input[%d]: %s\n", lineNum, input);         // Uncomment to print out each line   
        
        // Breaks apart each word based on delimiter
        const char *delimiter = " ";
        char *currWord = strtok(input, delimiter);
        while(currWord != NULL){
            // Switches each char in word to lowercase
            for(int i = 0; currWord[i] != '\0'; i++){
                currWord[i] = tolower(currWord[i]);
            }
            // printf("Word[%d]; %s\n", wordCount, currWord);         // Uncomment to print out each word   
            
            insert(ht, currWord, lineNum);
            currWord = strtok(NULL, delimiter);
            wordCount++;
        }
        lineNum++; 
    }
    printf("done.\n");

    // Calculating Load Factor
    float loadFactor = calculateLoadFactor(ht);
    printf("Load factor: %.2f", loadFactor);

    // // Printing Hash Table (Mainly made for testing)
    // printf("\nPrinting Hash Table:\n");
    // printHashTable(ht);

    // Searching Hash Table for Word
    do{
        printf("\nEnter a word to search (or leave blank to quit): ");
        char word[100];
        char *originalWord = malloc(sizeof(char) * 100);
        int *results = malloc(sizeof(int) * 50);
        int foundCount = 0;       
        fgets(word, sizeof(word), stdin);
        if (word[0] == '\n') {
            free(results);
            free(originalWord);
            break;
        }
        if (word[strlen(word) - 1] == '\n'){
            word[strlen(word) - 1] = '\0';
        }
        // Switches each char in word to lowercase
        strncpy(originalWord, word, strlen(word));
        for(int i = 0; word[i] != '\0'; i++){
            word[i] = tolower(word[i]);
        }
        // printf("Word: %s\n", word);   // Uncomment to print out search word
        
        get(ht, word, &results, &foundCount);
        // printf("results: %d " results[0]);
        // printf("foundCount: %d", foundCount);

        // TODO: Can replace "word" with originalWord to have it print exactly what was inputted
        if(foundCount >= 1){
            printf("Word '%s' found at line number(s): ", word);
            for(int i = 0; i < foundCount; i++){
                printf("%d ", (results[i] + 1));
            }
            free(results);
            free(originalWord);
        } else {
            printf("Word '%s' not found.", word);
            free(results);
            free(originalWord);
        }
    } while(1);

    fclose(input_file);
    freeHashTable(ht);
    free(ht);
    return EXIT_SUCCESS;
}