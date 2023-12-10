#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caixa.h"
#include "../auxFuncoes/auxFuncoes.h"
#include "../cadastroMercadoria/cadastroMercadoria.h"

void leCpfVendedor(char *cpf)
{
  printf("CPF do vendedor:");
  fgets(cpf, 13, stdin);
  cpf[strcspn(cpf, "\n")] = '\0';
}

void leCpfCliente(char *cpf)
{
  printf("CPF do Cliente:");
  fgets(cpf, 13, stdin);
  cpf[strcspn(cpf, "\n")] = '\0';
}

char *leCod(char *cod)
{
  printf("Cód de barras:");
  fgets(cod, 10, stdin);
  cod[strcspn(cod, "\n")] = '\0';
  return cod;
}

int leQtd(int quantidade)
{
  printf("Quantidade:");
  scanf("%d", &quantidade);
  return quantidade;
}

void leMetodoPag(void)
{
  char charOpcao = '0';
  printf("\n");
  printf("           Escolha o método de pagamento:             \n");
  printf("\n");
  printf("(1) PIX\n");
  printf("(2) CARTÃO\n");
  printf("(3) ESPÉCIE\n");
  scanf(" %c", &charOpcao);
  getchar();
  exibeMetodoPag(charOpcao);
}
// Função de Matheus Diniz
int criar_id(void)
{
  FILE *fp = fopen("caixa.bin", "rb");
  if (fp == NULL)
  {
    return 1;
    // Percorre o arquivo inteiro
    fseek(fp, 0, SEEK_END);
    // Para verificiar o tamanho do arquivo
    if ((long)ftell(fp) == 0)
    {
      // caso o arquivo esteja vázio
      fclose(fp);
      return 1;
    }
  }
  else
  {
    // Posicione o ponteiro no início do último registro
    // Ver a última estrutura Adicionada

    // long adicionada para evitar problemas de conversão pelo sizeof, para um valor negativo, causando um estouro no fseek
    fseek(fp, -((long)sizeof(Caixa)), SEEK_END);
    // Agora você pode ler o último registro usando fread

    Caixa ultstruct;
    fread(&ultstruct, sizeof(Caixa), 1, fp);

    // Obtenha o ID do último registro e incremente
    int id = ultstruct.id + 1;

    fclose(fp); // Feche o arquivo aqui
    return id;
  }
}

int exibeMetodoPag(char escolhaPag)
{
  switch (escolhaPag)
  {
  case '1':
    condicoesPixEspecie();
    break;
  case '2':
    condicoesCartao();
    break;
  case '3':
    condicoesPixEspecie();
    break;
  default:
    printf("------------------>Opção inválida!<-----------------\n");
  }
  return 0;
}

void escolhaCaixa(char escolhaOpcao)
{
  Caixa *caixa;
  switch (escolhaOpcao)
  {
  case '1':
    caixa = realizarTransacao();
    gravandoTransacao(caixa);
    break;
  case '2':
    pesquisarTransacao();
    break;
  case '3':
    cancelarTransacao();
    break;
  default:
    printf("------------------>Opção inválida!<-----------------\n");
  }
}

void resumoDaCompraPix(float valorCompra, int porcentagem)
{
  system("clear||cls");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("                RESUMO FINAL DA COMPRA              \n");
  printf("____________________________________________________\n");
  printf("Valor da compra: R$ %.2f\n", valorCompra);
  printf("Valor com desconto: R$ %.2f\n", desconto(valorCompra, porcentagem));
  getchar();
}

float resumoDaCompraCartao(int parcelas, float valorCompra)
{
  char decisao;
  float valorFinal = 0;
  float valorParcelado = 0;

  printf("Valor disponível para dividir em %dx\n", parcelas);
  printf("Deseja dividir(s/n)?");
  scanf(" %c", &decisao);

  if (decisao == 's')
  {
    valorFinal = valorCompra + (10 * parcelas);
    valorParcelado = valorFinal / parcelas;

    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                RESUMO FINAL DA COMPRA              \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("Valor final: R$%.2f\n", valorFinal);
    printf("%d Parcelas: R$%.2f\n", parcelas, valorParcelado);
    return valorFinal;
  }
  else
  {
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                RESUMO FINAL DA COMPRA              \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("Valor final: R$%.2f\n", valorFinal);
    return valorFinal;
  }
}

float condicoesCartao(void)
{
  float valorFinal;
  float valorCompra;

  valorCompra = 1000;

  if (valorCompra < 500)
  {
    valorFinal = resumoDaCompraCartao(2, valorCompra);
  }

  else if (valorCompra >= 500 && valorCompra < 1200)
  {
    valorFinal = resumoDaCompraCartao(4, valorCompra);
  }

  else if (valorCompra >= 1200)
  {
    valorFinal = resumoDaCompraCartao(8, valorCompra);
  }
  return valorFinal;
}

void condicoesPixEspecie(void)
{
  float valorCompra;
  valorCompra = 1000;

  if (valorCompra <= 500)
  {
    resumoDaCompraPix(valorCompra, 5);
  }
  else if (valorCompra > 500 && valorCompra < 1000)
  {
    resumoDaCompraPix(valorCompra, 10);
  }
  else if (valorCompra >= 1000)
  {
    resumoDaCompraPix(valorCompra, 15);
  }
}

