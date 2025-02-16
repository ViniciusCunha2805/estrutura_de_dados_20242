#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    char placa[10];
    char cpfDono[15];
} RegistroVeiculo;

typedef struct {
    char cpf[15];
    char nomeCompleto[50];
} RegistroProprietario;

typedef struct {
    char placa[10];
    float valorMulta;
} RegistroMulta;

typedef struct {
    RegistroVeiculo veiculos[MAX_RECORDS];
    int total;
} ListaVeiculos;

typedef struct {
    RegistroProprietario proprietarios[MAX_RECORDS];
    int total;
} ListaProprietarios;

typedef struct {
    RegistroMulta multas[MAX_RECORDS];
    int total;
} ListaMultas;

ListaVeiculos carregarVeiculos(char nomeArquivo[]) {
    ListaVeiculos lv;
    lv.total = 0;
    FILE *arquivo = fopen(nomeArquivo, "r");
    char linha[100];
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL && lv.total < MAX_RECORDS) {
        sscanf(linha, "%[^,],%*[^,],%*[^,],%s", lv.veiculos[lv.total].placa, lv.veiculos[lv.total].cpfDono);
        lv.total++;
    }
    fclose(arquivo);
    return lv;
}

ListaProprietarios carregarProprietarios(char nomeArquivo[]) {
    ListaProprietarios lp;
    lp.total = 0;
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        exit(1);
    }
    char linha[100];
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL && lp.total < MAX_RECORDS) {
        sscanf(linha, "%[^,],%[^,]", lp.proprietarios[lp.total].cpf, lp.proprietarios[lp.total].nomeCompleto);
        lp.total++;
    }
    fclose(arquivo);
    return lp;
}

ListaMultas carregarMultas(char nomeArquivo[]) {
    ListaMultas lm;
    lm.total = 0;
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        exit(1);
    }
    char linha[100];
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL && lm.total < MAX_RECORDS) {
        sscanf(linha, "%[^,],%*[^,],%f", lm.multas[lm.total].placa, &lm.multas[lm.total].valorMulta);
        lm.total++;
    }
    fclose(arquivo);
    return lm;
}

void gerarRelatorio(ListaVeiculos lv, ListaProprietarios lp, ListaMultas lm) {
    float totalPorCpf[MAX_RECORDS] = {0};
    int qtdMultasPorCpf[MAX_RECORDS] = {0};

    for (int i = 0; i < lm.total; i++) {
        for (int j = 0; j < lv.total; j++) {
            if (strcmp(lv.veiculos[j].placa, lm.multas[i].placa) == 0) {
                for (int k = 0; k < lp.total; k++) {
                    if (strcmp(lp.proprietarios[k].cpf, lv.veiculos[j].cpfDono) == 0) {
                        totalPorCpf[k] += lm.multas[i].valorMulta;
                        qtdMultasPorCpf[k]++;
                        break;
                    }
                }
                break;
            }
        }
    }

    printf("RELATÓRIO DE MULTAS POR PROPRIETÁRIO\n");
    for (int i = 0; i < lp.total; i++) {
        if (qtdMultasPorCpf[i] > 0) {
            printf("%s\tTotal: R$ %.2f\tMultas: %d\n", lp.proprietarios[i].nomeCompleto, totalPorCpf[i], qtdMultasPorCpf[i]);
        }
    }

    float maiorValor = -1, menorValor = 1e9;
    int indiceMaior = -1, indiceMenor = -1;

    for (int i = 0; i < lp.total; i++) {
        if (qtdMultasPorCpf[i] > 0) {
            if (totalPorCpf[i] > maiorValor) {
                maiorValor = totalPorCpf[i];
                indiceMaior = i;
            }
            if (totalPorCpf[i] < menorValor) {
                menorValor = totalPorCpf[i];
                indiceMenor = i;
            }
        }
    }

    if (indiceMaior != -1 && indiceMenor != -1) {
        printf("\nMAIOR INFRATOR: %s, Total: R$ %.2f, Multas: %d\n", lp.proprietarios[indiceMaior].nomeCompleto, maiorValor, qtdMultasPorCpf[indiceMaior]);
        printf("MENOR INFRATOR: %s, Total: R$ %.2f, Multas: %d\n", lp.proprietarios[indiceMenor].nomeCompleto, menorValor, qtdMultasPorCpf[indiceMenor]);
    }
}

int main() {
    ListaVeiculos veiculos = carregarVeiculos("tabveiculos.txt");
    ListaProprietarios proprietarios = carregarProprietarios("tabproprietarios.txt");
    ListaMultas multas = carregarMultas("tabmultas.txt");

    gerarRelatorio(veiculos, proprietarios, multas);

    return 0;
}
