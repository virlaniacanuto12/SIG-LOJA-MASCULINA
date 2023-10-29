#include <stdio.h> 
#include <stdlib.h>
#include "cadastroCliente.h"
#include "../auxFuncoes/auxFuncoes.h"

char senhas[6];
char nomes[20];
char cpfs[20];
char dataNasCliente[20];

/*void leSenha(char *senha){
  printf("Digite sua senha:");
  fgets(senha, sizeof(senha), stdin);
  verificarSenha(senha);
  }*/

void lerNomes(char *nome){
  printf("Nome:");
  fgets(nome, sizeof(nome), stdin);
  //validarNome(nome);
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

void cadastrarCliente(void){
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
    printf("                  CADASTRAR CLIENTE                 \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    lerNomes(nomes);//não aparece
    printf("CPF:\n");
    printf("Data de nascimento:\n");
    printf("Tel:\n");
    printf("Email:\n");
    printf("Estado civil:\n");
    //leSenha(senha);//não está parando para fazer leitura
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
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
    printf("                  VERIFICAR CLIENTE                 \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("        Informe o CPF do cliente que deseja         \n");
    printf("                verificar o cartão:                 \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
}

void escolhaMenuCliente(char escolha){
    switch(escolha){
        case '1':
            cadastrarCliente();
        break;
        case '2':
            atualizarCliente();
        break;
        case '3':
            excluirCliente();
        break;
        case '4':
            verificarCliente();
        break;
        default:
            printf("------------------>Opção inválida!<-----------------\n");
    }
}