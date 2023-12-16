#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"

void escolhaMenuRelatorio(char escolha)
{
    switch (escolha)
    {
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

void menuRelatorioVendedor(char escolha)
{
    switch (escolha)
    {
    case '1':
        vendedoresAtivos();
        break;
    case '2':
        vendedoresOrdem();
        break;
    case '3':
        destaquesMes();
        break;
    default:
        printf("------------------>Opção inválida!<-----------------\n");
    }
}

void menuRelatorio(void)
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
        printf("- - - - - - - - - - - SHOPMEN - - - - - - - - - - - \n");
        printf("____________________________________________________\n");
        printf("                                                    \n");
        printf("                     RELATÓRIOS                     \n");
        printf("____________________________________________________\n");
        printf("                                                    \n");
        printf("             1- Relatório Vendedor                  \n");
        printf("             2- Relatório Cliente                   \n");
        printf("             3- Relatório Mercadoria                \n");
        printf("             3- Relatório Vendas                    \n");
        printf("             0- Voltar                              \n");
        printf("____________________________________________________\n");
        scanf("%c", &charOpcao);
        escolhaMenuRelatorio(charOpcao);
    } while (charOpcao != '0');
}

void relatorioVendedores(void)
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
        printf("- - - - - - - - - - - SHOPMEN - - - - - - - - - - - \n");
        printf("____________________________________________________\n");
        printf("                                                    \n");
        printf("                RELATÓRIOS VENDEDOR                 \n");
        printf("                                                    \n");
        printf("               Digite (0) Para Voltar               \n");
        printf("____________________________________________________\n");
        printf("                                                    \n");
        printf("             1- Vendedores ativos:                  \n");
        printf("             3- Listar por naturalidade:            \n");
        printf("____________________________________________________\n");
        scanf("%c", &charOpcao);
        menuRelatorioVendedor(charOpcao);
        getchar();
    } while (charOpcao != '0');
}

void vendedoresAtivos(void)
{
    Vendedores *vendedores = (Vendedores *)malloc(sizeof(Vendedores));
    FILE *fp;
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
    printf("             RELATÓRIOS VENDEDORES ATIVOS           \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");

    fp = fopen("arquivoVendedor.bin", "rb");

    if (fp == NULL)
    {
        printf("\nSem registro de vendedores. Faça primeiro os cadastros para depois listar.\n");
    }
    else
    {
        while (fread(vendedores, sizeof(Vendedores), 1, fp))
        {
            if (vendedores->status != 'i')
            {
                printf("\nNome: %s\n", vendedores->nomeVendedor);
                printf("CPF: %s\n", vendedores->cpfVendedor);
                printf("Celular: %s\n", vendedores->celVendedor);
                printf("Data de nascimento: %s\n", vendedores->dataNascimento);
                printf("Estado civil: %s\n", vendedores->estadoCivil);
                printf("Escolaridade: %s\n", vendedores->escolaridade);
                printf("Status: %c\n", vendedores->status);
            }
        }
    }
    getchar();
}

void vendedoresNaturalidade(void)
{
    Vendedores *vendedores = (Vendedores *)malloc(sizeof(Vendedores));
    FILE *fp;
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
    printf("        RELATÓRIOS VENDEDORES POR NATURALIDADE      \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("         De qual cidade vc deseja filtrar?          \n");
}

void saldoVendasMes(void)
{
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
    printf("               Saldo de vendas do mês:              \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
}

void saldoVendasDia(void)
{
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

void destaquesMes(void)
{
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