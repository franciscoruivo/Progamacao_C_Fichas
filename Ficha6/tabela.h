
#ifndef P2324_AULA5_TABELA_H
#define P2324_AULA5_TABELA_H

#include "retangulo.h"
#define MAX 20 // para defenir o max de retangulos na tabela EXTRA
void printV(ret a[], int total);

int addRet(ret a[], int *total);

void duplicaAltLarg(ret a[], int total);

int quadrante1(ret a[], int total);

void eliminaMenor(ret a[], int *total);
void inverte(ret a[], int *total);
void eliminaVarios(ret a[], int *total, int lim);
void elimina(ret a[], int *total, int indice);//i)
void imprimequadrados(ret a[], int total);//d)
#endif //P2324_AULA5_TABELA_H
