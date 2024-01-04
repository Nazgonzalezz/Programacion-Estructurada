/*4.3 Se dispone de un archivo con nombre Llamadas.dat que contiene llamadas telefónicas realizadas en una
empresa. Por cada llamada se dispone de la siguiente información:
        • Sector (15 caracteres máximo)
        • Duración en segundos (entero)
        • Tipo de llamada (entero: 1 local, 2 larga distancia, 3 celular)
El archivo se encuentra organizado por Sector. Se solicita:
    a. Calcular y mostrar por cada sector, la cantidad de llamadas realizadas de cada tipo.
    b. Determinar cuál es el sector que habló la mayor cantidad de tiempo.
    c. En un archivo llamado costos.dat hay un único registro que contiene los costos por segundo de los
    tres tipos de llamadas (3 float). Se debe generar el archivo gastos.dat que totalice los gastos de
    llamadas de cada sector.
    d. Realizar una función que muestre los datos almacenados en gastos.dat en forma de listado.
    e. Generar un archivo para cada sector con el detalle de llamadas valorizado. El archivo se debe
    generar con nombresector.dat y debe contener:
        • Duración en segundos (entero)
        • Tipo de llamada (entero)
        • Costo de la llamada (float)*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>
typedef struct
{
    char  sector [16];
    int duracion;
    int tipollamada;
}T_LLamadas;

typedef struct
{
	float costo;
}T_Costos;

typedef struct
{
	char sector [16];
	float costosTotales;
}T_GASTOS;


int main()
{
    char sectoractual [16], hablomas [16];
    T_LLamadas aux;
    T_GASTOS  gastosaux;
    int vCONT[3], sum, mayor;
    FILE * arch;
    FILE * arch2;
    FILE * arch3;
    
    strcpy(hablomas,"bandera");
    
    arch=fopen ("LLAMADAS.dat","rb")//contiene todas las llamadas,sectores
    arch2=fopen("costos.dat","rb");//contiene los costos por llamadas por sector
    arch3=fopen("gastos.dat","wb");//lo creo yo, pongo el sector y el costo
    
    if (arch==NULL|| arch2==NULL||arch3==NULL)
    {
        printf("error de archivo");
        exit(1);
    }
    //----------------------------------------------------------------------------------------------------------------------------------
    fread(&aux,sizeof(T_LLamadas),1,arch);
    while(!feof(arch))
    {
        vCONT[0]=0;//inicializo los contadores en cero
    	vCONT[1]=0;
        vCONT[2]=0;
		sum=0;
        strcpy(sectoractual,aux.sector);
        //------------------------------------------------------------------------------------------------------------------------------
        while(strcmpi(sectoractual,aux.sector)==0&&!feof(arch ))//mientras que siga en ese corte de control
        {
            cont [aux.tipollamada-1]++;//voy contando a medida que sea ese tipo de llamada
            sum+=aux.duracion;//acumulo todas las llamadas
            fread(&aux,sizeof(T_LLamadas),1,arch);
        }

        //-------------------------------------------------------------------------------------------------------------------------------
        if (strcmpi (hablomas,"bandera")==0||sum>mayor)//uso una bandera para saber cual hablo mas en las llamadas 
        {
            strcpy(hablomas,sectoractual);
            mayor=sum;
        }
		printf("SECTOR %s\n %-7s %-7s %-7s",sectoractual,"TIPO 1","TIPO 2","TIPO 3");
		printf(" %-7d %-7d %-7d",vCONT[0],vCONT[1],vCONT[2]);
		gastosaux.sector=sectoractual;
		gastosaux.costosTotales=

    }
    //------------------------------------------------------------------------------------------------------------------------------------
    fclose(arch);
    fclose(arch2);
    fclose(arch3);
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




















