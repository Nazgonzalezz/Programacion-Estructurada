/*4.5 En un estadio de fútbol se incorporó un nuevo sistema para censar la cantidad de espectadores que pasan
por cada una de las entradas de forma de analizar el comportamiento de la gente y poder diseñar una mejor
distribución de las vías de acceso.
El estadio tiene 15 puertas numeradas del 1 al 15. La recolección de datos se realizó en todos los partidos
disputados en el estadio a lo largo de varios meses para poder tener un volumen de información suficiente
que permita realizar un análisis.
La información registrada se encuentra en un archivo con la siguiente estructura:
		• Código del Evento (texto de 10 caracteres máximo)
		• Número de puerta (entero)
		• Cantidad de Espectadores (entero)
La información se haya ordenada por Código de Evento. Se solicita calcular y mostrar:
		a. Cantidad de espectadores por cada evento.
		b. El evento con menor cantidad de espectadores.
		Guía Práctica – V1.0 4 / 5
		c. Grabar un archivo con el promedio de espectadores que ingresaron por cada una de las 15 entradas.
		en todos los eventos analizados, informando el número de puerta y promedio.
*/
#include <stdio.h>
#include <string.h>
typedef struct	{
					char codigoEvento[11];
					int puerta;
					int cantidadEspectadores;
				}T_ESTADIOFULBO;
				
typedef struct	{
					float promedio;
					int puerta;
				}T_PROMESPECTADORES;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarEVENTOS();
void mostrar();
int main()
{
	T_PROMESPECTADORES auxProm;
	int vPuertas[15]={0}, i;
	T_ESTADIOFULBO aux;
	int cantidadDeEventos=0,acu,min=-1;
	char codigoActual[11],codiEventoMenosEspectador[11];
	FILE *arch, *arch2;
	arch2=fopen("PromedioDeEspectadores.dat","wb");
	arch=fopen("Eventos.dat","rb");
	if(arch==NULL || arch2==NULL)
	{
		printf("error al abrir archivos");
		exit(1);
	}
	mostrarEVENTOS();
	
	fread(&aux,sizeof(T_ESTADIOFULBO),1,arch);
	while( !feof(arch))
	{
		strcpy(codigoActual,aux.codigoEvento);
		acu=0;
		while( !feof(arch) && strcmpi(codigoActual,aux.codigoEvento)==0)
		{
			vPuertas[aux.puerta-1]+=aux.cantidadEspectadores;	
			acu+=aux.cantidadEspectadores;
			fread(&aux,sizeof(T_ESTADIOFULBO),1,arch);
		}
		cantidadDeEventos++;
		if( min==-1 || acu<min)
		{
			min=acu;
			strcpy(codiEventoMenosEspectador,codigoActual);
		}
		printf("\nEl evento %s tuvo %d cantidad de espectadores ",codigoActual,acu);
	}
	fclose(arch);
	printf("\n\nEl evento con menos espectadores es %s y tuvo %d cantidad de espectadores\n",codiEventoMenosEspectador,min);
	
	if(cantidadDeEventos!=0)
	{
		for(i=0;i<15;i++)
		{
			auxProm.promedio=vPuertas[i]/cantidadDeEventos;
			auxProm.puerta=i+1;
			fwrite(&auxProm,sizeof(T_PROMESPECTADORES),1,arch2);	
		}
	}
	fclose(arch2);
	mostrar();
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrar()
{
	int i;
	T_PROMESPECTADORES aux; 
	FILE * arch;
	arch=fopen("PromedioDeEspectadores.dat","rb");
	if(arch==NULL)
	{
		printf("error");
		exit(1);
	}
	printf("\n %-7s %-8s\n","PUERTA","PROMEDIO");
	for(i=0;i<15;i++)
	{
		fread(&aux,sizeof(T_PROMESPECTADORES),1,arch);
		printf(" %-7d %-8.2f\n",aux.puerta,aux.promedio);
	}
	fclose(arch);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
void mostrarEVENTOS()
{
	T_ESTADIOFULBO aux;
	FILE * arch;
	arch=fopen("Eventos.dat","rb");
	if(arch==NULL)
	{
		printf("error");
		exit(1);
	}
	printf("\n %-15s|%-10s|%-20s\n","CODIGO EVENTO","PUERTA","CANT DE ESPECTADORES");	
	printf("****************************************************\n");
	fread(&aux,sizeof(T_ESTADIOFULBO),1,arch);
	while(!feof(arch))
	{
		printf(" %-15s|%-10d|%-20d\n",aux.codigoEvento,aux.puerta,aux.cantidadEspectadores);
		fread(&aux,sizeof(T_ESTADIOFULBO),1,arch);
	}
	fclose(arch);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------





























