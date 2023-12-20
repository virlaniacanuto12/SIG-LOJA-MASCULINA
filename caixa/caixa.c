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
  int cpfValido = 0;
  do
  {
    printf("CPF Vendedor:");
    fgets(cpf, 13, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    cpfValido = validarCpf(cpf);

    if (!cpfValido)
    {
      printf("CPF inválido. Por favor, insira um CPF válido.\n");
    }
  } while (!validarCpf(cpf));
}

void leCpfCliente(char *cpf)
{
  int cpfValido = 0;
  do
  {
    printf("CPF Cliente:");
    fgets(cpf, 13, stdin);
    // getchar();
    cpf[strcspn(cpf, "\n")] = '\0';

    cpfValido = validarCpf(cpf);
    getchar();
    if (!cpfValido)
    {
      printf("CPF inválido. Por favor, insira um CPF válido.\n");
      getchar();
    }
  } while (!validarCpf(cpf));
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

char leMetodoPag(void)
{
  getchar();
  char charOpcao = '0';
  printf("______________________________________________________\n");
  printf("                                                      \n");
  printf("           Escolha o método de pagamento:             \n");
  printf("                                                      \n");
  printf("        (1) PIX || (2) CARTÃO || (3) ESPÉCIE          \n");
  printf("______________________________________________________\n");

  scanf(" %c", &charOpcao);
  getchar();
  return charOpcao;
}

void exibeMetodoPag(char escolhaPag, float valorFinal)
{
  switch (escolhaPag)
  {
  case '1':
    condicoesPixEspecie(valorFinal);
    break;
  case '2':
    condicoesCartao(valorFinal);
    break;
  case '3':
    condicoesPixEspecie(valorFinal);
    break;
  default:
    printf("------------------>Opção inválida!<-----------------\n");
  }
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

float resumoDaCompraPix(float valorCompra, int porcentagem)
{
  float valorFinal = 0;
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("                RESUMO FINAL DA COMPRA              \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("Valor da compra: R$ %.2f\n", valorCompra);
  printf("Valor com desconto: R$ %.2f\n", desconto(valorCompra, porcentagem));
  getchar();
  return valorFinal;
}

// Calcula o preço final com base nos aumentos do cartão e grava na struct
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
    // soma 10% no valor final
    valorFinal = valorCompra + ((10 * valorCompra) / 100);
    valorParcelado = valorFinal / parcelas;

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

void condicoesCartao(float valorFinal)
{
  if (valorFinal < 500)
  {
    resumoDaCompraCartao(2, valorFinal);
  }

  else if (valorFinal >= 500 && valorFinal < 1200)
  {
    resumoDaCompraCartao(4, valorFinal);
  }

  else if (valorFinal >= 1200)
  {
    resumoDaCompraCartao(8, valorFinal);
  }
}

void condicoesPixEspecie(float valorFinal)
{
  if (valorFinal <= 500)
  {
    resumoDaCompraPix(valorFinal, 5);
  }
  else if (valorFinal > 500 && valorFinal < 1000)
  {
    resumoDaCompraPix(valorFinal, 10);
  }
  else if (valorFinal >= 1000)
  {
    resumoDaCompraPix(valorFinal, 15);
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
      if ((strcmp(mercadoria->codBarras, codBarras) == 0) && (mercadoria->status != 'i'))
      {
        return mercadoria;
      }
    }
    fclose(fp);
    return NULL;
  }
  return NULL;
}

/*int verificarDataPonto(Caixa *caixa, Vendedor *vendedor)
{
  char mesVendedor[3];
  char mesCaixa[3];

  extrairMes(vendedor->dataHora, mesVendedor);
  extrairMes(caixa->dataHora, mesCaixa);

  if (strcmp(mesVendedor, mesCaixa) == 0)
  {
    printf("O mês da data do vendedor é igual ao mês da data da caixa: %s.\n", mesVendedor);
    return 1;
  }
  else
  {
    printf("O mês da data do vendedor é diferente do mês da data da caixa.\n");
    return 0;
  }
}*/

int pontuacaoVendedor(Mercadoria *mercadoria, float valorTotal, char *cpfVendedor)
{
  Vendedor *vendedor;
  FILE *fp;
  vendedor = (Vendedor *)malloc(sizeof(Vendedor));
  fp = fopen("arquivoVendedor.bin", "r+b");

  int pontos = 0;
  if (fp == NULL)
  {
    return 0;
  }
  while (fread(vendedor, sizeof(Vendedor), 1, fp))
  {
    if ((strcmp(vendedor->cpfVendedor, cpfVendedor) == 0) && (vendedor->status != 'i'))
    {
      // if (verificarDataPonto(caixa, vendedor))
      //{
      if (valorTotal <= 500)
      {
        pontos = 100;
        vendedor->pontos += pontos;
        printf("Pontos vendedor: %d", vendedor->pontos);
      }
      else if (valorTotal > 500 && valorTotal <= 1000)
      {
        pontos = 150;
        vendedor->pontos += pontos;
        printf("Pontos vendedor: %d", vendedor->pontos);
      }
      else if (valorTotal > 1000)
      {
        pontos = 200;
        vendedor->pontos += pontos;
        printf("Pontos vendedor: %d", vendedor->pontos);
      }

      fseek(fp, -sizeof(Vendedor), SEEK_CUR); // Volte para a posição correta no arquivo
      fwrite(vendedor, sizeof(Vendedor), 1, fp);
      fclose(fp);
      return 1;
      // break; // Sai do loop após encontrar e atualizar o vendedor
    }
  }
  fclose(fp);
  free(vendedor);
  return 0;
}

// precisa fazer uma verificação para saber se a quantidade no estoque é maior que a quantidade vendida
float valorTotal(Mercadoria *mercadoria, int quantidadeVendida)
{
  float valorTot = 0;
  valorTot = quantidadeVendida * mercadoria->preco;
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

  char opcaoPag;
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

  limparBufferEntrada();
  leCpfCliente(caixa->cpfCliente);

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

  ler_DataHora(caixa->dataHora);
  printf("Data e hora: %s\n", caixa->dataHora);

  caixa->id = criar_id();
  printf("ID da venda: %d\n", caixa->id);

  valorTot = valorTotal(mercadoria, quantidadeVendida);

  printf("Valor Total:%2.f\n", valorTot);
  getchar();

  opcaoPag = leMetodoPag();
  exibeMetodoPag(opcaoPag, valorTot);
  getchar();

  caixa->status = 'a';

  // Se escrever no arquivo novamente após o reusmo da compra talvez dê certo
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
    printf("Valor:%2.f\n", caixa->valor);
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
    printf("\t\tTransação não encontrada!\n");
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

/*Através da struct caixa, após achar a venda no arq de acordo como id digitado na função cancelarTransacao(),
pegamos o campo codBarras da struct e usamos a função getMercadoria() para conseguir pegar a struct
de mercadoria equivalente a venda e repor o estoque.
*/
void repondoEstoque(Caixa *caixa)
{
  Mercadoria *mercadoria;
  mercadoria = getMercadoria(caixa->codBarras);
  printf("Cod barras: %s\n", mercadoria->codBarras);
  printf("Quantidade vendida: %d\n", caixa->quantidade);
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
  fp = fopen("arquivoCaixa.bin", "r+b");

  if (fp == NULL)
  {
    printf("Erro na abertura do arquivo!");
    getchar();
  }
  else
  {
    while (fread(caixa, sizeof(Caixa), 1, fp) == 1)
    {
      if (caixa->id == id)
      {
        achei = 1;
        repondoEstoque(caixa);
        caixa->status = 'i';
        fseek(fp, -sizeof(Caixa), SEEK_CUR);
        fwrite(caixa, sizeof(Caixa), 1, fp);
        break;
        // getchar();
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
