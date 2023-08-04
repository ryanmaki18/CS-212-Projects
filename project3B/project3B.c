#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "project3B_deque.h"
#define UNUSED __attribute__((unused))

/*
FIXME: NOT PRINTING IN CORRECT ORDER 
    (Look at Camouswire for what issue is. Their solution used 2 boolean variables, not 4)

TODO: CHECK FOR MEMORY LEAKS ------> TEST ON CHECKER 
*/

int main(UNUSED int argc, UNUSED char *argv[]){
    Deque *strDeque = createDeque();
    Deque *numDeque = createDeque();
    
    char input[MAX_STR_LEN];
    char *endPtr = NULL;
    bool InsertStrFrontOrBack = true;    // Adds to front first, then switches to back -- For Strings
    bool InsertNumFrontOrBack = true;    // Adds to front first, then switches to back -- For Nums

    do{
        printf("Please enter an integer or a string (empty to exit): \n");
        fgets(input, sizeof(input), stdin);
        if (input[0] == '\n') {
            break; 
        }
        // Added '\0' since input was printing with extra '\n' character each print
        input[strlen(input) - 1] = '\0';

        long num = strtol(input, &endPtr, 10);
        if (endPtr == input){
            // Then input is a string
            if (InsertStrFrontOrBack){
                insertFront(strDeque, input, (size_t) (sizeof(input) + 1));
            } else {
                insertBack(strDeque, input, (size_t) (sizeof(input) + 1));
            }
            InsertStrFrontOrBack = !InsertStrFrontOrBack;     // Switches to opposite
            printf("You entered the string: \"%s\"\n", input);
        } else {
            // Then input is a number
            if (InsertNumFrontOrBack){
                insertFront(numDeque, &num, (size_t) sizeof(long));
            } else {
                insertBack(numDeque, &num, (size_t) sizeof(long));
            }
            InsertNumFrontOrBack = !InsertNumFrontOrBack;     // Switches to opposite
            printf("You entered the number: %ld\n", num);
        }
    } while(1);

    // Printing string deque
    printf("\nPrinting string deque\n");
    printDeque(strDeque, printStr);

    // Printing long deque:
    printf("\nPrinting long deque\n");
    printDeque(numDeque, printNum);

    // // FIXME: TEMPORARILY CHANGED FROM TRUE TO CORRESPONDING VARIABLE ABOVE
    // bool RemoveStrFrontOrBack = InsertStrFrontOrBack;    // Removes front first, then switches to back -- For Strings
    // bool RemoveNumFrontOrBack = InsertNumFrontOrBack;    // Removes front first, then switches to back -- For Nums

    // Removing string deque data using count
    printf("\nRemoving string deque data using count\n");
    char returnedStr[MAX_STR_LEN];
    while(strDeque->count > 0){
        if (!InsertStrFrontOrBack){
            removeFront(strDeque, returnedStr, (size_t) MAX_STR_LEN);
        } else {
            removeBack(strDeque, returnedStr, (size_t) MAX_STR_LEN);
        }
        InsertStrFrontOrBack = !InsertStrFrontOrBack;     // Switches to opposite
        printf("Removing %s\n", returnedStr);
    }

    // Removing long deque data using count
    printf("\nRemoving long deque data using count\n");
    int returnedNum[MAX_STR_LEN];
    while(numDeque->count > 0){
        if (!InsertNumFrontOrBack){         //FIXME: CHANGED TO ! TO GET IT TO WORK
            removeFront(numDeque, returnedNum, (size_t) MAX_STR_LEN);
        } else{
            removeBack(numDeque, returnedNum, (size_t) MAX_STR_LEN);
        }
        InsertNumFrontOrBack = !InsertNumFrontOrBack;     // Switches to opposite
        printf("Removing %d\n", *returnedNum);
    }

    // Free the memory used by the deques
    freeDeque(numDeque);
    freeDeque(strDeque);

    return EXIT_SUCCESS;
}
