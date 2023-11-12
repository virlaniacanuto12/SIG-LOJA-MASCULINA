#include <stdio.h> 
#include <stdio_ext.h> 
#include <stdlib.h>
#include <string.h>
#include "cadastroVendedor.h" 
#include "../auxFuncoes/auxFuncoes.h"

void leCpf(char *cpf) {
  printf("CPF:");
  fgets(cpf, 13, stdin);
  // Remove the newline character
  if (cpf[strlen(cpf) - 1] == '\n') {
    cpf[strlen(cpf) - 1] = '\0';
  }
}

void leCel(char *cel) {
  printf("Tel:");
  fgets(cel, 13, stdin);
  // Remove the newline character
  if (cel[strlen(cel) - 1] == '\n') {
    cel[strlen(cel) - 1] = '\0';
  }
}

void leNomes(char *nome) {
  printf("Nome:");
  fgets(nome, 50, stdin);
  // Remove the newline character
  if (nome[strlen(nome) - 1] == '\n') {
    nome[strlen(nome) - 1] = '\0';
  }
}

void leDataNasc(char *dataNasc) {
  printf("Data de nascimento(xx/xx/xxxx):");
  fgets(dataNasc, 12, stdin);
  // Remove the newline character
  if (dataNasc[strlen(dataNasc) - 1] == '\n') {
    dataNasc[strlen(dataNasc) - 1] = '\0';
  }
}

void leEstadoCivil(char *estadoCivil) {
  printf("Estado civil:");
  fgets(estadoCivil, 50, stdin);
  // Remove the newline character
  if (estadoCivil[strlen(estadoCivil) - 1] == '\n') {
    estadoCivil[strlen(estadoCivil) - 1] = '\0';
  }
}

void leEscolaridade(char *escolaridade) {
  printf("Escolaridade:");
  fgets(escolaridade, 50, stdin);
  // Remove the newline character
  if (escolaridade[strlen(escolaridade) - 1] == '\n') {
    escolaridade[strlen(escolaridade) - 1] = '\0';
  }
}

void leNaturalidade(char *naturalidade) {
  printf("Naturalidade:");
  fgets(naturalidade, 50, stdin);
  // Remove the newline character
  if (naturalidade[strlen(naturalidade) - 1] == '\n') {
    naturalidade[strlen(naturalidade) - 1] = '\0';
  }
}


void escolhaMenuVendedor(char escolha){
    Vendedor *vendedor;
    switch(escolha){
        case '1':
          vendedor = cadastroVendedor();
          gravandoVendedor(vendedor);
          break;
        case '2':
          getchar();
          lendoDados();
          break;
        case '3':
          atualizarVendedor();
          getchar();
          break;
        case '4':
          getchar();
          excluirVendedor();
          break;
        case '5':
          conquistas();
          break;
        default:
            printf("------------------>Opção inválida!<-----------------\n");
    }
}

Vendedor* cadastroVendedor(void){
  Vendedor *vendedor;
  vendedor = (Vendedor *)malloc(sizeof(Vendedor));
  
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
  printf("                CADASTRAR VENDEDOR                  \n");
  printf("                                                    \n");
  printf("               Digite (0) Para Voltar               \n");
  printf("____________________________________________________\n");
 // scanf("%c", &charOpcao);
  
  leNomes(vendedor->nomeVendedor);

  leCel(vendedor->celVendedor);

  leCpf(vendedor->cpfVendedor);

  leDataNasc(vendedor->dataNascimento);
  
  leEstadoCivil(vendedor->estadoCivil);

  leNaturalidade(vendedor->naturalidade);

  leEscolaridade(vendedor->escolaridade);

  vendedor->status='A';
  return vendedor;
}

void gravandoVendedor(Vendedor *vendedor) {
  FILE *fp;
  fp = fopen("arquivoVendedor.bin", "ab");

  if (fp == NULL) {
    printf("Erro na criação do arquivo\n!");
    getchar(); //exit(1);
  }
  fwrite(vendedor, sizeof(Vendedor), 1, fp);
  fclose(fp);
  free(vendedor);
}


void exibeVendedor(Vendedor* vendedor) {
  char situacao[20];
  if ((vendedor == NULL) || (vendedor->status == 'x')) {
    printf("Vendedor não encontrado\n");
  } else {
    printf("Nome:%s\n", vendedor->nomeVendedor);
    printf("CPF:%s\n", vendedor->cpfVendedor);
    printf("Celular:%s\n", vendedor->celVendedor);
    printf("Data de nascimento:%s\n", vendedor->dataNascimento);
    printf("Estado Civil:%s\n", vendedor->estadoCivil);
    printf("Naturalidade:%s\n", vendedor->naturalidade);
    printf("Escolaridade:%s\n", vendedor->escolaridade);
    printf("Status:%c\n", vendedor->status);
  }
  if (vendedor->status == 'a') {
    strcpy(situacao,"Cadastro Ativo");
  } else {
    strcpy(situacao,"Cadastro Inativo");
  }
}

