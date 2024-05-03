#include <stdio.h>
#include "retangulo.h"

void printRet(ret r){
    printf("C1: (%d,%d)\n",r.canto.x,r.canto.y);
    printf("C2: (%d,%d)\n",r.canto.x+r.larg,r.canto.y);
    printf("C3: (%d,%d)\n",r.canto.x+r.larg,r.canto.y+r.alt);
    printf("C4: (%d,%d)\n",r.canto.x,r.canto.y+r.alt);
}

void initRet(ret* p){
    printf("\n Indique as cordenas para o canto inferior esquerdo : \n ");
    initPonto(&p->canto);
    printf("\n Indique a altura \n->");
    scanf("%d",&p->alt);
    printf("\n Indique a largura \n->");
    scanf("%d",&p->larg);
}

int areaR(ret r){
    return r.alt*r.larg;
}

int dentroR(ret r, ponto2D a){
    printRet(r);
    printPonto(a);
    if(a.x>r.canto.x && a.x<r.canto.x+r.larg){
        if(a.y>r.canto.y && a.y<r.canto.y+r.alt){
            printf(("\n O ponto esta dentro do retangulooo! \n"));
        }
    }else{
        printf("\n O ponto nao esta dentro do retangulo! \n");
    }
    return 0;
}

void moveR(ret* p, int dx, int dy){
    p->canto.x=p->canto.x+dx;
    p->canto.y=p->canto.y+dy;
}
void interseR(ret* a,ret* b){
    if(a->canto.x>b->canto.x && a->canto.y<b->canto.y){
        if(a->canto.x+a->larg>b->canto.x+b->larg && a->canto.y+a->alt<b->canto.y+b->alt){
           //idk
        }
    }
}
