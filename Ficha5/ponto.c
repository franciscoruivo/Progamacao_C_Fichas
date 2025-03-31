
#include <stdio.h>
#include "ponto.h"
#include <math.h>

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
        p->x = p->x + dx;
        p->y = p->y + dy;
}

// Devolve o quadrante a que pertence o ponto recebido por parâmetro  1 e)
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
// Recebe 3 pontos
// Devolve 1 se estiverem na mesma reta, 0 se não estiverem
//1f)
int eReta(ponto2D a, ponto2D b, ponto2D c) {
    if ((a.x == b.x && a.y == b.y) || (a.x == c.x && a.y == c.y) || (b.x == c.x && b.y == c.y)) {
        return 1;
    }
    if (a.x == b.x || b.x == c.x) {
        if (a.x == b.x && a.x == c.x) {
            printf("\n Estao na mesma Reta ");
            return 1;
        }
        return 0;
    }
    float m = (float)(b.y - a.y) / (b.x - a.x);
    float b_eq = a.y - m * a.x;
    if (c.y == m * c.x + b_eq) {
        printf("\n Estao na mesma Reta ");
        return 1;
    }

    return 0;
}

// Função para calcular a distância Euclidiana entre dois pontos
double distancia_euclidiana(ponto2D p1, ponto2D p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