void lendoDados(void){
  FILE *fp;
  Vendedor* vendedor;
  vendedor = (Vendedor*) malloc(sizeof(Vendedor));
  fp = fopen("arquivoVendedor.bin","rb");

  if (fp == NULL){
    printf("Erro na abertura do arquivo\n");
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
  printf("               USUÁRIOS CADASTRADOS                 \n");
  printf("____________________________________________________\n");

  while(fread(vendedor, sizeof(Vendedor), 1, fp)){
    exibeVendedor(vendedor);
    printf("\n");
  }
  
  fclose(fp);
  free(vendedor);
  getchar();
}

void menuVendedor(void){
    char charOpcao = '7';
    do{
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
        printf("                   MENU VENDEDOR                    \n");
        printf("____________________________________________________\n");
        printf("                                                    \n");
        printf("             1 - Cadastrar vendedor                 \n");
        printf("             2 - Pesquisar vendedor                 \n");
        printf("             3 - Editar vendedor                    \n");
        printf("             4 - Excluir vendedor                   \n");
        printf("             5 - Registro vendas                    \n");
        printf("             6 - Conquistas                         \n");
        printf("             0 - Voltar                             \n");
        printf("____________________________________________________\n");
        scanf("%c", &charOpcao);
        escolhaMenuVendedor(charOpcao);
        //getchar();
    }while(charOpcao != '0');
}

void atualizarVendedor(void){
    char cpf[13];
    Vendedor* vendedor = (Vendedor*) malloc(sizeof(Vendedor));
    FILE* fp;
    int achei = 0;
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("- - - - - - Loja de Artigos Masculinos - - - - - - -\n");
    printf(" Developed by @virlaniacanuto12 -- since Aug, 2023  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf(" - - - - - - - - - - SHOPMEN - - - - - - - - - - -  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                  EDITAR VENDEDOR                   \n");
    printf("                                                    \n"); 
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("  Informe o cpf do vendedor que deseja atualizar:   \n");
    printf("____________________________________________________\n");
    scanf(" %[0-9]", cpf);
    //leCpf(cpf);
    getchar();
    fp = fopen("arquivoVendedor.bin", "r+b");
    if (fp == NULL) {
      printf("\t\t Erro na abertura do arquivo!\n");
      getchar();
    }else{
      while (fread(vendedor, sizeof(Vendedor), 1, fp) == 1) {
        if(strcmp(vendedor->cpfVendedor, cpf) == 0) {
          printf("\n");
          printf("                  Usuário Encontrado                \n");
          printf("                                                    \n");
          printf("           Informe os dados para atualizar:         \n");
      
          leCel(vendedor->celVendedor);

          leEstadoCivil(vendedor->estadoCivil);
      
          leEscolaridade(vendedor->escolaridade);

          vendedor-> status = 'a';
          fseek(fp, (-1)*sizeof(Vendedor), SEEK_CUR);
          //fseek(fp, -sizeof(Vendedor), SEEK_CUR);
          fwrite(vendedor, sizeof(Vendedor), 1, fp);
          achei = 1;
          break;
        }
      }
    }
    if(!achei){
      printf("\n");
      printf("\t\t\t CPF não encontrado!\n");
    } else{
      printf("\n");
      printf("\t\t\t Usuário atualizado com sucesso!\n");
    }
    getchar();
    fclose(fp);
    free(vendedor);
}   


void excluirVendedor(void){
    char cpf[13];
    Vendedor* vendedor = (Vendedor*) malloc(sizeof(Vendedor));
    FILE* fp;
    int achei = 0;
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("- - - - - - Loja de Artigos Masculinos - - - - - - -\n");
    printf(" Developed by @virlaniacanuto12 -- since Aug, 2023  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf(" - - - - - - - - - - SHOPMEN - - - - - - - - - - -  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                 EXCLUIR VENDEDOR                   \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("    Informe o CPF do vendedor que deseja excluir:   \n");
    printf("____________________________________________________\n");
    //tinha erro aqui
    fgets(cpf, 12, stdin);
    getchar();
    fp = fopen("arquivoVendedor.bin", "r+b");
    
    if (fp == NULL) {
      printf("Erro na abertura do arquivo!\n");
      printf("Tecle <ENTER> para voltar...\n");
      getchar();
    } else {
      while (fread(vendedor, sizeof(Vendedor), 1, fp) == 1) {
        if(strcmp(vendedor->cpfVendedor, cpf) == 0) {
          printf("Usuário Encontrado\n");
          printf("\n");
          vendedor->status = 'i';
          fseek(fp, -sizeof(Vendedor), SEEK_CUR);
          fwrite(vendedor, sizeof(Vendedor), 1, fp);
          achei = 1;
          break;
        }
      }
    }
    if (!achei) {
        printf("\n");
        printf("\t\tUsuário não encontrado!\n");
    } else {
        printf("\n");
        printf("\t\tUsuário excluído com sucesso!\n");
    }

  fclose(fp);
  free(vendedor);
  getchar();
}

/*A função registro de vendas irá exibir as vendas que o vendedor informado realizou no mês*/
void registroVendas(void){
    char cpfVendedor;
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("- - - - - - Loja de Artigos Masculinos - - - - - - -\n");
    printf(" Developed by @virlaniacanuto12 -- since Aug, 2023  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf(" - - - - - - - - - - SHOPMEN - - - - - - - - - - -  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                REGISTRO DE VENDAS                  \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("        Informe o CPF do vendedor que deseja        \n"); 
    printf("          verificar o registro de vendas:           \n");
    printf("____________________________________________________\n");
    scanf("%c", &cpfVendedor);
    getchar();
}
/*A função conquista irá exibir as conquistas que aquele vendedor ja possui.
Vai existir o broche de ouro, prata e bronze que vai variar de acordo com o valor vendido pelo vendedor*/
void conquistas(void){
    char cpfVendedor;
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("- - - - - - Loja de Artigos Masculinos - - - - - - -\n");
    printf(" Developed by @virlaniacanuto12 -- since Aug, 2023  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf(" - - - - - - - - - -  SHOPMEN - - - - - - - - - - - \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                    CONQUISTAS                      \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("        Informe o CPF do vendedor que deseja        \n"); 
    printf("            verificar as conquistas:                \n");
    printf("____________________________________________________\n");
    scanf("%c", &cpfVendedor);
    getchar();
}
