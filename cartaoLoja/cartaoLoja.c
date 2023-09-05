#include <stdio.h> 
#include <stdlib.h>
#include "cartaoLoja.h"

void menuCartao(void){
    char charOpcao;
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
}

void cadastrarCartao(void){
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
    printf("                CADASTRAR CARTÃO                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("              Nome do cliente                       \n");
    printf("              CPF:                                  \n");
    printf("              Data de nascimento:                   \n");
    printf("              Estado civil:                         \n");
    printf("              Escolaridade:                         \n");
    printf("              Fechamento de fatura:                 \n");
    printf("              Vencimento de fatura:                 \n");
    printf("              Renda:                                \n");
    printf("____________________________________________________\n");
}

void atualizarCartao(void){
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
    printf("                ATUALIZAR CARTÃO                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("        Informe o CPF do cliente que deseja         \n");
    printf("              atualizar o cartão:                   \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("              Renda:                                \n");
    printf("              Limite:                               \n");
    printf("              Data de fechamento:                   \n");
    printf("              Data de vencimento:                   \n");
    printf("              Senha:                                \n");
    printf("____________________________________________________\n");
}

void excluirCartao(void){
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
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("        Informe o CPF do cliente que deseja         \n");
    printf("                excluir o cartão:                   \n");
    printf("____________________________________________________\n");
}
/*A função verificar irá exibir os eguintes dados do cliente respectivo ao CPF:
data de vencimento, data de fechamento da fatura, limite e limite disponível.
*/
void verificarCartao(void){
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
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("        Informe o CPF do cliente que deseja         \n");
    printf("                verificar o cartão:                 \n");
    printf("____________________________________________________\n");
}