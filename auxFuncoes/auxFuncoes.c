#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include "auxFuncoes.h"
#include <stdbool.h>
#include <time.h>
#include <unistd.h>


//Função compartilhada por Vinicius Maia
int ddd[27] = {11, 21, 27, 31, 41, 47, 51, 61, 62, 63, 65, 67, 68, 69,
               71, 79, 81, 82, 83, 84, 85, 86, 91, 92, 95, 96, 98};

int buscaDdd(int busca) {
  int tam = sizeof(ddd) / sizeof(ddd[0]);
  for (int i = 0; i < tam; i++) {
    if (ddd[i] == busca) {
      return 1;
    }
  }
  return 0;
}

//Função compartilhada por Vinicius Maia
int buscaNum(int tam, char celular[]) {
  for (int i = 0; i < tam; i++) {
    if (!(celular[i] >= '0' && celular[i] <= '9')) {
      return 0;
    }
  }
  return 1;
}

//Função compartilhada por Vinicius Maia
int validaCel(char celular[]) {

  int tam = strlen(celular);
  int ddd = ((celular[0] - '0') * 10) + (celular[1] - '0');

  if (tam != 11) {
    return 0;
  }

  if (!buscaDdd(ddd)) {
    return 0;
  }

  if (!buscaNum(tam, celular)) {
    return 0;
  }

  return 1;
}

//compartilhada por Vinicius Maia
void limparBufferEntrada() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

//Feita com ajuda do chat GPT
int validarNum(char *senha) {
  for (int i = 0; senha[i] != '\0'; i++) {
    if (!isdigit(senha[i])) {
      return 1; // Sair com erro
    }
  }
  return 0;
}

float desconto(float valorCompra, int porcentagem){
  float desconto;
  float valorFinal;
  desconto = (valorCompra * porcentagem) / 100;
  valorFinal = valorCompra - desconto;
  return valorFinal;
}

//Feita por Mariana Santos
void ler_Datahora(char* dataHora) {
    time_t tempoAtual;
    struct tm *infoTempo;

    time(&tempoAtual);
    infoTempo = localtime(&tempoAtual);

    strftime(dataHora, 20, "%d/%m/%Y %H:%M:%S", infoTempo);
}

// Função baseada no código de https://github.com/RenanMRb/ProjetoEagleEyes.git
int validarCpf(const char* cpf) {
    int i, j, digito1 = 0, digito2 = 0;

    // Verifica se o CPF possui 11 dígitos
    if (strlen(cpf) != 11) {
        return 0;
    }

    // Verifica se o CPF não possui todos os dígitos iguais
    for (i = 0; i < 10; i++) {
        if (cpf[i] != cpf[i + 1]) {
            break;
        }
    }
    if (i == 10) {
        return 0;
    }

    // Calcula os dígitos verificadores do CPF
    for (i = 0, j = 10; i < 9; i++, j--) {
        digito1 += (cpf[i] - '0') * j;
    }
    digito1 %= 11;
    if (digito1 < 2) {
        digito1 = 0;
    } else {
        digito1 = 11 - digito1;
    }
    if ((cpf[9] - '0') != digito1) {
        return 0;
    }

    for (i = 0, j = 11; i < 10; i++, j--) {
        digito2 += (cpf[i] - '0') * j;
    }
    digito2 %= 11;
    if (digito2 < 2) {
        digito2 = 0;
    } else {
        digito2 = 11 - digito2;
    }
    if ((cpf[10] - '0') != digito2) {
        return 0;
    }

    // Se passou por todas as verificações, o CPF é válido
    return 1;
} 
