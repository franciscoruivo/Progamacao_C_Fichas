#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*a) Considerando que cada paciente é completamente identificado pelo seu nome, defina a(s)
estrutura(s) que considerar necessária(s) para a resolução do problema.*/
typedef struct paciente no, *pno;

struct paciente{
    char nome[100];
    int urgencia; // 1 para grávidas, 2 para idosos e crianças, 3 para restantes
    pno prox;
};


// Função auxiliar para obter dados do utilizador e prencher um novo nó a inserir na lista
// Recebe endereço do nó a preencher
int getDados(pno p, pno lista) {
    printf("Nome: ");
    scanf(" %[^\n]", p->nome);
    printf("Nivel de urgencia (1: gravidas, 2: idosos/criancas, 3: restantes): ");
    scanf("%d", &p->urgencia);
    p->prox = NULL;
    return 1;
}
void mostraLista(pno lista){
    printf("\n Lista de Espera :\n ");
    while (lista != NULL){
        printf("Nome do paciente:  %s\n", lista->nome);
        lista = lista->prox;
    }
}
pno addListafinal(pno lista) { //b e ex5
    pno novo, aux, anterior = NULL;
    novo = malloc(sizeof(no));
    if (novo == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return lista;
    }
    getDados(novo, lista);

    if (lista == NULL) {
        lista = novo;
    } else {
        aux = lista;
        while (aux != NULL && aux->urgencia <= novo->urgencia) {
            anterior = aux;
            aux = aux->prox;
        }
        if (anterior == NULL) {
            novo->prox = lista;
            lista = novo;
        } else {
            anterior->prox = novo;
            novo->prox = aux;
        }
    }

    return lista;
}

pno libertarpaciente(pno lista) {
    if (lista == NULL) {
        printf("\n A lista esta vazia.\n");
        return lista;
    }
    pno temp = lista; // está a guardar o ponteiro para o primeiro nó da lista

    printf("\n O paciente: %s foi atendido com sucesso\n", temp->nome);

    lista = lista->prox;

    free(temp);

    return lista; //  lista atualizada
}

/*[Início] -> [Paciente1] -> [Paciente2] -> [Paciente3] -> NULL
Antes da Remoção:
NULL <- [Início] -> [Paciente1] -> [Paciente2] -> [Paciente3] -> NULL

Removendo Paciente2:
[Início] -> [Paciente1] ------> [Paciente3] -> NULL
- Se 'atual' for o primeiro nó (ou seja, 'anterior' é NULL), atualiza o início da lista para o próximo nó.
 *- Caso contrário, ajusta o ponteiro 'prox' do nó 'anterior' para saltar o nó 'atual', efetivamente removendo-o da lista.

*/
pno desistencia_paciente(pno lista) {
    char nick[100];
    pno atual = lista, anterior = NULL;
    printf("\nIndique o nome do paciente que pretende desistir: ");
    scanf(" %[^\n]", nick);

    while (atual != NULL) {
        if (strcmp(nick, atual->nome) == 0) {
            if (anterior == NULL) {
                // Remover o primeiro nó
                lista = atual->prox;
            } else {
                // Remover um nó do meio ou do fim
                anterior->prox = atual->prox;
            }
            printf("\nHouve uma desistencia por parte do paciente: %s\n", nick);
            free(atual);
            return lista; // Retorna a lista atualizada após a remoção
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("Paciente nao encontrado.\n");
    return lista; // Retorna a lista inalterada se o nome não for encontrado
}


int main(){
    pno lista = NULL; // a)
    for (int i=0; i < 3; i++) {
        lista = addListafinal(lista);
    }
    mostraLista(lista);
    lista=libertarpaciente(lista);
    mostraLista(lista);
    // Desistência de um paciente
    //lista = desistencia_paciente(lista);

    while (lista != NULL) {
        pno temp = lista;
        lista = lista->prox;
        free(temp);
    }
    return 0;
}
