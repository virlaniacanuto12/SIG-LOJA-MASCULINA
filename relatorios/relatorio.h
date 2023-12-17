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
void menuRelatorio(void); 
void relatorioVendedores(void);
void vendedoresAtivos(void);
void vendedoresNaturalidade(void);
void menuRelatorioVendedor(char);

void mercadoriaTam(void);
void mercadoriaCor(void);
void relatorioMercadoria(void);
void menuRelatorioMercadoria(char escolha);

void relatorioVendas(void);
void menuRelatorioCaixa(char escolha);
void vendaMes(void);

void saldoVendasMes(void);
void saldoVendasDia(void);

void escolhaMenuRelatorio(char);
