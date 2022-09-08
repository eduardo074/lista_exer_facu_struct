#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int tam = 5;

typedef struct{
    char matricula[30], nome[30];
    float nota1[3];
}Aluno;

void cadastrarDadosAluno(Aluno *p_aluno);
void alunoMaiorNota(Aluno *p_aluno);
void maiorMedia(Aluno *p_aluno, float *p_media);
void imprimirResultado(Aluno *p_aluno, float *p_media);

int main()
{
    Aluno aluno[tam], *p_aluno;
    p_aluno = &aluno;
    int op = 0;
    float media[5] = {0}, *p_media;
    p_media = &media;
    cadastrarDadosAluno(p_aluno);

    do
    {

        printf("\n\n\t------Menu do aluno------\n\n");
        printf("1 - Encontrar o aluno com a maior nota da primeira prova\n2 - Encontrar aluno com maior media geral e a menor media geral\n3 - Mostrar Os alunos aprovados e reprovados\n4 - sair");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            alunoMaiorNota(p_aluno);
            break;

        case 2:
            maiorMedia(p_aluno, p_media);
            break;

        case 3:
            imprimirResultado(p_aluno, p_media);
            break;

        case 4:
        printf("\nSaindo.......");
            break;
        
        default:
        printf("Opcao Invalida\n");
            break;
        }
    

    } while (op > 0 && op < 4);
    
    return 0;
}

void cadastrarDadosAluno(Aluno *p_aluno){

    for (int i = 0; i < tam; i++)
    {

        printf("\n\nInforme o numero da matricula do aluno %d: ", i);
        fgets(p_aluno[i].matricula, 30, stdin);
        printf("Informe o nome do aluno: ");
        fgets(p_aluno[i].nome, 30, stdin);
        for (int j = 0; j < 3; j++)
        {
            printf("\nInforma a nota %d nota de %s  ",j, p_aluno[i].nome);
            scanf("%f", &p_aluno[i].nota1[j]);
        }
        scanf("%c");
    } 
}

void alunoMaiorNota(Aluno *p_aluno){

    float maiorNota = 0;
    int copy_i;

    for (int i = 0; i < tam; i++)
    {
        if (p_aluno[i].nota1[0] > maiorNota)
        {
            maiorNota = p_aluno[i].nota1[0];
            copy_i = i;
        }
    }
    printf("\n\nO aluno com maior nota da primeira prova eh %s com %.2f ", p_aluno[copy_i].nome, maiorNota);
}
void maiorMedia(Aluno *p_aluno, float *p_media){

    float maiorMedia = 0, menorMedia = 0 ;
    int copy_i, copy_i_menor;

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            p_media[i] = p_media[i] + p_aluno[i].nota1[j];
        }
    }
    for (int i = 0; i < tam; i++)
    {
        p_media[i] = p_media[i] / tam;
    }

    for (int i = 0; i < tam; i++)
    {
        if(i == 0){
            menorMedia = p_media[i];
        }
        if (p_media[i] > maiorMedia)
        {
            maiorMedia = p_media[i];
            copy_i = i;
        }
        if (p_media[i] < menorMedia)
        {
            menorMedia = p_media[i];
            copy_i_menor = i;
        }
    }
    printf("\n\nA maior media eh %.2f do aluno %s", maiorMedia, p_aluno[copy_i].nome);
    printf("\nA menor media eh %.2f do aluno %s", menorMedia, p_aluno[copy_i_menor].nome);
}

void imprimirResultado(Aluno *p_aluno, float *p_media){
    for (int i = 0; i < tam; i++)
    {
        printf("\no aluno %s com media %.2f foi ",p_aluno[i].nome, *(p_media + i));
        if ( *(p_media + i) >= 6)
        {
            printf("Aprovado\n");
        }else{
            printf("Reprovado\n");
        }
    }
}