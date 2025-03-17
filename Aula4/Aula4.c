#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// Programação 2024-25
// Aula 4 - Matrizes

//Ex1
// Recebe: Dimensões e endereço de uma matriz de inteiros
// A ordem dos parâmetros é crucial: o número de colunas tem que surgir antes do parâmetro que apresenta a matriz à função.
// A função imprime o conteúdo da matriz na consola
void printMat(int nLin, int nCol, int m[][nCol]){
    int i, j;

    for(i=0; i<nLin; i++){
        for(j=0; j<nCol; j++)
            printf("%d\t", m[i][j]);
        putchar('\n');
    }
}

void printFloatMat(int nLin, int nCol, float m[][nCol]){
    for(int i=0; i<nLin; i++){
        for(int j=0; j<nCol; j++)
            printf("%.1f\t", m[i][j]);
        putchar('\n');
    }
}

//Ex2
// Recebe: Dimensões e endereço de uma matriz de inteiros
// Recebe: Endereço de 2 variáveis inteiras onde deve colocar os indices das colunas com menor e maior média
// Escreve na consola as médias dos valores de cada coluna
void calcMediaCol(int nLin, int nCol, int m[][nCol], int* iMin, int* iMax){
    float media[nCol];
    int soma, minCol = 0, maxCol = 0;
    float minMedia=0, maxMedia=0;

    for (int i = 0; i < nCol; i++) {
        soma = 0;  // Reset soma for each column
        for (int j = 0; j < nLin; j++) {
            soma += m[j][i];
        }
        media[i] = (float)soma /  nLin;
        if (i == 0 || media[i] < minMedia) {
            minMedia = media[i];
            minCol = i;
        }
        if (i == 0 || media[i] > maxMedia) {
            maxMedia = media[i];
            maxCol = i;
        }
    }
    *iMin = minCol;
    *iMax = maxCol;
    for (int i = 0; i < nCol; i++) {
        printf("Media da coluna %d: %.2f\n", i, media[i]);
    }
}



