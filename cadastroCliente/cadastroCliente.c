#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <unistd.h>
#include <time.h>
#include "cadastroCliente.h"
#include "../auxFuncoes/auxFuncoes.h"

void lerNomes(char *nome)
{
  printf("Nome:");
  fgets(nome, 51, stdin);
  // validarNome(nome);
  /*if (nome[strlen(nome) - 1] == '\n') {
    nome[strlen(nome) - 1] = '\0';
  }*/
}

void lecpfCliente(char *cpf)
{
  printf("CPF:");
  fgets(cpf, 13, stdin);
  /*if (cpf[strlen(cpf) - 1] == '\n') {
    cpf[strlen(cpf) - 1] = '\0';
  }*/
}

void leclienteDataNasc(char *dataNasc)
{
  printf("Data de nascimento:");
  fgets(dataNasc, 9, stdin);
  if (dataNasc[strlen(dataNasc) - 1] == '\n')
  {
    dataNasc[strlen(dataNasc) - 1] = '\0';
  }
  getchar();
}

void leTel(char *tel)
{
  printf("Tel:");
  fgets(tel, 12, stdin);
  getchar();
}

void leEmail(char *email)
{
  printf("Email:");
  fgets(email, 50, stdin);
}

void leEstadoCivilCliente(char *estadoCivil)
{
  printf("Estado civil:");
  fgets(estadoCivil, 21, stdin);
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

  lerNomes(cliente->nomeCliente);
  limparBufferEntrada();

  lecpfCliente(cliente->cpfCliente);

  leclienteDataNasc(cliente->clienteDataNasc);
  limparBufferEntrada();

  leTel(cliente->tel);
  limparBufferEntrada();

  leEmail(cliente->email);

  leEstadoCivilCliente(cliente->estadoCivilCliente);

  cliente->status = 'A';

  printf("                                                    \n");
  printf("            Cliente cadastrado com sucesso!         \n");
  printf("____________________________________________________\n");

  sleep(1);
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
  printf("                  EXCLUIR CLIENTE                   \n");
  printf("                                                    \n");
  printf("               Digite (0) Para Voltar               \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("        Informe o CPF do cliente que deseja         \n");
  printf("                excluir o cartão:                   \n");

  fgets(cpf, 12, stdin);
  getchar();
  fp = fopen("arquivoCliente.bin", "r+b");

  if (fp == NULL)
  {
    printf("Erro na abertura do arquivo!\n");
    printf("Tecle <ENTER> para voltar...\n");
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
        achei = 1;
        break;
      }
    }
  }
  if (!achei)
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
    lendoCliente();
    // verificarCliente();
    break;
  default:
    printf("------------------>Opção inválida!<-----------------\n");
  }
}