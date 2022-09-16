#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tam = 2; 

typedef struct
{
    int codOrigem, codDestino;
}Voos;

typedef struct
{
    int codigo, qtdVoos_saem, qtdVoos_chegam;
}Aeroportos;

void lerAeroportos(Aeroportos *p_aeroportos,Voos *p_voos);

int main()
{
    Aeroportos aeroportos, *p_aeroportos;
    p_aeroportos = &aeroportos;

    Voos voos, *p_voos;
    p_voos = &voos;

    lerAeroportos(p_aeroportos, p_voos);

    return 0;
}
void lerAeroportos(Aeroportos *p_aeroportos, Voos *p_voos){
    

    printf("\t\n\n---------Cadastrento de areoporto---------\n\n");
    for (int i = 0; i < tam; i++)
    {
        printf("\nInforme o codigo do aeroporto %d: ", i);
        scanf("%d", &p_aeroportos[i].codigo);
    }
    
    
    for (int i = 0; i < tam; i++)
    {
        int cont = 0;
        printf("\n\n-----Voo numero %d-----", i);

       
        do
        {
            printf("\nInforme o codigo do aeroporto de origem: ");
            scanf("%d", &p_voos[i].codOrigem);
            
               for (int j = i + 1; j < tam; j++)
               {
                 if (p_voos[i].codOrigem == p_aeroportos[j].codigo)
                 {
                    cont++;
                    break;
                 }
               }
            

            if (cont == 0)
            {
                printf("\nCodigo nao existente\n");
            }
            printf("\n\n%d\n\n", cont);
        } while (cont != 1);
        
        

        printf("\nInforme o codigo do aeroporto de destino: ");
        scanf("%d", &p_voos[i].codDestino);
    }
    
    
}