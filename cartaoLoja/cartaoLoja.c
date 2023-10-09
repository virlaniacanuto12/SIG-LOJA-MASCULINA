#include <stdio.h> 
#include <stdlib.h>
#include "cartaoLoja.h"
#include "../auxFuncoes/auxFuncoes.h"

char senha[6];
char nome[20];
char cpf[20];
char dataNascCliente[20];

void leSenha(char *senha){
  printf("Digite sua senha:");
  fgets(senha, sizeof(senha), stdin);
  verificarSenha(senha);
}

void menuCartao(void){
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
        printf("                 MENU CARTÃO LOJA                   \n");
        printf("____________________________________________________\n");
        printf("                                                    \n");
        printf("             1 - Cadastrar cartão                   \n");
        printf("             2 - Atualizar cartão                   \n");
        printf("             3 - Excluir cartão                     \n");
        printf("             4 - Verificar cartão                   \n");
        printf("             0 - Voltar                             \n");
        printf("                                                    \n");
        printf("____________________________________________________\n");
        scanf("%c", &charOpcao);
        //getchar();
        escolhaMenuCartao(charOpcao);
    }while(charOpcao != '0');
}

void cadastrarCartao(void){
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
    printf("                  CADASTRAR CARTÃO                  \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("Nome do cliente:\n");
    printf("CPF:\n");
    printf("Data de nascimento:\n");
    printf("Tel:\n");
    printf("Estado civil:\n");
    printf("Fechamento de fatura:\n");
    printf("Vencimento de fatura:\n");
    printf("Renda:\n");
    leSenha(senha);
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
}

void atualizarCartao(void){
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
    printf("                  ATUALIZAR CARTÃO                  \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("        Informe o CPF do cliente que deseja         \n");
    printf("              atualizar o cartão:                   \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("              Renda:                                \n");
    printf("              Data de fechamento:                   \n");
    printf("              Data de vencimento:                   \n");
    printf("              Senha:                                \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
}

void excluirCartao(void){
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
    printf("                  EXCLUIR CARTÃO                    \n");
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
/*A função verificar irá exibir os eguintes dados do cliente respectivo ao CPF:
data de vencimento, data de fechamento da fatura, limite e limite disponível.
*/
void verificarCartao(void){
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
    printf("                  VERIFICAR CARTÃO                  \n");
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

void escolhaMenuCartao(char escolha){
    switch(escolha){
        case '1':
            cadastrarCartao();
        break;
        case '2':
            atualizarCartao();
        break;
        case '3':
            excluirCartao();
        break;
        case '4':
            verificarCartao();
        break;
        default:
            printf("------------------>Opção inválida!<-----------------\n");
    }
}