
#include "retangulo.h"
#include <stdio.h>

// Escreve as coordenadas dos 4 cantos do retangulo recebido como parâmetro
void printRet(ret r){
    printf(" canto 1 cordernadas (x) (y): %d %d \n",r.canto.x,r.canto.y);
    printf(" canto 2 cordernadas (x) (y): %d %d \n",r.canto.x+r.larg,r.canto.y);
    printf(" canto 3 cordernadas (x) (y): %d %d \n",r.canto.x,r.canto.y+r.alt);
    printf(" canto 4 cordernadas (x) (y): %d %d \n",r.canto.x+r.larg,r.canto.y+r.alt);
}

// Inicializa os dados do retangulo referenciado pelo parâmetro recebido.
// O utilizador indica os valores
void initRet(ret* p){
    printf("\n Indique a cordenadas x do canto : ");
    scanf("%d",&p->canto.x);
    printf("\n Indique a cordenadas y do canto : ");
    scanf("%d",&p->canto.y);
    printf("\n Indique a altura : ");
    scanf("%d",&p->alt);
    printf("\n Indique a largura : ");
    scanf("%d",&p->larg);

}

// Devolve a area do retangulo recebido como parâmetro
int areaR(ret r){
    return r.alt*r.larg;
}

// Verifica se o ponto a se encontra dentro do retangulo r
// Devolve 1 se suceder, ou 0, caso contrario
int dentroR(ret r, ponto2D a){
    if (a.x>=r.canto.x && a.x<=(r.canto.x+r.larg) && a.y>=r.canto.y && a.y<=(r.canto.y+r.alt)){
        printf("\n O ponto esta dentro do retangulo \n");
    return 1;
    }
    printf("\n O ponto nao esta dentro do retangulo! \n");
    return 0;
    }




// Verifica se os 2 retangulos recebidos como parametro se intersetam.
// Devolve 1 se suceder, ou 0, caso contrario
int overlap(ret r1, ret r2) {
    // Verifica se os retângulos se sobrepõem
    // Se a coordenada x do canto direito de r1 for maior que a coordenada x do canto esquerdo de r2,
    // e se a coordenada x do canto direito de r2 for maior que a coordenada x do canto esquerdo de r1,
    // então pode haver sobreposição na horizontal.
    if (r1.canto.x + r1.larg > r2.canto.x && r2.canto.x + r2.larg > r1.canto.x) {

        // Se a coordenada y da base de r1 for maior que a coordenada y do topo de r2,
        // e se a coordenada y da base de r2 for maior que a coordenada y do topo de r1,
        // então pode haver sobreposição na vertical.
        if (r1.canto.y + r1.alt > r2.canto.y && r2.canto.y + r2.alt > r1.canto.y) {
            printf("\n  overlap");
            return 1; // Há sobreposição
        }
    }

    return 0; // Não há sobreposição
}
/*

g) Escreva uma função em C que desloque um retângulo no plano. A função recebe três
parâmetros: o endereço do retângulo a deslocar, o deslocamento ao longo do eixo xx e o
deslocamento ao longo do eixo yy*/

void deslocarRetangulo(ret *r, int dx, int dy){
    r->canto.x += r->canto.x+dx;
    r->canto.y += r->canto.y+dy;
    }

// Função para calcular a interseção sobre união (IoU) de dois retângulos
float calcularIoU(ret r1, ret r2) {
    // Coordenadas do retângulo de interseção
    int x_inter_esq = (r1.canto.x > r2.canto.x) ? r1.canto.x : r2.canto.x;
    int y_inter_sup = (r1.canto.y > r2.canto.y) ? r1.canto.y : r2.canto.y;
    int x_inter_dir = (r1.canto.x + r1.larg < r2.canto.x + r2.larg) ? r1.canto.x + r1.larg : r2.canto.x + r2.larg;
    int y_inter_inf = (r1.canto.y + r1.alt < r2.canto.y + r2.alt) ? r1.canto.y + r1.alt : r2.canto.y + r2.alt;

    // Calcula largura e altura da interseção
    int largura_inter = x_inter_dir - x_inter_esq;
    int altura_inter = y_inter_inf - y_inter_sup;

    // Se não houver interseção, retorna 0
    if (largura_inter <= 0 || altura_inter <= 0) {
        return 0.0;
    }


    int area_inter = largura_inter * altura_inter;
    int area_r1 = r1.larg * r1.alt;
    int area_r2 = r2.larg * r2.alt;
    int area_uniao = area_r1 + area_r2 - area_inter;
    return (float) area_inter / area_uniao;
}