typedef struct caixa Caixa;

struct caixa{
  char nomeVendedor[51];
  char cpfVendedor[13];
  char codBarras[9];
  char tel[12];
  char email[50];
  char estadoCivilCliente[21];
  char dataCaixa[12];
  int idTransacao; 
  char statusTransacao; 
};

void menuCaixa(void);
Caixa* realizarTransacao(void);
void pesquisarTransacao(void); 
void cancelarTransacao(void);
void gravandoTransacao(Caixa *caixa);


void pagamentoCaixa(void);
void leMetodoPag(void); 
void exibirPix(void);

int exibeMetodoPag(char);
int condicoesPixEspecie(void);
int condicoesCartao(void); 

float leValor(void);
