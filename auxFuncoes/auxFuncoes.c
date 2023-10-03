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
        printf("Inválido");
        return 0;
    }
    // Verificar se o usuário não digitou um espaço em branco,tanto no ínicio como no final
    if ((isspace(nome[0])) || (isspace(nome[tam - 2]))) {
        printf("Inválido");
        return 0;
    }
    //esse loop serve para procurar a questão de números
    for (int j = 0; j < tam - 1; j++) {
        if (!letraAcentuada(nome[j])) {
            printf("Inválido");
            return 0;
        }
    }
    // Verifica se dois espaços em branco consecutivos
    for (int i = 0; i < tam - 2; i++) {
        if ((isspace(nome[i])) && (isspace(nome[i + 1]))) {
            printf("Inválido");
            return 0;
        }
    }
    return 1;
}

void leSenha(char *senha){
  printf("Digite sua senha:");
  fgets(senha, sizeof(senha), stdin);
  verificarSenha(senha);
}

void leNomes(char *nome){
  printf("Nome:");
  fgets(nome, sizeof(nome), stdin);
  validarNome(nome);
}
