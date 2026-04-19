#include <stdio.h>              
#include <stdlib.h>
#include <stdbool.h>

bool lemonadeChange( int* bills, int billsSize ) {
    int cinco = 0, dez = 0;

    for( int i = 0;i < billsSize;i++ ){
        if ( bills[i] == 5 ) {  
            cinco++;
        } else if ( bills[i] == 10 ) {  
            if ( cinco > 0 ) {
                cinco--;
                dez++;
            } else {
                return false;
            }
        } else if ( bills[i] == 20 ) {  
            if( dez > 0 && cinco > 0 ) {
                cinco = cinco - 1;
                dez = dez - 1;
            } else if ( cinco > 2 ) {
                cinco = cinco - 3;
            } else {
                return false;
            } 
        }
    }
    return true;
}

int main(){


    int vetor1[] = {5,5,5,10,10,10,20,20,20,20};
    int vetor2[] = {5,5,5,5,5,5,5,10,10,10};
    int vetor3[] = {5,5,5,10,10,10,5,5,5,20,5,5,10,20,20};

    printf("TESTE 1\n");
    if ( lemonadeChange(vetor1,10) ) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }

    printf("TESTE 2\n");
    if ( lemonadeChange(vetor2,10) ) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }

     printf("TESTE 3\n");
    if ( lemonadeChange(vetor3,15) ) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }

    return 0;
}