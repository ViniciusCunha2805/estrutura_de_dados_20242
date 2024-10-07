#include <stdio.h>
#include <string.h>

typedef struct{int dia; int mes; int ano;} t_data;

typedef struct {
    char titulo[10];
    char nome[10];
    char editora[10];
    t_data ano_pub;
}t_livro;

int main(){
    t_livro livro;

    strcpy(livro.titulo,"Cafe");
    strcpy(livro.nome,"Jose");
    strcpy(livro.editora,"Ler");

    livro.ano_pub.dia = 7;
    livro.ano_pub.mes = 10;
    livro.ano_pub.ano = 2024;

    puts("LIVRO");
    printf("Titulo: %s\n", livro.titulo);
    printf("Nome: %s\n", livro.nome);
    printf("Titulo: %s\n", livro.editora);
    printf("%d/%d/%d\n", livro.ano_pub.dia, livro.ano_pub.mes, livro.ano_pub.ano);

    return 0;
}
