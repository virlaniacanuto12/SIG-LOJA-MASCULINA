typedef struct mercadoria Mercadoria;

struct mercadoria{
  char nomeFornecedor[51];
  char codBarras[13];
  char cnpj[13];
  char tamanho[12];
  char cor[50];
  char preco[21];
};

void opcaoMenu(char);
void leCnpj(char*);
void leNomeFornecedor(char*);
void leCodBarras(char*);
void leTamanho(char*);
void leCor(char*);
void lePreco(char*);
void menuMercadoria(void);
void cadastroMercadoria(void);
void editarMercadoria(void);
void excluirMercadoria(void);
void pesquisarMercadoria(void);
void escolhaMenuMercadoria(char);