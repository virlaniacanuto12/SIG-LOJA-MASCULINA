#include <stdio.h> 
#include <stdlib.h>
#include "cadastroMercadoria.h"

char nomeFornecedor[61];
char cnpjFornecedor[15];
char lote[7];

void exibirMenuMercadoria(void){
    char charOpcao;
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("- - - - - - Loja de Artigos Masculinos - - - - - - -\n");
    printf(" Developed by @virlaniacanuto12 -- since Aug, 2023  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("| - - - - - - - - - - SHOPMEN - - - - - - - - - - -|\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                  MENU MERCADORIA                   \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Cadastrar estoque                  \n");
    printf("             2 - Editar estoque                     \n");
    printf("             3 - Excluir estoque                    \n");
    printf("             4 - Pesquisar estoque                  \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    //return charOpcao;
}
/*Sobre o código do lote: será 8 números onde os 4 primeiros se refere ao lote
e os 4 restante sobre a peça em específico.
*/
void cadastroMercadoria(void){
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("- - - - - - Loja de Artigos Masculinos - - - - - - -\n");
    printf(" Developed by @virlaniacanuto12 -- since Aug, 2023  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("| - - - - - - - - - - SHOPMEN - - - - - - - - - - -|\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("|               CADASTRAR MERCADORIA               |\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("Nome do fornecedor:                                 \n");
    printf("CNPJ do fornecedor:                                 \n");
    printf("Cód do produto:                                     \n");  
    printf("Tamanho:                                            \n");
    printf("Cor:                                                \n");
    printf("Preço de venda:                                     \n");
    printf("____________________________________________________\n");

    
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
    printf("| - - - - - - - - - - SHOPMEN - - - - - - - - - - -|\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("|                 EDITAR MERCADORIA                |\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Tipo da peça                       \n");
    printf("             2 - Cód de barras                      \n");
    printf("             3 - Quantidade                         \n");
    printf("             4 - Tamanho                            \n");
    printf("             5 - Cor                                \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    //return charOpcao;
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
    printf("| - - - - - - - - - - SHOPMEN - - - - - - - - - - -|\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("|                EXCLUIR MERCADORIA                |\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          Digite o cód de barras(12 dígitos):       \n");
    printf("          Para voltar (0):                          \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    //return charOpcao;
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
    printf("| - - - - - - - - - - SHOPMEN - - - - - - - - - - -|\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("|               PESQUISAR MERCADORIA               |\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("         Informe cód de barras(12 dígitos):         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    //return charOpcao;
}