// Programação 2024/25
// Aula Prática 1 
//Francisco Ruivo 20211142024 11/02

#include <stdio.h>

// Recebe: Tabela de inteiros a com tamanho tam
// Mostra na consola os valores armazenados na tabela
void mostraTab(int a[], int tam){
    int i;

    for(i=0; i<tam; i++)
        printf("%d\t", a[i]);
    putchar('\n');
}

// Exercicio 1
// Recebe: Tabela de inteiros a com tamanho tam
// Devolve maior valor armazenado na tabela
int maior(int a[], int tam){
    int i, m = a[0];
    for(i=1; i<tam; i++)
        if(a[i] > m)
            m = a[i];
    return m;
}

// Exercicio 2
// Recebe: Tabela de inteiros a com tamanho tam
// Devolve posição do maior valor armazenado na tabela
int posMaior(int a[], int tam) {
    if (tam <= 0) return -1; // Caso a tabela esteja vazia, retorna -1 (indicando erro)
    int vmaior = a[0]; // Inicializa com o 1 elemento
    int pos = 0;

    for (int i = 0; i < tam; i++) {
        if (a[i] > vmaior) {
            vmaior = a[i];
            pos = i;
        }
    }
    return pos;
}
// Exercicio 3
// Recebe: Tabela de inteiros a com tamanho tam
// Devolve número de ocorrências do maior valor na tabela
int contaMaior(int a[], int tam){
    if (tam <= 0) return -1;
    int vmaior = a[0]; // Inicializa com o 1 elemento
    int contador=0;

    for (int i = 0; i < tam; i++) {
        if (a[i] > vmaior) {
            vmaior = a[i];
        }
    }
    for (int j = 0; j < tam; j++) {
        if (a[j] == vmaior) {
            contador++;
        }
    }
    return contador;
}


// Exercicio 4
// Recebe: Tabela de inteiros a com tamanho tam
// Devolve o elemento mais comum da tabela
int maisComum(int a[], int tam) {
    if (tam == 0) return -1;

    int maxContagem = 0, elementoMaisComum = a[0];

    for (int i = 0; i < tam; i++) {
        int contagem = 0;
        for (int j = 0; j < tam; j++) {
            if (a[j] == a[i]) {
                contagem++;
            }
        }
        if (contagem > maxContagem) {
            maxContagem = contagem;
            elementoMaisComum = a[i];
        }
    }

    return elementoMaisComum;
}
//ex5. Escreva uma função em C que inverta a ordem pela qual se encontram os elementos numa tabela
//de inteiros. A função recebe como argumentos o nome e a dimensão da tabela.
void inverte(int a[], int tam) {
    int temp;
    for (int i = 0; i < tam / 2; i++) { //até a metade do array
        temp = a[i];
        a[i] = a[tam - 1 - i]; // Troca com o elemento do final
        a[tam - 1 - i] = temp; // temp na posição correta
    }
}

void deslocaDireita(int a[], int tam) {
    if (tam <= 1) return; // Se o array for vazio ou tiver 1 elemento, não há deslocamento

    int ultimo = a[tam - 1]; // Armazena o último elemento

    // Percorre o array de trás para frente, movendo os elementos para a direita
    for (int i = tam - 1; i > 0; i--) {
        a[i] = a[i - 1];
    }

    a[0] = ultimo;
}
//ex7
void unicos(int v[], int tam) {
    for (int i = 0; i < tam; i++) {
        int repetido = 0;
        for (int j = 0; j < tam; j++) {
            if (i != j && v[i] == v[j]) {
                repetido = 1;
            }
        }
        if (repetido == 0) {
            printf("%d ", v[i]);
        }
    }
    printf("\n");
}
//ex8
void calculaSoma(int tab[], int dim, int valor) {
    // Percorre todas as combinações possíveis de 3 elementos
   int ncombi=0;
    for (int i = 0; i < dim - 2; i++) {
        for (int j = i + 1; j < dim - 1; j++) {
            for (int k = j + 1; k < dim; k++) {
                if (tab[i] + tab[j] + tab[k] == valor) {
                    printf("\n %d + %d + %d =7 ", tab[i], tab[j], tab[k]);
                    ncombi++;
                }
            }
        }
    }
    printf("\n Numero de Combinacoes possiveis : %d",ncombi);
}
//ex9 a)
int pesquisaOrd(int tab[], int dim, int valor) {
    for (int i = 0; i < dim; i++) {
        if (tab[i] == valor) {
            printf("Valor %d  encontrado na tabela.",valor);
            return 1;
        }
        if (tab[i] > valor) {
            printf("Valor %d nao encontrado na tabela.",valor);
            return 0; // Como a tabela está ordenada, se encontramos um valor maior, o valor não está na tabela
        }
    }
    return 0;
}
//ex9 b)
int pesquisaOrdBinaria(int tab[], int dim, int valor) {
    int esq = 0, dir = dim - 1;

    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;

        if (tab[meio] == valor) {
            return 1;
        }
        if (tab[meio] < valor) {
            esq = meio + 1; // Procura na metade direita
        } else {
            dir = meio - 1; // Procura na metade esquerda
        }
    }
    return 0;
}

int main(){

    int tab1[8] = {11, 12, 8, 8, 12, 1, 4, 2};
    int tab2[6] = {1, 4, 5, 2, 2, 3};
    int valoresordenados[6] = {1, 3, 5, 7, 9, 11, 13};

    printf("Tabela 1:\n");
    mostraTab(tab1, 8);
    printf("Maior: %d\n", maior(tab1, 8));
    printf("Pos Maior (a contar do zero): %d\n", posMaior(tab1, 8));
    printf("Conta Maior: %d\n", contaMaior(tab1, 8));
    printf("Mais comum: %d\n\n", maisComum(tab1, 8));
    inverte(tab1,8);
    printf("Ex5 tab invertida:\n\n");
    mostraTab(tab1, 8);
    printf("Tabela 2:\n");
    mostraTab(tab2, 6);
    printf("Maior: %d\n", maior(tab2, 6));
    printf("Pos Maior (a contar do zero): %d\n", posMaior(tab2, 6));
    printf("Conta Maior: %d\n", contaMaior(tab2, 6));
    printf("Mais comum: %d\n\n", maisComum(tab2, 6));
    deslocaDireita(tab2,6);
    printf("Ex6 tab deslocada 1 para a Direita:\n\n");
    mostraTab(tab2, 6);
    printf("Ex7 Valores unicos no array:\n\n");
    unicos(tab2,6);
    printf("Ex8 :");
    calculaSoma(tab2, 6, 7); /* combinação de todos os conjuntos de 3 elementos
 * da tabela cuja soma seja igual a um determinado valor*/
    printf("\n Ex9 pesquisaOrd :");
    mostraTab(valoresordenados,6);
    int valor = 5;
    pesquisaOrd(valoresordenados,6,valor);
    printf("\n Ex9 pesquisaOrd_binaria : ");
    mostraTab(valoresordenados,6);
    if (pesquisaOrdBinaria(valoresordenados, 6, valor)) {
        printf("Valor %d encontrado na tabela!\n", valor);
    } else {
        printf("Valor %d nao encontrado na tabela.\n", valor);
    }
    return 0;
}

