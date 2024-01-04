#include <stdio.h>
void ingresaCodigos(int[],int); //a esto se lo llamaba prototipoooo
int busqueda(int[],int,int);
int LeerYvalidar(int,int);
int EstaDentroDelRango(int,int,int);
int maximo(int[],int);
int minimo(int[],int);
void mostrarMaximo(int[],int[],int,int);
void mostrarMinimo(int[],int[],int,int);
int main()
{
	int produc[5]={0},i,codigoProd[5],aux,pos;
	ingresaCodigos(codigoProd,5);
	printf("\n\nCARGAR PRODUCTOS\n");
	do{
		printf("Ingrese el codigo del producto ");
		scanf("%d",&aux);
		pos=busqueda(codigoProd,aux,5);
		if(aux==0)
			pos=1;
		if(pos==-1)
			printf("el codigo que ingreso no esta en la lista\n");
	  }while(pos==-1);
	while(aux!=0)
	{
		printf("Ingrese la cantidad vendida de ese codigo ");
		scanf("%d",&produc[pos]);
		 
		do{
		printf("Ingrese el codigo del producto ");
		scanf("%d",&aux);
		pos=busqueda(codigoProd,aux,5);
		if(aux==0)
			pos=1;
		if(pos==-1)
			printf("el codigo que ingreso no esta en la lista\n");
		}while(pos==-1);
	}
	for(i=0;i<5;i++)
	{
		printf("codigo %d  cantidad vendida %d\n",codigoProd[i],produc[i]);
	}
	mostrarMaximo(produc,codigoProd,maximo(produc,5),5);
	mostrarMinimo(produc,codigoProd,minimo(produc,5),5);
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////                FUNCIONES                        /////////////////////////////////////////////////////////////
void ingresaCodigos(int v[],int cant)
{
	int i,pos,aux;
	for(i=0;i<cant;i++)
	{
		do{
			aux=LeerYvalidar(1000,9999);
			pos=busqueda(v,aux,i);
			if(pos!=-1)
				printf("dato duplicado\n");
		}while(pos!=-1);
		v[i]=aux;
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
int busqueda(int v[],int dato,int num)
{
	int pos=-1,i=0;
	while(pos==-1 && i<num)
	{
		if(v[i]==dato)
			pos=i;
		else
			i+=1;
	}
	return pos;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
int LeerYvalidar(int li,int ls)
{
	int num;
	do{
		printf("\nIngrese un codigo ");
		scanf("%d",&num);
		if(EstaDentroDelRango(num,li,ls)==0)
		printf("dato fuera del rango establecido\n");
	}while(EstaDentroDelRango(num,li,ls)==0);
	return num;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
int EstaDentroDelRango(int num,int li,int ls)
{
	if(num>=li && num<=ls)
		return 1;
	else
		return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
int maximo(int v[],int num)
{
	int max,i;
	for(i=0;i<num;i++)
	{
		if(i==0 || v[i]>max)
			max=v[i];
	}
	return max;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
int minimo(int v[],int num)
{
	int min,i;
	for(i=0;i<num;i++)
	{
		if(i==0 || v[i]<min)
			min=v[i];
	}
	
	return min;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void mostrarMaximo(int produc[],int codigoProd[],int max,int num)
{
	int i;
	printf("La maxima venta es %d y los codigos de estas ventas son: \n",max);
	for(i=0;i<num;i++)
	{
		if(produc[i]==max)
			printf("%d\n",codigoProd[i]);
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
void mostrarMinimo(int produc[],int codigoProd[],int min,int num)
{
	int i;
	printf("La minima venta es %d y los codigos de estas ventas son: \n",min);
	for(i=0;i<num;i++)
	{
		if(produc[i]==min)
			printf("%d\n",codigoProd[i]);
	}
}










