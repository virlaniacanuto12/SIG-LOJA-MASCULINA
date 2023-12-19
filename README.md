<h1 align = "center">SIG-LOJA-MASCULINA</h1>

## Descrição do Repositório 

Repositório criado para o projeto desenvolvido durante a disciplina de programação.

## Proposta geral do projeto

O presente projeto tem como objetivo desenvolver um programa de computador que auxilie no gerenciamento 
de uma loja de artigos masculinos. O sistema desenvolvido entrega soluções para a loja integrando as informações de clientes, vendedores, mercadoria e vendas. Para que seja obtido, principalmente, um controle 
de vendas maior, no que diz respeito aos vendedores responsáveis, a sua respectiva quantidade de vendas e a controle de mercadoria vendida.


### Compilação

`gcc -c -Wall auxFuncoes/auxFuncoes.c; gcc -c -Wall cadastroCliente/cadastroCliente.c; gcc -c -Wall cadastroCliente/cadastroCliente.c; gcc -c -Wall cadastroMercadoria/cadastroMercadoria.c; gcc -c -Wall cadastroVendedor/cadastroVendedor.c; gcc -c -Wall caixa/caixa.c ; gcc -c -Wall main.c; gcc -o sigloja *.o;`