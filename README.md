<h1 align = "center">SIG-LOJA-MASCULINA</h1>

## Descrição do Repositório 

Repositório criado para o projeto desenvolvido durante a disciplina de programação.

## Proposta geral do projeto

O presente projeto tem como objetivo desenvolver um programa de computador que auxilie no gerenciamento 
de uma loja de artigos masculinos. O sistema desenvolvido entrega soluções para a loja integrando as informações de clientes, vendedores, mercadoria e vendas. Para que seja obtido, principalmente, um controle 
de vendas maior, no que diz respeito aos vendedores responsáveis, a sua respectiva quantidade de vendas e a controle de mercadoria vendida.

## Atenção - Ler as especificações abaixo poderão ajudar na compreensão

No mód de cliente, fora as funcionalidades do CRUD, tem a opção 5 que faz a listagem dos clientes por ordem alfabética(um dos relatórios). Já no mód de vendedor tem duas funcionalidade a aparte do CRUD: conquistas e registro de vendas. A funcionalidade de registro de vendas é o relatório combinado, que lista as vendas(pegando do arquivo caixa) com base no cpf do vendedor. Ou seja, todas as vendas realizadas por ele, serão listadas nessa opção. Na função de conquistas, eu exibo um pódio dos 3 melhores vendedores com base nas pontuações recebidas a partir do valor das vendas em que eles são os responsáveis.

### Compilação

`gcc -c -Wall auxFuncoes/auxFuncoes.c; gcc -c -Wall cadastroCliente/cadastroCliente.c; gcc -c -Wall cadastroCliente/cadastroCliente.c; gcc -c -Wall cadastroMercadoria/cadastroMercadoria.c; gcc -c -Wall cadastroVendedor/cadastroVendedor.c; gcc -c -Wall caixa/caixa.c ; gcc -c -Wall main.c; gcc -o sigloja *.o;`