#include <stdio.h>
void carga(int[],int);
int maximo(int[],int);
void mostrarMaximo(int[],int,int);
int main()
{
	int vec[10],max;
	carga(vec,10);
	max=maximo(vec,10);
	mostrarMaximo(vec,max,10);
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
int maximo(int vec[],int num)
{
	int max=vec[0],i; //aca pongo como maximo al primer elemento
	for(i=1;i<num;i++)
	{
		if(vec[i]>max)
			max=vec[i];
	}
	return max;
}
void mostrarMaximo(int vec[],int max,int num)
{
	int cont=0,i;
	printf("el numero maximo es: %d y se repite en las posiciones: ",max);
	for(i=0;i<num;i++)
	{
		if(vec[i]==max)
		{
			printf("%d\n",i+1);
			cont++;
		}
	}
	printf("\nel valor se repite: %d",cont);
}
















