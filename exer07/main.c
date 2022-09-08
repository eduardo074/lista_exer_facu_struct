#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tam = 5; 

typedef struct 
{
   int codigo, qtd;
   float preco;
   char nomeProduto[30];
}Produtos;

void lerDadosProdutos(Produtos *p_produtos);
void verificarEstoque(Produtos *p_produtos);

int main()
{
    Produtos produtos[tam], *p_produtos;
    p_produtos = &produtos;

    lerDadosProdutos(p_produtos);
    verificarEstoque(p_produtos);
    
    return 0;
}


void lerDadosProdutos(Produtos *p_produtos){


    printf("\t\n------------------Cadastrar produtos------------------\n\n");
    for (int i = 0; i < tam; i++)
    {
        printf("\nInforme o codigo do produto: ");
        scanf("%d", &p_produtos[i].codigo);
        printf("Informe o nome do produto: ");
        scanf(" %[^\n]s", p_produtos[i].nomeProduto);
        printf("Informe o preco do produto: ");
        scanf("%f", &p_produtos[i].preco);
        printf("Informe a quatidade de %s: ", p_produtos[i].nomeProduto);
        scanf("%d", &p_produtos[i].qtd);
    }
}

void verificarEstoque(Produtos *p_produtos){
    int codigo, qtd, contqtd = 0;

    do
    {
        printf("\t\n\n------------------Faca seu pedido------------------\n\n");
        printf("\nInforme o codigo do produto: ");
        scanf("%d", &codigo);

        for (int i = 0; i < tam; i++)
        {
            if (codigo == p_produtos[i].codigo)
            {
                printf("\nProduto encontrado\n");
                printf("\nEstoque disponivel\nCodigo: %d\nNome: %s\nPreco unidade: %.2f R$\nQuantidade disponivel: %d\n", p_produtos[i].codigo, p_produtos[i].nomeProduto, p_produtos[i].preco, p_produtos[i].qtd);

                printf("\nInforme a quantidade a ser pedida: ");
                scanf("%d", &qtd);

                if (qtd <= p_produtos[i].qtd)
                {
                    printf("\n------------------Pedido realizado com sucesso------------------\n");
                    printf("\nEstoque atualizado\n");
                    p_produtos[i].qtd = p_produtos[i].qtd - qtd;
                    printf("\nCodigo: %d\nNome: %s\nPreco unidade: %.2f R$\nQuantidade disponivel: %d\n", p_produtos[i].codigo, p_produtos[i].nomeProduto, p_produtos[i].preco, p_produtos[i].qtd);
                }else{
                    printf("\nQuanidade indisponivel\n");
                }
            }
            if (codigo != p_produtos[i].codigo)
            {
                 contqtd++;
            }
            
        }
        if (contqtd == tam)
        {
            printf("\nCodigo Invalido\n");
        }
        
        
    } while (codigo != 0);
    
}