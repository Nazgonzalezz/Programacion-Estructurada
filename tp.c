/*	Una empresa de alquiler de autos tiene una flota de 15 autos de alta gama, identificados por un código alfanumérico de hasta 9 caracteres.
Antes de procesar los alquileres se cargan en memoria los vehículos que se encuentran operativos (sin duplicados). Es posible que algunos de los vehículos
se encuentren afectados a otra actividad y no se alquilen en ese momento. El fin de la carga termina con una patente "FINAUTO"
	
Los vehículos se alquilan por semana completa (Semana 1 a semana 4 en el mes) y se desea procesar el alquiler de un solo mes.
Esto significa que el programa debe contemplar que permanentemente se vea en la parte superior de la pantalla un listado que indique código de vehículos activos 
y en paralelo el estado de ese vehículo en cada una de las semanas indicando un 1 si está libre o un 0 si está ocupada la semana (listado correctamente formateado para una visualización prolija).
		Ejemplo:
		VEHÍCULO	SEMANA 1	SEMANA 2	SEMANA 3	SEMANA 4
		COROLLA 1    	1        	1	       0			0
		CRUZE II	    1       	1	       0			1
		COROLLA 2   	0	        1	       0			0
	
Al comienzo del procesamiento todos los vehículos activos se encuentran libres en todas las semanas y a medida que se procesan se van actualizando los datos.
Primero se pregunta si se desea reservar o anular reserva: 
		Ejemplo:
		MENU PRINCIPAL
		Elija Opción:
		1-Reserva
		2-Anulación
		3-Salir del Sistema
	
Si es reserva se sigue de la siguiente forma:
El cliente puede optar por dos métodos de reserva y lo informa antes de comenzar (Tomar como ejemplo el menú anterior):
	_Por Semana: El cliente indica que semana quiere y el sistema le asigna el primer vehículo del listado libre esa semana o le informa que no existen vehículos
	libres esa semana.
	_Por código vehículo: El cliente pide un vehículo determinado que exista en el listado y si el vehículo está disponible le asigna la primera semana libre o le
	informa que ese vehículo no tiene semanas disponibles.
Si se desea anular reserva se indicará vehículo y semana a anular y si el vehículo existe y la semana está reservada, se procede a anular reserva y contabilizar 
anulación.
Si el vehículo no existe se informa y se vuelve al menú principal.
Al finalizar el proceso se informará:

			1)	Listado actualizado de los vehículos y su situación semana por semana.
			2)	Cantidad de reservas perdidas en total por cualquiera de los dos métodos de reservas.
			3)	Listado con la cantidad de anulaciones de reservas por vehículo.
*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int buscar(char[][15],char[], int);
void mostrarMatriz(char[][15],int[][4],int,int);
int reservarSeman(int[][4],int,int);
int reservarAuto(int[][4],int,int);
int LeerYvalidar(int,int);
int EstaDentroDelRango(int,int,int);
int main()
{
	char vAUTOS[10][15],aux[10],autoo[10];
	int i=0,j,l,flag,pos,vAUTOXSEMANA[15][4]={0},opcion,opcion2,semana,flag2,contReservas=0, vLISTAANULACIONES[15]={0};
	//------------------------------- se cargan en memoria los autos  ------------------------------------------------------------------------------------
	printf("Ingrese el codigo del auto que va a cargar (El fin de la carga termina con una patente FINAUTO)");
	gets(aux);
	if(strcmpi(aux,"FINAUTO")!=0)
	{
		strcpy(vAUTOS[i],aux);
		i++;
	}
	while(strcmpi(aux,"FINAUTO")!=0 && i<15)
	{
		flag=-1;
		do{
			if(flag==-1)
			{
				printf("Ingrese el codigo del auto que va a cargar (El fin de la carga termina con una patente FINAUTO)");
				flag=1;
			}
			else
				printf("\nError, ese codigo ya existe. Ingreselo devuelta: ");
			gets(aux);
			pos=buscar(vAUTOS,aux,i);
		}while(pos!=-1);
		strcpy(vAUTOS[i],aux);
		i++;
	}
	//-------------------------------------------------------------------------------------------------------------------------------------------------------
	//---------------------------------------- inicializo la matriz vAUTOXSEMANA en 1  y la muestro------------------------------------------------------------
	for(l=0;l<4;l++)
	{
		for(j=0;j<i+1;j++)
		{
			vAUTOXSEMANA[j][l]=1;
		}
	}
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	system("cls");
	do
    {
       system("cls");
	   printf ("MENU PRINCIPAL\nelija opcion:\n1) reserva\n2) anulacion\n3) salir del sistema\n");
       scanf ("%d",&opcion);
       switch (opcion)
       {
            case 1:
                system("cls");
                printf ("elija metodo de reserva:\n1) por semana\n2) por codigo de vehiculo\n3) volver\n");
                scanf ("%d",&opcion2);
                switch (opcion2)
                {
                    case 1:
						system("cls");
					    mostrarMatriz(vAUTOS,vAUTOXSEMANA,i,4);
						printf("Ingrese la semana que quiere ");
                        semana=LeerYvalidar(1,4);
                        	
                        flag2=reservarSeman(vAUTOXSEMANA,semana-1,i);
                        if(flag2==-1)
                        {
                        	printf("No se encuentra disponible ningun auto en esa semana\n\n");
                        	getch();
                    	}
                        else 
                        {
                        	vAUTOXSEMANA[flag2][semana-1]=0;
                        	contReservas++;
                    	}
                        break;
                        
                    case 2:
                        system("cls");
                        mostrarMatriz(vAUTOS,vAUTOXSEMANA,i,4);
                        do{
                        	fflush(stdin);
							printf("Ingrese el nombre del auto que quiere ");
                        	gets(autoo);
                        	pos=buscar(vAUTOS,autoo,i);
                        	if(pos==-1)
                        		printf("Error. no existe ese auto\n");
                    	}while(pos==-1);
                    	flag2=reservarAuto(vAUTOXSEMANA,pos,4);
                    	if(flag2==-1)
                    	{
                        	printf("No se encuentra disponible ninguna semana disponible para ese auto\n\n");
                        	getch();
                    	}
                        else 
                        {
                        	vAUTOXSEMANA[pos][flag2]=0;
                        	contReservas++;
						}
                        break;

                    case 3:
                        system("cls");
                        break;
                    }
                break;
            case 2:
                system("cls");
                mostrarMatriz(vAUTOS,vAUTOXSEMANA,i,4);
                fflush(stdin);
				printf("Ingrese el nombre del auto de la reserva que va a anular ");
                gets(autoo);
                pos=buscar(vAUTOS,autoo,i);
                printf("Ingrese la semana de la reserva que quiere anular ");
                semana=LeerYvalidar(1,4);
                if(pos==-1)
                	printf("Error. Como el auto no existe no se puede hacer la anulacion");
                else
                {
                	vAUTOXSEMANA[pos][semana-1]=1;
                	vLISTAANULACIONES[pos]++;
                	contReservas=contReservas-1;
            	}
                getch();
                break;
            case 3:
                break;
       }
    }while (opcion!=3);
    system("cls");
    mostrarMatriz(vAUTOS,vAUTOXSEMANA,i,4);
    printf("\nLa cantidad de reservas es de %d\n",contReservas);
    printf("\n %-9s %11s \n","AUTOS","ANULACIONES");;
    j=0;
    while(j<i)
    {
    	printf(" %-9s %d\n",vAUTOS[j],vLISTAANULACIONES[j]);
    	j++;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////// FUNCIONES  /////////////////////////////////////////////////////////////////////////////////
int buscar(char v[][15],char buscado[], int cant)
{
	int i=0, pos=-1;
	while (pos==-1 && i<=cant)
	{
		if (strcmpi(v[i], buscado)==0)
 			pos=i;
		else
 			i++;
	}
	return pos;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
void mostrarMatriz(char vAUTOS[][15],int vAUTOXSEMANA[][4],int columna,int fila)
{
	int i,j;
	printf("%9s %8s %8s %8s %8s\n","VEHICULO","SEMANA1","SEMANA2","SEMANA3","SEMANA4");
	for(i=0;i<columna;i++)
	{
		printf(" %-9s  ",vAUTOS[i]);
		for(j=0;j<fila;j++)
		{
			printf(" %-8d ",vAUTOXSEMANA[i][j]);
		}
		printf("\n");
	}
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
int reservarSeman(int vAUTOXSEMANA[][4], int seman,int cantAutos)
{
	int i=0,autoo=-1;
	while(i<cantAutos &&autoo==-1)
	{
		if(vAUTOXSEMANA[i][seman]==1)
			autoo=i;
		else 
			i++;	
	}
	return autoo;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------
int reservarAuto(int vAUTOXSEMANA[][4],int pos,int cantSemanas)
{
	int i=0,seman=-1;
	while(i<cantSemanas && seman==-1)
	{
		if(vAUTOXSEMANA[pos][i]==1)
			seman=i;
		else
			i++;
	}
	return seman;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------
int LeerYvalidar(int li,int ls)
{
	int num; 
	do{
		scanf("%d",&num);
		if(EstaDentroDelRango(num,li,ls)==0)
			printf("Error, lo ingreso mal. Intentelo devuelta ");
	}while(EstaDentroDelRango(num,li,ls)==0);
	return num;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
int EstaDentroDelRango(int num,int li,int ls)
{
	if(num>=li && num<=ls)
		return 1;
	else
		return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------


