// Programação 2024/25
// Aula Prática 3 - Ponteiros e Endereços: Comunicação entre funções e manipulação de tabelas

#include <stdio.h>
#include <string.h> // apenas para ultimos dois exs


void mostrar(int *tab,int tam) {
    for(int i=0;i<tam;i++) {
        printf("%d ",tab[i]);
    }
}
void f1(){
    int a=12, *p;
    float x=3.5, *q;
    p = &a;
    q = &x;
    printf("Valores: a=%d\tx=%.2f\n", a, x);
    printf("Valores: a=%d\tx=%.2f\n", *p, *q);
    printf("Endereco/Localizacao: a -> %p\tx -> %p\n", &a, &x);
    printf("Endereco/Localizacao: a -> %p\tx -> %p\n", p, q);
}
void f2(int x, int *p){
    printf("F2: Endereco/Localizacao: x=%p\tb=%p\n", &x, p);
    x++;
    (*p)++;
    printf("Valores em F2: a=%d\tb=%d\n", x, *p);
}
// Exercicio 3
// Recebe: Endereços/ponteiros para 3 variáveis do tipo float
// Deve efetuar a rotação de valores entre essas variáveis
void rotacao(float *p1, float *p2, float *p3){
    float auxiliar = *p1;
    *p1 = *p3;
    *p3 = *p2;
    *p2 = auxiliar;

}

// Exercicio 4
// Recebe: Endereço inicial de uma tabela de inteiros, tamanho da tabela e endereços de 4 variáveis inteiras
// Deve colocar nas variáveis referenciadas pelos 4 ponteiros:
// número de pares, de impares, maior valor e posição do maior valor
void conta(int *t, int tam, int *np, int *ni, int *maior, int *pos){
    *maior = t[0];
    *pos = 0;
    *np = 0;
    *ni = 0;

    for(int i = 0; i < tam; i++) {
        if (t[i] > *maior) {
            *maior = t[i];
            *pos = i;
        }
        if (t[i] % 2 == 0) {
            (*np)++;
        } else {
            (*ni)++;
        }
    }
}


// Exercicio 5
// Recebe: Endereço inicial e tamnaho de uma tabela de inteiros e endereços de 2 variáveis inteiras
// Deve colocar nas variáveis referenciadas pelos 2 ponteiros o maior e segundo maior elementos existentes na tabela
void procuraDupla(int *tab, int tam, int *prim, int *seg){
    if (tam < 2) return;
    *prim = *seg = tab[0];

        for (int i = 1; i < tam; i++) {
            if (tab[i] > *prim) {
                *seg = *prim;
                *prim = tab[i];
            } else if (tab[i] > *seg) {
                *seg = tab[i];
            }
        }
    }



/*Ex 6 Escreva uma função em C que receba, como argumentos, o nome e a dimensão de uma tabela
unidimensional de números inteiros e que coloque a zero todos os elementos cujo valor seja inferior
à média dos valores armazenados nessa tabela. Pode assumir que quando a função for chamada a
tabela já foi inicializada */

void zerar(int *tab, int tam) {
    float media=0;
    int soma=0;
    for (int i = 0; i < tam; i++) {
      soma+=tab[i];
    }
    media = (float) soma / tam;
printf("Media = %.2f\n", media);
    for (int j = 0; j < tam; j++) {
        if (tab[j] < media) {
            tab[j] = 0;
        }
    }

}
/*
Ex7
 Escreva uma função em C que receba, como argumentos, os nomes e as dimensões de dois
vetores de inteiros e verifique se estes são iguais. Considere que dois vetores de inteiros são iguais
se tiverem o mesmo número de elementos e se, em posições equivalentes, tiverem elementos com
o mesmo valor. A função devolve 1 se os vetores forem iguais, ou 0, no caso contrário. */

int verificarEx7(int *tab1, int *tab2, int tam1, int tam2) {
    // Se os tamanhos forem diferentes, já retorna 0
    if (tam1 != tam2) {
        return 0;
    }

    // Verifica elemento por elemento
    for (int i = 0; i < tam1; i++) {
        if (tab1[i] != tab2[i]) {
            return 0;  // Se houver uma diferença, os vetores não são iguais
        }
    }

    return 1;  // Se passou pelo loop sem diferenças, os vetores são iguais
}

/*8. Escreva uma função em C que receba 2 tabelas de inteiros e que contabilize quantos elementos
elas têm em comum. A função tem o seguinte protótipo:

Recebe informação sobre as duas tabelas e devolve o número de elementos em comum. As tabelas
recebidas estão ordenadas de forma crescente e dentro de cada uma das tabelas não existem
elementos repetidos */


