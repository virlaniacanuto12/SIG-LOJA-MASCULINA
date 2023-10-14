#include <stdio.h> 
#include <stdlib.h>
#include "caixa.h"
#include "../auxFuncoes/auxFuncoes.h"


int exibeMetodoPag(char escolhaPag) {
  switch (escolhaPag) {
  case '1':
    condicoesPixEspecie();
    break;
  case '2':
    condicoesCartao();
    break;
  case '3':
    condicoesPixEspecie();
    break;
  default:
    printf("------------------>Opção inválida!<-----------------\n");
  }
  return 0;
}

float leValor() {
  float valorCompra;
  printf("Insira o valor a ser pago:");
  scanf("%f", &valorCompra);
  return valorCompra;
}

void exibirPix() { printf("CHAVE PIX: shopman@gmail.com"); }

void leMetodoPag(void){
  char charOpcao = '0';
  printf("Escolha o método de pagamento:\n");
  printf("(1) PIX\n");
  printf("(2) CARTÃO\n");
  printf("(3) ESPÉCIE\n");
  scanf(" %c", &charOpcao);
  exibeMetodoPag(charOpcao);
}

int condicoesCartao(void) {
  float valorFinal = 0;
  float valorCompra = 0;
  float parcelas;
  char decisao;

  valorCompra = leValor();

  if (valorCompra < 500) {
    printf("Valor disponível para dividir em 2x\n");
    printf("Deseja dividir(s/n)?");
    scanf(" %c", &decisao);
    if (decisao == 's') {
      valorFinal = valorCompra + 20;
      parcelas = valorFinal / 2;
      printf("                      \n");
      printf("RESUMO FINAL DA COMPRA\n");
      printf("Valor final: R$%.2f\n", valorFinal);
      printf("Parcelas: R$%.2f\n", parcelas);
    }else{
      printf("RESUMO FINAL DA COMPRA\n");
      printf("Valor final: R$%.2f\n", valorFinal);
    }
    return 1;
  } 
  
  else if (valorCompra >= 500 && valorCompra < 1200) {
    printf("Valor disponível para dividir em 4x\n");
    printf("Deseja dividir(s/n)?");
    scanf(" %c", &decisao);
    if (decisao == 's') {
      valorFinal = valorCompra + 20;
      parcelas = valorFinal / 4;
      printf("                      \n");
      printf("RESUMO FINAL DA COMPRA\n");
      printf("Valor final: R$%.2f\n", valorFinal);
      printf("Parcelas: R$%.2f\n", parcelas);
    }else{
      printf("RESUMO FINAL DA COMPRA\n");
      printf("Valor final: R$%.2f\n", valorFinal);
    }
    return 1;
  } 
  
  else if (valorCompra > 1200) {
    printf("Valor disponível para dividir em 8x\n");
    printf("Deseja dividir(s/n)?");
    scanf(" %c", &decisao);
    if (decisao == 's') {
      valorFinal = valorCompra + 20;
      parcelas = valorFinal / 8;
      printf("                      \n");
      printf("RESUMO FINAL DA COMPRA\n");
      printf("Valor final: R$%.2f\n", valorFinal);
      printf("Parcelas: R$%.2f\n", parcelas);
    }else{
      printf("RESUMO FINAL DA COMPRA\n");
      printf("Valor final: R$%.2f\n", valorFinal);
    }
    return 1;
  }
  return 0;
}

int condicoesPixEspecie(void) {
  float valorFinal;
  float valorCompra;

  valorCompra = leValor();

  if (valorCompra <= 500) {
    valorFinal = valorCompra - desconto(valorCompra, 5);
    printf("RESUMO FINAL DA COMPRA\n");
    printf("Valor da compra: R$ %.2f\n", valorCompra);
    printf("Valor com desconto: R$ %.2f\n", valorFinal);
    return 1;
  } else if (valorCompra > 500) {
    valorFinal = valorCompra - desconto(valorCompra, 10);
    printf("RESUMO FINAL DA COMPRA\n");
    printf("Valor da compra: R$%.2f\n", valorCompra);
    printf("Valor com desconto: R$%.2f\n", valorFinal);
    return 1;
  } else if (valorCompra >= 1000) {
    valorFinal = valorCompra - desconto(valorCompra, 10);
    printf("RESUMO FINAL DA COMPRA\n");
    printf("Valor da compra: R$%.2f\n", valorCompra);
    printf("Valor com desconto: R$%.2f\n", valorFinal);
    return 1;
  }
  return 0;
}


/*A função pagamento caixa deverá pedir o cód de barras até as peças escolhiidas pelo cliente acabarem. 
Após isso, é exibido o valor total das suas compras e o programa segue. A informação data será pedida para 
que a dinâmica dos relatórios possa ser feita*/

void pagamentoCaixa(void){
    //char charOpcao = '0';
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
    printf("                  CAIXA-PAGAMENTO                   \n");
    printf("                                                    \n");
    printf("               Digite (0) Para Voltar               \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("Vendedor responsável:\n");
    printf("Data:\n");
    printf("Cód de barras:\n");
    printf("Método de pagamento:\n");
    //scanf(" %c",&charOpcao);
    leMetodoPag();
    //printf("%c",charOpcao);
    printf("Vendedor:\n");
    printf("____________________________________________________\n");

}