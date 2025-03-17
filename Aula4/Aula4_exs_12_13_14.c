#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 //EX12 mudar argumentos para  AAA e BBB, a sequência final será: ABABAB.
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s palavra1 palavra2\n", argv[0]);
        return 1;
    }

    char *palavra1 = argv[1];
    char *palavra2 = argv[2];

    if (strlen(palavra1) != strlen(palavra2)) {
        printf("As palavras devem ter o mesmo número de caracteres.\n");
        return 1;
    }

    int comprimento = strlen(palavra1);
    char resultado[2 * comprimento + 1];
    int indiceResultado = 0;

    for (int i = 0; i < comprimento; i++) {
        resultado[indiceResultado++] = palavra1[i];
        resultado[indiceResultado++] = palavra2[i];
    }

    resultado[indiceResultado] = '\0';

    printf("%s\n", resultado);

    return 0;
}
/*
//EX13 mudar os argumentos para calcular  a média dos números 10, 2, 31, 4 e 12 = 11.8

int main(int argc, char *argv[]) {
    // Verifica se há pelo menos um número para calcular a média
    if (argc < 2) {
        printf("Uso: %s <num1> <num2> ...\n", argv[0]);
        return 1; // Retorna 1 para indicar erro
    }

    int soma = 0;
    // Loop para somar todos os números passados como argumentos
    for (int i = 1; i < argc; i++) {
        soma += atoi(argv[i]); // Converte a string para inteiro e soma
    }
    double media = (double)soma / (argc - 1);

    printf("%.1f\n", media);

    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//EX14  indicado nos argumentos a data 12-01-2024 deve escrever 12 de janeiro de 2024.
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s dd-mm-aaaa\n", argv[0]);
        return 1;
    }
    char *meses[] = {
        "janeiro", "fevereiro", "março", "abril", "maio", "junho",
        "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"
    };
    char *data = argv[1];
    int dia, mes, ano;

    if (sscanf(data, "%d-%d-%d", &dia, &mes, &ano) != 3) {
        printf("Formato de data invalido.\n");
        return 1; // Retorna 1 para indicar erro
    }
    if (mes < 1 || mes > 12) {
        printf("Mes invalido.\n");
        return 1;
    }

    // Imprime a data formatada
    printf("%d de %s de %d\n", dia, meses[mes - 1], ano);

    return 0; // Retorna 0 para indicar sucesso
}