int comuns(int *tabA, int tamA, int *tabB, int tamB) {
    int i = 0, j = 0, ncomuns = 0;

    while (i < tamA && j < tamB) {
        if (tabA[i] == tabB[j]) {
            ncomuns++;
            i++;
            j++;
        } else if (tabA[i] < tabB[j]) {
            i++;
        } else {
            j++;
        }
    }

    return ncomuns;
}


/*Escreva uma função em C que receba um vetor de inteiros e mova todos os seus elementos
algumas posições para a direita. O vetor deve ser considerado como sendo circular, ou seja, durante
o deslocamento os últimos elementos voltam a entrar a partir do início. A função recebe, como
parâmetros, o vetor, a sua dimensão e o número de posições a deslocar para a direita. Se o número
de posições a deslocar for superior ou igual à dimensão do vetor, a função não efetua nenhuma
alteração.
Por exemplo, se a função receber o vetor {2, 4, 6, 8, 10} com indicação para deslocar 2 posições:
Deverá alterar o vetor para o seguinte conteúdo: {8, 10, 2, 4, 6}.
A função tem o seguinte protótipo:*/

// Função para deslocar os elementos do vetor para a direita
void desloca(int *v, int tam, int shift) {
    if (shift >= tam) {
        return;
    }
    int temp[tam];
    for (int i = 0; i < tam; i++) {
        temp[i] = v[i];
    }

    //  deslocamento circular
    for (int i = 0; i < tam; i++) {
        // Calcula a nova posição do elemento com o deslocamento, usando o operador `%`
        int novaPos = (i + shift) % tam;  // % é usado para garantir que a posição "volte" ao começo
        // Coloca o elemento na nova posição
        v[novaPos] = temp[i];  // A posição no vetor original é atualizada com o valor do vetor temporário
    }
}





int main(){
    float x=1.2, y=4.9, z=-2.3;

    int tab1[10] = {12, 7, 9, 4, 1, 4, 41, 7, 21, 14};
    int tab2[5] = {-2, -7, -8, -9, -1};
    int tab3[8] = {11, 14, 11, 5, 8, 3, -4, -1};
    int tab4[8] = {12, 10, 11, 5, 8, 3, -4, -1};


    int pares=0, impares=0, maior=0, posMaior=0;
    int prim=0, seg=0;
    f1();
    printf("Antes: X=%.1f\tY=%.1f\tZ=%.1f\n", x, y, z);

    rotacao(&x, &y, &z);
    printf("Depois: X=%.1f\tY=%.1f\tZ=%.1f\n", x, y, z);

    // Colocar chamada da funcao conta()
    conta(tab1,10,&pares,&impares,&maior,&posMaior);
    printf("Pares: %d\tImpares: %d\t, Maior: %d\t, Posicao: %d\n", pares, impares, maior, posMaior);

    // Colocar chamada da funcao procuraDupla()
    procuraDupla(tab1,10,&prim,&seg);
    printf("Maior: %d\t, Segundo Maior: %d\n", prim, seg);
    mostrar(tab1,10);
    printf("\n");
   // zerar(tab1,10);
    int ex7=0;
    ex7=verificarEx7(tab4,tab3,8,8);
    mostrar(tab3,8);
    printf("\n");
    mostrar(tab4,8);
    if(ex7==1) {
    printf("Vetores Iguais\n");
     }else {
         printf("Vetores Diferentes\n");
    }
    int tab6[8] = {1, 3, 5, 7, 9, 11, 13, 15};
    int tab7[6] = {3, 5, 7, 9, 11, 15};
    int numComuns = comuns(tab6, 8, tab7, 6);
    printf("Numero de elementos comuns: %d\n", numComuns);

    return 0;
}
/* ex 11 e 12
int main() {
    int i, *p, *q;
    int a[5] = {0, 1, 2, 3, 4};
    for(p=a; p<= a+4; p++)
        printf("%d\t", *p);
    putchar('\n');
    for(p=a,i=1; i<3; i++)
        printf("%d\t", p[i]);
    putchar('\n');
    for(p=a, q=a+4; p<=q; p++, q--)
        printf("%d\t%d\t", *p, *q);
    return 0;
}

void f12A(char *a, char *b){
    do{
        b--;
        printf("%s\n", b);
    }while(a != b);
}
void f12B(char *a, char *b){
    while(a<b)
        printf("%s\n", a++);
}
int main(){
    char st1[10] = "123!";
    f12A(st1, st1+strlen(st1));
    f12B(st1, st1+strlen(st1));
    return 0;
}*/