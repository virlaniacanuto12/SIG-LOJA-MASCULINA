#include <stdio.h> 
#include <stdlib.h>
#include "cadastroMercadoria.h"


void exibirMenu(void){
    char charOpcao;
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("- - - - - - Loja de Artigos Masculinos - - - - - - -\n");
    printf("                                                    \n");
    printf("- - - - - - - - - - - SHOPMEN - - - - - - - - - - - \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("- - - - - - - - - MENU MERCADORIA - - - - - - - - - \n");
    printf("                                                    \n");
    printf("             1 - Cadastrar estoque                  \n");
    printf("             2 - Atualizar estoque                  \n");
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
    printf("- - - - - - - - CADASTRO-MERCADORIA - - - - - - - - \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("Nome do fornecedor:\n");
    printf("CNPJ do fornecedor:\n");
    printf("Lote/remessa:\n");
    printf("____________________________________________________\n");
    printf("Informe a seção das peças:\n");
    printf("Acessórios(A)|Peças superiores(S)|Peças inferiores(I)|Calçados(C)\n");
    printf("Qual o tipo da peças?\n");
    printf("Qual o tamanho das peças?\n");
    printf("Qual a cor das peças?\n");
    printf("Quantidade de peças?\n");
    
}