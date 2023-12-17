#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"
#include <string.h>
#include "../cadastroVendedor/cadastroVendedor.h"
#include "../cadastroMercadoria/cadastroMercadoria.h"

void escolhaMenuRelatorio(char escolha)
{
    getchar();
    switch (escolha)
    {
    case '1':
        relatorioVendedores();
        getchar();
        break;
    case '2':
        relatorioMercadoria();
        getchar();
        break;
    case '3':
        //relatorioMercadoria();
        getchar();
        break;
    case '4':
        // relatorioVendas();
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
        vendedoresNaturalidade();
        getchar();
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
        printf("             2- Relatório Mercadoria                \n");
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
        printf("             1- Vendedores ativos                   \n");
        printf("             2- Listar por naturalidade             \n");
        printf("____________________________________________________\n");
        scanf("%c", &charOpcao);
        menuRelatorioVendedor(charOpcao);
        getchar();
    } while (charOpcao != '0');
}

void vendedoresAtivos(void)
{
    Vendedor *vendedor;
    FILE *fp;
    vendedor = (Vendedor *)malloc(sizeof(Vendedor));
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
        while (fread(vendedor, sizeof(Vendedor), 1, fp))
        {
            if (vendedor->status != 'i')
            {
                exibeVendedor(vendedor);
                printf("\n");
            }
        }
    }
    fclose(fp);
    free(vendedor);
    getchar();
}

void vendedoresNaturalidade(void)
{
    getchar();
    Vendedor *vendedor;
    FILE *fp;
    vendedor = (Vendedor *)malloc(sizeof(Vendedor));

    char naturalidade[50];
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
    printf("                                                    \n");
    printf("         De qual cidade vc deseja filtrar?          \n");
    printf("                                                    \n");
    leNaturalidade(naturalidade);
    printf("                                                    \n");

    fp = fopen("arquivoVendedor.bin", "rb");

    if (fp == NULL)
    {
        printf("\nSem registro de vendedores. Faça primeiro os cadastros para depois listar.\n");
    }
    else
    {
        while (fread(vendedor, sizeof(Vendedor), 1, fp))
        {
            if (strcmp(vendedor->naturalidade, naturalidade) == 0)
            {
                exibeVendedor(vendedor);
                printf("\n");
            }
        }
    }
    fclose(fp);
    free(vendedor);
    getchar();
}

void menuRelatorioMercadoria(char escolha)
{
    switch (escolha)
    {
    case '1':
        mercadoriaCor();
        getchar();
        break;
    case '2':
        mercadoriaTam();
        getchar();
        break;
    default:
        printf("------------------>Opção inválida!<-----------------\n");
    }
}

void relatorioMercadoria(void)
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
        printf("             1- Mercadoria por cor                  \n");
        printf("             2- Mercadoria por tamanho              \n");
        printf("____________________________________________________\n");
        scanf("%c", &charOpcao);
        menuRelatorioMercadoria(charOpcao);
        getchar();
    } while (charOpcao != '0');
}

void mercadoriaCor(void)
{
    getchar();
    Mercadoria *mercadoria;
    FILE *fp;
    mercadoria = (Mercadoria *)malloc(sizeof(Vendedor));

    char cor[50];
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
    printf("            RELATÓRIO MERCADORIA POR COR            \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("           Qual cor vc deseja filtrar?              \n");
    printf("                                                    \n");
    leCor(cor);
    printf("                                                    \n");
    //getchar();

    fp = fopen("arquivoMercadoria.bin", "rb");

    if (fp == NULL)
    {
        printf("\nSem registro de vendedores. Faça primeiro os cadastros para depois listar.\n");
    }
    else
    {
        while (fread(mercadoria, sizeof(Mercadoria), 1, fp))
        {
            if (strcmp(mercadoria->cor, cor) == 0)
            {
                exibeMercadoria(mercadoria);
                printf("\n");
            }
        }
    }
    fclose(fp);
    free(mercadoria);
    getchar();
}

void mercadoriaTam(void)
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
    printf("           RELATÓRIO MERCADORIA POR TAMANHO         \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
}