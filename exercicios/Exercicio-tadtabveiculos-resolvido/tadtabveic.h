#ifndef ___I_FES_ED20242__

#define ___I_FES_ED20242__

typedef struct {
	char placa[10]; // privado
	char marca[10]; // privado
	char modelo[32]; // privado
	double preco; // privado
} t_veiculo; // nome é publico

typedef struct {
	t_veiculo veics[10]; // privado
	int tam; // privado
} tad_tabela; // PUBLICO, vc usar o nome tad_tabela pra declarar

// PUBLICO
tad_tabela load_tabela();
t_veiculo getVeiculo(tad_tabela t, int pos);
t_veiculo mais_caro(tad_tabela t);
t_veiculo mais_barato(tad_tabela t);
int len_tab(tad_tabela t);
void print_veic(t_veiculo v);
tad_tabela todos_da_marca(tad_tabela tab, char marca[32]);

#endif