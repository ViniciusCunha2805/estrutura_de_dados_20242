#include <stdio.h>
#include "tadtabveic.h"

int main(){
	tad_tabela tab = load_tabela("dados-tabveic.txt","rt");
	tad_tabela so_ford;
	t_veiculo v;

	printf("Carro mais caro: \n");
	v = mais_caro(tab);
	print_veic(v);

	puts("\n");

	printf("Carro mais barato: \n");
	v = mais_barato(tab);
	print_veic(v);

	puts("");

	printf("\n\nTodos os veiculos da marca Toyota");
	so_ford = todos_da_marca(tab, "TOYOTA");

	for(int i=0; i < len_tab(so_ford); i++){
		print_veic(getVeiculo(so_ford, i));
	    printf("\n");
	}

	return 0;
}
