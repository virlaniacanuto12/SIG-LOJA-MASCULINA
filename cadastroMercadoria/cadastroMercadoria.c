#include <stdio.h> 
#include <stdlib.h>
#include "cadastroMercadoria.h"


void exibirMenu(void){
    char charOpcao;
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("- - - - - - - - CADASTRO-MERCADORIA - - - - - - - - \n");
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

