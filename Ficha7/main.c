#include <stdio.h>
#include <stdlib.h>

#include "agenda.h"

int main() {

    pct tab = NULL;
    int i, total=0;

    for(i=0; i<3; i++)
        tab = addC(tab, &total);

    listaC(tab, total);
    //alinea c)  adiciona contacto garantir que os nomes sao unicos
    //alinea d)
    //e

    printf("Contacto: %d\n", getTel(tab, total, "Ana"));
    atualizaTel(tab, total, "Ana", 921231230);//f
    listaC(tab,total);
    printf("Existem %d operadores moveis\n", getOperador(tab, total)); //g 91 92 93 94 quantos diferentes é que há

    free(tab);

    return 0;
}
