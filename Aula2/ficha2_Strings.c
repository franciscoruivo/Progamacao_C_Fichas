#include <stdio.h>
#include <string.h>
#include <ctype.h>

void imprimirString(char str[]) {
    printf("String original: '%s'\n", str);
}
//EX6
void imprimeStringInvertida(char str[]) {
    int tamanho = strlen(str); // Obtém o tamanho da string
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%c", str[i]); // Imprime cada caractere
    }
    printf("\n"); // Imprime uma nova linha no final
}

//ex7
    void ex7(char str[]) {
        int tamanho = strlen(str);
        int inicioPalavra = 0; //

        for (int i = 0; i <= tamanho; i++) {
            if (str[i] == ' ' || str[i] == '\0') { // Se encontrar um espaço ou o fim da string
                if (i > inicioPalavra) {
                    for (int j = inicioPalavra; j < i; j++) {
                        printf("%c", str[j]);
                    }
                    printf("\n"); // nova linha
                }
                inicioPalavra = i + 1; // Atualiza o í do início da prox palavra
            }
        }
    }
void ex8(char str1[], char str2[], char str3[]) {
    if (strcmp(str1, str2) == 0) {
        strcpy(str3, "Conteudo Igual!");
        return;
    }

    if (strlen(str1) == strlen(str2)) {
        strcpy(str3, "Tamanho Igual!");
        return;
    }

    // Encontra a string lexicograficamente menor
    char strMenor[100];
    if (strcmp(str1, str2) < 0) {
        strcpy(strMenor, str1);
        strcpy(str3, str1);  // str1 é a menor
        strcat(str3, str2);
    } else {
        strcpy(strMenor, str2);
        strcpy(str3, str2);  // str2 é a menor ou igual
        strcat(str3, str1);
    }
}
void ex9(char str[]) {
    int tamanho = strlen(str);
    int inicioPalavra = -1;

    for (int i = 0; i <= tamanho; i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            if (inicioPalavra == -1) {
                inicioPalavra = i;
            }
        } else {
            if (inicioPalavra != -1) {
                for (int j = inicioPalavra; j < i; j++) {
                    printf("%c", str[j]);
                }
                printf("\n");
                inicioPalavra = -1; // Reinicia para encontrar a próxima palavra
            }
        }
    }
}

int ex10(char str[]) {
    int tamanho = strlen(str);
    int inicioPalavra = -1;
    int contador = 0;

    for (int i = 0; i <= tamanho; i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            if (inicioPalavra == -1) {
                inicioPalavra = i;
                contador++;
            }
        } else {
            inicioPalavra = -1;
        }
    }
    return contador;
}


void ex11(char str[]) {
    int i = 0, j = 0;
    int espacoAnterior = 1; // Flag para controlar espaços consecutivos

    while (str[i] != '\0') {
        if (str[i] != ' ' || !espacoAnterior) {
            str[j++] = str[i];
        }
        espacoAnterior = (str[i] == ' ');
        i++;
    }
    if (j > 0 && str[j - 1] == ' ') {
        j--; // Remove espaço no final, se houver
    }
    str[j] = '\0';
}
void ex12(char str[]) {
    //altera as vogais para maiúsculas
        while (*str != '\0') {
            if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u') {
                *str = toupper(*str);  // Converte para maiúscula
            }
            else if (*str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U') {
                *str = *str;
            }
            str++;
        }
    }
int ex13(const char *str) {
    //verificar_digitos_ou_pontuacao
    int digitos = 0;
    int pontuacao = 0;


    while (*str != '\0') {
        if (isdigit(*str)) {
            digitos++;
        } else if (ispunct(*str)) {
            pontuacao++;
        }
        str++;
    }

    if (digitos > pontuacao) {
        return 1;   // Mais dígitos
    } else if (pontuacao > digitos) {
        return -1;  // Mais sinais de pontuação
    } else {
        return 0;   // Empate
    }
}

int ex14(const char *str) {
    int alfabeto[26] = {0};
    int count = 0;

    while (*str != '\0') {
        char c = *str;

        if (isalpha(c)) {
            c = tolower(c);
            if (alfabeto[c - 'a'] == 0) {
                alfabeto[c - 'a'] = 1;
                count++;
            }
        }
        str++;
    }

    return count;
}
int main() {
    char String[] = "Hoje e      Domingo!"; // para testar ex10 e ex 11
    imprimeStringInvertida(String); //EX6
    ex7(String); //EX7
    //ex8

    char str1[100], str2[100], str3[200];

    // Teste 1: Conteúdo igual
    strcpy(str1, "casa");
    strcpy(str2, "casa");
    ex8(str1, str2, str3);
    printf("Teste 1: %s\n", str3);

    // Teste 2: Tamanho igual
    strcpy(str1, "carro");
    strcpy(str2, "navio");
    ex8(str1, str2, str3);
    printf("Teste 2: %s\n", str3);

    // Teste 3: Tamanho diferente, str1 < str2
    strcpy(str1, "bola");
    strcpy(str2, "futebol");
    ex8(str1, str2, str3);
    printf("Teste 3: %s\n", str3);

    // Teste 4: Tamanho diferente, str2 < str1
    strcpy(str1, "futebol");
    strcpy(str2, "bola");
    ex8(str1, str2, str3);
    printf("Teste 4: %s\n", str3);
    char ex9string[] = "   Olaaa   mundo!  Isso  e o ex   9 da ficha 2 .  .     ";
    imprimirString(ex9string);
    ex9(ex9string);
    //ex10
    imprimirString(String);
    int contador = ex10(String);
    printf("Ex 10 , Contador da string -> %d", contador);

    ex11(String);
    printf(" \n\nEx11 String sem espacos extras: '%s'\n", String);


//ex12 // para  ex13
    char fraseex12[100];

    printf("Ex 12 e 13 Digite uma frase: ");
    fgets(fraseex12, sizeof(fraseex12), stdin);
    ex12(fraseex12);
    printf(" Ex 12 altera as vogais para maiusculas \n Frase alterada: %s", fraseex12);

//ex13

    int resultado = ex13(fraseex12);
    if (resultado == 1) {
        printf(" mais digitos na frase.\n");
    } else if (resultado == -1) {
        printf(" mais sinais de pontuacao na frase.\n");
    } else {
        printf(" empate entre digitos e sinais de pontuacao.\n");
    }

    //ex14
    char frase2[100];
    printf("Digite uma frase: ");
    fgets(frase2, sizeof(frase2), stdin);
    int resultadoo = ex14(frase2);
    printf("Numero de caracteres alfabeticos distintos: %d\n", resultadoo);

    return 0;
}




