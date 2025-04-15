#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa no, *pno;

struct pessoa{
    char nome[100];
    int id;
    float peso, altura, imc;
    pno prox;
};


// Função auxiliar para obter dados do utilizador e prencher um novo nó a inserir na lista
// Recebe endereço do nó a preencher
int getDados(pno p, pno lista) {
    pno aux = lista;
    int id;

    printf("Nome: ");
    scanf(" %[^\n]", p->nome);

    do {
        printf("ID: ");
        scanf("%d", &id);
        aux = lista;
        while(aux != NULL) {
            if(aux->id == id) {
                printf("ID ja existe! Insira outro ID.\n");
                break;
            }
            aux = aux->prox;
        }
    } while(aux != NULL);

    p->id = id;

    do {
        printf("Peso (Kg) e Altura (Metros): ");
        scanf("%f %f", &(p->peso), &(p->altura));
        if (p->peso <= 0) {
            printf("Erro: O peso tem de ser superior a 0!\n");
        }
        if (p->altura <= 0) {
            printf("Erro: A altura tem de ser superior a 0!\n");
        }
    } while (p->peso <= 0 || p->altura <= 0);

    p->imc = p->peso / (p->altura * p->altura);
    p->prox = NULL;

    return 1;
}

// Função para adicionar um novo nó à lista
// Recebe ponteiro de lista e devolve ponteiro de lista depois da inserção
// Esta função não está de acordo com o pedido no enunciado (2b) e tem que ser corrigida em 2 pontos:
// 1. Insere o novo nó no início da liste e não no final
// 2. Não valida se o ID é único. Esta validação poderá ser feita diretamente na função GetDados(), mas,
// para isso, terá que receber o ponteiro de lista como parâmetro adicional

//B  INSERÇÃO NO FINAL deve garantir que o id indicado é único e não se encontra atribuído a outra pessoa que
//já esteja na lista. A nova pessoa deve ser adicionada ao final da lista ligada.

pno addListafinal(pno lista) {
    pno novo, aux;
    novo = malloc(sizeof(no));
    if(novo == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return lista;
    }
    getDados(novo, lista);

    if(lista == NULL) {
        lista = novo;
    } else {
        // Encontrar o último nó
        aux = lista;
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        // Inserir após o último nó
        aux->prox = novo;
    }

    return lista;
}
/*
pno addLista(pno lista){
    pno novo;
// INCERSÃO NO INICIO
    novo = malloc(sizeof(no));
    if(novo == NULL)
        return lista;
    getDados(novo);
    novo->prox = lista;
    return novo;
}*/


// Função que mostra o conteúdo da lista
// Recebe ponteiro de lista como parâmetro
void mostraLista(pno lista){
    while (lista != NULL){
        printf("%d - %s\n", lista->id, lista->nome);
        printf("P: %.1f\tA: %.1f\tIMC: %.2f\n\n", lista->peso, lista->altura, lista->imc);
        lista = lista->prox;
    }
}

// Função para atualizar o peso de uma das pessoas
// Recebe ponteiro de lista, id da pessoa a atualizar e novo peso
// Deve tambem ser atualizado o imc
void atualizaPeso(pno lista, int id, float novoPeso){
    while (lista != NULL){
        if(lista->id==id){
            lista->peso = novoPeso;
        }
        lista = lista->prox;
    }
}


// Função para eliminar uma pessoa da lista
// Recebe ponteiro de lista e id da pessoa a eliminar
// Devolve ponteiro de lista depois da eliminação
pno elimina(pno lista, int id){
    pno atual, anterior=NULL;
    atual=lista;
    while(atual != NULL && atual->id !=id){
        anterior =atual;
        atual = atual->prox;
    }
    if(atual ==NULL){// 1
        return lista;
    }
    if(anterior==NULL)
        lista = atual->prox;
    else
        anterior->prox = atual->prox;
    free(atual);
    return lista;
}

//g

pno eliminalimite(pno lista, float imc){ //g
    pno atual = lista;
    pno anterior = NULL;
    pno temp;

    while(atual != NULL){ // percorre a lista
        if (atual->imc < imc) {
            temp = atual; // Guarda o nó a ser eliminado
            if (anterior == NULL) { // Se for o primeiro nó da lista
                lista = atual->prox;  // Atualiza o início da lista
                atual = lista;
            } else {   // Se nao for o primeiro nó da lista
                anterior->prox = atual->prox;
                atual = atual->prox;
            }
            free(temp);
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
    return lista;
}
pno eliminaUltimosK(pno lista, int k) {
    if (lista == NULL || k <= 0) return lista;

    // Primeiro, contar o número total de nós
    int total = 0;
    pno temp = lista;
    while (temp != NULL) {
        total++;
        temp = temp->prox;
    }

    // Se k for maior que o total, não fazer nada
    if (k >= total) return lista;

    // Encontrar o nó antes do ponto de corte
    int posicaoCorte = total - k;
    temp = lista;
    for (int i = 1; i < posicaoCorte; i++) {
        temp = temp->prox;
    }

    // Libertar os últimos k nós
    pno atual = temp->prox;
    temp->prox = NULL;

    while (atual != NULL) {
        pno proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    return lista;
}

int main(){
    pno lista = NULL; // a)
    int i;

    for(i=0; i<3; i++)
        lista = addListafinal(lista);
    mostraLista(lista);
  //  printf("\n Pos Atualizar peso do id 123 \n");
   // atualizaPeso(lista, 123, 78.5);
    //mostraLista(lista);
   // lista = elimina(lista, 456);
   // printf("\n Lista apos eliminar id 456 \n");
   // mostraLista(lista);
  //  lista = eliminalimite(lista, 30);
   // printf("\n Lista apos eliminar imcs menores que 30 \n");
   // mostraLista(lista);
    // Falta libertar a lista antes de terminar o programa
// treinar inserção ordenada
printf("\n eliminaUltimosK\n");
    lista = eliminaUltimosK(lista, 2); // Para eliminar os últimos 2 nós
    mostraLista(lista);
    free(lista);
    return 0;
}
