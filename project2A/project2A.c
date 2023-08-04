/* Project 2A -- Ryan Maki */
// C program that finds the odd, composite numbers between 10 and 500
#include <stdio.h>

#define UNUSED __attribute__ ((unused))

int isComposite(int num);

int main(UNUSED int argc, UNUSED char *argv[]) {
    int i;
    for (i = 10; i <=500; i++) {
        int isOdd = 0;
        // Checks if Odd
        if ((i % 2) == 1)
            isOdd = 1;
        if (isOdd && isComposite(i))
            printf("%d is a composite number.\n", i);
    }
    return 0;
}

int isComposite(int num){
    for (int i = 2; i <= ((i+(num/i))/2); i++) {
        if ((num % i) == 0)
            return 1;
    }
    return 0;
}
