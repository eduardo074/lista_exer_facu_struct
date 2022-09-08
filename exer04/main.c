#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tam = 10; 


typedef struct
{
    char nome[30];
    int matricula;
    float mediaFinal;
}Aluno;

void lerDados(Aluno *p_aluno);
void resultado(Aluno *p_aluno, Aluno *p_aprovados, Aluno *p_reprovados);


int main()
{
    Aluno aluno[tam], *p_aluno, aprovados[tam], reprovados[tam], *p_aprovados, *p_reprovados;

    p_aluno = &aluno;
    p_aprovados = &aprovados;
    p_reprovados = &reprovados;


    lerDados(p_aluno);
    resultado(p_aluno, p_aprovados, p_reprovados);
    return 0;
}


void lerDados(Aluno *p_aluno){
    for (int i = 0; i < tam; i++)
    {
       printf("\nInforme o nome do aluno: ");
       scanf(" %[^\n]s", p_aluno[i].nome);
       printf("Informe a matricula do aluno: ");
       scanf("%d", &p_aluno[i].matricula);
       printf("Informe a media final do aluno: ");
       scanf("%f", &p_aluno[i].mediaFinal);
    }
}

void resultado(Aluno *p_aluno, Aluno *p_aprovados, Aluno *p_reprovados){
    int  j = 0, k = 0;
    
    for (int i = 0; i < tam; i++)
    {
        if (p_aluno[i].mediaFinal >= 5)
        {
            strcpy(p_aprovados[j].nome, p_aluno[i].nome);
            p_aprovados[j].matricula = p_aluno[i].matricula;
            p_aprovados[j].mediaFinal = p_aluno[i].mediaFinal;
    
            j++;
        }else{
            strcpy(p_reprovados[k].nome, p_aluno[i].nome);
            p_reprovados[k].matricula = p_aluno[i].matricula;
            p_reprovados[k].mediaFinal = p_aluno[i].mediaFinal;
            
            k++;
        }
    }
    

    printf("\n\n-----Aprovados-----");
    for (int i = 0; i < j; i++)
    {
       printf("\n\nNome: %s\nMatricula: %d\nMedia final: %.2f",p_aprovados[i].nome, p_aprovados[i].matricula, p_aprovados[i].mediaFinal);
    }

    printf("\n\n-----Reprovados-----");
    for (int i = 0; i < k; i++)
    {
      printf("\n\nNome: %s\nMatricula: %d\nMedia final: %.2f",p_reprovados[i].nome, p_reprovados[i].matricula, p_reprovados[i].mediaFinal);
    }
}