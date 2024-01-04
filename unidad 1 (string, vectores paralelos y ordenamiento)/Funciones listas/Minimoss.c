#include <stdio.h>
void carga(int[],int);
int minimo(int[],int);
void mostrarMinimo(int[],int,int);
int main()
{
	int vec[10],min;
	carga(vec,10);
	min=minimo(vec,10);
	mostrarMinimo(vec,min,10);
	return 0;
}
void carga(int vec[],int num)
{
	int i;
	for(i=0;i<num;i++)
	{
		printf("ingrese un numero (%d)",i+1);
		scanf("%d",&vec[i]);
	}
}
int minimo(int vec[],int num)
{
	int min=vec[0],i; //aca pongo como maximo al primer elemento
	for(i=1;i<num;i++)
	{
		if(vec[i]<min)
			min=vec[i];
	}
	return min;
}
void mostrarMinimo(int vec[],int min,int num)
{
	int cont=0,i;
	printf("el numero maximo es: %d y se repite en las posiciones: ",min);
	for(i=0;i<num;i++)
	{
		if(vec[i]==min)
		{
			printf("%d\n",i+1);
			cont++;
		}
	}
	printf("\nel valor se repite: %d",cont);
}
















