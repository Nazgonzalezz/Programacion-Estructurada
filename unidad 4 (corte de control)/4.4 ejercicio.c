/*4.4 La empresa de colectivos línea 166 desea saber cuánto debe cobrar en un mes determinado según los viajes
realizados y registrados en el sistema mediante la tarjeta SUBE para ello dispone de un archivo de viajes
los viajes del mes que está ordenado por número de Interno (colectivo) que contiene la siguiente
información:
		• Número de Interno (entero)
		• Número tarjeta SUBE (entero)
		• Código de Tarifa (texto de 10 caracteres máximo)
		• Día (entero)
		• Hora (entero)
Se dispone de un segundo archivo llamado tarifas.dat que contiene información de las tarifas por cada mes con
la siguiente estructura:
		• Mes (entero)
		• Código de Tarifa (texto de 10 caracteres máximo)
		• Precio (float)
Se sabe que como máximo se manejan 8 tarifas distintas en cada mes.
Se solicita:
		a. Ingresar por teclado el mes a procesar y recuperar las tarifas correspondientes
		b. Mostrar el importe total a cobrar por la empresa
		c. Generar un archivo que contenga la cantidad de viajes y la recaudación de cada interno en el mes.
		d. Informar el interno que realizó menos cantidad de viajes
		e. Por cada interno mostrar cuantos viajes se realizaron por cada tipo de tarifa ordenado por cantidad de
		viajes en forma descendente.
Funciones obligatorias:
		• CargaTarifas: que levanta a un vector en memoria las tarifas del mes ingresado por teclado.
		• OrdenarViajes: para ordenar los viajes según lo pedido en el punto e.
		• MostrarViajes: para mostrar en forma de listado los viajes ordenados del punto e.*/
#include <stdio.h>
#include <string.h>
typedef struct	{	
					int numInterno;
					int numSube;
					char codigoTarifa[11];
					int dia;
					int hora;
				}T_VIAJES;
				
typedef struct	{
					int mes;
					char codigoTarifa[11];
					float precio;
				}T_TARIFAS;
typedef struct	{
					int cantidadViajes;
					int interno;
					float recaudacionTotal;
				}T_RECAUxINTERNO;	
			
