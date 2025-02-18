/*
Ler 3 valores (A, B e C) representando as medidas dos lados de um triângulo
e escrever se formam ou não um triângulo e qual tipo de triângulo é.
OBS: para formar um triângulo, o valor de cada lado deve ser menor que 
a soma dos outros 2 lados.
*/

#include <stdlib.h>
#include <stdio.h>

int main () {
    int a, b, c;
    printf("Digite os valores inteiros para a, b e c: \n");
    scanf("%d %d %d", &a, &b, &c);
    
    if (a + b < c || a + c < b || b + c < a || a <= 0 || b <= 0 || c <= 0) {
        printf("NAO E TRIANGULO");
    } else if (a == b && a == c) {
        printf("EQUILATERO");
    } else if ((a == b && a != c) || (b == c && b != a) || (c == a && c != b)) {
        printf("ISOCELES");
    } else {
        printf("ESCALENO");
    }
    
    return 0;
}