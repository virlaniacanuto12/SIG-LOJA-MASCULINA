typedef struct vendedor Vendedor;

struct vendedor{
  char nomeVendedor[50];
  char cpfVendedor[13];
  char celVendedor[13];
  char dataNascimento[12];
  char estadoCivil[50];
  char naturalidade[50];
  char escolaridade[50];
  char status;
  int pontos;
};

Vendedor* cadastroVendedor(void);
void menuVendedor(void);
void pesquisarVendedor(void);
void excluirVendedor(void);
void atualizarVendedor(void);
void registroVendas(void);
void conquistas(void);
void escolhaMenuVendedor(char);  
void leNomes(char*);
void lecpfVendedor(char *cpf);
void leCel(char*);
void leDataNasc(char*);
void leEstadoCivil(char*);
void leEscolaridade(char*);
void gravandoVendedor(Vendedor *vendedor);
void exibeVendedor(Vendedor* vendedor);
void lendoDados(void);

