#include <stdio.h> 
#include <stdlib.h>
#include "caixa.h"


/*A função pagamento caixa deverá pedir o cód de barras até as peças escolhiidas pelo cliente acabarem. 
Após isso, é exibido o valor total das suas compras e o programa segue. A informação data será pedida para 
que a dinâmica dos relatórios possa ser feita*/

void pagamentoCaixa(void){
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
    printf("                       CAIXA                        \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             Data:                                  \n");
    printf("             Cód de barras:                         \n");
    printf("             Método de pagamento:                   \n");
    printf("             Vendedor:                              \n");
    printf("             Cupom de desconto:                     \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
}