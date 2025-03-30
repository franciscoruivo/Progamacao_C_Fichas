#include <stdio.h>
#include <string.h>
//ex 5
typedef struct info dados;
struct info{
    int v[5];
    int *p;
    float media;
};
/*
Esta função recebe uma tabela tab de estruturas do tipo dados com tam elementos. Cada uma das
estruturas armazenadas na tabela tem o campo v completamente preenchido com 5 valores inteiros.
A função deve efetuar as seguintes alterações em cada uma das estruturas da tabela:
- Calcular a média dos 5 valores armazenados no campo v e colocar este valor no campo media;
- Colocar o ponteiro p a apontar para o elemento de v que tenha o maior valor. Pode assumir que a
tabela v de cada estrutura armazena valores únicos, i.e., não existem repetições no vetor.
A função devolve o número de médias contabilizadas que se encontrem no intervalo [limA, limB]*/
int processa(dados *tab, int tam, float limA, float limB) {
    int contador = 0;
    for (int i = 0; i < tam; i++) {
        int soma = 0;
        for (int j = 0; j < 5; j++) {
            soma += tab[i].v[j];
        }

        tab[i].media = soma / 5.0;

        int *maior_valor = &tab[i].v[0];
        for (int j = 1; j < 5; j++) {
            if (*maior_valor < tab[i].v[j]) {
                maior_valor = &tab[i].v[j];
            }
        }
        tab[i].p = maior_valor;

        if (tab[i].media >= limA && tab[i].media <= limB) {
            contador++;
        }
    }
    return contador;
}






//*a é um ponteiro para a[0]
void f1(int *a, int tam) {
    int i, *p = a; // Ponteiro apontando para o início do vetor
    for (i = 0; i < tam; i++) {
            if (*p == a[tam - 1]) // Se o elemento for igual ao último
            *p = 0;           // Substitui por 0
        p++; // incrementa o ponteiro
    }
}
/*
se 1 == 1 | 0
se 2 == 1 | 2
se 1 == 1 | 0
se 2 == 1 | 2
se 1 == 1 | 0
Opção A)

void printtab(int *a, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}*/

void f2(int nLin, int nCol, int a[][nCol], int *b, int tam) {
    int *p = a[1]; // ponteiro apontado para a posição a[1]
    printf("%d\n", *a); // como aponta para a[0] dá conflito, teria de ser mat[0][0] tendo em conta que é um array bidimensional (int a[][nCol]),
    printf("%d\n", b[1]); // 2
    printf("%d\n", a[1]); // acrescentar[0]);// de igual forma , a é um array bidimensional (int a[][nCol]) logo para dar print temos de especificar a coluna
    printf("%d\n", *p); // ponteiro apontado para a[1] , assume logo que é a[1][0.
}
// linhas 2 e 4
// Opção B)
/*
struct info{
 char s[10];
 int a;
};

void f3(struct info a, struct info* b){
 printf("%c %c ", a.s[1], b->s[0]);
 printf("%d %d\n", (*b).a, a.a);
}*/
// B X 20 10 D)

void f4(char *p1, char *p2){
    while(p1[0] != *p2){
        printf("%c %s ", *p1, p1);
        p1++;
    }
}
// Opção B


int main() {
    /*alinea A
    int tab[5] = {1, 2, 1, 2, 1};
    f1(tab, 5);
    printtab(tab, 5)
    /*
    int tab[5] = {1, 2, 3, 4, 5};
    int mat[2][3] = {{10, 20, 30}, {40, 50, 60}};
    f2(2, 3, mat, tab, 5);
    */
    /*
    struct info a={"ABC", 10}, b={"XYZ", 20};
    f3(a, &b);
    */
    /*
    char s[20] = "ABC";
    f4(s, s+strlen(s)-1);
    */


    dados tabela[3] = {
        {{10, 20, 30, 40, 50}, NULL, 0},
        {{5, 15, 25, 35, 45}, NULL, 0},
        {{8, 18, 28, 38, 48}, NULL, 0}
    };

    float limA = 20.0, limB = 40.0;
    int resultado = processa(tabela, 3, limA, limB);
    for (int i = 0; i < 3; i++) {
        printf("Estrutura %d:\n", i + 1);
        printf("  Media: %.2f\n", tabela[i].media);
        printf("  Maior valor: %d\n", *tabela[i].p);
    }

    return 0;
}




