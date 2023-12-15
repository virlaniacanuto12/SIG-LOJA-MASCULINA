#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "caixa.h"
#include "../auxFuncoes/auxFuncoes.h"
#include "../cadastroMercadoria/cadastroMercadoria.h"
#include "../cadastroVendedor/cadastroVendedor.h"

// função de Mariana Santos
void ler_DataHora(char *dataHora)
{
  time_t tempoAtual;
  struct tm *infoTempo;

  time(&tempoAtual);
  infoTempo = localtime(&tempoAtual);

  strftime(dataHora, 20, "%d/%m/%Y %H:%M:%S", infoTempo);
}

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

float *leValor(float *valor)
{
  printf("Valor:");
  scanf("%f", valor);
  return valor;
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
  FILE *fp = fopen("arquivoCaixa.bin", "rb");
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

// Pega a struct no arquivo com base no cod barras e retorna a estrutura inteira
Mercadoria *getMercadoria(char *codBarras)
{
  Mercadoria *mercadoria;
  FILE *fp;
  mercadoria = (Mercadoria *)malloc(sizeof(Mercadoria));
  fp = fopen("arquivoMercadoria.bin", "rb");

  if (fp == NULL)
  {
    printf("Erro na abertura do arquivo!");
    getchar();
    return NULL;
  }
  else
  {
    while (!feof(fp))
    {
      fread(mercadoria, sizeof(Mercadoria), 1, fp);
      // printf("Codigos: |%s|\t|%s|\n", codBarras, mercadoria->codBarras);
      if ((strcmp(mercadoria->codBarras, codBarras) == 0) && (mercadoria->status != 'i'))
      {
        // printf("achou!\n");
        return mercadoria;
      }
    }
    fclose(fp);
    return NULL;
  }
  return NULL;
}
// Para testar precisa da função de valorTotal(que vai calcular com base na quantidade que o cliente deseja comprar)
int pontuacaoVendedor(Mercadoria *mercadoria, float valorTotal, char *cpfVendedor)
{
  Vendedor *vendedor;
  FILE *fp;
  vendedor = (Vendedor *)malloc(sizeof(Vendedor));
  fp = fopen("arquivoVendedor.bin", "rb");

  if (fp == NULL)
  {
    return 0;
  }
  while (fread(vendedor, sizeof(Vendedor), 1, fp))
  {
    printf("Entrou no while");
    printf("CPF vendedor struct: %s", vendedor->cpfVendedor);
    printf("CPF vendedor: %s", cpfVendedor);
    if ((strcmp(vendedor->cpfVendedor, cpfVendedor) == 0) && (vendedor->status != 'i'))
    {
      printf("ENTROU NO IF");
      if (valorTotal <= 500)
      {
        vendedor->pontos += 50;
        printf("Pontos vendedor: %d", vendedor->pontos);
        return 1;
      }
      else if (valorTotal > 500 && valorTotal <= 1000)
      {
        vendedor->pontos += 100;
        printf("Pontos vendedor: %d", vendedor->pontos);
        return 1;
      }
      else if (valorTotal > 1000)
      {
        vendedor->pontos += 150;
        printf("Pontos vendedor: %d", vendedor->pontos);
        return 1;
      }
    }
  }
  return 0;
  fclose(fp);
}

// precisa fazer uma verificação para saber se a quantidade no estoque é maior que a quantidade vendida
float valorTotal(Mercadoria *mercadoria, int quantidadeVendida)
{
  float valorTot = 0;
  valorTot = (mercadoria->quantidade - quantidadeVendida) * mercadoria->preco;
  printf("Valor total %2.f", valorTot);
  return valorTot;
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
  Mercadoria *mercadoria;
  Caixa *caixa;
  caixa = (Caixa *)malloc(sizeof(Caixa));
  char codBarras[10];
  int quantidadeVendida;
  float valorTot = 0;
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
  printf("              CAIXA REALIZAR TRANSAÇÃO              \n");
  printf("                                                    \n");
  printf("               Digite (0) Para Voltar               \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");

  leCpfCliente(caixa->cpfCliente);
  limparBufferEntrada();

  leCpfVendedor(caixa->cpfVendedor);

  do
  {
    strcpy(codBarras, leCod(caixa->codBarras));

    if (getMercadoria(codBarras) != NULL)
    {
      mercadoria = getMercadoria(codBarras);
      encontrado = 1;
    }
    else
    {
      printf("Produto não cadastrado!!");
    }
  } while (encontrado != 1);

  do
  {
    quantidadeVendida = leQtd(caixa->quantidade);
    if (quantidadeVendida > mercadoria->quantidade)
    {
      printf("Estoque indisponível!");
      printf("Estoque atual: %d\n", mercadoria->quantidade);
      getchar();
    }
    else
    {
      mercadoria->quantidade -= quantidadeVendida;
    }
  } while (quantidadeVendida > mercadoria->quantidade);

  valorTot = valorTotal(mercadoria, quantidadeVendida);
  //  leMetodoPag();
  printf("Valor Total:%2.f", valorTot);

  ler_DataHora(caixa->dataHora);
  printf("Data e hora: %s\n", caixa->dataHora);

  caixa->id = criar_id();
  printf("ID da venda: %d\n", caixa->id);

  caixa->status = 'A';

  pontuacaoVendedor(mercadoria, valorTot, caixa->cpfVendedor);
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
  if ((caixa == NULL) || (caixa->status == 'i'))
  {
    printf("Transação não encontrada!");
  }
  else
  {
    printf("CPF do cliente:%s\n", caixa->cpfCliente);
    printf("CPF do vendedor:%s\n", caixa->cpfVendedor);
    printf("Cod de barras:%s\n", caixa->codBarras);
    printf("Quantidade:%d\n", caixa->quantidade);
    printf("Valor unidade:%2.f\n", caixa->valor);
    printf("ID da transação:%d\n", caixa->id);
    printf("Data e hora:%s\n", caixa->dataHora);
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
  scanf(" %d", &id);
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
  // getchar();
}
/*Através da struct caixa, após achar a venda no arq de acordo como id digitado na função cancelarTransacao(),
pegamos o campo codBarras da struct e usamos a função getMercadoria() para conseguir pegar a struct
de mercadoria equivalente a venda e repor o estoque.
*/
void repondoEstoque(Caixa *caixa)
{
  Mercadoria *mercadoria;
  mercadoria = getMercadoria(caixa->codBarras);
  printf("Quantidade mercadoria: %d", mercadoria->quantidade);
  printf("Quantidade caixa: %d", caixa->quantidade);
  mercadoria->quantidade += caixa->quantidade;
  printf("Quantidade mercadoria atualizada: %d\n", mercadoria->quantidade);
}

void cancelarTransacao(void)
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
  printf("              CAIXA CANCELAR TRANSAÇÃO              \n");
  printf("                                                    \n");
  printf("               Digite (0) Para Voltar               \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("   Informe o id da transação que deseja cancelar:   \n");
  printf("____________________________________________________\n");
  scanf(" %d", &id);
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
        repondoEstoque(caixa);
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
    printf("\t  Cancelamento realizada com sucesso! \n");
  }
  fclose(fp);
  free(caixa);
  // getchar();
}
