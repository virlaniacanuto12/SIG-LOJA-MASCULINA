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

