#include <stdio.h>
#include "ponto.h"
#include "retangulo.h"

int main(){

    ponto2D p0,p1 = {3, 5}, p2,p3 = {3, 5};ret tab[10] = {{{2,2},1,5}, {{1,1},4,2}, {{1,4},1,3}};
    /*
    printPonto(p1);

    initPonto(&p2);
    printPonto(p2);

    movePonto(&p1, 1, 1);
    printPonto(p1);
    quadrante(p1);

    eReta(p1,p2,p3);
    double distancia = distancia_euclidiana(p1, p2);
    printf("\n distancia Euclidiana entre os pontos -> : %.2f\n", distancia);
*/
    ret r1,r2;
    initRet(&r1);
    printRet(r1);
    int area;
    area=areaR(r1);
  //  printf("Area do retangulo: %d\n",area);

    initRet(&r2);
    initPonto(&p0);
    dentroR(r2,p0);



    int dx, dy;
    printf("Indique o deslocamento em x: ");
    scanf("%d", &dx);
    printf("Indique o deslocamento em y: ");
    scanf("%d", &dy);
    overlap(r1,r2);
    deslocarRetangulo(&r1, dx, dy);
    printf("1n Retangulo apos deslocamento:\n");
    printRet(r1);

    return 0;
}
