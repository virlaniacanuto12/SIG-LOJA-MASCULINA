typedef struct caixa Caixa;

struct caixa{
  char cpfCliente[13];
  char cpfVendedor[13];
  char codBarras[9];
  char dataCaixa[12];
  int quantidade;
  int id; 
  char status; 
};

void menuCaixa(void);
Caixa* realizarTransacao(void);
void pesquisarTransacao(void); 
void cancelarTransacao(void);
void gravandoTransacao(Caixa *caixa);


void pagamentoCaixa(void);
void leMetodoPag(void); 
void exibirPix(void);
int criar_id(void);

int exibeMetodoPag(char);
void condicoesPixEspecie(void);
float condicoesCartao(void); 
float resumoDaCompraCartao(int par, float valor);

