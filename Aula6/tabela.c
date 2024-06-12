#include <stdio.h>
#include "tabela.h"
#include "ponto.h"

void printV(ret a[], int total){
    int i;

    printf("\n Existem %d retangulos na tabela", total);
    for(i=0; i<total; i++) {
        printf("\n R. %d\n", i+1);
        printRet(a[i]);
    }
}


/*Escreva uma função em C que adicione um novo retângulo à tabela. Os dados necessários são
indicados pelo utilizador. A função recebe o endereço inicial da tabela e o endereço de uma
        variável inteira contendo o número de retângulos aí armazenados. A função deve verificar se
        existe espaço na tabela para adicionar o novo retângulo. Caso a adição seja efetuada, a função
deve atualizar a variável inteira que contém o número de retângulos armazenados. A função
devolve 1 se a adição for sem sucedida, ou 0, caso contrário*/
int addRet(ret a[], int *total){
    if(*total<10){
        printf("Tem %d retangulos",(*total));
        ret novoRet;
        printf("\n Insira os dados do novo retangulo:\n");
        printf("Coordenada x: ");
        scanf("%d", &novoRet.canto.x);
        printf("Coordenada y: ");
        scanf("%d", &novoRet.canto.y);
        printf("Largura: ");
        scanf("%d", &novoRet.larg);
        printf("Altura: ");
        scanf("%d", &novoRet.alt);
        a[*total]=novoRet;
        (*total)++;
        printf("\n A adicao foi bem sucedida \n");
    }else{
        printf("Limite de %d retangulos \n",(*total));
    }
    return 0;
}
/*Escreva uma função em C que duplique a altura e largura de todos os retângulos com área par
que estão armazenados na tabela. A função recebe o endereço inicial da tabela e o número de
retângulos aí armazenados.*/
// Percorrer todos os quadrados , se a area for para ,
void duplicaAltLarg(ret a[], int total){
    for(int i=0;i<total;i++){
        int area=areaR(a[i]);
        if(area % 2 == 0){
            printf("\n Area de retangulo %d e par , valor : %d",i+1,area);
            a[i].alt*=2;
            a[i].larg*=2;
        } else{
            printf("\n Area de retangulo %d e impar, valor : %d ",i+1,area);
        }
    }
}

//Escreva uma função em C que verifique quantos retângulos armazenados na tabela têm o seu
//canto inferior esquerdo no primeiro quadrante do plano cartesiano. A função recebe o endereço
//inicial da tabela e o número de retângulos aí armazenados como parâmetros e devolve o valor
//contabilizado.
int quadrante1(ret a[], int total){
    int contador=0;
    for(int i=0;i<total;i++){
        int rquadrante=quadrante(a[i].canto);
        if(rquadrante==1){
            contador++;
        }
    }
    printf(" \n Existem %d com canto inferior esquerdo no primeiro quadrante do plano cartesiano ", contador);
    return 0;
}
/*Escreva uma função em C que elimine da tabela o retângulo com menor área que aí estiver
        armazenado. A função recebe o endereço inicial da tabela e o endereço de uma variável inteira
        contendo o número de retângulos aí armazenados. Caso a eliminação seja bem sucedida, a
função deve atualizar a variável inteira que contém o número de retângulos armazenados.*/
void eliminaMenor(ret a[], int *total) {
    if (*total == 0) {
        printf("Não há retângulos na tabela.\n");
        return;
    }

    int menorarea = areaR(a[0]);
    int id = 0;

    // Encontrar o índice do retângulo com a menor área
    for (int i = 0; i < *total; i++) {
        int area = areaR(a[i]);
        if (area < menorarea) {
            menorarea = area;
            id = i;
        }
    }
    printf("Menor area e de %d derivado do retangulo %d\n", menorarea, id + 1);
for (int i = id; i < *total - 1; i++) {
a[i] = a[i + 1];
}
// Decrementar o total de retângulos
(*total)--;
    printf("\n Retangulo com menor area removido com sucesso!");
}
void inverterordem(ret a[], int *total){
    int start = 0;
    int end = *total - 1;
    if (*total == 0) {
        printf("Não há retângulos na tabela.\n");
        return;
    }
    while (start < end) {
        ret temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}
/*Escreva uma função em C que elimine da tabela todos os retângulos com área inferior a um
        determinado limite. A função recebe o endereço inicial da tabela, o endereço de uma variável
inteira contendo o número de retângulos aí armazenados e o valor limite a considerar. Esta
        função deve atualizar a variável inteira que contém o número de retângulos armazenados.*/
void eliminaVarios(ret a[], int *total, int lim){
    for(int i=0;i<*total;i++){
        if(areaR(a[i])<lim){
            for (int j=i;j< *total - 1; j++) {
                a[j] = a[j + 1];
            }
            (*total)--;
        }
    }

}