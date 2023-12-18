#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "cadastroMercadoria.h"
#include "../auxFuncoes/auxFuncoes.h"

void leCnpj(char *cnpj)
{
  printf("CNPJ do fornecedor:");
  fgets(cnpj, 13, stdin);
  cnpj[strcspn(cnpj, "\n")] = '\0';
}

void leNomeFornecedor(char *nomeFornecedor)
{
  printf("Nome do Fornecedor:");
  fgets(nomeFornecedor, 51, stdin);
  nomeFornecedor[strcspn(nomeFornecedor, "\n")] = '\0';
}

void leCodBarras(char *codBarras)
{
  printf("Código de barras:");
  fgets(codBarras, 13, stdin);
  codBarras[strcspn(codBarras, "\n")] = '\0';
  // if (codBarras[strlen(codBarras) - 1] == '\n')
  // {
  //   codBarras[strlen(codBarras) - 1] = '\0';
  // }
}

void leQuantidade(int *quantidade)
{
  printf("Quantidade:");
  scanf(" %d", quantidade);
  getchar();
}

void leTamanho(char *tamanho)
{
  printf("Tamanho:");
  fgets(tamanho, 12, stdin);
  tamanho[strcspn(tamanho, "\n")] = '\0';
}

void leCor(char *cor)
{
  printf("Cor:");
  fgets(cor, 50, stdin);
  cor[strcspn(cor, "\n")] = '\0';
}

void lePreco(float *preco)
{
  printf("Preço:");
  scanf(" %2.f", preco);
}

void gravandoMercadoria(Mercadoria *mercadoria)
{
  FILE *fp;
  fp = fopen("arquivoMercadoria.bin", "ab");

  if (fp == NULL)
  {
    printf("Erro na criacao do arquivo\n!");
    getchar();
  }

  fwrite(mercadoria, sizeof(Mercadoria), 1, fp);
  fclose(fp);
  free(mercadoria);
}

void exibeMercadoria(Mercadoria *mercadoria)
{
  char situacao[20];

  if ((mercadoria == NULL) || (mercadoria->status == 'i'))
  {
    printf("Vendedor não encontrado\n");
  }
  else
  {
    printf("Cod de barras:%s\n", mercadoria->codBarras);
    printf("Nome do fornecedor:%s\n", mercadoria->nomeFornecedor);
    printf("CNPJ:%s\n", mercadoria->cnpj);
    printf("Tamanho:%s\n", mercadoria->tamanho);
    printf("Quantidade:%d\n", mercadoria->quantidade);
    printf("Cor:%s\n", mercadoria->cor);
    printf("Preço:%2.f\n", mercadoria->preco);
  }
  if (mercadoria->status == 'A')
  {
    strcpy(situacao, "Cadastro Ativo");
  }
  else
  {
    strcpy(situacao, "Cadastro Inativo");
  }
}

void escolhaMenuMercadoria(char escolha)
{
  Mercadoria *mercadoria;
  switch (escolha)
  {
  case '1':
    mercadoria = cadastroMercadoria();
    gravandoMercadoria(mercadoria);
    exibeMercadoria(mercadoria);
    break;
  case '2':
    editarMercadoria();
    break;
  case '3':
    excluirMercadoria();
    break;
  case '4':
    getchar();
    pesquisarMercadoria();
    break;
  default:
    printf("------------------>Opção inválida!<-----------------\n");
  }
}

void menuMercadoria(void)
{
  char charOpcao;
  do
  {
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
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
    escolhaMenuMercadoria(charOpcao);
  } while (charOpcao != '0');
}
/*Sobre o código do lote: será 8 números onde os 4 primeiros se refere ao lote
e os 4 restante sobre a peça em específico.
*/
Mercadoria *cadastroMercadoria(void)
{
  Mercadoria *mercadoria;
  mercadoria = (Mercadoria *)malloc(sizeof(Mercadoria));
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

  leCodBarras(mercadoria->codBarras);

  leQuantidade(&(mercadoria->quantidade));

  leCor(mercadoria->cor);

  leTamanho(mercadoria->tamanho);

  leNomeFornecedor(mercadoria->nomeFornecedor);

  leCnpj(mercadoria->cnpj);

  lePreco(&(mercadoria->preco));

  mercadoria->status = 'A';
  return mercadoria;
}

