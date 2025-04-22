#include <stdlib.h>
#include <stdio.h>

#include "parque.h"


// Liberta todo o espaco ocupado pela estrutura dinamica

void libertaTudo(pCliente p){
    pCliente auxC;
    pAcesso auxA;

    while(p != NULL){
        while(p->lista != NULL){
            auxA = p->lista;
            p->lista = p->lista->prox;
            free(auxA);
        }
        auxC = p;
        p = p->prox;
        free(auxC);
    }
}
// Cria e devolve uma estrutura dinamica exemplo para teste das funções deste exercicio
// A informação criada é igual ao exemplo ilustrado na ficha pratica 9

pCliente criaExemploED(){
    int totC = 3, i, j, k=-1;
    cliente a[] = {{13, 2, NULL, NULL},{17,1,NULL,NULL},{22,3,NULL,NULL}};
    acesso b[] = {{{10,20},{11,52},NULL}, {{14,30},{17,2},NULL}, {{10,50},{-1,-1},NULL},
                  {{9,11},{9,12},NULL},{{10,5},{12,0},NULL},{{14,33},{-1,-1},NULL}};

    pCliente lista = NULL, novoC;
    pAcesso novoA;

    for(i=0; i<totC; i++){
        k+=a[i].contador;
    }
    for(i=totC-1; i>=0; i--){
        novoC = malloc(sizeof(cliente));
        if(novoC == NULL){
            libertaTudo(lista);
            return NULL;
        }
        *novoC = a[i];
        novoC->prox = lista;
        lista = novoC;
        for(j=0; j<novoC->contador; j++){
            novoA = malloc(sizeof(acesso));
            if(novoA == NULL){
                libertaTudo(lista);
                return NULL;
            }
            *novoA = b[k--];
            novoA->prox = novoC->lista;
            novoC->lista = novoA;
        }
    }
    return lista;
}


// Recebe ponteiro para o inicio da estrutura dinamica
// Escreve toda a informação armazenada (clientes e respetivos acessos)
void mostraTudo(pCliente p){
    pAcesso auxA;

    while(p != NULL){
        printf("\nUtilizador com id %d efetuou %d acessos\n", p->id, p->contador);
        auxA = p->lista;
        while(auxA != NULL){
            printf("Entrou as %2.2d:%2.2d. ", auxA->in.h, auxA->in.m);
            if(auxA->out.h == -1)
                printf("Ainda nao saiu do parque\n");
            else
                printf("Saiu as %2.2d:%2.2d\n", auxA->out.h, auxA->out.m);
            auxA = auxA->prox;
        }
        p = p->prox;
    }
}


// Recebe ponteiro para o inicio da estrutura dinamica
// Devolve numero de clientes que se encontram no parque (têm uma utilização em aberto)
int dentroParque(pCliente p) {
    int count = 0;
    pAcesso auxA;

    while (p != NULL) {
        auxA = p->lista;
        while (auxA != NULL) {
            // Verifica se o cliente ainda está no parque
            if (auxA->out.h == -1) {
                count++;
            }
            auxA = auxA->prox;
        }
        p = p->prox;
    }

    return count;
}


// Recebe ponteiro para o inicio da estrutura dinamica e hora
// Devolve numero de clientes que estavam dentro do parque na hora x
int dentroParqueHora(pCliente p, hora x) {
    int count = 0;
    pAcesso auxA;

    while (p != NULL) {
        int clienteDentro = 0; // Assume que o cliente não está dentro

        auxA = p->lista;
        while (auxA != NULL) {
            // Verifica se o cliente estava dentro do parque na hora x
            int entrouAntes = (auxA->in.h < x.h) || (auxA->in.h == x.h && auxA->in.m <= x.m);
            int saiuDepois = (auxA->out.h == -1) || (auxA->out.h > x.h) || (auxA->out.h == x.h && auxA->out.m >= x.m);

            if (entrouAntes && saiuDepois) {
                clienteDentro = 1; // Marca que o cliente estava dentro
            }
            auxA = auxA->prox;
        }

        if (clienteDentro) {
            count++;
        }

        p = p->prox;
    }

    return count;
}
// Recebe ponteiro para o inicio da estrutura dinamica e endereço de variável inteira
// Devolve id do cliente que passou mais minutos no parque e coloca esse número de minutos na variável referenciada pelo segundo parametro
int maisMinutos(pCliente p, int *m){
    *m = 0;
    return -1;
}

pCliente eliminaCliente(pCliente p, int id){
    return p;
}

//a)
// Recebe ponteiro para o inicio da estrutura dinamica, id de um cliente e hora de ativação da cancela
// Devolve ponteiro para inicio da estrutura dinamica depois de atualizar o registo do cliente com este novo acesso
pCliente acessoParque(pCliente p, int id, hora x){





    return p;
}

