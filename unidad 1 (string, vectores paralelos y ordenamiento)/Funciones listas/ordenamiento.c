#include <stdio.h>
void ordenarBurbuja(int[],int); //a eso se lo llama prototipo
void cargarVec(int[],int);
void mostrarVec(int[],int);
int main()
{
	int vector[5];
	cargarVec(vector,5);
	ordenarBurbuja(vector,5);
	mostrarVec(vector,5);
	return 0;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ordenarBurbuja(int v[],int tamano)
{
	int i,desordenado,aux,limite=tamano-1;
	do{
		desordenado=0;
		for(i=0;i<limite;i++) //uso un for para recorrer por lo menos una vez el vector. 
		{
			if (v[i]>v[i+1])//pregunto, si el lugar numero 1 es maas chiquito al lugar 0 los cambio de lugar 
			{
				aux=v[i];
				v[i]=v[i+1];
				v[i+1]=aux;
				desordenado=i;//a medida que el for va haciendo los ciclos si se llega a producir un cambio de lugar mi variable desordenado va a cambiar su valor 
			}
		}
		limite=desordenado; //si efectuo un cambio no tengo que verificar que los numeros anteriores a ese cambio esten ordenados, por eso esta variable toma este
		//valor, para que el ciclo recorra los otros numeros 
	}while(desordenado);//Si una variable toma valor 0 siempre va a ser false. Si una variable toma un valor distinto a cero es true
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void cargarVec(int vec[],int num)
{
	int i;
	for(i=0;i<num;i++)
	{
		printf("Ingrese un numero ");
		scanf("%d",&vec[i]);
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void mostrarVec(int v[],int num)
{
	int i;
	for(i=0;i<num;i++)
	{
		printf("%d\n",v[i]);
	}
}







