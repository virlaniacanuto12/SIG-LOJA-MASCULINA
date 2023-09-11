#include <stdio.h> 
#include <stdlib.h>
#include "cadastroVendedor.h" 

void escolhaMenuVendedor(char escolha){
        switch(escolha){
        case '0':
            printf("Saindo do programa!");
        break;
        case '1':
            cadastroVendedor();
        break;
        case '2':
            atualizarVendedor();
        break;
        case '3':
            excluirVendedor();
        break;
        case '4':
            registroVendas();
        break;
        case '5':
            conquistas();
        break;
        default:
            printf("------------------>Opção inválida!<-----------------\n");
        }
        menuVendedor();
}

char menuVendedor(void){
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
    printf("                   MENU VENDEDOR                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Cadastrar vendedor                 \n");
    printf("             2 - Atualizar vendedor                 \n");
    printf("             3 - Excluir vendedor                   \n");
    printf("             4 - Registro vendas                    \n");
    printf("             5 - Conquistas                         \n");
    printf("             0 - Voltar                             \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    escolhaMenuVendedor(charOpcao);
    return charOpcao;
}

char cadastroVendedor(void){
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
    printf("                CADASTRAR VENDEDOR                  \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("              Nome:                                 \n");
    printf("              Tel:                                  \n");
    printf("              CPF:                                  \n");
    printf("              Data de nascimento:                   \n");
    printf("              Estado civil:                         \n");
    printf("              Naturalidade:                         \n");
    printf("              Escolaridade:                         \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
    return charOpcao;
}

char atualizarVendedor(void){
    char charOpcao;
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("- - - - - - Loja de Artigos Masculinos - - - - - - -\n");
    printf(" Developed by @virlaniacanuto12 -- since Aug, 2023  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf(" - - - - - - - - - - SHOPMEN - - - - - - - - - - -  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                ATUALIZAR VENDEDOR                  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("        Informe a opção que deseja atualizar:       \n");
    printf("                                                    \n");
    printf("            1 - Estado civil                        \n");
    printf("            2 - Naturalidade                        \n");
    printf("            3 - Escolaridade                        \n");
    printf("            0 - Voltar                              \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
    return charOpcao;
}

char excluirVendedor(void){
    char charOpcao;
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("- - - - - - Loja de Artigos Masculinos - - - - - - -\n");
    printf(" Developed by @virlaniacanuto12 -- since Aug, 2023  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf(" - - - - - - - - - - SHOPMEN - - - - - - - - - - -  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                 EXCLUIR VENDEDOR                   \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("    Informe o CPF do vendedor que deseja excluir:   \n");
    printf("____________________________________________________\n");
    scanf("%c", &charOpcao);
    getchar();
    return charOpcao;
}

/*A função registro de vendas irá exibir as vendas que o vendedor informado realizou no mês*/
char registroVendas(void){
    char cpfVendedor;
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("- - - - - - Loja de Artigos Masculinos - - - - - - -\n");
    printf(" Developed by @virlaniacanuto12 -- since Aug, 2023  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf(" - - - - - - - - - - SHOPMEN - - - - - - - - - - -  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                REGISTRO DE VENDAS                  \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("        Informe o CPF do vendedor que deseja        \n"); 
    printf("          verificar o registro de vendas:           \n");
    printf("____________________________________________________\n");
    scanf("%c", &cpfVendedor);
    getchar();
    return cpfVendedor;
}
/*A função conquista irá exibir as conquistas que aquele vendedor ja possui.
Vai existir o broche de ouro, prata e bronze que vai variar de acordo com o valor vendido pelo vendedor*/
char conquistas(void){
    char cpfVendedor;
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("- - - - - - Loja de Artigos Masculinos - - - - - - -\n");
    printf(" Developed by @virlaniacanuto12 -- since Aug, 2023  \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf(" - - - - - - - - - -  SHOPMEN - - - - - - - - - - - \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                    CONQUISTAS                      \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("        Informe o CPF do vendedor que deseja        \n"); 
    printf("            verificar as conquistas:                \n");
    printf("____________________________________________________\n");
    scanf("%c", &cpfVendedor);
    getchar();
    return cpfVendedor;
}
