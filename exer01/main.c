#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int hora, minutos, segundos;
}Horario;

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    Horario horario;
    Data data;
    char texto[150];
}Anotacoes;


void lerDadosAnotacoes(Anotacoes *p_anotacoes);
void imprimirDadosAnotacoes(Anotacoes *p_anotacoes);

int main()
{
    Anotacoes anotacoes, *p_anotacoes;
    p_anotacoes = &anotacoes;
    lerDadosAnotacoes(p_anotacoes);
    imprimirDadosAnotacoes(p_anotacoes);

    return 0;
}

void lerDadosAnotacoes(Anotacoes *p_anotacoes){

    printf("\nDescreve o compromisso\n");
    scanf("%[^\n]s", p_anotacoes->texto);
    printf("Informe a data do compromisso, dd/mm/aaaa: ");
    scanf("%d%d%d", &p_anotacoes->data.dia, &p_anotacoes->data.mes,&p_anotacoes->data.ano);
    printf("\nInforme o horario do compromisso, h:mm:ss: ");
    scanf("%d%d%d", &p_anotacoes->horario.hora, &p_anotacoes->horario.minutos,&p_anotacoes->horario.segundos);

}

void imprimirDadosAnotacoes(Anotacoes *p_anotacoes){
    printf("\n\nCompromisso: %s\nData: %d/%d/%d\nHorario: %d:%d:%d\n", p_anotacoes->texto, p_anotacoes->data.dia, p_anotacoes->data.mes, p_anotacoes->data.ano,p_anotacoes->horario.hora,p_anotacoes->horario.minutos,p_anotacoes->horario.segundos);
}