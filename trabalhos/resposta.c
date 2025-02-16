#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char nome[50];
    char categoria[30];
    char marca[30];
    float preco;
    int garantia;
    int quantidade;
} Item;

typedef struct {
    Item produtos[MAX_ITEMS];
    int total;
} TabelaItens;

TabelaItens carregarTabela(char nomeArquivo[]) {
    TabelaItens tabela;
    tabela.total = 0;
    FILE *arquivo = fopen(nomeArquivo, "r");
    
    char linha[200];
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL && tabela.total < MAX_ITEMS) {
        sscanf(linha, "%d,%49[^,],%29[^,],%29[^,],%f,%d,%d",
               &tabela.produtos[tabela.total].id,
               tabela.produtos[tabela.total].nome,
               tabela.produtos[tabela.total].categoria,
               tabela.produtos[tabela.total].marca,
               &tabela.produtos[tabela.total].preco,
               &tabela.produtos[tabela.total].garantia,
               &tabela.produtos[tabela.total].quantidade);
        tabela.total++;
    }
    fclose(arquivo);
    return tabela;
}

void gerarRelatorio(TabelaItens tabela) {
    char marcas[MAX_ITEMS][30];
    float valorTotalPorMarca[MAX_ITEMS] = {0};
    int qtdTotalPorMarca[MAX_ITEMS] = {0};
    int numMarcas = 0;

    for (int i = 0; i < tabela.total; i++) {
        int indiceMarca = -1;
        for (int j = 0; j < numMarcas; j++) {
            if (strcmp(marcas[j], tabela.produtos[i].marca) == 0) {
                indiceMarca = j;
                break;
            }
        }

        if (indiceMarca == -1) {
            strcpy(marcas[numMarcas], tabela.produtos[i].marca);
            indiceMarca = numMarcas;
            numMarcas++;
        }

        valorTotalPorMarca[indiceMarca] += tabela.produtos[i].preco * tabela.produtos[i].quantidade;
        qtdTotalPorMarca[indiceMarca] += tabela.produtos[i].quantidade;
    }

    printf("RELATÓRIO TOTAL EM ESTOQUE POR MARCA (R$ E QUANT. TOTAIS)\n");
    for (int i = 0; i < numMarcas; i++) {
        printf("%s\t%.2f\t%d itens\n", marcas[i], valorTotalPorMarca[i], qtdTotalPorMarca[i]);
    }

    float maiorEstoque = valorTotalPorMarca[0];
    float menorEstoque = valorTotalPorMarca[0];
    int indiceMaior = 0, indiceMenor = 0;

    for (int i = 1; i < numMarcas; i++) {
        if (valorTotalPorMarca[i] > maiorEstoque) {
            maiorEstoque = valorTotalPorMarca[i];
            indiceMaior = i;
        }
        if (valorTotalPorMarca[i] < menorEstoque) {
            menorEstoque = valorTotalPorMarca[i];
            indiceMenor = i;
        }
    }

    printf("\nMAIOR TOTAL EM ESTOQUE: %s, %.2f\n", marcas[indiceMaior], maiorEstoque);
    printf("MENOR TOTAL EM ESTOQUE: %s, %.2f\n", marcas[indiceMenor], menorEstoque);
}

int main() {
    TabelaItens tabela = carregarTabela("tabti.txt");
    gerarRelatorio(tabela);
    return 0;
}
