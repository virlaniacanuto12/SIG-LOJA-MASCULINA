#include <stdio.h>
#include <stdlib.h>
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

void leSenha(void) {
  char senha[4]; 
  int i = 1;
  while (i) {
    printf("Digite sua senha:");
    fgets(senha, sizeof(senha), stdin);
    limparBufferEntrada();
    i = validarNum(senha);
    if (i == 1) {
      printf("Senha inválida. Digite apenas números!\n");
    }
  }
}