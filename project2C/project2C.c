#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

/*
        This is designed to be a playground within which you can test and sample ideas about pointers
        in preparation for project2C. Note: The address and integer values here do not directly map to the
        questions in project2C. Use this script to figure out how pointer access, dereferencing and arithmetic work,
        then apply those concepts to project2C.

        In our setup, we allocate an array of 4KB of data.
        It is unlikely that you will seg fault by walking off the end of the array.
        If you dereference a pointer and get a result of -1, consider it to be out of bounds.

        i.e. printf("%d\n", A+22);

        A note on print formats: If you are printing the address of a value (a pointer),
        use %p. If you are printing a dereferenced value to an integer pointer, use %d.
                If you are printing the result of a pointer arithmetic formula, use %ld. Some examples below.
        Feel free to make up more examples or to pull from the document for additional tests.
*/

/*You do not have to understand the setup, merely the implementation.*/
void* setup()
{
    size_t pagesize = sysconf(_SC_PAGESIZE);
    void *ptr = mmap((void*)0x10000000, pagesize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    /*printf("Virtual memory allocated using mmap at address: %p\n", ptr);*/

    int blocks = (int)pagesize / sizeof(int);
    int *A = (int*)ptr;
    for (int i = 0; i < blocks; ++i)
    {
        A[i] = -1;
    }
    return ptr;
}

int main() {

    size_t pagesize = sysconf(_SC_PAGESIZE);

    void* ptr = setup();
    int* A = (int*)ptr;
    int* B[3] = { A, A+7, A+14 };

    for (int i = 0; i < 21; ++i)
    {       
        if (i == 0) {
            A[0] = 0;
        } else if (i == 1) {
            A[1] = 0;
        } else if (i == 2) {
            A[2] = 1;
        } else if (i == 3) {
            A[3] = 1;
        } else if (i == 4) {
            A[4] = 2;    
        } else if (i == 5) {
            A[5] = 4;
        } else if (i == 6) {
            A[6] = 7;
        } else if (i == 7) {
            A[7] = 13;
        } else if (i == 8) {
            A[8] = 24; 
        } else if (i == 9) {
            A[9] = 44;
        } else if (i == 10) {
            A[10] = 81;
        } else if (i == 11) {
            A[11] = 149;
        } else if (i == 12) {
            A[12] = 274;    
        } else if (i == 13) {
            A[13] = 233;
        } else if (i == 14) {
            A[14] = 377;
        } else if (i == 15) {
            A[15] = 610;
        } else if (i == 16) {
            A[16] = 987; 
        } else if (i == 17) {
            A[17] = 1597;
        } else if (i == 18) {
            A[18] = 2584;
        } else if (i == 19) {
            A[19] = 4181;
        } else if (i == 20) {
            A[20] = 6765;
        }
        

		/*Uncomment this code if you want to print through all values of A*/
        /*printf("A + %d = %p\n", i, A + i);
        printf("A[%d] = %d\n", i, A[i]);*/
    }

    printf("\n");
    printf("A = %p\n", A);
    printf("A[2] = %d\n", A[2]);
    printf("&A = %p\n", &A);
    printf("*(A + 5) - *(A + 3) = %d\n", *(A + 5) - *(A + 3));
    printf("(A + 7) - (A + 2) = %ld\n", (A + 7) - (A + 2));
    printf("A[5] - *(A + 4) = %d\n", A[5] - *(A + 4));
    printf("*A = %d\n", *A);
    printf("B[1] = %p\n", B[1]);
    printf("(A+12) - B[1] = %ld\n", (A+12) - B[1]);
    printf("B[1][4] = %d\n", B[1][4]);
    printf("*(A + 4) = %d\n", *(A + 4));
    printf("B[2][3] - A[16] = %d\n", B[2][3] - A[16]);
    printf("(A+6) = %p\n", (A+6));
    //printf("\n");
    printf("&(B[2][3]) - &(A[15]) = %ld\n", &(B[2][3]) - &(A[15]));
    printf("B[2][0] - B[1][6] = %d\n", B[2][0] - B[1][6]);
    printf("*(&A[6]) = %d\n", *(&A[6]));
    printf("B[2][0] - B[1][7] = %d\n", B[2][0] - B[1][7]);
    printf("B[3] - B[1] = %ld\n", B[3] - B[1]);

    /*
    printf("\n");
	printf("*(&A) = %p\n", *(&A));
	printf("B[0] = %p\n", B[0]);
	printf("A + 1 = %p\n", A + 1);
	printf("A + 6 = %p\n", A + 6);
	printf("B[1] = %p\n", B[1]);
	printf("*(A + 6 + 2) = %d\n", *(A + 8));
	printf("B[1][2] = %d\n", B[1][2]);
	printf("*A = %d\n", *A);
	printf("(A + 3) - (A + 5) = %ld\n", (A + 3) - (A + 5));
	printf("&(B[1][2]) - (A + 4) = %ld\n", &(B[1][2]) - (A + 4));
    */

    /*deallocate the memory used to setup this environment*/
    munmap(ptr, pagesize);

    return 0;
}
