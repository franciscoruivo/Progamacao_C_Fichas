
#include <stdio.h>
#include "ponto.h"

// Escreve as coordenadas do ponto recebido como parâmetro
void printPonto(ponto2D a){
    printf("Ponto: (%d,%d)\n", a.x, a.y);
}

// Inicializa as coordenadas do ponto referenciado pelo parâmetro recebido. O utilizador indica os valores
void initPonto(ponto2D* p){
    printf("Indique coordenada x \n -> ");
    scanf("%d",&(p->x));
    printf("Indique coordenada y \n -> ");
    scanf("%d",&(p->y));
}

// Recebe endereço de um ponto e valores para o deslocamento ao longo dos eixos
// Atualiza as coordenadas do ponto
void movePonto(ponto2D* p, int dx, int dy){
    (p->x)=(p->x-dx);
    (p->y)=(p->y-dy);
}

// Devolve o quadrante a que pertence o ponto recebido por parâmetro
int quadrante(ponto2D a){
    if((a.x<0) && (a.y<0)){
        printf("\n Quadrante 3");
    }else if((a.x>0) && (a.y>0)){
        printf("\n Quadrante 1");
    }else if((a.x>0) && (a.y<0)){
        printf("\n Quadrante 4");
    } else if((a.x<0) && (a.y>0)){
       printf("\n Quadrante 2");
    }else{
        printf(("\n Parametros errados"));
    }
}

// Recebe 3 pontos
// Devolve 1 se estiverem na mesma reta, 0 se não estiverem

int eReta(ponto2D a, ponto2D b, ponto2D c) {
    // Verifica se os pontos a e b são iguais, o que tornaria a equação da reta indefinida.
    if ((a.x == b.x && a.y == b.y) || (a.x == c.x && a.y == c.y) || (b.x == c.x && b.y == c.y)) {
        return 1; // Pontos iguais, consideramos como estando na mesma reta.
    }

    // Verifica se os pontos a e b ou b e c têm a mesma coordenada x, para evitar divisão por zero.
    if (a.x == b.x || b.x == c.x) {
        // Se a coordenada x for a mesma, verifica se os pontos c também têm a mesma coordenada x.
        if (a.x == b.x && a.x == c.x) {
            return 1; // Pontos alinhados verticalmente.
        }
        return 0; // Pontos não estão alinhados.
    }

    // Calcula os coeficientes  (m)  (b) da reta que passa pelos pontos a e b.
    float m = (float)(b.y - a.y) / (b.x - a.x);
    float b_eq = a.y - m * a.x;

    // Verifica se o ponto c está na mesma reta.
    if (c.y == m * c.x + b_eq) {
        return 1; // Pontos estão alinhados.
    }

    return 0; // Pontos não estão alinhados.
}