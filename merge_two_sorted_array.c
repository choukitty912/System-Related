/*-------------------------------------------
 * Merge Two sorted array 
 * Sept 17th, 2019
 *-------------------------------------------*/

 #include <stdio.h>
#include <stdlib.h>

 //  Merge two sorted arrays into a third array while removing redundant values.  Return size of merged array C.
//  Either list may be empty.  Memory allocated for C is guaranteed to be sufficient for merged list.
//
//  Example:
//    A[] contains   1,3,5,11,22,55,87 
//    B[] contains   2,2,3,8,11,25  
//    C[] should be  1,2,3,5,8,11,22,25,55,87

uint32_t ArrayMerge(uint32_t Asize, uint32_t *A, uint32_t Bsize, uint32_t *B, uint32_t *C) 
{
    if (!C) return 0;

    if (!A && !B) return 0;

    uint32_t count = 0, i = 0, j = 0;
    while (i < Asize  && j < Bsize) {
        while (i < (Asize - 1) && A[i] == A[i+1]) {
            i++;
        }
        while (j < (Asize - 1) && B[j] == B[j+1]) {
            j++;
        }

        if (A[i] < B[j]) {
            if (count == 0 || (count >0 && C[count-1] != A[i])) {
                C[count++] = A[i];
            }
            i++;
        } else {
            if (count == 0 || (count > 0 && C[count-1] != B[j])) {
                C[count++] = B[j];
            }
            j++;
        }
    }

    while (i < Asize) {
        while (i < (Asize - 1) && A[i] == A[i+1]) {
            i++;
        } 
        if (count == 0 || (count >0 && C[count-1] != A[i])) {
                C[count++] = A[i];
        }
        i++;
    }

    while (j < Bsize) {
        while (i < (Bsize - 1) && B[i] == B[i+1]) {
            j++;
        } 
        
        if (count == 0 || (count > 0 && C[count-1] != B[j])) {
                C[count++] = B[j];
        }
        j++;
    }

    return count;
}

void print_array(uint32_t Asize, uint32_t *A) {

    for (int i = 0; i < Asize; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(void) 
{

//  Example:
//    A[] contains   1,3,5,11,22,55,87 
//    B[] contains   2,2,3,8,11,25  
//    C[] should be  1,2,3,5,8,11,22,25,55,87
    uint32_t A[] = {1,3,5,11,22,55,87, 87, 87 };
    uint32_t B[] = { 2,2,3,8,11,25  };
    uint32_t *C = malloc(sizeof(A) + sizeof(B));

    int count = ArrayMerge(9, A, 6, B, C);
    printf("Input: \n");
    print_array(9, A);
    print_array(6,B);
    printf("Output: \n");
    print_array(count, C);

    return 0;


}
