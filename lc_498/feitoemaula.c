#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int *vetor;
    vetor = (int*)malloc(sizeof(int) * (matSize * *matColSize));
    *returnSize = matSize * *matColSize;

    int i = 0, j = 0;
    int p = 0;
    int tamMatriz = matSize * *matColSize;
    
    while(p < tamMatriz){

    while(i >= 0 && j < *matColSize){
            vetor[p] = mat[i][j];
            p++;
            j++;
            i--;
        }
        if(i < 0){
            i++;
            j--;
        } else if(j > *matColSize){
            j--;
            i = i + 2;
        }

        while(j >= 0 && i < matSize){
            vetor[p] = mat[i][j];
            p++;
            i++;
            j--;
        }
        if(j < 0){
            j++;
            i--;
        } else if(i > matSize){
            i--;
            j = j + 2;
        }
    }

    
    return vetor;
}