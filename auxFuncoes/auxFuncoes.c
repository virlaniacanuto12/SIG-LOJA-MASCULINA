#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include "auxFuncoes.h"

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
