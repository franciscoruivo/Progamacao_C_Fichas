#include <stdio.h>
#include "ponto.h"
#include "retangulo.h"
#include "tabela.h"

int main(){
    int total=3;
    ret tab[10] = {{{2,2},1,5}, {{1,1},4,2}, {{1,4},1,3}};
   /* ponto2D p1 = {3, 5},p2,p3,p4;
    ret r1;
    ret r2;
    printPonto(p1);

    initPonto(&p2);
    initPonto(&p3);
    printPonto(p2);

    movePonto(&p1, 0, 0);//mudar valores para test
    printPonto(p1);
    quadrante(p1);
    quadrante(p2);
    int resultado = eReta(p1,p2,p3);
    if (resultado) {
        printf("\n Os pontos estao alinhados na mesma reta.\n");
    } else {
        printf("\n Os pontos nao estao alinhados na mesma reta.\n");
    }

   int area;
    initRet(&r1);
    //initRet(&r2);
    printRet(r1);
  //  printRet(r2);
    area= areaR(r1);
    printf("\n A area do retangulo e de %d unidades quadradas xD",area);
    printf("\n Indique as cordenas para o ponto de teste \n");
    initPonto(&p4);
    dentroR(r1,p4);
    printRet(r1);
    moveR(&r1,5,10);
    printf("Apos movimentacao \n");
    printRet(r1);
    //extra interseR(&r1,&r2);
    return 0;

*/

   printV(tab, total);
   addRet(tab, &total);
   printV(tab, total);
    duplicaAltLarg(tab, total);
    quadrante1(tab,total);
    eliminaMenor(tab,&total);
    printV(tab, total);
    inverterordem(tab,&total);
    eliminaVarios(tab,&total,5);
    printV(tab, total);
    return 0;
}
