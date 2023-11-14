#include <stdio.h> 
#include <stdlib.h>
#include "relatorio.h"

void escolhaMenuRelatorio(char escolha){
    switch(escolha){
        case '1':
            relatorioVendedores();
            break;
        case '2':
            saldoVendasDia();
        break;
        case '3':
            destaquesMes();
        break;
        default:
            printf("------------------>Opção inválida!<-----------------\n");
    }
}

void menuRelatorio(void){
    char charOpcao;
    do{
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
        printf("                     RELATÓRIOS                     \n");
        printf("____________________________________________________\n");
        printf("                                                    \n");
        printf("             1- Relatório Vendedor:                 \n");
        printf("             2- Relatório Cliente:                  \n");
        printf("             3- Relatório Mercadoria:               \n");
        printf("             4- Saldo de vendas do mês:             \n");
        printf("             5- Saldo de vendas do dia:             \n");
        printf("             6- Destaques vendedores                \n");
        printf("             0- Voltar                              \n");
        printf("____________________________________________________\n");
        scanf("%c", &charOpcao);
        escolhaMenuRelatorio(charOpcao);
    }while(charOpcao != '0');
}

void relatorioVendedores(void){
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
    printf("                RELATÓRIOS VENDEDOR                 \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1- Vendedores ativos:                  \n");
    printf("             2- Ordem alfabética:                   \n");
    printf("             3- Listar por naturalidade.            \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
}

void saldoVendasMes(void){
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
    printf("                     RELATÓRIOS                     \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                Saldo de vendas do mês:             \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
}

void saldoVendasDia(void){
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
    printf("                     RELATÓRIOS                     \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("               Saldo de vendas do dia:              \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
}

void destaquesMes(void){
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
    printf("                     RELATÓRIOS                     \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("              Vendedores em destaque mês:           \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
}