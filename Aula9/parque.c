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
int dentroParque(pCliente p){
    int contador=0;
    pAcesso auxA;
    while(p != NULL){
        auxA = p->lista;
        while(auxA != NULL){
            if(auxA->out.h == -1)
                contador++;
            auxA = auxA->prox;
        }
        p = p->prox;
    }
    return contador;
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
    pAcesso auxA;
    int idminutos;
    *m=0;
    while(p != NULL){
        auxA = p->lista;
        while(auxA != NULL){
           int horas= (auxA->out.h) - (auxA->in.h) ;
           int minutos = (auxA->out.m)- (auxA->in.m);
           int totalminutos= (horas*60)+minutos;
           if( totalminutos > *m){
               *m=totalminutos;
                idminutos = p->id;
           }
            auxA = auxA->prox;
        }
        p = p->prox;
    }
    return idminutos;
}

pCliente eliminaCliente(pCliente p, int id){
    pCliente  atual=p;
    pCliente anterior = NULL;
    pAcesso auxA;


    while (atual!=NULL && atual->id!=id){
        anterior=atual;
        atual=atual->prox;
    }
    if(atual==NULL){
        return p;
    }
    while(atual->lista!=NULL){
     auxA= atual->lista;
     atual->lista = atual->lista->prox;
     free(auxA);
    }
    if(anterior==NULL){
        p=atual->prox;
    }else{
        anterior->prox=atual->prox;
    }
    free(atual);
    return p;
}


// Recebe: ponteiro para início da lista, id do cliente e hora da ativação da cancela
// Objetivo: Regista um acesso (entrada ou saída) de um cliente ao parque
pCliente acessoParque(pCliente p, int id, hora x) {
    // 1. Ponteiro para percorrer a lista de clientes
    pCliente atual = p;

    // 2. Percorre a lista até encontrar o cliente com o id indicado
    while (atual != NULL && atual->id != id) {
        atual = atual->prox;
    }

    // 3. Se não encontrou o cliente, devolve a lista sem alterações
    if (atual == NULL) {
        // Criar novo cliente
        pCliente novoCliente = malloc(sizeof(cliente));
        if (novoCliente == NULL) return p; // Falha de memória

        novoCliente->id = id;
        novoCliente->contador = 0;
        novoCliente->lista = NULL;
        novoCliente->prox = p; // Insere à cabeça
        p = novoCliente;
        atual = novoCliente;
        //return p;
    }

    // 4. Ponteiro para o acesso mais recente deste cliente
    pAcesso acessoAtual = atual->lista;

    // 5. Se existe um acesso em aberto (última saída == -1), então esta ativação é uma saída
    if (acessoAtual != NULL && acessoAtual->out.h == -1) {
        // Atualiza a hora de saída desse acesso
        acessoAtual->out = x;
    } else {
        // 6. Caso contrário, esta ativação é uma nova entrada
        // Aloca memória para novo acesso
        pAcesso novoAcesso = malloc(sizeof(acesso));
        if (novoAcesso == NULL) return p; // Falha de memória → devolve lista como está

        // Preenche a hora de entrada
        novoAcesso->in = x;
        // Indica que ainda não saiu (valores sentinela)
        novoAcesso->out.h = -1;
        novoAcesso->out.m = -1;
        // Liga o novo acesso à lista deste cliente
        novoAcesso->prox = atual->lista;
        atual->lista = novoAcesso;
        // Atualiza o número de acessos deste cliente
        atual->contador++;
    }

    // 7. Devolve o ponteiro para início da lista (não muda)
    return p;
}
