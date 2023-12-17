typedef struct vendedores Vendedores;

struct vendedores{
  char nomeVendedor[50];
  char cpfVendedor[13];
  char celVendedor[13];
  char dataNascimento[12];
  char estadoCivil[50];
  char naturalidade[50];
  char escolaridade[50];
  char status;
};

//Funções relatórios vendedores
void destaquesMes(void);
void menuRelatorio(void); 
void relatorioVendedores(void);
void vendedoresAtivos(void);
void vendedoresOrdem(void);
void vendedoresNaturalidade(void);

void mercadoriaTam(void);
void mercadoriaCor(void);
void relatorioMercadoria(void);


void saldoVendasMes(void);
void saldoVendasDia(void);

void escolhaMenuRelatorio(char);
void menuRelatorioVendedor(char);
