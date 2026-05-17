#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int *vetor;
    vetor = ( int* )malloc( sizeof( int ) * ( matSize * *matColSize ) );
    *returnSize = matSize * *matColSize;

    int i = 0, j = 0;
    int p = 0;
    int tamMatriz = matSize * *matColSize;
    
    while ( p < tamMatriz ) {

        while ( i >= 0 && j < *matColSize ) {
            vetor[p] = mat[i][j];
            p++;

            if ( j + 1 >= *matColSize ) {
                i++;
                break;
            } else if ( i == 0) {
                j++;
                break;
            } else {
                i--;
                j++;
            }
        }

        while( j >= 0 && i < matSize ){
            vetor[p] = mat[i][j];
            p++;
        
            if ( i + 1 >= matSize ) {
                j++;
                break;
            } else if ( j == 0 ) {
                i++;
                break;
            } else {
                i++;
                j--;
            }
        }
    }

    
    return vetor;
}

int main() {

    int **mat;
    int matColSize = 3;
    int returnSize;
    int *vetor;

    mat = ( int** ) malloc( sizeof( int* ) * 3 );

    for ( int i = 0; i < 3; i++ ) {
        mat[i] = ( int* ) malloc ( sizeof( int ) * 3);
    }

    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[0][2] = 3;
    mat[1][0] = 4;
    mat[1][1] = 5;
    mat[1][2] = 6;
    mat[2][0] = 7;
    mat[2][1] = 8;
    mat[2][2] = 9;

    vetor = findDiagonalOrder(mat,3,&matColSize,&returnSize);

    for ( int i = 0; i < returnSize; i++ ) {
        printf( "%d ", vetor[i] );
    }

    for ( int i = 0; i < 3; i++ ) {
        free( mat[i] );
    }

    free( mat );
    free( vetor );

    return 0;
}