typedef struct caixa Caixa;

struct caixa{
  char nomeVendedor[51];
  char cpfVendedor[13];
  char codBarras[9];
  char tel[12];
  char email[50];
  char estadoCivilCliente[21];
  char id; 
};

void menuCaixa(void);
void realizarTransacao(void);
void pesquisarTransacao(void);
void cancelarTransacao(void);



void pagamentoCaixa(void);
void leMetodoPag(void); 
int exibeMetodoPag(char);
float leValor(void);
void exibirPix(void);
int condicoesPixEspecie(void);
int condicoesCartao(void); 