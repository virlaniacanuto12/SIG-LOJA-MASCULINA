#include <stdio.h> 
#include <stdlib.h>
#include "cadastroVendedor.h" 
#include "../auxFuncoes/auxFuncoes.h"


void leCpf(char *cpf){
  printf("CPF:");
  fgets(cpf, sizeof(cpf), stdin);
}

void leCel(char *cel){
  printf("Tel:");
  fgets(cel, sizeof(cel), stdin);
}

void leNomes(char *nome){
  printf("Nome:");
  fgets(nome, sizeof(nome), stdin);
  //validarNome(nome);
}

void leDataNasc(char *dataNasc){
  printf("Data de nascimento(xx/xx/xxxx):");
  fgets(dataNasc, sizeof(dataNasc), stdin);
}

void leEstadoCivil(char *estadoCivil){
  printf("Estado civil:");
  fgets(estadoCivil, sizeof(estadoCivil), stdin);
}

void leNaturalidade(char *naturalidade){
  printf("Naturalidade:");
  fgets(naturalidade, sizeof(naturalidade), stdin);
}

void leEscolaridade(char *escolaridade){
  printf("Escolaridade:");
  fgets(escolaridade, sizeof(escolaridade), stdin);
}


void escolhaMenuVendedor(char escolha){
    switch(escolha){
        case '1':
            cadastroVendedor();
        break;
        case '2':
            atualizarVendedor();
        break;
        case '3':
            excluirVendedor();
        break;
        case '4':
            registroVendas();
        break;
        case '5':
            conquistas();
        break;
        default:
            printf("------------------>Opção inválida!<-----------------\n");
    }
}

Vendedor* cadastrandoVendedor(void){
  Vendedor *vendedor;
  vendedor = (Vendedor *)malloc(sizeof(Vendedor));
  leNomes(vendedor->nomeVendedor);
  limparBufferEntrada();
  // fflush(stdin);

  leCel(vendedor->celVendedor);
  limparBufferEntrada();
  // fflush(stdin);

  leCpf(vendedor->cpfVendedor);
  limparBufferEntrada();
  // fflush(stdin);

  leDataNasc(vendedor->dataNascimento);
  limparBufferEntrada();
  // fflush(stdin);

  leEstadoCivil(vendedor->estadoCivil);
  limparBufferEntrada();
  // fflush(stdin);

  leNaturalidade(vendedor->naturalidade);
  limparBufferEntrada();
  // fflush(stdin);

  leEscolaridade(vendedor->escolaridade);
  return vendedor;
}

int gravandoVendedor(void) {
  //limparBufferEntrada();
  FILE *fp;
  Vendedor *novoVendedor;
  fp = fopen("arquivo.bin", "ab");

  if (fp == NULL) {
    printf("Erro na criacao do arquivo\n!");
    exit(1);
  }
  novoVendedor = cadastrandoVendedor();
  fwrite(novoVendedor, sizeof(Vendedor), 1, fp);
  fclose(fp);
  free(novoVendedor);
  return 0;
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
        printf("             2 - Atualizar vendedor                 \n");
        printf("             3 - Excluir vendedor                   \n");
        printf("             4 - Registro vendas                    \n");
        printf("             5 - Conquistas                         \n");
        printf("             0 - Voltar                             \n");
        printf("____________________________________________________\n");
        scanf("%c", &charOpcao);
        escolhaMenuVendedor(charOpcao);
        //getchar();
    }while(charOpcao != '0');
}

void cadastroVendedor(void){
    //Vendedor* vendedor;
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
    printf("                CADASTRAR VENDEDOR                  \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    gravandoVendedor();
    getchar();
    scanf("%c", &charOpcao);
}

void atualizarVendedor(void){
    char charOpcao;
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
    printf("                ATUALIZAR VENDEDOR                  \n");
    printf("                                                    \n"); 
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("           Informe os dados para atualizar:         \n");
    printf("                                                    \n");
    printf("           Estado civil                             \n");
    printf("           Naturalidade                             \n");
    printf("           Escolaridade                             \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
}

void excluirVendedor(void){
    char charOpcao;
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
    scanf("%c", &charOpcao);
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
