#include <stdlib.h>
#include <stdio.h>

int main(){
    int **p;

    p = malloc(10*sizeof(int *));

    for (int i = 0, i < 10, i++){
        p[i] = malloc(sizeof(int));
        *p[i] = i + 1;
    }
    return 0;
}



/*   Enunciado: Faça um vetor dinâmico que armazena inteiros dinâmicos. Depois, faça os vetores terem valores de 1 a 10 respectivamente. */
