/*4.7 La empresa RED VIAL S.A. desea controlar el flujo vehicular en sus cabinas de peaje a lo largo del mes. Para
ello se debe procesar la información provista por las barreras que se encuentra almacenada en el archivo
barreras.dat que contiene la siguiente información:
• Día (entero)
• Hora (0 a 24)
• Número de barrera (entero)
Dentro del archivo la información se encuentra ordenada por día y hora. Determinar:
a. La cantidad de vehículos por cada hora.
b. La cantidad de vehículos de cada día.
c. Ingresar por teclado los precios del peaje para horario normal y horario pico (de 7 a 11 y de 17 a 19).
Con esos valores guardar un archivo con la recaudación de cada día.*/

#include<stdio.h>

typedef struct
{
    int dia;
    int hora;
    int NroBarrera;
}tBarrera;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int cantdia, canthora, diact, horact;
    float recaudacionxdia=0, precionorm, preciopico;


    tBarrera aux;

    FILE *arch;
    arch=fopen("Barreras.dat","rb");
    if(arch==NULL)
    {
        exit(1);
    }

    printf("\nIngrese el precio del peaje en horario normal:");
    scanf("%f", &precionorm);
    printf("\nIngrese el precio del peaje en horario pico:");
    scanf("%f", &preciopico);
    fread(&aux,sizeof(tBarrera),1,arch);

    while(!feof(arch))
    {
        diact=aux.dia;
        cantdia=0;
        while(!feof(arch)&&diact==aux.dia)
        {
            canthora=0;
            horact=0;
            while(!feof(arch)&&diact==aux.dia&&horact==aux.dia)
            {
                canthora++;
                if((aux.hora>=7&&aux.hora<=11)||(aux.hora>=17&&aux.hora<=19))
                {
                    recaudacionxdia+=preciopico;
                }
                recaudacionxdia+=precionorm;
            }
            cantdia+=canthora;
            printf("\nEl dia %d a la hora %d hubo %d veiculos", diact, horact, canthora);
        }
        printf("\nEl dia %d hubo un total %d vehiculos. Se recaudaron %.2f", diact, cantdia, recaudacionxdia);
    }


    fclose(arch);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
