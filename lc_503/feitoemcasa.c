#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* nextGreaterElements( int* nums, int numsSize, int* returnSize ) {
    *returnSize = numsSize;

    if ( *returnSize == 1 ) {
        nums[0] = -1;
        return nums;
    } 
    
    int j;
    int *vetor;
    vetor = ( int* )malloc( sizeof( int ) * numsSize );

    for ( int i = 0;i < numsSize; i++ ) {
        j = i + 1;  
        while ( true ){
            if( j == numsSize ) {
                j = 0;
            }
            vetor[i] = -1;
            if ( nums[j] > nums[i] ) {
                vetor[i] = nums[j];
                break;
            } else if( i == j && i == 0 ) {
                break;
            }
            j++;
            if ( i == j ) {
                break;
            }  
        }
    }
    return vetor;
}

int main(){

   

    return 0;
}