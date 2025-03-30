#include "funcao.h"
#include <string.h>
#include <stdio.h>

// Nome:Francisco Carreira Ruivo
// Número:2021142024

// Deve cumprir todas as regras de submissão (ver enunciado), caso contrário o trabalho poderá não ser avaliado

void mostraTab(projeto a[], int tam){
    int i;

    for(i=0; i<tam; i++){
        printf("Projeto %d:\n", i);
        printf("Inicio: %2.2d:%2.2d:%4d\tFinal: %2.2d:%2.2d:%4d\tDuracao: %d\n",
               a[i].inicio.dia, a[i].inicio.mes, a[i].inicio.ano,a[i].final.dia, a[i].final.mes, a[i].final.ano, a[i].duracao);
        printf("Palavras chave: {%s, %s, %s, %s}\n", a[i].palavras[0], a[i].palavras[1], a[i].palavras[2], a[i].palavras[3]);
        printf("Orcamento: %d\n\n", a[i].valor);
    }
}

// Escreva o codigo da função:
// void desafio2(projeto a[], int tam);

// Recebe:
// Tabela de estruturas do tipo projeto (a)
// Dimensão da tabela (tam)

// As estruturas armazenadas na tabela têm os campos inicio, final e pal completamente preenchidos.
// Para cada uma destas estruturas, a função deve preencher os campos duracao e valor:
// 1.Colocar no campo duracao o número de dias que decorreram entre o início e o final do projeto
// 2. Colocar no campo valor o orçamento total do projeto.
// Função auxiliar para calcular se um ano é bissexto
// Verifica se um caractere é uma vogal
int ehVogal(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
int ehBissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return 1;
    }
    return 0;
}
// duração do projeto em dias
int calculaDuracao(data inicio, data final) {
    int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Se o ano for bissexto
    if (ehBissexto(inicio.ano)) {
        diasPorMes[2] = 29;  // Fevereiro tem 29 dias em bissextos
    }
    int dias = 0;
    if (inicio.mes == final.mes) {
        dias = final.dia - inicio.dia;
    } else {
        dias = (diasPorMes[inicio.mes] - inicio.dia) + final.dia;
        for (int m = inicio.mes + 1; m < final.mes; m++) {
            dias += diasPorMes[m];
        }
    }
    return dias;
}
int calculaOrcamento(char palavras[4][20]) {
    int total = 0;

    for (int i = 0; i < 4; i++) {
        int vogais = 0;
        int len = strlen(palavras[i]);

        // Conta o número de vogais
        for (int j = 0; j < len; j++) {
            if (ehVogal(palavras[i][j])) {
                vogais++;
            }
        }

        if (vogais == 2 && ehVogal(palavras[i][0]) && ehVogal(palavras[i][len - 1])) {
            total += 10;  // 2 vogais nas posições inicial e final
        } else if (vogais == 1) {
            total += 5;   // 1 vogal
        } else if (vogais > 3) {
            total += 1;   // Mais de 3 vogais
        }
    }

    return total;
}
void desafio2(projeto a[], int tam) {
    for (int i = 0; i < tam; i++) {
        a[i].duracao = calculaDuracao(a[i].inicio, a[i].final);
        a[i].valor = calculaOrcamento(a[i].palavras);
    }
}
