/*1.1.2 Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI
negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Tenga en cuenta que no pueden
existir 2 o más alumnos con el mismo DNI.
Mostrar el Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado), ordenado de
mayor a menor por nota.
*/
int cargaDNIsinDupli(int[],int[],int);
int buscar(int[],int,int);
void ordenarBurbuja(int[],int[],int);
int LeerYvalidar(int,int);
int EstaDentroDelRango(int,int,int);
#include <stdio.h>
int main()
{
	int vDNI[5],vNota[5],ultimaPos,i=0;
	ultimaPos=cargaDNIsinDupli(vDNI,vNota,5);
	ordenarBurbuja(vDNI,vNota,ultimaPos);
	printf(" DNI\t\t\tNOTA\n");
	while (i<ultimaPos)
	{
		printf("%d\t\t%d\n",vDNI[i],vNota[i]);
		i++;
	}
	
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////      FUNCIONES  ////////////////////////////////////////////////////////////////////////////////////////////////////

void ordenarBurbuja(int vDNI[],int vNota[],int tamano)
{
	int i,desordenado,aux,limite=tamano-1;
	do{
		desordenado=0;
		for(i=0;i<limite;i++) //uso un for para recorrer por lo menos una vez el vector. 
		{
			if (vNota[i]<vNota[i+1])//pregunto, si el lugar numero 1 es maas chiquito al lugar 0 los cambio de lugar 
			{
				aux=vDNI[i];
				vDNI[i]=vDNI[i+1];
				vDNI[i+1]=aux; 
				
				aux=vNota[i];
				vNota[i]=vNota[i+1];
				vNota[i+1]=aux;
				
				desordenado=i;//a medida que el for va haciendo los ciclos si se llega a producir un cambio de lugar mi variable desordenado va a cambiar su valor 
			}
		}
		limite=desordenado; //si efectuo un cambio no tengo que verificar que los numeros anteriores a ese cambio esten ordenados, por eso esta variable toma este
		//valor, para que el ciclo recorra los otros numeros 
	}while(desordenado);//Si una variable toma valor 0 siempre va a ser false. Si una variable toma un valor distinto a cero es true
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
int cargaDNIsinDupli(int vecDNI[],int vecNota[],int num)
{
	int i=0,aux,pos,nota;
	aux=LeerYvalidarDNI(10000000,99999999);
	while (i<num && aux>0)
	{	
		vecDNI[i]=aux;
		printf("ingrese la nota ");
		scanf("%d",&nota);
		vecNota[i]=nota;
		do{
			aux=LeerYvalidarDNI(10000000,99999999);
			pos=buscar(vecDNI,aux,i); //le mando i porque solo quiero que busque hasta donde cargue el vector
			if(pos!=-1)
				printf("el DNI ya existe. \n");
		}while(pos!=-1);
		i++;
	}
	return i;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
int buscar(int vec[],int dato,int num)
{
	int pos=-1,i=0;
	while(i<num &&pos==-1) //si encuentro el dato dejo de buscar
	{
		if(vec[i]==dato)
			pos=i;
	}
	return pos;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int LeerYvalidarDNI(int li,int ls)
{
	int num; 
	do{
		printf("ingrese el dni ");
		scanf("%d",&num); 
		if( (EstaDentroDelRango(num,li,ls)==0)&&(EstaDentroDelRango(num,ls*-1,li*-1)==0))  
			printf("ingreso mal el dni\n");
	}while( (EstaDentroDelRango(num,li,ls)==0) && (EstaDentroDelRango(num,ls*-1,li*-1)==0) );//aca invierto los numeros porque los negativos 
	return num;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
int EstaDentroDelRango(int num,int li,int ls)
{
	if(num>=li && num<=ls) 
		return 1;
	else
		return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------



























