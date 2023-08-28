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
    printf("- - - - - - - - - - - SHOPMEN - - - - - - - - - - - \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                  MENU MERCADORIA                   \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Cadastrar estoque                  \n");
    printf("             2 - Editar estoque                     \n");
    printf("             3 - Excluir estoque                    \n");
    printf("             4 - Atualizar estoque                  \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    //return charOpcao;
}

void cadastroMercadoria(void){
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
    printf("                  CADASTRAR ESTOQUE                 \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("Nome do fornecedor:                                 \n");
    printf("CNPJ do fornecedor:                                 \n");
    printf("Lote:                                               \n");
    printf("                   SEÇÃO DAS PEÇAS                  \n");
    printf("                                                    \n");
    printf("Tipo da peça:                                       \n");
    printf("Acessórios(A)|Peças superiores(S)                   \n");
    printf("Peças inferiores(I)|Calçados(C):                    \n");
    printf("                                                    \n");
    printf("Descrição da peça:                                  \n");
    printf("Tamanho:                                            \n");
    printf("Cor:                                                \n");
    printf("Quantidade:                                         \n");
    
}