/*Abre o arquivo mercadoria e com base no cód barras encontra a struct do produto,
diminui a quantidade e retorna o preço total com base na quantidade do produto e seu valor.
*/
Mercadoria *getMercadoria(char *codBarras, int quantidadeVendida)
{
  Mercadoria *mercadoria;
  FILE *fp;
  mercadoria = (Mercadoria *)malloc(sizeof(Mercadoria));
  fp = fopen("arquivoMercadoria.bin", "rb");

  if (fp == NULL)
  {
    printf("Erro na abertura do arquivo!");
    getchar();
  }
  else
  {
    while (!feof(fp))
    {
      printf("Entrou no while");
      fread(mercadoria, sizeof(Mercadoria), 1, fp);
      if ((strcmp(mercadoria->codBarras, codBarras) == 0) && (mercadoria->status != 'i'))
      {
        printf("Entrou no primeiro if");
        if (mercadoria->quantidade == 0 || quantidadeVendida > mercadoria->quantidade)
        {
          printf("Estoque indisponível!");
          printf("Estoque atual: %d\n", mercadoria->quantidade);
          getchar();
        }
        // diminui quantidade comprada do estoque e mostra quanto ficou
        else
        {
          mercadoria->quantidade -= quantidadeVendida;
          printf("Disponível no estoque!");
          printf("Estoque pós venda: %d\n", mercadoria->quantidade);
          getchar();
          fseek(fp, -sizeof(Mercadoria), SEEK_CUR);
          fwrite(mercadoria, sizeof(Mercadoria), 1, fp);
          break;
        }
      }
    }
  }
  fclose(fp);
  return mercadoria;
}

void menuCaixa(void)
{
  char escolha;
  do
  {
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
    printf("                    MENU CAIXA                      \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Realizar transação                 \n");
    printf("             2 - Pesquisar transação                \n");
    printf("             3 - Cancelar transação                 \n");
    printf("____________________________________________________\n");
    scanf("%c", &escolha);
    escolhaCaixa(escolha);
    getchar();
  } while (escolha != '0');
}

/*A função pagamento caixa deverá pedir o cód de barras até as peças escolhidas pelo cliente acabarem.
Após isso, é exibido o valor total das suas compras e o programa segue. A informação data será pedida para
que a dinâmica dos relatórios possa ser feita*/

Caixa *realizarTransacao(void)
{
  Caixa *caixa;
  caixa = (Caixa *)malloc(sizeof(Caixa));
  // float preco = 0;
  char codBarras[10];
  int quantidadeVendida = 0;
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
  printf("              CAIXA REALIZAR TRANSAÇÃO              \n");
  printf("                                                    \n");
  printf("               Digite (0) Para Voltar               \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");

  leCpfCliente(caixa->cpfCliente);
  limparBufferEntrada();

  leCpfVendedor(caixa->cpfVendedor);

  strcpy(codBarras, leCod(caixa->codBarras));


  quantidadeVendida = leQtd(caixa->quantidade);

  getMercadoria(codBarras, quantidadeVendida);

  //leMetodoPag();

  caixa->id = criar_id();
  caixa->status = 'A';

  getchar();
  return caixa;
}

void gravandoTransacao(Caixa *caixa)
{
  FILE *fp;
  fp = fopen("arquivoCaixa.bin", "ab");

  if (fp == NULL)
  {
    printf("Erro na gravação do arquivo!");
    getchar();
  }

  fwrite(caixa, sizeof(Caixa), 1, fp);
  fclose(fp);
  free(caixa);
}

void exibeTransacao(Caixa *caixa)
{
  // char situacao[20];

  if ((caixa == NULL) || (caixa->status == 'i'))
  {
    printf("Transação não encontrada!");
  }
  else
  {
    printf("CPF do cliente:%s\n", caixa->cpfCliente);
    printf("CPF do vendedor:%s\n", caixa->cpfVendedor);
    printf("Cod de barras:%s\n", caixa->codBarras);
    printf("ID da transação:%d\n", caixa->id);
  }
}

void pesquisarTransacao(void)
{
  FILE *fp;
  Caixa *caixa;
  int id = 0;
  int achei = 0;

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
  printf("             CAIXA PESQUISAR TRANSAÇÃO              \n");
  printf("                                                    \n");
  printf("               Digite (0) Para Voltar               \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("   Informe o id da transação que deseja pesquisar:  \n");
  printf("____________________________________________________\n");
  scanf("%d", &id);
  getchar();

  caixa = (Caixa *)malloc(sizeof(Caixa));
  fp = fopen("arquivoCaixa.bin", "rb");

  if (fp == NULL)
  {
    printf("Erro na abertura do arquivo!");
    getchar();
  }
  else
  {
    while (fread(caixa, sizeof(Caixa), 1, fp))
    {
      if ((caixa->id == id) && (caixa->status != 'i'))
      {
        achei = 1;
        exibeTransacao(caixa);
        printf("\n");
        break;
        getchar();
      }
    }
  }
  if (!achei)
  {
    printf("\n");
    printf("\t\t\t Transação não encontrada!\n");
    getchar();
  }
  else
  {
    printf("\n");
    printf("\t  Pesquisa realizada com sucesso!\n");
  }
  fclose(fp);
  free(caixa);
  //getchar();
}

void cancelarTransacao(void)
{
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
  printf("              CAIXA CANCELAR TRANSAÇÃO              \n");
  printf("                                                    \n");
  printf("               Digite (0) Para Voltar               \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("   Informe o id da transação que deseja cancelar:   \n");
  printf("____________________________________________________\n");
  getchar();
}