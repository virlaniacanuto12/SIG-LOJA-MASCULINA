#include <stdio.h> 
#include <stdlib.h>
#include "cadastroMercadoria/cadastroMercadoria.h" 
#include "cadastroVendedor/cadastroVendedor.h" 
#include "caixa/caixa.h"
#include "cadastroCliente/cadastroCliente.h"
#include "relatorios/relatorio.h"
#include "auxFuncoes/auxFuncoes.h"

void tela_apresentation(void) {
  char enter;
  system("clear||cls");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("----Universidade Federal do Rio Grande do Norte-----\n");
  printf("------------Centro de Ensino Superior---------------\n");
  printf("-----Departamento de Computacao e Tecnologia--------\n");
  printf("---------Disciplina DCT1106 --> Programacao---------\n");
  printf("-------------Projeto SIG-LOJA-MASCULINA-------------\n");
  printf("  Developed by @virlaniacanuto12 -- since Aug, 2023 \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("- - - - - - - - -SIG-LOJA-MASCULINA- - - - - - - - -\n");
  printf("                                                    \n");
  printf(" Projeto tem como objetivo desenvolver um programa  \n");
  printf(" que realize a gestão e o acompanhamento do         \n");
  printf(" funcionamento e logiśtica de uma                   \n");
  printf(" loja de artigos masculinos                         \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("-----------------------ALUNA------------------------\n");
  printf("                                                    \n");
  printf("             Virlania Micarla Medeiros Canuto       \n");
  printf("____________________________________________________\n");
  printf("---------->Pressione enter para continuar!<---------\n");
  scanf("%c",&enter);
  //getchar();
}

char tela_principal(void) {
  char escolha;
  system("clear||cls");
  printf("\n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("----Universidade Federal do Rio Grande do Norte-----\n");
  printf("------------Centro de Ensino Superior---------------\n");
  printf("-----Departamento de Computacao e Tecnologia--------\n");
  printf("---------Disciplina DCT1106 -- Programacao----------\n");
  printf("------------Projeto SIG-LOJA-MASCULINA--------------\n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("- - - - - - - - SIG-LOJA-MASCULINA - - - - - - - - -\n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("             1 - Cadastro Vendedor                  \n");
  printf("             2 - Cadastro Mercadoria                \n");
  printf("             3 - Cadastro Cliente                   \n");
  printf("             4 - Caixa                              \n");
  printf("             5 - Relatórios                         \n");
  printf("             0 - Encerrar                           \n");
  printf("____________________________________________________\n");
  scanf("%c",&escolha);
  getchar();
  return escolha;
} 

int main(){
  char escolha;
    do{
      tela_apresentation();
      escolha = tela_principal();
      switch(escolha){
        case '0':
          printf("----------Encerrando programa.............\n");
          break;
        case '1':
          menuVendedor();
        break;
        case '2':
          menuMercadoria();
        break;
        case '3':
          menuCliente();
        break;
        case '4':
          menuCaixa();
        break;
        case '5':
          menuRelatorio();
        break;
        default:
          printf("------------Opção inválida!--------------\n");
      }
    } while(escolha != '0');
	return 0; 
}