//ex3
void tMat(int n, int mat[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

/* ex4 Escreva uma função em C que verifique se todos os elementos de uma matriz de inteiros são
únicos. A função tem o seguinte protótipo:
A função devolve 1 se todos os elementos da matriz forem únicos, ou 0, caso contrário.*/

int unicaMat(int nLin, int nCol, int *mat) {
    int total = nLin * nCol; // total de elementos na matriz

    // Percorre todos os elementos da matriz
    for (int i = 0; i < total; i++) {
        for (int j = i + 1; j < total; j++) {
            if (*(mat + i) == *(mat + j)) {
                return 0;
            }
        }
    }
    return 1;
}
//ex5
// Função que reduz uma imagem de tamanho MxM para uma imagem M/2 x M/2.
// A nova imagem é formada pela média dos 4 pixels adjacentes (2x2) na imagem original.
void reduzirImagem(int M, const int *imagem, float *reduzida) {
    for (int i = 0; i < M; i += 2) {
        for (int j = 0; j < M; j += 2) {
            // A cada ciclo dos dois laços, estamos a olhar para um bloco 2x2 da imagem original.
            // Esse bloco é composto por 4 elementos. Vamos calcular a média desses 4 elementos.
            // Os 4 elementos da imagem original são:
            // imagem[i][j], imagem[i][j+1], imagem[i+1][j], imagem[i+1][j+1]
            // O cálculo da média é feito somando estes 4 valores e dividindo por 4.0f
            // O "f" garante que estamos a dividir por um número de ponto flutuante.

            // *(imagem + i * M + j) -> Acede ao elemento imagem[i][j]
            // *(imagem + i * M + j + 1) -> Acede ao elemento imagem[i][j+1]
            // *(imagem + (i + 1) * M + j) -> Acede ao elemento imagem[i+1][j]
            // *(imagem + (i + 1) * M + j + 1) -> Acede ao elemento imagem[i+1][j+1]
            // Este cálculo é feito para cada bloco 2x2 da matriz original.

            // A média é calculada e armazenada na posição apropriada da matriz reduzida.
            // *(reduzida + (i / 2) * (M / 2) + (j / 2)) -> Acede à posição na matriz reduzida
            // (i / 2) e (j / 2) são as novas coordenadas na matriz reduzida (metade das dimensões da original).
            *(reduzida + (i / 2) * (M / 2) + (j / 2)) =
                (*(imagem + i * M + j) + *(imagem + i * M + j + 1) +
                 *(imagem + (i + 1) * M + j) + *(imagem + (i + 1) * M + j + 1)) / 4.0f;
        }
    }
}
//ex6

void espiral(int dim, int mat[][dim]) {
    int topo = 0, baixo = dim - 1, esquerda = 0, direita = dim - 1;
    int direcao = 0; // 0: direita, 1: baixo, 2: esquerda, 3: cima

    while (topo <= baixo && esquerda <= direita) {
        if (direcao == 0) { // Direita
            for (int i = esquerda; i <= direita; i++) {
                printf("%d, ", mat[topo][i]);
            }
            topo++;
        } else if (direcao == 1) { // Baixo
            for (int i = topo; i <= baixo; i++) {
                printf("%d, ", mat[i][direita]);
            }
            direita--;
        } else if (direcao == 2) { // Esquerda
            for (int i = direita; i >= esquerda; i--) {
                printf("%d, ", mat[baixo][i]);
            }
            baixo--;
        } else if (direcao == 3) { // Cima
            for (int i = baixo; i >= topo; i--) {
                printf("%d, ", mat[i][esquerda]);
            }
            esquerda++;
        }
        direcao = (direcao + 1) % 4;
    }
    printf("\n");
}
//ex7

void imprimirMatriz(int nLin, int nCol, char tab[][nCol]) {
    for (int i = 0; i < nLin; i++) {
        for (int j = 0; j < nCol; j++) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}
void procuraPal(int nLin, int nCol, char tab[][nCol], char *pal) {
    int comp  = strlen(pal);
    for (int i = 0; i < nLin; i++) {
        for (int j = 0; j <= nCol - comp ; j++) {
            int k;
            for (k = 0; k < comp ; k++) {
                if (tab[i][j + k] != pal[k]) {
                    break;
                }
            }
            if (k == comp) {
                printf("A palavra %s surge: Ao longo da linha %d com inicio na coluna %d\n", pal, i, j);
            }
        }
    }
    for (int j = 0; j < nCol; j++) {
        for (int i = 0; i <= nLin - comp; i++) {
            int k;
            for (k = 0; k < comp; k++) {
                if (tab[i + k][j] != pal[k]) {
                    break;
                }
            }
            if (k == comp) {
                printf("A palavra %s surge: Ao longo da coluna %d com inicio na linha %d\n", pal, j, i);
            }
        }
    }
}
//ex8


void traduz(char *mes) {
    char *pt[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    char *eng[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    for (int i = 0; i < 12; i++) {
        if (strcmp(mes, pt[i]) == 0) {
            printf("%s -> %s\n", mes, eng[i]);
            return;
        }
    }
    printf("Mes nao encontrado.\n");
}
//ex9

bool verificaPlaneta(char *nome) {
    char *planetas[] = {
        "Mercurio", "Venus", "Terra", "Marte", "Jupiter", "Saturno", "Urano", "Netuno"
    };
    int numPlanetas = sizeof(planetas) / sizeof(planetas[0]);

    for (int i = 0; i < numPlanetas; i++) {
        if (strcmp(nome, planetas[i]) == 0) {
            return true;
        }
    }
    return false;
}

//ex10

// 10 a)
// Recebe a matriz de sinonimos e a indicacao do numero de linhas (sabe-se que são 2 colunas)
// Escreve na consola todos os pares de sinonimos

void escreve_sin(char *sin[][2],int nlin){

    for(int i=0;i<nlin;i++){
        printf("%s %s\n",sin[i][0],sin[i][1]);
    }
}

// 10 b)
// Recebe a matriz de sinonimos, a indicacao do numero de linhas e a palavra a pesquisar
// Devolve ponteiro para sinonimo da palavra recebida por parametro (NULL se não existir sinonimo)
char *pesquisa_sinonimo(char *sin[][2], int tot_lin, char *p) {
    for (int i = 0; i < tot_lin; i++) {
        if (strcmp(p, sin[i][0]) == 0) {
            return sin[i][1]; // Retorna o sinônimo
        } else if (strcmp(p, sin[i][1]) == 0) {
            return sin[i][0]; // Retorna o sinônimo
        }
    }
    return NULL; // Retorna NULL se nenhum sinônimo for encontrado
}

// 10 c)
// Recebe a matriz de sinonimos e a indicacao do numero de linhas
// Devolve ponteiro para a palavra alfabeticamente mais pequena que se encontra na matriz (NULL se não existirem palavras)
char *alfaMin(char *sin[][2], int tot_lin){

    int tam=strlen(sin[0][0]);
    char *mpal=sin[0][0];

    for(int i=0;i<tot_lin;i++){
        for(int j=0;j<2;j++){
            if(sin[i][j] != NULL && strlen(sin[i][j])<tam){
                tam=strlen(sin[i][j]);
                mpal=sin[i][j];
            }
        }
    }
    return mpal;
}
//10d
void contaVogais(char tabela[][2][50], int numPares) {
    int contagem[5] = {0};
    for (int i = 0; i < numPares; i++) {
        for (int j = 0; j < 2; j++) {
            char *palavra = tabela[i][j];
            for (int k = 0; palavra[k] != '\0'; k++) {
                char c = palavra[k];
                if (c == 'a' || c == 'A') {
                    contagem[0]++;
                } else if (c == 'e' || c == 'E') {
                    contagem[1]++;
                } else if (c == 'i' || c == 'I') {
                    contagem[2]++;
                } else if (c == 'o' || c == 'O') {
                    contagem[3]++;
                } else if (c == 'u' || c == 'U') {
                    contagem[4]++;
                }
            }
        }
    }

    printf("Contagem de vogais:\n");
    printf("a: %d\n", contagem[0]);
    printf("e: %d\n", contagem[1]);
    printf("i: %d\n", contagem[2]);
    printf("o: %d\n", contagem[3]);
    printf("u: %d\n", contagem[4]);
}

//10e
int contaPalavrasRepetidas(char tabela[][2][50], int numPares) {
    int contagem[100] = {0};
    char palavras[100][50];
    int numPalavras = 0;
    int repetidas = 0;
    // tratar aqui de  todas as palavras únicas
    for (int i = 0; i < numPares; i++) {
        for (int j = 0; j < 2; j++) {
            char *palavra = tabela[i][j];
            int encontrada = 0;
            for (int k = 0; k < numPalavras; k++) {
                if (strcmp(palavra, palavras[k]) == 0) {
                    encontrada = 1;
                    break;
                }
            }
            if (!encontrada) {
                strcpy(palavras[numPalavras], palavra);
                numPalavras++;
            }
        }
    }

    // Contar ocorrências de cada palavra
    for (int i = 0; i < numPares; i++) {
        for (int j = 0; j < 2; j++) {
            char *palavra = tabela[i][j];
            for (int k = 0; k < numPalavras; k++) {
                if (strcmp(palavra, palavras[k]) == 0) {
                    contagem[k]++;
                    break;
                }
            }
        }
    }

    // Contar palavras repetidas
    for (int i = 0; i < numPalavras; i++) {
        if (contagem[i] > 1) {
            repetidas++;
        }
    }

    return repetidas;
}

//10f
void verificaSinonimos(char *frase, char *sinonimos[][2], int numPares) {
    char *palavra = strtok(frase, " "); // Divide a frase em palavras
    while (palavra != NULL) {
        char *sinonimo = pesquisa_sinonimo(sinonimos, numPares, palavra);
        if (sinonimo != NULL) {
            printf("%s -> %s\n", palavra, sinonimo);
        }
        palavra = strtok(NULL, " "); // Obtém a próxima palavra
    }
}
int main(int argc, char *argv[]) {

    int mat1[3][3] = {{1,2,2},{7,8,9},{12,13,14}};
    int mat2[2][5] = {{10,2,13,4,8},{5, 9, 12, 1, 0}};

    int a=-1,b=-1;

    printf("Mat 1:\n");
    printMat(3, 3, mat1);
    printf("\nMat 2:\n");
    printMat(2, 5, mat2);

    calcMediaCol(2, 5, mat2, &a, &b);
    printf("\n\nCol. com menor media: %d\nCol. com maior media: %d\n", a, b);

    tMat(3, mat1);
    printf("\nMat 1 Transposta:\n");
    printMat(3, 3, mat1);

    //Ex 4
    if (unicaMat(3, 3, mat1)) {
        printf("\nMat 1 tem todos os elemenos Unicos \n");
    } else {
        printf("\nMat 1 n tem todos os elemenos Unicos \n");
    }

    //ex5
    int imagem[8][8] = {
        {0, 4, 9, 3, 6, 7, 2, 9},
        {9, 4, 7, 8, 3, 4, 7, 2},
        {5, 1, 2, 6, 3, 8, 6, 2},
        {7, 1, 4, 8, 7, 2, 0, 7},
        {4, 9, 3, 5, 2, 1, 5, 7},
        {5, 3, 4, 7, 8, 9, 1, 0},
        {2, 3, 5, 6, 7, 9, 2, 4},
        {2, 3, 4, 5, 6, 7, 8, 9}
    };
    printf("\n Imagem Original:\n");
    int M=8;
    float reduzida[M/2][M/2];
    printMat(M,M,imagem);
    reduzirImagem(M, imagem, reduzida);
    printf("\nImagem Reduzida:\n");
    printFloatMat(M/2, M/2, reduzida);

//ex6
    int matex6[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    printf("\nEx 6 Antes Expiral:\n");
    printMat(4,4, matex6);
    espiral(4, matex6);
    printf("\n");
//ex7

    char tab7[5][6] = {
        //   0    1    2    3   4     5
        {'e', 'B', 'a', 'u', 'l', 'q'},//0
        {'l', 'e', 'r', 'r', 's', 's'},//1
        {'u', 'w', 'u', 'q', 'g', 'r'},//2
        {'a', 'a', 'l', 'l', 'u', 'a'},//3
        {'P', 'm', 'h', 'u', 'd', 'j'} //4
    };
    imprimirMatriz(5, 6, tab7);
    printf("\n");
    procuraPal(5, 6, tab7, "lua");

    //ex8
    char *pt[12]={"Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};
    char *eng[12]={"January","February","March","April","May","June","July","August","September","October","December"};
    char palavra[50];
    printf("Indique um Mes para traducao:  ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = 0;
    traduz(palavra);
    printf("\n");
    //ex9
    printf("Indique um palavra para testar ex9 :  ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = 0;

    if (verificaPlaneta(palavra)) {
        printf("%s e um planeta do sistema solar.\n", palavra);
    } else {
        printf("%s nao e um planeta do sistema solar.\n", palavra);
    }

//ex10

    char *s[5][2] = {{"estranho", "bizarro"},
                   {"desconfiar", "suspeitar"},
                   {"vermelho", "encarnado"},
                   {"duvidar", "desconfiar"},
                   {"carro", "automovel"}};
    char  *pav,*p,*q;
    escreve_sin(s, 5);
    //10b
    printf("\n");
    printf("\nPalavra a pesquisar: ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = 0;
    p = pesquisa_sinonimo(s, 5, palavra);
    if(p == NULL)
        printf("A palavra %s nao tem sinonimo conhecido\n", palavra);
    else
        printf("A palavra %s e sinonimo de %s\n", p, palavra);
//10c
    q = alfaMin(s, 5);
    printf("\nA palavra alfabeticamente mais pequena e %s\n", q);
    alfaMin(s, 5);
    //10d

    char dezd[3][2][50] = {
        {"casa", "carro"},
        {"elefante", "casa"},
        {"ovo", "casa"}
    };
    contaVogais(dezd,3);
    //10e
    int repetidas = contaPalavrasRepetidas(dezd, 3);
    printf("Numero de palavras repetidas: %d\n", repetidas);


    char word[100];
    printf("Digite uma frase: ");
    fgets(word, sizeof(word), stdin);

    palavra[strcspn(word, "\n")] = 0;

    verificaSinonimos(word, s, 5);
    return 0;
}

/* outputs
 ex 11)

 abcdef
ijk
op*

ex 12)
1       2       3
3       4       5       6

*/



