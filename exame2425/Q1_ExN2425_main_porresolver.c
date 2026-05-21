/*Questão 1 – Exame da época Normal de Programação 2024/2025*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dados {
    int id;
    char nome[100];
    int qtd;
    int minstock;
} item;

// Função pedida no exame
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


// Fazer a resolução da questão


   fclose(fr);   fclose(fb);   return 1;
}

// Função auxiliar para criar o ficheiro binário com dados de exemplo
void criar_ficheiro_binario(const char *fichBin) {
    FILE *f = fopen(fichBin, "wb");
    if (!f) { // OU if (f==NULL)
       printf("\nErro ao criar ficheiro binário %s\n", fichBin);
       return;
    }
   //alterei farinha em relação ao enunciado para gerar alertas para stocks baixos
    item ingredientes[5] = {
       {1, "Farinha", 400, 200},
       {2, "Leite Magro", 3000, 500},
       {3, "Ovos XXL", 100, 12},
       {4, "Sal", 505, 10},
       {5, "Açucar", 150, 30}
    };

    fwrite(ingredientes, sizeof(item), 5, f);
    fclose(f);
}

// Função auxiliar para criar o ficheiro de texto da receita
void criar_ficheiro_receita(const char *fichReceita) {
    FILE *f = fopen(fichReceita, "w");
    if (!f) {  // OU if (f==NULL)
       printf("\nErro ao criar ficheiro de receita%s\n", fichReceita);
       return;
    }

    fprintf(f, "2 : Leite Magro : 100 : O leite deve estar morno\n");
    fprintf(f, "3 : Ovos XXL : 6 : Nada a referir\n");
    fprintf(f, "1 : Farinha : 250 : Farinha T55\n");

    fclose(f);
}

// Função para mostrar o conteúdo do ficheiro binário
void mostrar_ficheiro_binario(const char *fichBin) {
   FILE *f = fopen(fichBin, "rb"); // Abrir bin rio para leitura
    if (f == NULL) {
      printf("\nErro ao abrir ficheiro binário %s\n", fichBin);
      return;
    }

    item ing;
    printf("\n--- Ingredientes após atualização ---\n");
    while (fread(&ing, sizeof(item), 1, f) == 1) {
        printf("ID: %d, Nome: %s, Quantidade: %d, Mínimo: %d\n",
               ing.id, ing.nome, ing.qtd, ing.minstock);
    }

    fclose(f);
}

void main() {
    const char *ficheiro_bin = "ingredientes.bin";
    const char *ficheiro_txt = "receita.txt";

    criar_ficheiro_binario(ficheiro_bin);
    criar_ficheiro_receita(ficheiro_txt);

    mostrar_ficheiro_binario(ficheiro_bin);

    if (atualizar_stock(ficheiro_bin, ficheiro_txt)) {
        printf("\nAtualização de stock concluída com sucesso.\n");
    } else {
        printf("\nErro na atualização de stock.\n");
    }

    mostrar_ficheiro_binario(ficheiro_bin);
}

