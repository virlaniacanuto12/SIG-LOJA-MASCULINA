#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include "auxFuncoes.h"
#include <stdbool.h>

bool v = true;
bool f = false;

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

int verificarSenha(char *senha) {
  int i = 1;
  while (i) {
    int tam = strlen(senha);
    i = validarNum(senha);
    if(tam-1 > 4){
      return 0;
      i = 0;
    }
    else if (i == 1) {
      return 0;
      i = 0;
    }
  }
  return 1;
}

bool letraAcentuada(char c) {   //recebe uma letra por vez
    //um char com as palavras que possam vir a ser acentuadas
    char letras_acentuadas[] = "ÁÀÂÃÉÈÊÍÌÎÓÒÔÕÚÙÛÇáàâãéèêíìîóòôõúùûç"; 
    //ela roda um loop que termina até o caracter nulo do fgets
    for (int i = 0; letras_acentuadas[i] != '\0'; i++) {  
        // aí se a letra em questão for igual ao char letras_acentuadas retornará vdd
        //esse loop e esse if verificiarão toda as letras
        if (c == letras_acentuadas[i]) {
            return true;
        }
    }
    //verifica se a letra c é uma letra ou um espaço em branco 
    return isalpha(c) || c == ' ';
}

//Função compartilhada por Matheus Diniz
int validarNome(char *nome) {
    // Pega o tamanho da variável nome
    int tam = strlen(nome);
    //só permite nome maiores que 2 letras 
    // é utilizado 3 para contar com o \n do teclado
    if (tam<3){
        return 0;
    }
    // Verificar se o usuário não digitou um espaço em branco,tanto no ínicio como no final
    if ((isspace(nome[0])) || (isspace(nome[tam - 2]))) {
        return 0;
    }
    //esse loop serve para procurar a questão de números
    for (int j = 0; j < tam - 1; j++) {
        if (!letraAcentuada(nome[j])) {
            return 0;
        }
    }
    // Verifica se dois espaços em branco consecutivos
    for (int i = 0; i < tam - 2; i++) {
        if ((isspace(nome[i])) && (isspace(nome[i + 1]))) {
            return 0;
        }
    }
    return 1;
}

float desconto(float valorCompra, int porcentagem){
  float desconto;
  float valorFinal;
  desconto = (valorCompra * porcentagem) / 100;
  valorFinal = valorCompra - desconto;
  return valorFinal;
}