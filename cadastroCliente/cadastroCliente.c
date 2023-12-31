#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <unistd.h>
#include <time.h>
#include "cadastroCliente.h"
#include "../auxFuncoes/auxFuncoes.h"
#include "../caixa/caixa.h"

void lerNomes(char *nome)
{
  printf("Nome:");
  fgets(nome, 51, stdin);
  nome[strcspn(nome, "\n")] = '\0';
}

void lecpfCliente(char *cpf)
{
  int cpfValido = 0;
  do
  {
    printf("CPF:");
    fgets(cpf, 13, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    cpfValido = validarCpf(cpf);

    if (!cpfValido)
    {
      printf("CPF inválido. Por favor, insira um CPF válido.\n");
    }
  } while (!validarCpf(cpf));
}

void leclienteDataNasc(char *dataNasc)
{
  printf("Data de nascimento:");
  fgets(dataNasc, 9, stdin);
  dataNasc[strcspn(dataNasc, "\n")] = '\0';
  getchar(); // Limpa o buffer
}

void leTel(char *tel)
{
  printf("Tel:");
  fgets(tel, 12, stdin);
  tel[strcspn(tel, "\n")] = '\0';
  getchar(); // Limpa o buffer
}

void leEmail(char *email)
{
  printf("Email:");
  fgets(email, 50, stdin);
  email[strcspn(email, "\n")] = '\0';
  getchar();
}

void leEstadoCivilCliente(char *estadoCivil)
{
  printf("Estado civil:");
  fgets(estadoCivil, 21, stdin);
  estadoCivil[strcspn(estadoCivil, "\n")] = '\0';
}

void menuCliente(void)
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
    printf("             5 - Cliente por ordem alfabética       \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    // sgetchar();
    escolhaMenuCliente(charOpcao);
  } while (charOpcao != '0');
}

Cliente *cadastrarCliente(void)
{
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
  limparBufferEntrada();

  lerNomes(cliente->nomeCliente);

  lecpfCliente(cliente->cpfCliente);

  leclienteDataNasc(cliente->clienteDataNasc);

  leTel(cliente->tel);

  leEmail(cliente->email);

  leEstadoCivilCliente(cliente->estadoCivilCliente);

  cliente->status = 'A';

  getchar();
  return cliente;
}

void gravandoCliente(Cliente *cliente)
{
  FILE *fp;
  fp = fopen("arquivoCliente.bin", "ab");

  if (fp == NULL)
  {
    printf("Erro na criação do arquivo!");
    getchar();
  }

  fwrite(cliente, sizeof(Cliente), 1, fp);
  fclose(fp);
  free(cliente);
}

void exibeCliente(Cliente *cliente)
{
  char situacao[20];

  if ((cliente == NULL) || (cliente->status == 'i'))
  {
    printf("Cliente não encontrado!");
  }
  else
  {
    printf("Nome:%s\n", cliente->nomeCliente);
    printf("CPF:%s\n", cliente->cpfCliente);
    printf("Celular:%s\n", cliente->tel);
    printf("Email:%s\n", cliente->email);
    printf("Data de nascimento:%s\n", cliente->clienteDataNasc);
    printf("Estado Civil:%s\n", cliente->estadoCivilCliente);
    printf("Status:%c\n", cliente->status);
  }
  if (cliente->status == 'A')
  {
    strcpy(situacao, "Cadastro Ativo");
  }
  else
  {
    strcpy(situacao, "Cadastro Inativo");
  }
}

void lendoCliente(void)
{
  FILE *fp;
  Cliente *cliente;
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

  cliente = (Cliente *)malloc(sizeof(Cliente));
  fp = fopen("arquivoCliente.bin", "rb");

  if (fp == NULL)
  {
    printf("Erro na abertura do arquivo!\n");
    getchar();
  }

  while (fread(cliente, sizeof(Cliente), 1, fp))
  {
    exibeCliente(cliente);
  }

  fclose(fp);
  free(cliente);
  getchar();
}

void editarCliente(void)
{
  char cpf[13];
  Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));
  FILE *fp;
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
  printf("                  EDITAR CLIENTE                    \n");
  printf("                                                    \n");
  printf("               Digite (0) Para Voltar               \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("        Informe o CPF do cliente que deseja         \n");
  printf("              atualizar o cartão:                   \n");

  scanf(" %[0-9]", cpf);
  getchar();
  sleep(1);

  fp = fopen("arquivoCliente.bin", "r+b");

  if (fp == NULL)
  {
    printf("Erro na abertura do arquivo!\n");
    getchar();
  }
  else
  {
    while (!feof(fp))
    {
      fread(cliente, sizeof(Cliente), 1, fp);
      if (strcmp(cliente->cpfCliente, cpf) == 0)
      {
        printf("\n");
        printf("       Cliente Encontrado!!\n");
        printf("\n");
        printf("   Informe os dados para atualizar:\n");
        printf("\n");

        leEmail(cliente->email);

        leTel(cliente->tel);

        leEstadoCivilCliente(cliente->estadoCivilCliente);

        fseek(fp, (-1) * sizeof(Cliente), SEEK_CUR);
        fwrite(cliente, sizeof(Cliente), 1, fp);
        achei = 1;
        break;
      }
    }
  }
  if (!achei)
  {
    printf("\n");
    printf("        CPF não encontrado!\n");
  }
  else
  {
    printf("\n");
    printf("  Usuário atualizado com sucesso!\n");
    // limparBufferEntrada();
  }
  fclose(fp);
  free(cliente);
  getchar();
}

