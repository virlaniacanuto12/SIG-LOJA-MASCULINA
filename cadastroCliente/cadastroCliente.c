#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h> 
#include "cadastroCliente.h"
#include "../auxFuncoes/auxFuncoes.h"


void lerNomes(char *nome){
  printf("Nome:");
  fgets(nome, 51, stdin);
  //validarNome(nome);
   if (nome[strlen(nome) - 1] == '\n') {
    nome[strlen(nome) - 1] = '\0';
  }
}

void lecpfCliente(char *cpf){
  printf("CPF:");
  fgets(cpf, 13, stdin);
  if (cpf[strlen(cpf) - 1] == '\n') {
    cpf[strlen(cpf) - 1] = '\0';
  }
}

void leclienteDataNasc(char *dataNasc){
  printf("Data de nascimento:");
  fgets(dataNasc, 9, stdin);
   if (dataNasc[strlen(dataNasc) - 1] == '\n') {
    dataNasc[strlen(dataNasc) - 1] = '\0';
  }
}

void leTel(char *tel){
  printf("Tel:");
  fgets(tel, 12, stdin);
}

void leEmail(char *email){
  printf("Email:");
  fgets(email, 50, stdin);
}

void leEstadoCivilCliente(char *estadoCivil){
  printf("Estado civil:");
  fgets(estadoCivil, 21, stdin);
}


void menuCliente(void){
    char charOpcao;
    do{
        system("clear||cls");
        printf("____________________________________________________\n");
        printf("                                                    \n");
        printf("- - - - - - Loja de Artigos Masculinos - - - - - - -\n");
        printf(" Developed by @virlaniacanuto12 -- since Aug, 2023  \n");
        printf("____________________________________________________\n");
        printf("                                                    \n");
        printf("- - - - - - - - - - SHOPMEN - - - - - - - - - - - - \n");
        printf("____________________________________________________\n");
        printf("                                                    \n");
        printf("                  MENU CLIENTE                      \n");
        printf("____________________________________________________\n");
        printf("                                                    \n");
        printf("             1 - Cadastrar cliente                  \n");
        printf("             2 - Atualizar cliente                  \n");
        printf("             3 - Excluir cliente                    \n");
        printf("             4 - Verificar cliente                  \n");
        printf("             0 - Voltar                             \n");
        printf("                                                    \n");
        printf("____________________________________________________\n");
        scanf("%c", &charOpcao);
        //getchar();
        escolhaMenuCliente(charOpcao);
    }while(charOpcao != '0');
}

Cliente* cadastrarCliente(void){
  Cliente *cliente;
  cliente = (Cliente *)malloc(sizeof(Cliente));
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("- - - - - - Loja de Artigos Masculinos - - - - - - -\n");
    printf(" Developed by @virlaniacanuto12 -- since Aug, 2023  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("  - - - - - - - - - - SHOPMEN - - - - - - - - - - - \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                  CADASTRAR CLIENTE                 \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    
    lerNomes(cliente->nomeCliente);

    lecpfCliente(cliente->cpfCliente);

    leclienteDataNasc(cliente->clienteDataNasc);

    leTel(cliente->tel);

    leEmail(cliente->email);

    leEstadoCivilCliente(cliente->estadoCivilCliente);

    cliente->status='A'; 
   
    printf("____________________________________________________\n");
    return cliente; 
}

void gravandoCliente(Cliente *cliente){
  FILE *fp;
  fp = fopen("arquivoCliente.bin","ab");

  if(fp == NULL ){
    printf("Erro na criação do arquivo!");
    getchar();
  }

  fwrite(cliente, sizeof(Cliente),1,fp);
  fclose(fp);
  free(cliente);
}

void exibeCliente(Cliente* cliente){
  char situacao[20];

  if((cliente == NULL) || (cliente->status == 'i')){
    printf("Cliente não encontrado!");
  } else{
    printf("Nome:%s\n", cliente->nomeCliente);
    printf("CPF:%s\n", cliente->cpfCliente);
    printf("Celular:%s\n", cliente->tel);
    printf("Email:%s\n", cliente->email);
    printf("Data de nascimento:%s\n", cliente->clienteDataNasc);
    printf("Estado Civil:%s\n", cliente->estadoCivilCliente);
    printf("Status:%c\n", cliente->status);
  }
  if (cliente->status == 'a'){
    strcpy(situacao, "Cadastro Ativo");
  } else {
    strcpy(situacao, "Cadastro Inativo");
  }
}

void lendoCliente(void){
  FILE *fp;
  Cliente* cliente;
  cliente = (Cliente*) malloc(sizeof(Cliente));
  fp = fopen("arquivoCliente.bin","rb");

  if (fp == NULL){
    printf("Erro na abertura do arquivo!\n");
    exit(1);
  }
  
  system("clear||cls");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("- - - - - - Loja de Artigos Masculinos - - - - - - -\n");
  printf(" Developed by @virlaniacanuto12 -- since Aug, 2023  \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("- - - - - - - - - - - SHOPMEN - - - - - - - - - - - \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("               CLIENTES CADASTRADOS                 \n");
  printf("____________________________________________________\n");

  while(fread(cliente, sizeof(Cliente), 1, fp)){
    exibeCliente(cliente);
    printf("\n");
  }
  
  fclose(fp);
  free(cliente);
  getchar();

}

void atualizarCliente(void){
    char charOpcao;
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("- - - - - - Loja de Artigos Masculinos - - - - - - -\n");
    printf(" Developed by @virlaniacanuto12 -- since Aug, 2023  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("  - - - - - - - - - - SHOPMEN - - - - - - - - - - - \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                  ATUALIZAR CLIENTE                 \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("        Informe o CPF do cliente que deseja         \n");
    printf("              atualizar o cartão:                   \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("              Email:                                \n");
    printf("              Tel:                                  \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
}

void excluirCliente(void){
    char charOpcao;
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("- - - - - - Loja de Artigos Masculinos - - - - - - -\n");
    printf(" Developed by @virlaniacanuto12 -- since Aug, 2023  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("  - - - - - - - - - - SHOPMEN - - - - - - - - - - - \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                  EXCLUIR CLIENTE                   \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("        Informe o CPF do cliente que deseja         \n");
    printf("                excluir o cartão:                   \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
}
/*A função verificar irá exibir os seguintes dados do cliente respectivo ao CPF:
data de vencimento, data de fechamento da fatura, limite e limite disponível.
*/
void verificarCliente(void){
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("- - - - - - Loja de Artigos Masculinos - - - - - - -\n");
    printf(" Developed by @virlaniacanuto12 -- since Aug, 2023  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("  - - - - - - - - - - SHOPMEN - - - - - - - - - - - \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                  VERIFICAR CLIENTE                 \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("        Informe o CPF do cliente que deseja         \n");
    printf("                verificar o cartão:                 \n");
    printf("____________________________________________________\n");
    getchar();
}

void escolhaMenuCliente(char escolha){
  Cliente *cliente;
    switch(escolha){
        case '1':
          cliente = cadastrarCliente();
          gravandoCliente(cliente);
          break;
        case '2':
            atualizarCliente();
          break;
        case '3':
            excluirCliente();
          break;
        case '4':
          getchar();
          lendoCliente();
            //verificarCliente();
          break;
        default:
            printf("------------------>Opção inválida!<-----------------\n");
    }
}