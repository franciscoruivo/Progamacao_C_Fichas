// NOTAS IMPORTANTES

// 1. Altere o nome deste ficheiro. Deve passar a ter o seu numero de aluno como nome, mantendo a extensão .c
// Por exemplo, se o número de aluno for 1234567, o ficheiro deve passar a chamar-se: 1234567.c

// 2. Complete a sua identificação nas linhas 11 e 12

// 3. Só pode escrever código dentro da função desafio1(). Não pode alterar mais nada neste ficheiro
// Esta função não deve escrever nada na consola

// Nome completo: Francisco Carreira Ruivo
// Número de aluno: 2021142024

#include <stdio.h>

// Recebe:
// Endereço inicial de uma tabela de inteiros (tab)
// Dimensão de uma tabela de inteiros (tam)
// Endereço de uma variável inteira (contaP)

// Devolve o número de elementos da tabela que têm 2 vizinhos (à sua esquerda e à sua direita) com valores diferentes do seu.
// Coloca na variável referenciada por contaP o número de pares do array
// Considera-se que existe um par no array quando 2 elementos em posições consecutivas têm o mesmo valor

int desafio1(int *tab, int tam, int *contaP){
    int contador_viz = 0;
    *contaP = 0;
    // O elemento da 1ª posição do array não possui vizinho da esquerda
    // O elemento da ultima posição do array não possui vizinho da direita
    for (int i = 1; i<tam-1; i++) {
        if ((tab[i - 1] != tab[i]) && (tab[i + 1] != tab[i])) {
            contador_viz++;
        }
    }
// Conta a quantidade de pares de elementos consecutivos iguais
// O último elemento do array não possui um sucessor para formar um par

    for (int j = 0; j<tam-1; j++) {
        if (tab[j] == tab[j + 1]) {
            (*contaP)++;
        }
    }
    return contador_viz;
}

int main() {
    int tab1[9] = {5, 4, 8, 4, 4, 4, 2, 3, 3};

    int tab2[10] = {-3, -2, 0, 0, 1, 4, 3, -2, 9, 1};

    int tab3[9] = {1, 1, 4, 4, 4, 4, 3, 1, 1};

    int tab4[5] = {0, 0, 0, 0, 0};

    int c1=0, c2=0, c3=0, c4 = 0, d1, d2, d3, d4;

    d1 = desafio1(tab1, 9, &c1);
    d2 = desafio1(tab2, 10, &c2);
    d3 = desafio1(tab3, 9, &c3);
    d4 = desafio1(tab4, 5, &c4);

    printf("%d %d %d %d %d %d %d %d\n", d1, c1, d2, c2, d3, c3, d4, c4);
    return 0;
}