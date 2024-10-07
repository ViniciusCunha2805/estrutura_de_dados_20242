#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
        int x; 
        int y;
        }t_ponto;

struct t_ponto {
    int x; 
    int y;
};

double distancia( t_ponto A,  t_ponto B){
    double dist = sqrt(pow((A.x - B.x), 2) + pow((A.y - B.y), 2));
    return dist;
}

int main(){
    t_ponto P, Q;
    int val;
    double d;

    printf("Entre com o x do ponto P: ");
    scanf("%d", &val);
    P.x = val;

    printf("Entre com o y do ponto P: ");
    scanf("%d", &val);
    P.y = val;

    printf("Entre com o x do ponto Q: ");
    scanf("%d", &val);
    Q.x = val;

    printf("Entre com o y do ponto Q: ");
    scanf("%d", &val);
    Q.y = val;

    d = distancia(P, Q);

    printf("Valor da distância entre P e Q igual a %.2lf\n",d);



    return 0;
}
