#include <stdio.h>

typedef struct{
    int real;
    int imaginario;
}t_complexo;

t_complexo soma_complexo(t_complexo x, t_complexo y){
    t_complexo aux;
    aux.real = x.real + y.real;
    aux.imaginario = x.imaginario + y.imaginario;
    return aux;
} 


int main(){
    t_complexo a = {5, 7};
    t_complexo b = {3, -12};
    t_complexo soma;

    soma = soma_complexo(a,b);

    printf("soma.real: %d\n", soma.real);
    printf("soma.imaginario: %d\n", soma.imaginario);



    return 0;
}