void editarMercadoria(void)
{
  Mercadoria *mercadoria;
  int encontrado = 0;
  char codBarras[13];
  FILE *fp;

  system("clear||cls");
  getchar();
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
  printf("               Informe o cód do produto:            \n");
  printf("                                                    \n");
  scanf(" %[0-9]", codBarras);
  getchar();

  mercadoria = (Mercadoria *)malloc(sizeof(Mercadoria));
  fp = fopen("arquivoMercadoria.bin", "rb");

  if (fp == NULL)
  {
    printf("Erro na abertura do arquivo!\n");
    getchar();
  }
  else
  {
    while (!feof(fp))
    {
      fread(mercadoria, sizeof(Mercadoria), 1, fp);
      if ((strcmp(mercadoria->codBarras, codBarras) == 0) && mercadoria->status != 'i')
      {
        printf("\n");
        printf("                Mercadoria Encontrado                \n");
        printf("                                                     \n");
        printf("           Informe os dados para atualizar:          \n");

        leTamanho(mercadoria->tamanho);

        leQuantidade(&(mercadoria->quantidade));
        // limparBufferEntrada();

        leCor(mercadoria->cor);
        // limparBufferEntrada();

        lePreco(&(mercadoria->preco));

        fseek(fp, (-1) * sizeof(Mercadoria), SEEK_CUR);
        fwrite(mercadoria, sizeof(Mercadoria), 1, fp);
        encontrado = 1;
        break;
      }
    }
    if (!encontrado)
    {
      printf("          Mercadoria atualizada com sucesso!         \n");
    }
    else
    {
      printf("             Mercadoria não encontrada!              \n");
    }
  }
  fclose(fp);
  free(mercadoria);
  getchar();
}

void excluirMercadoria(void)
{
  char codBarras[13];
  Mercadoria *mercadoria = (Mercadoria *)malloc(sizeof(Mercadoria));
  FILE *fp;
  int encontrado = 0;
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
  printf("                 EXCLUIR MERCADORIA                 \n");
  printf("                                                    \n");
  printf("               Digite (0) Para Voltar               \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("          Digite o cód de barras(12 dígitos):       \n");

  scanf(" %[0-9]", codBarras);
  getchar();
  fp = fopen("arquivoMercadoria.bin", "r+b");

  if (fp == NULL)
  {
    printf("Erro na abertura do arquivo!\n");
    getchar();
  }
  else
  {
    while (fread(mercadoria, sizeof(Mercadoria), 1, fp) == 1)
    {
      if (strcmp(mercadoria->codBarras, codBarras) == 0)
      {
        printf("Mercadoria encontrada!\n");
        printf("\n");
        mercadoria->status = 'i';
        fseek(fp, -sizeof(Mercadoria), SEEK_CUR);
        fwrite(mercadoria, sizeof(Mercadoria), 1, fp);
        encontrado = 1;
        break;
      }
    }
  }
  if (!encontrado)
  {
    printf("\n");
    printf("Mercadoria não encontrada!");
  }
  else
  {
    printf("\n");
    printf("Mercadoria excluída com sucesso!\n");
  }
  fclose(fp);
  free(mercadoria);
  getchar();
}
/*A função pesquisar irá detalhar as informações básicas(quantidade,) do LOTE
que o usuário passar e as informações específicas do produto(cor e tamanho)*/

void pesquisarMercadoria(void)
{
  char codBarras[13];
  FILE *fp;
  Mercadoria *mercadoria;
  int encontrado = 0;
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
  // leCodBarras(codBarras);
  scanf(" %[0-9]", codBarras);
  getchar();

  mercadoria = (Mercadoria *)malloc(sizeof(Mercadoria));
  fp = fopen("arquivoMercadoria.bin", "rb");

  if (fp == NULL)
  {
    printf("Erro na abertura do arquivo!\n");
    getchar();
  }
  else
  {
    while (fread(mercadoria, sizeof(Mercadoria), 1, fp) == 1)
    {
      if ((strcmp(mercadoria->codBarras, codBarras) == 0) && (mercadoria->status != 'i'))
      {
        encontrado = 1;
        exibeMercadoria(mercadoria);
        printf("\n");
        getchar();
      }
    }
  }
  if (!encontrado)
  {
    printf("\n");
    printf("Mercadoria não encontrada!");
    getchar();
  }

  fclose(fp);
  free(mercadoria);
}