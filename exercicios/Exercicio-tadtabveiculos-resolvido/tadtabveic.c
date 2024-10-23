#include "tadtabveic.h"
#include "string.h"
#include <stdlib.h>
#include <stdio.h>

tad_tabela new_tabela(){
	tad_tabela aux;
	aux.tam = 5;
	char entrada[64];
	
	for(int i=0; i < aux.tam; i++){
		fgets(entrada,30,stdin);
		entrada[strlen(entrada)-1] = '\0';
		strcpy(aux.veics[i].placa, entrada);

		fgets(entrada,30,stdin);
		entrada[strlen(entrada)-1] = '\0';
		strcpy(aux.veics[i].marca, entrada);

		fgets(entrada,30,stdin);
		entrada[strlen(entrada)-1] = '\0';
		strcpy(aux.veics[i].modelo, entrada);

		fgets(entrada,30,stdin);
		entrada[strlen(entrada)-1] = '\0';
		aux.veics[i].preco = atof(entrada);		
	}

	return aux;
}

int len_tab(tad_tabela t){
	return t.tam;
}

t_veiculo getVeiculo(tad_tabela t, int pos){
	return t.veics[pos];
}

t_veiculo mais_caro(tad_tabela t){
	t_veiculo caro;
	t_veiculo aux;
	caro = t.veics[0];

	for(int i=1; i < t.tam; i++){
		aux = t.veics[i];
		if(aux.preco > caro.preco)
			caro = aux;
	}

	return caro;
}

t_veiculo mais_barato(tad_tabela t){
	t_veiculo barato;
	t_veiculo aux;
	caro = t.veics[0];

	for(int i=1; i < t.tam; i++){
		aux = t.veics[i];
		if(aux.preco < barato.preco)
			barato = aux;
	}

	return barato;
}

void print_veic(t_veiculo v){
	printf("%s, %s, %s, %.2lf", v.placa, v.marca, v.modelo, v.preco);
}

tad_tabela todos_da_marca(tad_tabela tab, char marca[32]){
	tad_tabela aux;
	aux.tam = 0;

	for(int i=0; i < len_tab(tab); i++){
		if(strcmp(tab.veics[i].marca,marca) == 0){
			aux.veics[aux.tam++] = tab.veics[i];
		}
	}
	return aux;
}