int buscar(char[],T_TARIFAS[],int);
int cargarTarifa(int,T_TARIFAS[]);
void mostrarTarifas(T_TARIFAS[],int);
void ordenarArchivo();
void mostrarRECAUxINTERNO();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int mes,cantTarifas,numActual,cont,pos,menorViaje=-1,numInternoMenorViaje;
	float acu,importTotal=0;
	T_TARIFAS vTarifas[8];
	T_VIAJES auxViajes;
	T_RECAUxINTERNO auxInterno;
	FILE * arch, *arch2;
	//aca ingreso el mes que voy a procesar en el sistema (asi se por que mes filtrar )
	do{
		printf("Ingrese el mes a procesar ");
		scanf("%d",&mes);
		if(mes<1 || mes>12)
			printf("Eroor, el numero ingresado no es una fecha validad de mes(1...12)\n");
	}while(mes<1 || mes>12);
	cantTarifas=cargarTarifa(mes,vTarifas);
	mostrarTarifas (vTarifas,cantTarifas);
	//-------------------------------------------------------------------------------------------------------------------------------------------------------
	arch=fopen("viajes.dat","rb");
	arch2=fopen("RecaudacionPorInterno.dat","wb");
	if(arch==NULL || arch2==NULL)
	{
		printf("error de archivo ");
		exit(1);
	}
	fread(&auxViajes,sizeof(T_VIAJES),1,arch);
	while( !feof(arch) )
	{
		numActual=auxViajes.numInterno;
		cont=0;
		acu=0;
		while(!feof(arch) && numActual==auxViajes.numInterno)
		{
			pos=buscar(auxViajes.codigoTarifa,vTarifas,8);
			if(pos!=-1)
			{
				acu+=vTarifas[pos].precio;
				cont++;
			}
			fread(&auxViajes,sizeof(T_VIAJES),1,arch);
		}
		importTotal+=acu;
		auxInterno.interno=numActual;
		auxInterno.cantidadViajes=cont;
		auxInterno.recaudacionTotal=acu;
		fwrite(&auxInterno,sizeof(T_RECAUxINTERNO),1,arch2);
		if(menorViaje==-1 || cont<menorViaje)
		{
			menorViaje=cont;
			numInternoMenorViaje=numActual;
		}
	}
	fclose(arch);
	fclose(arch2);
	//----------------------------------------------------------------------------------------------------------------------------------------------------------
	printf("\nEl importe total a pagar por la empresa es $ %.2f",importTotal);
	printf("\nEl interno numero %d hizo la menor cantidad de viajes, y esta fue de %d",numInternoMenorViaje,menorViaje);
	printf("\n\nRECAUDACION X INTERNO SIN ORDENAR:\n\n");
	mostrarRECAUxINTERNO();
	ordenarArchivo();
	printf("\nRECAUDACION X INTERNO ORDENADA POR CANTIDAD DE VIAJES:\n\n");
	mostrarRECAUxINTERNO();
	
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int buscar(char codigoTarifa[], T_TARIFAS vTarifa[], int num)
{
	int pos=-1,i=0;
	
	while(pos==-1 && i<num)
	{
		if(strcmpi(vTarifa[i].codigoTarifa,codigoTarifa)==0)
			pos=i;
		else
			i++;
	}	
	return pos;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
int cargarTarifa(int mes,T_TARIFAS vTarifas[])
{
	int cantTarifas=0;
	T_TARIFAS auxTarifas;
	FILE * arch;
	arch=fopen("tarifas.dat","rb");
	if(arch==NULL)
	{
		printf("error al abrir el  archivo tarifas");
		exit(1);
	}
	
	fread(&auxTarifas,sizeof(T_TARIFAS),1,arch);
	while(!feof(arch))
	{
		if(auxTarifas.mes==mes)
		{
			vTarifas[cantTarifas].mes=auxTarifas.mes;
			strcpy(vTarifas[cantTarifas].codigoTarifa,auxTarifas.codigoTarifa);
			vTarifas[cantTarifas].precio=auxTarifas.precio;
			cantTarifas++;
		}
		fread(&auxTarifas,sizeof(T_TARIFAS),1,arch);
	}
	fclose(arch);
	return cantTarifas;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------
void mostrarTarifas (T_TARIFAS vTarifas[],int num)
{
	int i=0;
	printf("\n %-13s   %-3s   %-7s\n","CODIGO TARIFA","MES","PRECIO");
	while(i<num)
	{
		printf(" %-13s   %-3d   %-7.2f\n",vTarifas[i].codigoTarifa,vTarifas[i].mes,vTarifas[i].precio);
		i++;
	}
	printf("\n");
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
void ordenarArchivo()
{
	T_RECAUxINTERNO auxVieja,auxActual;
	int ordenado, cont, primerRecorrido=1,ultimoIntercambio,intercambio; 
	FILE * arch;
	arch=fopen("RecaudacionPorInterno.dat","r+b");
	if(arch==NULL)
	{
		printf("error al abrir RecaudacionPorInterno.dat");
		exit(1);
	}
	do{
		ordenado=1;
		fread(&auxVieja,sizeof(T_RECAUxINTERNO),1,arch);
		cont=1;
		//-------------------------------------------------------------------------------------------------
		while( (primerRecorrido && !feof(arch))    ||   (!primerRecorrido && cont<=ultimoIntercambio) )
		{
			fread(&auxActual,sizeof(T_RECAUxINTERNO),1,arch);
			cont++;
			if(!feof(arch))
			{
				if(auxActual.cantidadViajes<auxVieja.cantidadViajes) 
				{
					fseek(arch,sizeof(T_RECAUxINTERNO)*(-2),SEEK_CUR);
					fwrite(&auxActual,sizeof(T_RECAUxINTERNO),1,arch);
					fwrite(&auxVieja,sizeof(T_RECAUxINTERNO),1,arch);
					fflush(arch);
					intercambio=cont;
					ordenado=0;
				}
				else
					auxVieja=auxActual;
			}
		}
		//--------------------------------------------------------------------------------------------------
		ultimoIntercambio=intercambio;//
		primerRecorrido=0;//usaba esta bandera para realizar la primera vuelta si o si, por eso la cambio aca
		rewind(arch);//vuelvo al inicio del archivo
	}while(!ordenado);
	fclose(arch);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void mostrarRECAUxINTERNO()
{
	T_RECAUxINTERNO aux;
	FILE * arch;
	arch=fopen("RecaudacionPorInterno.dat","rb");
	if(arch==NULL)
	{
		printf("error al abrir RecaudacionPorInterno.dat");
		exit(1);
	}
	printf(" %-7s   %-14s   %-17s\n","INTERNO","CANT DE VIAJES","RECAUDACION TOTAL");
	printf("***********************************************\n");
	fread(&aux,sizeof(T_RECAUxINTERNO),1,arch);
	while(!feof(arch))
	{
		printf(" %-7d   %-14d   %-17.2f\n",aux.interno,aux.cantidadViajes,aux.recaudacionTotal);
		fread(&aux,sizeof(T_RECAUxINTERNO),1,arch);
	}
	printf("\n");
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------





















