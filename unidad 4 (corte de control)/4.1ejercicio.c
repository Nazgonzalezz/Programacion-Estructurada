/*4.1 Se dispone de un archivo llamado Rating.dat que guarda la información de los puntos obtenidos de rating en
los distintos programas de canales de cable a lo largo del día. Cada registro contiene:
• Número de canal (entero)
• Programa (texto de 35 caracteres máximo)
• Rating (float)
El archivo se encuentra ordenado por canal.
Se solicita informar:
a. Aquellos canales que obtengan menos de 15 puntos en total.
b. El canal más visto.
c. Generar un archivo con el promedio de rating de cada canal que incluya dos campos:
• Número de canal.
• Promedio.*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct  {
                   int numCanal;
                   char programa [36];
                   float rating;
                }T_CANAL;

typedef struct  {
                    int numCanal;
                    float promedio;
                }T_NUEVOARCH;
#include<stdio.h>
#include<string.h>
void mostrar();
int main()
{
    int canalActual,cont,numMayor;
    float puntos,promedio,mayor=-1;
    char vNomMayor[36];
    FILE * arch;
    FILE * arch2;
    T_CANAL aux;
    T_NUEVOARCH nuevo;
    arch=fopen("RATING.dat","rb");
    arch2=fopen("Nuevo.dat","wb");
    if(arch==NULL||arch2==NULL)
    {
        printf("error de archivo");
        exit(1);
    }
    //-------------------------------------------------------------------------------------------------------------------------------
    fread(&aux,sizeof(T_CANAL),1,arch);
    while(!feof(arch))
    {
        canalActual=aux.numCanal;
        puntos=0;
        cont=0;
        //-----------------------------------------------------------------------------------------------------------------------------
        while(aux.numCanal==canalActual&&!feof(arch ))
        {
            cont++;
            puntos+=aux.rating;
            fread(&aux,sizeof(T_CANAL),1,arch);
        }
        //----------------------------------------------------------------------------------------------------------------------------
        promedio=puntos/cont;
        if(promedio<15)
        {
            printf("\nnumero de canal que tiene menos de 15 puntos es: %d\n",canalActual);
        }
        if(mayor==-1||promedio>mayor)
        {
            strcpy(vNomMayor,aux.programa);
            numMayor=aux.numCanal;
            mayor=promedio;
        }
        nuevo.numCanal=canalActual;
        nuevo.promedio=promedio;

        fwrite(&nuevo,sizeof(T_NUEVOARCH),1,arch2);
    }
    //-------------------------------------------------------------------------------------------------------------------------------
    fclose(arch);
    fclose(arch2);
    printf("\nEl canal mas visto es %d y el nombre es %s ",numMayor,vNomMayor);
    mostrar();
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrar()
{
    T_CANAL aux1;
    FILE * arch3;
    arch3=fopen("RATING.dat","rb");
    if(arch3==NULL)
    {
        printf("error de archivo ");
        exit(1);
    }
    fread(&aux1,sizeof(T_CANAL),1,arch3);
    printf("\n\n\n %-35s %9s %7s \n","NOMBRE","NUM CANAL","RATING");
    while(!feof(arch3))
    {
        printf("%-35s %9d %7.2f\n",aux1.programa,aux1.numCanal,aux1.rating);
        fread(&aux1,sizeof(T_CANAL),1,arch3);
    }
}





