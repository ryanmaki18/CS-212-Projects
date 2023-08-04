#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int *AllocateArray(int N){
    /* Allocate an array with N integers.
     * The value of each element of the array should be a
     * random number between 0 and 10N.
     * Hint: use the rand() function and a modulo operator.
     */
    int *A = malloc(N * sizeof(int));
    for(int i = 0; i < N; i++){
        A[i] = rand() % (10 * (N + 1));
    }
    return A;
}

int ascendingCompare(const void *x_void, const void *y_void){
    int x = *(int *)x_void;
    int y = *(int *)y_void;
    return x - y;
}

int descendingCompare(const void *x_void, const void *y_void){
    // Not being called but can swap out with "ascendingCompare" arguement in qsort below
    int x = *(int *)x_void;
    int y = *(int *)y_void;
    return y - x;
}

void SortArray(int *A, int N){
    
    qsort(A, N, sizeof(int), ascendingCompare);
    
    // Bubble Sort
    // for (int i = 0; i < N; i++){
    //     for (int j = i + 1; j < N; j++){
    //         /* If this pair is out of order */
    //         if (A[i] > A[j]){
    //             /* Swap them */
    //             int tmp = A[j]; 
    //             A[j] = A[i];
    //             A[i] = tmp;
    //         }
    //     }
    // }
    
}

void DeallocateArray(int *A){
    free(A);
}

int main(){
// Default Sizes:
int sizes[8] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000 };

// For fun:
// int sizes[11] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000, 256000, 512000, 1024000 }; 


    for (int i = 0; i < 8; i++){
        double alloc_time = 0., sort_time = 0., dealloc_time = 0.;
        struct timeval startTime;
        struct timeval endTime;
        
        /* Call the three functions in a sequence. Also use
         * gettimeofday calls surrounding each function and set the 
         * corresponding variable (alloc_time, sort_time, dealloc_time).
         */

        // AllocateArray Function Call
        gettimeofday(&startTime, NULL);
        int *A = AllocateArray(sizes[i]);
        gettimeofday(&endTime, NULL);
        alloc_time = (double)(endTime.tv_sec - startTime.tv_sec) + 
                     ((double)(endTime.tv_usec - startTime.tv_usec) / 1000000.0);
        // Uncomment to print out all Arrays
        // for(int j = 0; j < sizes[i]; j++){
        //     printf("A[%d] = %d\n", j, A[j]);
        // }

        // SortArray Function Call
        gettimeofday(&startTime, NULL);
        SortArray(A, sizes[i]);
        gettimeofday(&endTime, NULL);
        sort_time = (double)(endTime.tv_sec - startTime.tv_sec) + 
                    ((double)(endTime.tv_usec - startTime.tv_usec) / 1000000.0);
        // Uncomment to print out all Arrays
        // for(int j = 0; j < sizes[i]; j++){
        //     printf("A[%d] = %d\n", j, A[j]);
        // }

        // DeallocateArray Function Call
        gettimeofday(&startTime, NULL);
        DeallocateArray(A);
        gettimeofday(&endTime, NULL);
        dealloc_time = (double)(endTime.tv_sec - startTime.tv_sec) + 
                       ((double)(endTime.tv_usec - startTime.tv_usec) / 1000000.0);

        printf("Timings for array of size %d\n", sizes[i]);
        printf("\tTime for allocation is %g, time per element = %g\n", alloc_time, alloc_time/sizes[i]);
        printf("\tTime for sort_time is %g, time per element = %g\n", sort_time, sort_time/sizes[i]);
        printf("\tTime for deallocation is %g\n", dealloc_time);
    }
}
