#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct projeto proj, *pproj;
typedef struct pessoa gestor, *pgest;

struct pessoa{
    int id;
    char nome[100];
    int total;
};

struct data{int dia, mes, ano;};

struct projeto{
    int id;
    struct data inicio;
    pgest p;
    pproj prox;
};

/* ========================================================= */
/* Funções auxiliares já dadas aos alunos                    */
/* ========================================================= */

void mostraGestores(pgest v, int n){
    int i;

    printf("\nGESTORES:\n");
    for(i = 0; i < n; i++){
        printf("ID: %d | Nome: %-10s | Total: %d\n",
               v[i].id, v[i].nome, v[i].total);
    }
}

void mostraProjetos(pproj lista){
    pproj aux = lista;

    printf("\nPROJETOS:\n");
    while(aux != NULL){
        printf("Projeto %d | Inicio: %02d/%02d/%04d | Gestor: %s ID %d\n",
               aux->id,
               aux->inicio.dia,
               aux->inicio.mes,
               aux->inicio.ano,
               aux->p->nome,
               aux->p->id);

        aux = aux->prox;
    }
}

pproj novoProjeto(int id, int d, int m, int a, pgest g){
    pproj novo = malloc(sizeof(proj));

    if(novo == NULL)
        return NULL;

    novo->id = id;
    novo->inicio.dia = d;
    novo->inicio.mes = m;
    novo->inicio.ano = a;
    novo->p = g;
    novo->prox = NULL;

    return novo;
}

pproj acrescentaInicio(pproj lista, int id, int d, int m, int a, pgest g){
    pproj novo = novoProjeto(id, d, m, a, g);

    if(novo == NULL)
        return lista;

    novo->prox = lista;
    return novo;
}

void libertaLista(pproj lista){
    pproj aux;

    while(lista != NULL){
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

/* ========================================================= */
/* QUESTÃO 2 - a preencher pelos alunos                      */
/* ========================================================= */

void datasProjetosGestor(int idGestor, pproj lista, pgest vetor, int dim){
    /* TODO */
}

/* ========================================================= */
/* QUESTÃO 3 - a preencher pelos alunos                      */
/* ========================================================= */

pgest eliminarGestor(int idElim, pproj lista, pgest vetor, int *dim){
    /* TODO */

    return vetor;
}

/* ========================================================= */
/* Programa principal de teste                               */
/* ========================================================= */

int main(){
    int n = 4;
    pgest gestores;
    pproj lista = NULL;

    gestores = malloc(n * sizeof(gestor));

    if(gestores == NULL){
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    gestores[0].id = 1;
    strcpy(gestores[0].nome, "Diana Silva");
    gestores[0].total = 2;

    gestores[1].id = 5;
    strcpy(gestores[1].nome, "Vanessa Lopes");
    gestores[1].total = 0;

    gestores[2].id = 6;
    strcpy(gestores[2].nome, "Carla Pires");
    gestores[2].total = 2;

    gestores[3].id = 9;
    strcpy(gestores[3].nome, "Artur Oliveira");
    gestores[3].total = 1;

    /*
        Projetos:
        - Gestor 1 e 6 têm 2 projetos: um antigo e um recente
        - Gestor 9  tem apenas 1 projeto
        - Gestor 5  não tem projetos
    */

    lista = acrescentaInicio(lista, 6, 4,  6, 2024, &gestores[3]); /* Artur Oliveira */
    lista = acrescentaInicio(lista, 3, 1,  1, 2025, &gestores[2]); /* Carla Pires */
    lista = acrescentaInicio(lista, 4, 12,  1, 2024, &gestores[0]); /* Diana Silva */
    lista = acrescentaInicio(lista, 7,  3, 6, 2023, &gestores[2]); /* Carla Pires */
    lista = acrescentaInicio(lista, 12, 12,  2, 2023, &gestores[0]); /* Diana Silva */

    printf("\n--- ESTADO INICIAL ---\n");
    mostraGestores(gestores, n);
    mostraProjetos(lista);

    printf("\n--- TESTES QUESTAO 2 ---\n");

    printf("\nGestor 1:\n");
    datasProjetosGestor(1, lista, gestores, n);
    /* Esperado:
       Mais antigo: 12/02/2023
       Mais recente: 12/01/2024
    */

    printf("\nGestor 6:\n");
    datasProjetosGestor(6, lista, gestores, n);
    /* Esperado:
       Mais antigo: 03/06/2023
       Mais recente: 01/01/2025
    */

    printf("\nGestor 9:\n");
    datasProjetosGestor(9, lista, gestores, n);
    /* Esperado:
       Não aplicável
    */

    printf("\nGestor 5:\n");
    datasProjetosGestor(5, lista, gestores, n);
    /* Esperado:
       Não aplicável
    */

    printf("\nGestor 99:\n");
    datasProjetosGestor(99, lista, gestores, n);
    /* Esperado:
       Não aplicável
    */

    printf("\n--- TESTE QUESTAO 3 ---\n");

    printf("\nEliminar gestor 6 Carla Pires.\n");
    gestores = eliminarGestor(6, lista, gestores, &n);

    printf("\n--- ESTADO APOS ELIMINACAO ---\n");
    mostraGestores(gestores, n);
    mostraProjetos(lista);

    /*
        Esperado, usando como critério transferir para o gestor com menos projetos:

        Antes:
        Diana Silva: 2
        Vanessa Lopes: 0
        Carla Pires: 2
        Artur Oliveira: 1

        Ao eliminar Carla Pires, os seus 2 projetos devem passar para um dos gestores
        com menos projetos, Vanessa Lopes (que tem 0).
        Pode fazer um outro exemplo novo em que sejam 2 os Gestores que têm menos projetos,
        para usar o critério de desempate (for )menor ID).

        Depois:
        Diana Silva: 2
        Vanessa Lopes: 2
        Artur Oliveira: 1

        E os projetos 3 e 7 devem apontar para Vanessa Lopes.
    */

    libertaLista(lista);
    free(gestores);

    return 0;
}
