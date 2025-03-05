// Programação 2024/25
// Aula Prática 2A - Matrizes

#include <stdio.h>

#include <stdbool.h> // Para usar o tipo bool
//ex1
// Recebe: Matriz de inteiros mat com 3 colunas e nLin linhas
// Mostra na consola os valores armazenados na matriz
void printMat(int mat[][3], int nLin){
    int i, j;

    for(i=0; i<nLin; i++){
        for(j=0; j<3; j++)
            printf("%d\t", mat[i][j]);
        putchar('\n');
    }
}
void preencheMatriz(int matriz[][3], int numLinhas) {
    int valor;

    for (int i = 0; i < numLinhas; i++) {
        printf("Introduza um valor inteiro para a linha %d: ", i + 1);
        scanf("%d", &valor);

        matriz[i][0] = valor;
        matriz[i][1] = valor * valor;
        matriz[i][2] = valor * valor * valor;
    }
}


// Função para verificar se um número é primo
bool ehPrimo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void preencheMatrizex3(int matriz[][3], int numLinhas) {
    int valor;
    bool valorValido;

    for (int i = 0; i < numLinhas; i++) {
        valorValido = false;
        while (!valorValido) {
            printf("Introduza um valor inteiro para a linha %d (entre 1 e 100): ", i + 1);
            scanf("%d", &valor);

            // Verificar se o valor está no intervalo [1, 100]
            if (valor >= 1 && valor <= 100) {
                // Verificar se é primo e se não existe na primeira coluna
                if (ehPrimo(valor)) {
                    bool repetido = false;
                    for (int j = 0; j < i; j++) {
                        if (matriz[j][0] == valor) {
                            repetido = true;
                            break;
                        }
                    }
                    if (!repetido) {
                        valorValido = true;
                    } else {
                        printf("Valor repetido. Introduza um valor diferente.\n");
                    }
                } else {
                    printf("Valor nao primo. Introduza um valor primo.\n");
                }
            } else {
                printf("Valor fora do intervalo. Introduza um valor entre 1 e 100.\n");
            }
        }

        matriz[i][0] = valor;
        matriz[i][1] = valor * valor;
        matriz[i][2] = valor * valor * valor;
    }
}
//ex4
int verificaRepetidos(int matriz[][3], int numLinhas) {
    for (int i = 0; i < numLinhas; i++) {
        for (int j = 0; j < 3; j++) {
            int elemento = matriz[i][j];
            for (int k = 0; k < numLinhas; k++) {
                for (int l = 0; l < 3; l++) {
                    // Se os índices são diferentes, comparar os elementos
                    if (i != k || j != l) {
                        if (matriz[k][l] == elemento) {
                            return 0; // Encontrou um elemento repetido
                        }
                    }
                }
            }
        }
    }
    return 1; // Todos os elementos são únicos
}
//ex5

int verificaQuadradoMagico(int matriz[3][3]) {
    int somaEsperada = matriz[0][0] + matriz[0][1] + matriz[0][2];

    // Verifica somas das linhas e das colunas
    for (int i = 1; i < 3; i++) {
        if (matriz[i][0] + matriz[i][1] + matriz[i][2] != somaEsperada) {
            return 0;
        }
    }
    for (int j = 0; j < 3; j++) {
        if (matriz[0][j] + matriz[1][j] + matriz[2][j] != somaEsperada) {
            return 0;
        }
    }

    // Verifica soma da diagonal principal e  secundária
    if (matriz[0][0] + matriz[1][1] + matriz[2][2] != somaEsperada) {
        return 0;
    }
    if (matriz[0][2] + matriz[1][1] + matriz[2][0] != somaEsperada) {
        return 0;
    }

    // Verifica se os valores estão entre 1 e 9 e se não há repetições
    // Cria um array booleano para rastrear quais valores já foram usados.
    // O índice 0 não é usado, pois os valores vão de 1 a 9.
    bool valoresUsados[10] = {false};
    // Itera sobre as linhas e colunas da matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int valor = matriz[i][j]; // Obtém o valor do elemento atual
            // Verifica se o valor está fora do intervalo [1, 9] ou se já foi usado
            if (valor < 1 || valor > 9 || valoresUsados[valor]) {
                // Se alguma das condições for verdadeira, a matriz não é um quadrado mágico
                return 0;
            }
            valoresUsados[valor] = true;
        }
    }
    return 1;
}





int main(){

    int m1[4][3] = {{1,2,3},{6,7,8},{10,11,12},{20,30,40}};
    int m2[10][3] = {0};
    int m3[5][3];
    int m4[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int m5[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 11, 12}};
    /*
    printMat(m1, 4);

   printf("\nMatriz preenchida:\n");
    printMat(m2, 10);
    preencheMatriz(m3, 5);
    printMat(m3,5);
    preencheMatrizex3(m3, 5);
    printMat(m3,5);

//ex4
    printf("Matriz m4: ");
    if (verificaRepetidos(m4, 4) == 1) {
        printf("Todos os elementos sao unicos.\n");
    } else {
        printf("A matriz contem elementos repetidos.\n");
    }

    printf("Matriz m5: ");
    if (verificaRepetidos(m5, 4) == 1) {
        printf("Todos os elementos sao unicos.\n");
    } else {
        printf("A matriz contem elementos repetidos.\n");
    }
    //ex5 quadrado magico*/
    int quadrado1[3][3] = {
        {6, 1, 8},
        {7, 5, 3},
        {2, 9, 4}
    };

    int quadrado2[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    if (verificaQuadradoMagico(quadrado1)) {
        printf("quadrado1 é um quadrado mágico.\n");
    } else {
        printf("quadrado1 não é um quadrado mágico.\n");
    }

    if (verificaQuadradoMagico(quadrado2)) {
        printf("quadrado2 é um quadrado mágico.\n");
    } else {
        printf("quadrado2 não é um quadrado mágico.\n");
    }

    return 0;
}


