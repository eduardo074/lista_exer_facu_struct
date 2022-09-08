#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tam = 5; 

typedef struct 
{
    char titulo[30];
    char autor[15];
    int ano;
}Livros;


void lerDadosLivro(Livros *p_livros);
void imprimirDadosLivro(Livros *p_livros, int i);
void buscaTitulo(Livros *p_livros);
void buscaAutor(Livros *p_livros);
void buscaAno(Livros *p_livros);


int main()
{
    Livros livros, *p_livros;
    p_livros = &livros;
    int op;
    
    lerDadosLivro(p_livros);

    printf("\t\n-----Bem vindo, escolha a opcao desejada-----\n\n");

    do
    {
        printf("\n\nOpcoes de busca\n\n1 - titulo\n2 - autor\n3 - ano\n4 - sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            buscaTitulo(p_livros);
            break;
        case 2:
            buscaAutor(p_livros);
            break;
        case 3:
            buscaAno(p_livros);
            break;
        case 4:
            printf("\nSaindo....");
            break;
        
        default:
        printf("\nOpcao invalida...");
            break;
        }

        
    } while (op != 4);
    

    
    return 0;
}

void lerDadosLivro(Livros *p_livros){

    printf("\t\n-------Informe os livros para serem armazenados-------\n\n");

    for (int i = 0; i < tam; i++)
    {
       printf("\nInforme o titulo do livro: ");
       scanf(" %[^\n]s", p_livros[i].titulo);
       printf("Infrome o autor do livro %s:", p_livros[i].titulo);
       scanf(" %[^\n]s", p_livros[i].autor);
       printf("Infrome o ano do livro: ");
       scanf("%d", &p_livros[i].ano);
    }
    
}

void buscaTitulo(Livros *p_livros){

    char buscaTitulo[30];
    int res, cont = 0;

    printf("Informe o titulo a ser buscado: ");
    scanf(" %[^\n]s", buscaTitulo);


    for (int i = 0; i < tam; i++)
    {

        res = strcmp(buscaTitulo, p_livros[i].titulo);

        if (res == 0)
        {
           imprimirDadosLivro(p_livros, i);
        }else{
           cont++; 
        }
    }
   if(cont == tam){
     printf("\n\n%s, Nao foi encontrado\n", buscaTitulo);
   }
}

void buscaAutor(Livros *p_livros){

  char buscaAutor[30];
    int res, cont = 0;

    printf("\nInforme o Autor a ser buscado: ");
    scanf(" %[^\n]s", buscaAutor);


    for (int i = 0; i < tam; i++)
    {

        res = strcmp(buscaAutor, p_livros[i].autor);

        if (res == 0)
        {
           imprimirDadosLivro(p_livros, i);
        }else{
           cont++; 
        }
    }
   if(cont == tam){
     printf("\n\n%s, Nao foi encontrado\n", buscaAutor);
   }
  
}
void buscaAno(Livros *p_livros){
  
    int  cont = 0, ano;

    printf("Informe o Autor a ser buscado: ");
    scanf("%d", &ano);


    for (int i = 0; i < tam; i++)
    {


        if ( ano == p_livros[i].ano)
        {
           imprimirDadosLivro(p_livros, i);
        }else{
           cont++; 
        }
    }
   if(cont == tam){
     printf("\n\n%d, Nao foi encontrado\n", ano);
   }
}


void imprimirDadosLivro(Livros *p_livros, int i){

    printf("\n\nTitulo: %s\nAutor: %s\nAno: %d", p_livros[i].titulo, p_livros[i].autor, p_livros[i].ano);
}


