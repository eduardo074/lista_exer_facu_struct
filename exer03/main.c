
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tam = 5; 



typedef struct 
{
    char estado[15];
    char cidade[30];
    char barrio[30];
    char rua[30];
    int numeroCasa;
}Endereco;


typedef struct 
{
    char nome[30];
    Endereco endereco;
}Pessoa;

void coletarDadosPessoas(Pessoa *p_pessoa);
void imprimirOrdemAlfa(Pessoa *p_pessoa);

int main()
{
    Pessoa pessoa[tam], *p_pessoa;
    p_pessoa = &pessoa;

    coletarDadosPessoas(p_pessoa);
    imprimirOrdemAlfa(p_pessoa);
    
    return 0;
}


void coletarDadosPessoas(Pessoa *p_pessoa){


    for (int i = 0; i < tam; i++)
    {
        printf("Informe seu nome: ");
        scanf(" %s", p_pessoa[i].nome);
        printf("Informe o seu estado: ");
        scanf(" %s", p_pessoa[i].endereco.estado);
        printf("Informe o sua cidade: ");
        scanf(" %s", p_pessoa[i].endereco.cidade);
        printf("Informe o seu barrio: ");
        scanf(" %s", p_pessoa[i].endereco.barrio);
        printf("Informe o sua rua: ");
        scanf(" %s", p_pessoa[i].endereco.rua);
        printf("Informe o numero da casa: ");
        scanf("%d", &p_pessoa[i].endereco.numeroCasa);
    }
}

void imprimirOrdemAlfa(Pessoa *p_pessoa){

    printf("\n\nTodos os dados na ordem alfabetica\n\n");

    Pessoa aux1;

    char aux[30];
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (p_pessoa[i].nome[0] > p_pessoa[j].nome[0])
            {
                aux1 = p_pessoa[i];
                p_pessoa[i] = p_pessoa[j];
                p_pessoa[j] = aux1;
            }
        }
    }

      for (int i = 0; i < tam; i++)
    {
        printf("\nnome: %s\n",  p_pessoa[i].nome);
        printf("estado: %s\n", p_pessoa[i].endereco.estado);
        printf("cidade: %s\n", p_pessoa[i].endereco.cidade);
        printf("barrio: %s\n", p_pessoa[i].endereco.barrio);
        printf("rua: %s\n", p_pessoa[i].endereco.rua);
        printf("numero da casa: %d\n", p_pessoa[i].endereco.numeroCasa);
    }
}