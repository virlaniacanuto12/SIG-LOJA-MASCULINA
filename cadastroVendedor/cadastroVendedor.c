#include <stdio.h> 
#include <stdlib.h>
#include "cadastroVendedor.h"

void exibirMenuVendedor(void){
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
    printf("                                                    \n");
    printf("____________________________________________________\n");
}

void cadastroVendedor(void){
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
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("              Nome:                                 \n");
    printf("              CPF:                                  \n");
    printf("              Data de nascimento:                   \n");
    printf("              Estado civil:                         \n");
    printf("              Naturalidade:                         \n");
    printf("              Escolaridade:                         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");

}

void atualizarVendedor(void){
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
    printf("                                                    \n");
    printf("____________________________________________________\n");
}

void excluirVendedor(void){
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
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("    Informe o CPF do vendedor que deseja excluir:   \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
}

/*A função registro de vendas irá exibir as vendas que o vendedor informado realizou no mês*/
void registroVendas(void){
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
    printf("                 REGISTRO DE VENDAS                 \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("        Informe o CPF do vendedor que deseja        \n"); 
    printf("          verificar o registro de vendas:           \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
}
/*A função conquista irá exibir as conquistas que aquele vendedor ja possui.
Vai existir o broche de ouro, prata e bronze que vai variar de acordo com o valor vendido pelo vendedor*/
void conquistas(void){
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
    printf("                    CONQUISTAS                      \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("        Informe o CPF do vendedor que deseja        \n"); 
    printf("            verificar as conquistas:                \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
}
