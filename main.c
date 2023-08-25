#include <stdio.h> 
#include <stdlib.h>
#include "cadastroMercadoria/cadastroMercadoria.h" 

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
  printf("Pressione enter para continuar!\n");
  enter = getchar();
  return enter;
}

char tela_principal(void) {
  char escolha;
  system("clear||cls");
  printf("\n");
  printf("____________________________________________________\n");
  printf("\n");
  printf("----Universidade Federal do Rio Grande do Norte-----\n");
  printf("------------Centro de Ensino Superior---------------\n");
  printf("-----Departamento de Computacao e Tecnologia--------\n");
  printf("---------Disciplina DCT1106 -- Programacao----------\n");
  printf("------------Projeto SIG-LOJA-MASCULINA--------------\n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("- - - - - - - - SIG-LOJA-MASCULINA - - - - - - - - -\n");
  printf("                                                    \n");
  printf("             1 - Cadastro Vendedor                  \n");
  printf("             2 - Cadastro Mercadoria                \n");
  printf("             3 - Seções                             \n");
  printf("             4 - Caixa                              \n");
  printf("             5 - Cartão da loja                     \n");
  printf("             0 - Relatórios                         \n");
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
    printf("Cadastro Vendedor");
   break;

   case '2':
    printf("Cadastro Mercadoria");
    exibirMenu();
   break;

   case '3':
    printf("Seções");
   break;

   case '4':
    printf("Caixa");
   break;

   case '5':
    printf("Cartão da Loja");
   break;

   case '6':
    printf("Relatórios");
   break;

   case '7':
    printf("Fim do programa.");
   break;

   default:
    printf("Opção inválida!");
  }

	return 0; 
}
