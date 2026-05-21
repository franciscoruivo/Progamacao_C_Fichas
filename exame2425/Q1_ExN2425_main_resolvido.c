/*
Abrir o ficheiro de texto (receita)
Abrir o ficheiro binário (stock)
Para cada linha da receita:

Ler o id e a quantidade usada
Ir buscar esse ingrediente ao ficheiro binário
Subtrair a quantidade
Guardar de volta
Se ficou abaixo do mínimo → imprimir alerta
*/
#include <stdio.h>
typedef struct dados {
    int id;
    char nome[100];
    int qtd;
    int minstock;
} item;

void criar_ficheiro_binario( const char *fichBin) {
    FILE *f = fopen(fichBin, "wb");
    if  (f==NULL){ // OU if (!f)
        printf("\nErro ao criar ficheiro binário %s\n", fichBin);
        return;
    }
    item ingredientes[5] = {
        {1, "Farinha", 400, 200},
        {2, "Leite Magro", 200, 500},
        {3, "Ovos XXL", 100, 12},
        {4, "Sal", 505, 10},
        {5, "Acucar", 150, 30}
    };
    fwrite(ingredientes, sizeof(item), 5, f);
    fclose(f);
}
void criar_ficheiro_receita(const char *ficheiro_txt) {
    FILE *f = fopen(ficheiro_txt, "w");
    if (!f) {  // OU if (f==NULL)
        printf("\nErro ao criar ficheiro de receita%s\n", ficheiro_txt);
        return;
    }

    fprintf(f, "2 : Leite Magro : 100 : O leite deve estar morno\n");
    fprintf(f, "3 : Ovos XXL : 6 : Nada a referir\n");
    fprintf(f, "1 : Farinha : 250 : Farinha T55\n");

    fclose(f);
}
void mostrar_ficheiro_binario(const char *ficheiro_bin) {
    FILE *f = fopen(ficheiro_bin, "rb");
    if (!f) {
        printf("\nErro ao abrir ficheiro de receita%s\n", ficheiro_bin);
        return;
    }
    item ing;
    printf("\n--- Ingredientes apos atualizacao ---\n");
    while (fread(&ing, sizeof(item), 1, f) == 1) {
        printf("ID: %d, Nome: %s, Quantidade: %d, Minimo: %d\n",
               ing.id, ing.nome, ing.qtd, ing.minstock);
    }

    fclose(f);
}
int atualizar_stock(const char *fichBin, const char *fichReceita) {

    FILE *fb = fopen(fichBin, "rb+"); // Abrir binário para leitura e escrita
    if (fb == NULL) {  // OU if (!fb)
        printf("\nErro no acesso ao ficheiro binário %s\n", fichBin);
        return 0;
    }

    FILE *fr = fopen(fichReceita, "r"); // Abrir receita (txt) para leitura
    if (fr == NULL) {
        printf("\nErro no acesso ao ficheiro da receita %s\n", fichReceita);
        fclose(fb);
        return 0;
    }

    int id, qtd;
    char nome[100], comentario[200];
    item ing;

// ler o txt , identificar id do igrediente( na receita)  e quantidade
 //   ler o binario identificar id  e mudar quantidade derivada do txt

    while (fscanf(fr, " %d : %99[^:] : %d : %199[^\n]", &id, nome, &qtd, comentario) == 4){
        fseek(fb, (id - 1) * sizeof(item), SEEK_SET);
        fread(&ing, sizeof(item), 1, fb);
        ing.qtd -= qtd;
        if (ing.qtd<=ing.minstock) {
            printf(" \n  O ingrediente %s com %d  tem stock abaixo do mínimo. ", ing.nome, ing.minstock);
        }
        fseek(fb, (id - 1) * sizeof(item), SEEK_SET);  // ← corrige aqui
        fwrite(&ing, sizeof(item), 1, fb);              // ← completa aqui
}
    fclose(fr);   fclose(fb);   return 1;
}


void main() {
    const char *ficheiro_bin = "ingredientes.bin";
    const char *ficheiro_txt = "receita.txt";

    criar_ficheiro_binario(ficheiro_bin);
    criar_ficheiro_receita(ficheiro_txt);

    mostrar_ficheiro_binario(ficheiro_bin);

    if (atualizar_stock(ficheiro_bin, ficheiro_txt)) {
        printf("\nAtualizacao de stock concluida com sucesso.\n");
    } else {
        printf("\nErro na atualizacao de stock.\n");
    }

    mostrar_ficheiro_binario(ficheiro_bin);
}