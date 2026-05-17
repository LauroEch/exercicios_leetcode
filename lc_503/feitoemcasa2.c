#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int topo;
    int limite;
    int *elementos;
}Pilha;

void Reset(Pilha *pilha, int tamanho){
    pilha->limite = tamanho;
    pilha->topo = 0;
    pilha->elementos = (int*)malloc(sizeof(int) * tamanho);
}

bool Empty(Pilha *pilha){
    return pilha->topo == 0;
}

void Push(Pilha *pilha, int numero){
    pilha->elementos[pilha->topo] = numero;
    pilha->topo++;
}

void Pop(Pilha *pilha){
    if(pilha->topo == 0){
        return;
    }
    pilha->topo--;
}

int Topo(Pilha *pilha){
    return pilha->elementos[pilha->topo - 1];
}

int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    Pilha pilha;
    Reset(&pilha,numsSize * 2);

    int *vetor;
    vetor = malloc(sizeof(int) * numsSize);

    for(int i = 0;i<numsSize;i++){
        vetor[i] = -1;
    }

    for(int i = 0;i<numsSize * 2;i++){
        while(!Empty(&pilha) && nums[i%numsSize] > nums[Topo(&pilha)]){
            vetor[Topo(&pilha)] = nums[i%numsSize];
            Pop(&pilha);
        }
        Push(&pilha,i%numsSize);
    }

    free(pilha.elementos);
    return vetor;
}

int main(){




    return 0;
}