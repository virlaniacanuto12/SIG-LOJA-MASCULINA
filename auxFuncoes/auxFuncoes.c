#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include "auxFuncoes.h"

//compartilhada por Vinicius Maia
void limparBufferEntrada() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

/*void leNome(void){
  wchar_t nomeVendedor[51];
  wprintf(L"Nome: ");
  fgetws(nomeVendedor, sizeof(nomeVendedor) / sizeof(nomeVendedor[0]), stdin);
  wprintf(L"%ls", nomeVendedor);
}*/

//Feita com ajuda do chat GPT
int validarNum(char *senha) {
  for (int i = 0; senha[i] != '\0'; i++) {
    if (!isdigit(senha[i])) {
      return 1; // Sair com erro
    }
  }
  return 0;
}

int verificarSenha(char *senha) {
  int i = 1;
  while (i) {
    int tam = strlen(senha);
    i = validarNum(senha);
    if(tam-1 > 4){
      printf("Senha inválida. Digite apenas 4 números!\n");
      i = 0;
    }
    else if (i == 1) {
      printf("Senha inválida. Digite apenas números!\n");
      i = 0;
    }
  }
  return 1;
}

void leSenha(char *senha){
  printf("Digite sua senha:");
  fgets(senha, sizeof(senha), stdin);
  verificarSenha(senha);
 }