void excluirCliente(void)
{
  char cpf[13];
  Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));
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
  printf("                  EXCLUIR CLIENTE                   \n");
  printf("                                                    \n");
  printf("               Digite (0) Para Voltar               \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("        Informe o CPF do cliente que deseja         \n");
  printf("                excluir o cartão:                   \n");

  fgets(cpf, 12, stdin);
  getchar();
  fp = fopen("arquivoCliente.bin", "rb");

  if (fp == NULL)
  {
    printf("Erro na abertura do arquivo!\n");
    getchar();
  }
  else
  {
    while (fread(cliente, sizeof(Cliente), 1, fp) == 1)
    {
      if (strcmp(cliente->cpfCliente, cpf) == 0)
      {
        printf("Usuário Encontrado\n");
        printf("\n");
        cliente->status = 'i';
        fseek(fp, -sizeof(Cliente), SEEK_CUR);
        fwrite(cliente, sizeof(Cliente), 1, fp);
        encontrado = 1;
        break;
      }
    }
  }
  if (!encontrado)
  {
    printf("\n");
    printf("\t\tUsuário não encontrado!\n");
  }
  else
  {
    printf("\n");
    printf("\t\tUsuário excluído com sucesso!\n");
  }

  fclose(fp);
  free(cliente);
  getchar();
}

/*A função verificar irá exibir os seguintes dados do cliente respectivo ao CPF:
data de vencimento, data de fechamento da fatura, limite e limite disponível.
*/
void verificarCliente(void)
{
  char cpf[13];
  FILE *fp;
  Cliente *cliente;
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

  scanf(" %[0-9]", cpf);
  getchar();

  cliente = (Cliente *)malloc(sizeof(Cliente));
  fp = fopen("arquivoCliente.bin", "r+b");

  if (fp == NULL)
  {
    printf("Erro na abertura do arquivo!\n");
    getchar();
  }
  else
  {
    while (!feof(fp))
    {
      fread(cliente, sizeof(Cliente), 1, fp);
      if ((strcmp(cliente->cpfCliente, cpf) == 0) && (cliente->status != 'i'))
      {
        exibeCliente(cliente);
        printf("\n");
        getchar();
      }
    }
  }
  fclose(fp);
  free(cliente);
}


void relatorioCliente(void)
{
  getchar();
  FILE *fp = fopen("arquivoCliente.bin", "rb");
  Cliente *novo_cli;
  Cliente *lista;
  system("clear||cls");
  if (fp == NULL)
  {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("- - - - - - Loja de Artigos Masculinos - - - - - - -\n");
  printf(" Developed by @virlaniacanuto12 -- since Aug, 2023  \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("  - - - - - - - - - - SHOPMEN - - - - - - - - - - - \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("                 RELATÓRIO CLIENTE                  \n");
  printf("                                                    \n");
  printf("               Digite (0) Para Voltar               \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("            Clientes em ordem alfabética            \n");
  printf("                                                    \n");
  printf("%-12s", "CPF");
  printf("|");
  printf("%-30s", "Nome do Cliente");
  printf("\n");
  printf("%13s", "|");
  printf("\n");
  lista = NULL;
  novo_cli = (Cliente *)malloc(sizeof(Cliente));
  if (novo_cli == NULL)
  {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao alocar a memória!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  while (fread(novo_cli, sizeof(Cliente), 1, fp) == 1)
  {
    novo_cli->prox = NULL;
    if ((lista == NULL) || (strcmp(novo_cli->nomeCliente, lista->nomeCliente) < 0))
    {
      novo_cli->prox = lista;
      lista = novo_cli;
    }
    else
    {
      Cliente *ant = lista;
      Cliente *atual = lista->prox;
      while ((atual != NULL) && strcmp(atual->nomeCliente, novo_cli->nomeCliente) < 0)
      {
        ant = atual;
        atual = atual->prox;
      }
      ant->prox = novo_cli;
      novo_cli->prox = atual;
    }
    novo_cli = (Cliente *)malloc(sizeof(Cliente));
    if (novo_cli == NULL)
    {
      printf("\t\t\t>>> Processando as informações...\n");
      sleep(1);
      printf("\t\t\t>>> Houve um erro ao alocar a memória!\n");
      printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
      getchar();
    }
  }
  fclose(fp);
  novo_cli = lista;
  while(novo_cli != NULL) {
    printf("%-12s", novo_cli->cpfCliente);
    printf("|");
    printf("%-30s", novo_cli->nomeCliente);
    printf("\n");
    novo_cli = novo_cli->prox;
  }
  novo_cli = lista;
  while (lista != NULL) {
    lista = lista->prox;
    free(novo_cli);
    novo_cli = lista;
  }
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
}

void escolhaMenuCliente(char escolha)
{
  Cliente *cliente;
  switch (escolha)
  {
  case '1':
    cliente = cadastrarCliente();
    gravandoCliente(cliente);
    break;
  case '2':
    editarCliente();
    break;
  case '3':
    getchar();
    excluirCliente();
    break;
  case '4':
    getchar();
    verificarCliente();
    break;
  case '5':
    relatorioCliente();
    break;
  default:
    printf("------------------>Opção inválida!<-----------------\n");
  }
}