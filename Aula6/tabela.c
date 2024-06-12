#include <stdio.h>
#include "tabela.h"

void printV(ret a[], int total){
    int i;

    printf("Existem %d retangulos na tabela\n", total);
    for(i=0; i<total; i++) {
        printf("R. %d\n", i);
        printRet(a[i]);
    }
}
//Escreva uma função em C que adicione um novo retângulo à tabela. Os dados necessários são
//indicados pelo utilizador. A função recebe o endereço inicial da tabela e o endereço de uma
//variável inteira contendo o número de retângulos aí armazenados. A função deve verificar se
//existe espaço na tabela para adicionar o novo retângulo. Caso a adição seja efetuada, a função
//deve atualizar a variável inteira que contém o número de retângulos armazenados. A função
//devolve 1 se a adição for sem sucedida, ou 0, caso contrário.
int addRet(ret a[], int *total){
    if(*total == NULL)
        return 1;
    else

}

void duplicaAltLarg(ret a[], int total){

}


int quadrante1(ret a[], int total){
    return 0;
}

void eliminaMenor(ret a[], int *total){

}

void eliminaVarios(ret a[], int *total, int lim){

}