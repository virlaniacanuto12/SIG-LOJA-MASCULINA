typedef struct caixa Caixa;

struct caixa{
  char cpfCliente[13];
  char cpfVendedor[13];
  char codBarras[9];
  int quantidade;
  float valor; 
  int id; 
  char status;
  char dataHora[40]; 
};

void leCpfCliente(char *cpf);
void leCpfVendedor(char *cpf);
void extrairMes(char *dataHora, char *mes);

void menuCaixa(void);
Caixa* realizarTransacao(void);
void pesquisarTransacao(void); 
void cancelarTransacao(void);
void exibeTransacao(Caixa *caixa);
void gravandoTransacao(Caixa *caixa);

void pagamentoCaixa(void);
void escolhaCaixa(char);
char leMetodoPag(void); 
void exibirPix(void);
int criar_id(void);

void exibeMetodoPag(char, float);
void condicoesPixEspecie(float);
void condicoesCartao(float); 
float resumoDaCompraCartao(int par, float valor);

