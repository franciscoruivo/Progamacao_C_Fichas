#include <stdio.h>
#include "ponto.h"
#include "retangulo.h"
#include "tabela.h"

int main(){
//A)
    ret tab[10] = {{{1,1},10,5}, {{2,3},2,6}, {{-1,4},7,2}};
    int total = 3;

  //  printV(tab, total); //B)
    
    addRet(tab, &total); //C)
    addRet(tab, &total);
    printV(tab, total);

 //  duplicaAltLarg(tab, total); E)
   // printV(tab, total);

 //   printf("\n Existem %d retangulos no quadrante 1\n", quadrante1(tab, total)); //F)
    for(int i = 0; i < total; i++) {
        printf("Quadrado %d: ", i+1);
        int area=areaR(tab[i]);
        printf("A area do retangulo: %d \n", area);
    }
   // eliminaMenor(tab, &total); //G)
 //   printf("\n eliminaMenorArea: ");
 // printV(tab, total);
    //printf("\n Inverter Ordem do tab: "); //H)
   // inverte(tab,&total);

  //  eliminaVarios(tab, &total, 20); //I)
  //  printf("\nApos eliminar retangulos com area < 20:\n");
  //  printV(tab, total);
    printf("\n Cordenadas dos QUADRADOS que existem em tab");
    imprimequadrados(tab, total); // apenas aqueles que larg=alt
    return 0;
}
