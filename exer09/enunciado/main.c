#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tam = 5; 

typedef struct 
{
    char nome[20];
    int qtd;
    
}Igredientes;

typedef struct 
{
    char nome[25];
    int qtdIngre;
    Igredientes igredientes[];
}Receitas;

void lerDadosRecita(Receitas *p_receitas);
void buscarReceita(Receitas *p_receitas);

int main()
{
    Receitas receitas[tam], *p_receitas;
    p_receitas = &receitas;

    lerDadosRecita(p_receitas);
    buscarReceita(p_receitas);
    
    return 0;
}

void lerDadosRecita(Receitas *p_receitas){
    

    for (int i = 0; i < tam; i++)
    {
        printf("\t\n\n----------------Bem vindo----------------\n");
        printf("Informe o nome da receita: ");
        scanf(" %[^\n]s", p_receitas[i].nome);
        printf("Informe a quantidade de igredientes: ");
        scanf("%d", &p_receitas[i].qtdIngre);
        for (int j = 0; j < p_receitas[i].qtdIngre; j++)
        {
            printf("Informe o nome do igrediente: ");
            scanf(" %[^\n]s", p_receitas[i].igredientes[j].nome);
            printf("Informe a quantidade do igrediente: ");
            scanf("%d", &p_receitas[i].igredientes[j].qtd);
        }
    }
}

void buscarReceita(Receitas *p_receitas){
    char nome[25];
    int res, cont;

    do
    {
        printf("\t\n\n----------BUSCAR RECEITA----------\n");

        printf("Informe o nome da receita a ser buscada, ou digie p para parar: ");
        scanf(" %[^\n]s", nome);

        cont = 0;
    
        for (int i = 0; i < tam; i++)
        {
            res = strcmp(nome , p_receitas[i].nome);
            if (res == 0)
            {
                printf("\n\nNome da receita: %s\n", p_receitas[i].nome);
                printf("Quantidade de igredientes da receita: %d", p_receitas[i].qtdIngre);
                for (int j = 0; j < p_receitas[i].qtdIngre; j++)
                {
                    printf("\nNome: %s\nQuantidade: %d", p_receitas[i].igredientes[j].nome, p_receitas[i].igredientes[j].qtd);
                }
            }else{
                cont++;
            }
        }
        if (cont == tam)
        {
            printf("\nReceita nao encotrada\n");
        }
        
    } while (nome[0] != 'p');
}