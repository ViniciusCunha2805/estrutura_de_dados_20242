/*
Problema 3: dos triângulos.
*/

#include <stdlib.h>
#include <stdio.h>

int formaTriangulo(int x, int y, int z) {
    if (x+y<z || x+z<y || y+z<x || x <= 0 || y <= 0 || z <= 0){
        return 0;
    }else{
        return 1;
    }
}

int main(){
    int x, y, z;
    printf("Digite os valores inteiros para x, y e z: \n");
    scanf("%d %d %d", &x, &y, &z);
    int resultado = formaTriangulo(x, y, z);
    if(resultado == 1){
        printf("X, Y e Z formam um triangulo");
    }else{
        printf("X, Y e Z NAO formam um triangulo");
    }
}
