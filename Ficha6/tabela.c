#include <stdio.h>
#include "tabela.h"

void printV(ret a[], int total){
    int i;

    printf("\n Existem %d retangulos na tabela\n", total);
    for(i=0; i<total; i++) {
        printf("R. %d\n", i);
        printRet(a[i]);
    }
}

int addRet(ret a[], int *total){
    if (*total < 10) {
        printf("Tem %d retangulos",(*total));
        ret novoRet;
        printf("\n Insira os dados do retangulo %d:\n",*total+1);
        initRet(&novoRet);
        a[*total]=novoRet;
        (*total)++;
        printf("\n A adicao foi bem sucedida \n");
    }else{
        printf("Limite de %d retangulos \n",(*total));
    }
    return 0;
}
void printVQuadrados(ret a[], int total) {
    int i;

    for (i = 0; i < total; i++) {
        if (a[i].alt == a[i].larg) {
            printf("R. %d\n", i);
            printRet(a[i]);
        }
    }
}
void duplicaAltLarg(ret a[], int total){

    for(int i=0; i<total; i++) {
        int area=areaR(a[i]);
        if (area%2==0) {
            printf("\n Area de retangulo %d e par , valor : %d",i+1,area);
            a[i].alt=a[i].alt*2;
            a[i].larg=a[i].larg*2;
        }
    }
}




int quadrante1(ret a[], int total){
   int contador=0;
    for (int i=0; i<total; i++) {
        if (quadrante(a[i].canto)==1) {
            if (a->canto.x > 0 && a->canto.y > 0)
            contador++;
        }
    }
    return contador;
}

void eliminaMenor(ret a[], int *total){
    int aux=0;;
    int area=0;
    int menor=areaR(a[0]);
    for (int i=0;i<*total;i++) {
         area=areaR(a[i]);
        if (area<menor) {
            menor=area;
            aux=i;
        }
    }

    for (int i = aux; i < *total - 1; i++) {
        a[i] = a[i + 1];
    }

    (*total)--; // Atualiza o total de elementos
}
//H)
void inverte(ret a[], int *total) {
    ret aux;
    for (int i=0 ; i<*total/2; i++) {
        aux=a[i];
        a[i]=a[(*total)-1-i];
        a[(*total)-1-i]=aux;
    }
}
void elimina(ret a[], int *total,int indice) {
    for (int i=indice; i<*total; i++) {
        a[i]=a[i+1];
    }
    (*total)--;
}

//i)
void eliminaVarios(ret a[], int *total, int lim){
    for (int i = (*total) - 1; i >= 0; i--) {
        if (areaR(a[i]) < lim) {
            elimina(a, total, i);
        }
    }
}


//d) a esquecida
void imprimequadrados(ret a[], int total) {
    for (int i=0; i<total; i++) {
        if (a[i].alt == a[i].larg) {
            printf("\n R. %d\n", i);
            printRet(a[i]);
        }
    }
}