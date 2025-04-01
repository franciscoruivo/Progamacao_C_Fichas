
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "agenda.h"

// Escreve os dados de todos os contactos na agenda
// Recebe endereço do vetor e numero de contactos armazenados
void listaC(pct p, int total){
    int i;

    printf("Existem %d contactos na agenda\n", total);
    for(i=0; i<total; i++)
        printf("%s\t%d\n", p[i].nome, p[i].num);
}

// Adiciona um novo contacto ao vetor dinamico. Os dados são indicados pelo utilizador
// Recebe endereço do vetor e endereço de variavel inteira contento o numero de contactos
// Devolve endereço de vetor depois de efetuada a atualizacao
pct addC(pct p, int *total){
    char nome[200];
    int num;
    pct aux;
    printf("Nome do novo contacto: ");scanf(" %[^\n]", nome);
    for (int i = 0; i < *total; i++) {
        if (strcmp(p[i].nome, nome) == 0) {
            printf("\nErro: Contato ja existe!\n");
            return p;
        }
    }
    printf("Numero do novo contacto: ");scanf(" %d", &num);
    for (int i = 0; i < *total; i++) {
        if (p[i].num==num) {
            printf("\nErro: ja existe esse numero!\n");
            return p;
        }
    }

    aux=realloc(p,sizeof(ct)*(*total+1));
    if(aux == NULL) return p;
    p=aux;
    p[*total].num =num;
    strcpy(p[*total].nome,nome);
    (*total)++;

    return p;
}

// Recebe endereço do vetor, numero de contactos armazenados e nome do contacto a pesquisar
// Devolve o numero de telemovel de um contacto
int getTel(pct p, int total, char *nome){
    for(int i = 0; i < total; i++){
        if(strcmp(p[i].nome, nome) == 0){
            return p[i].num;
        }
    }
    return -1;
    }


// Atualiza numero de telemovel de um contacto
// Recebe endereço do vetor, numero de contactos armazenados, nome do contacto a atualizar e novo numero
// Devolve 1 se a atualizacao for efetuada, ou 0, caso contrario
int atualizaTel(pct p, int total, char *nome, int novoT){
    for(int i = 0; i < total; i++){
        if(strcmp(p[i].nome, nome) == 0){
            p[i].num=novoT;
        }
    }
    return 0;
}

// Recebe endereço do vetor e numero de contactos armazenados 
// Devolve o numero de operadores moveis diferentes que existem no array
int getOperador(pct p, int total) {
    int lista[total]; // Lista para armazenar prefixos
    int contador = 0;

    for (int i = 0; i < total; i++) {
        int prefixo = p[i].num / 10000000; // Obtém os primeiros 2 dígitos (96x)
        int existe = 0;
        for (int j = 0; j < contador; j++) {
            if (lista[j] == prefixo) {
                existe = 1;
                break;
            }
        }
        if (!existe) {
            lista[contador] = prefixo;
            contador++;
        }
    }
    return contador;
}


// Eliminar um novo contacto do vetor dinamico
// Recebe endereço do vetor, endereço de variavel inteira contento o numero de contactos e nome do contacto a eliminar
// Devolve endereço de vetor depois de efetuada a atualizacao
pct eliminaC(pct p, int *total, char *nome){
    pct novo;
    int i,j;
    for(int i = 0; i < total; i++){
        if(strcmp(p[i].nome, nome) == 0){
            // validar antes que o contacto existe;
            novo= malloc(sizeof (ct)*(*total-1));
            if(novo==NULL)return p;
            for(i = 0,j = 0; i < *total; i++){
                if(strcmp(p[i].nome, nome) != 0){
                    novo[j++]=p[i];
                }
            }
            free(p);
            (*total)--;

        }
    }

    return novo;
}