#include <stdio.h> 
#include <stdlib.h>
#include "cadastroMercadoria/cadastroMercadoria.h" 
#include "cadastroVendedor/cadastroVendedor.h" 
#include "caixa/caixa.h"
#include "cartaoLoja/cartaoLoja.h"



char tela_apresentation(void) {
  char enter;
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
  enter = getchar();
  return enter;
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
  printf("             3 - Caixa                              \n");
  printf("             4 - Cartão da loja                     \n");
  printf("             5 - Relatórios                         \n");
  printf("             0 - Sair                               \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("\n");
  scanf("%c",&escolha);
  return escolha;
} 

int main(){

  char tecla;
  while (tecla != 10){
    tecla = tela_apresentation();
  }

  char opcao;
  opcao = tela_principal();

  switch (opcao){
   case '1':
    exibirMenuVendedor();
   break;

   case '2':
    exibirMenuMercadoria();
   break;

   case '3':
    pagamentoCaixa();
   break;

   case '4':
    menuCartao();
   break;

   case '5':
    printf("Cartão da Loja");
   break;

   case '6':
    printf("Relatórios");
   break;
  
   default:
    printf("----------->Opção inválida!<------------");
  }

	return 0; 
}
