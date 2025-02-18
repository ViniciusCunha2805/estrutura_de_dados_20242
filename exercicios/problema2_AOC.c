/*
Problema 2: dos carros.
*/

#include <stdlib.h>
#include <stdio.h>


int main () {
    int kmx, vx, kmy, vy;
    int maior, menor, vmenor, vmaior;
    char carroMaior, carroMenor;
    printf("Digite o valor inteiro para kmx: \n");
    scanf("%d", &kmx);
    printf("Digite o valor inteiro para vx: \n");
    scanf("%d", &vx);
    printf("Digite o valor inteiro para kmy: \n");
    scanf("%d", &kmy);
    printf("Digite o valor inteiro para vy: \n");
    scanf("%d", &vy);
    int hora = 0;
    printf("kmx = %d | vx = %d | kmy = %d | vy = %d \n", kmx, vx, kmy, vy);
    if(kmx > kmy){
        maior = kmx; 
        menor = kmy;
        vmaior = vx;
        vmenor = vy;
        carroMaior = 'x';
        carroMenor = 'y';
    } else {
        maior = kmy;
        menor = kmx;
        vmaior = vy;
        vmenor = vx;
        carroMaior = 'y';
        carroMenor = 'x';
    }
    while(menor < maior){
        printf("Hora %d: Carro %c em %d e Carro %c em %d \n", hora, carroMenor, menor, carroMaior, maior);
        menor += vmenor;
        maior += vmaior;
        hora++; 
    }
    printf("Hora %d: Carro %c em %d e Carro %c em %d \n", hora, carroMenor, menor, carroMaior, maior);
    printf("Carro %c ultrapassou o carro %c na hora %d apos o KM %d \n", carroMenor, carroMaior, hora, maior);



    return 0;
}
