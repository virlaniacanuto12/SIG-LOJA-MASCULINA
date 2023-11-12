typedef struct cliente Cliente;

struct cliente{
  char nomeCliente[51];
  char cpfCliente[13];
  char clienteDataNasc[9];
  char tel[12];
  char email[50];
  char estadoCivilCliente[21];
  char status; 
};
void menuCliente(void);
void escolhaMenuCliente(char);
void exibeCliente(Cliente* cliente);
void gravandoCliente(Cliente* cliente);
void lendoCliente(void);
Cliente* cadastrarCliente(void);
void atualizarCliente(void);
void excluirCliente(void);
//void leSenha(char*);
void verificarCliente(void);
void lerNomes(char*);






