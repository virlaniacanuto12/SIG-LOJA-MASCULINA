struct vendedor{
  char nomeVendedor[51];
  char cpfVendedor[13];
  char celVendedor[13];
  char dataNascimento[12];
  char estadoCivil[50];
  char naturalidade[21];
  char escolaridade[31];
};

void cadastroVendedor(void); 
void menuVendedor(void);
void atualizarVendedor(void);
void excluirVendedor(void);
void registroVendas(void);
void conquistas(void);
void escolhaMenuVendedor(char);  
void leNomes(char*);
void leCpf(char*);
void leCel(char*);
void leDataNasc(char*);
void leEstadoCivil(char*);
void leEscolaridade(char*);