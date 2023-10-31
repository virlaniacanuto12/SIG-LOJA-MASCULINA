#include <stdio.h> 
#include <stdlib.h>
#include "cadastroMercadoria.h"
#include "../auxFuncoes/auxFuncoes.h"

void leCnpj(char *cnpj){
  printf("CNPJ do fornecedor:");
  fgets(cnpj, sizeof(cnpj), stdin);
}

void leNomeFornecedor(char *nomeFornecedor){
  printf("Nome do Fornecedor:");
  fgets(nomeFornecedor, sizeof(nomeFornecedor), stdin);
  //validarNome(nome);
}

void leCodBarras(char *codBarras){
  printf("Código de barras:");
  fgets(codBarras, sizeof(codBarras), stdin);
}

void leTamanho(char *tamanho){
  printf("Tamanho:");
  fgets(tamanho, sizeof(tamanho), stdin);
}

void leCor(char *cor){
  printf("Cor:");
  fgets(cor, sizeof(cor), stdin);
}

void lePreco(char *preco){
  printf("Preço:");
  fgets(preco, sizeof(preco), stdin);
}

Mercadoria* cadastrandoMercadoria(void){
  Mercadoria *mercadoria;
  mercadoria = (Mercadoria *)malloc(sizeof(Mercadoria));
  leNomes(mercadoria->nomeFornecedor);
  limparBufferEntrada();
  // fflush(stdin);

  leCodBarras(mercadoria->codBarras);
  limparBufferEntrada();
  // fflush(stdin);

  leTamanho(mercadoria->tamanho);
  limparBufferEntrada();
  // fflush(stdin);

  leCor(mercadoria->cor);
  limparBufferEntrada();
  // fflush(stdin);

  lePreco(mercadoria->preco);
  limparBufferEntrada();
  // fflush(stdin);

  return mercadoria;
}

int gravandoMercadoria(void) {
  //limparBufferEntrada();
  FILE *fp;
  Mercadoria *mercadoria;
  fp = fopen("arquivoMercadoria.bin", "ab");

  if (fp == NULL) {
    printf("Erro na criacao do arquivo\n!");
    exit(1);
  }
  mercadoria = cadastrandoMercadoria();
  fwrite(mercadoria, sizeof(mercadoria), 1, fp);
  fclose(fp);
  free(mercadoria);
  return 0;
}

void escolhaMenuMercadoria(char escolha){
    switch(escolha){
        case '1':
            cadastroMercadoria();
        break;
        case '2':
            editarMercadoria();
        break;
        case '3':
            excluirMercadoria();
        break;
        case '4':
            pesquisarMercadoria();
        break;
        default:
            printf("------------------>Opção inválida!<-----------------\n");
    }
}

void menuMercadoria(void){
    char charOpcao;
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
        printf("                  MENU MERCADORIA                   \n");
        printf("____________________________________________________\n");
        printf("                                                    \n");
        printf("             1 - Cadastrar mercadoria               \n");
        printf("             2 - Editar mercadoria                  \n");
        printf("             3 - Excluir mercadoria                 \n");
        printf("             4 - Pesquisar mercadoria               \n");
        printf("             0 - Voltar                             \n");
        printf("                                                    \n");
        printf("____________________________________________________\n");
        scanf("%c", &charOpcao);
        escolhaMenuMercadoria(charOpcao);
    }while(charOpcao!='0');
}
/*Sobre o código do lote: será 8 números onde os 4 primeiros se refere ao lote
e os 4 restante sobre a peça em específico.
*/
void cadastroMercadoria(void){
    char charOpcao;
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
    printf("                CADASTRAR MERCADORIA                \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    gravandoMercadoria();
    scanf("%c", &charOpcao);
    getchar();
}

void editarMercadoria(void){
    char charOpcao;
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
    printf("                  EDITAR MERCADORIA                 \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             Tipo da peça:                          \n");
    printf("             Cód de barras:                         \n");
    printf("             Quantidade:                            \n");
    printf("             Tamanho:                               \n");
    printf("             Cor:                                   \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
}

void excluirMercadoria(void){
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
    printf("                 EXCLUIR MERCADORIA                |\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          Digite o cód de barras(12 dígitos):       \n");
    printf("          Para voltar (0):                          \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
}
/*A função pesquisar irá detalhar as informações básicas(quantidade,) do LOTE 
que o usuário passar e as informações específicas do produto(cor e tamanho)*/

void pesquisarMercadoria(void){
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
    printf("                PESQUISAR MERCADORIA                \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("         Informe cód de barras(12 dígitos):         \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
}