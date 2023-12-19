typedef struct cliente Cliente;

struct cliente{
  char nomeCliente[51];
  char cpfCliente[13];
  char clienteDataNasc[12];
  char tel[12];
  char email[50];
  char estadoCivilCliente[21];
  char status;  
  Cliente* prox;
};

void menuCliente(void);
void escolhaMenuCliente(char);
void exibeCliente(Cliente* cliente);
void gravandoCliente(Cliente* cliente);
void lendoCliente(void);
void excluirCliente(void);
Cliente* cadastrarCliente(void);
void editarCliente(void);
void excluirCliente(void);

void verificarCliente(void);
void lerNomes(char*);
void relatorioCliente(void);






