#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tam = 5; 

typedef struct 
{
    int dia, mes, ano;
}Data;


typedef struct 
{
    char compromisso[60];
    Data data;
}Agenda;


void lerDadosCompro(Agenda *p_agenda);
void buscarAgenda(Agenda *p_agenda);

int main()
{
    Agenda agenda[tam], *p_agenda;
    p_agenda = &agenda;

    lerDadosCompro(p_agenda);
    buscarAgenda(p_agenda);
    
    return 0;
}


void lerDadosCompro(Agenda *p_agenda){
    for (int i = 0; i < tam; i++)
    {
        printf("\nInforme o compromisso: ");
        scanf(" %[^\n]s", p_agenda[i].compromisso);

        printf("Informe a data (dd/mm/aaaa): ");
        scanf("%d%d%d", &p_agenda[i].data.dia, &p_agenda[i].data.mes,&p_agenda[i].data.ano);
    }
}

void buscarAgenda(Agenda *p_agenda){
    int mes, ano;
    do
    {
        printf("\nPara buscar o compromisso informe mes e ano (mm/aaaa): ");
        scanf("%d%d", &mes, &ano);
        
        for (int i = 0; i < tam; i++)
        {
            if (mes == p_agenda[i].data.mes && ano == p_agenda[i].data.ano)
            {
                printf("\n\nCompromisso: %s\nData: %d/%d/%d\n", p_agenda[i].compromisso, p_agenda[i].data.dia, p_agenda[i].data.mes, p_agenda[i].data.ano);
            }
        }
    } while (mes != 0);
}