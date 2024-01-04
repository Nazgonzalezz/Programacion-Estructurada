/*1.1.3 Se ingresan los códigos de 15 productos de una empresa (números de 3 dígitos). Luego se ingresan las
ventas realizadas durante el día. Por cada venta se ingresa código de vendedor, código de artículo y cantidad.
Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005. Se puede recibir más de una venta
de un mismo vendedor y artículo. El ingreso de datos finaliza con código de vendedor igual a 0. Se desea:
a. Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas de cada producto.
b. Indicar el/los vendedores que realizaron menor cantidad de ventas (no de unidades).*/
#include <stdio.h>
void cargarCodiProd(int[],int);
int LeerYvalidar(int,int);
int EstaDentroDelRango(int,int,int);
int buscar(int[],int,int);
int main()
{	
	int vCodiProd[15];
	cargarCodiProd(vCodiProd,15);
	return 0;
	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cargarCodiProd(int vCodiProd[],int num)
{
	int i,aux; 
	for(i=0;i<num;i++)
	{
		do{
			printf("\nIngrese el codigo del producto ");
			aux=LeerYvalidar(100,999);
			if (buscar(vCodiProd,i,aux)!=-1)
				printf("El codigo ingresado ya existe\n");
		}while(buscar(vCodiProd,i,aux)!=-1);
		vCodiProd[i]=aux;
	}
	
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------
int LeerYvalidar(int li,int ls)
{
	int num;
	do{
		printf(" ");
		scanf("%d",&num);
		if(EstaDentroDelRango(num,li,ls)==0)
			printf("error.El dato ingresado no cumple con los parametros establecidos\nIngreselo devuelta");
	}while(EstaDentroDelRango(num,li,ls)==0);
	return num;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
int EstaDentroDelRango(int num,int li,int ls)
{
	if(num>=li && num<=ls)
		return 1;
	else 
		return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
int buscar(int v[],int num,int dato)
{
	int pos=-1,i=0;
	while(pos==-1 && i<num)
	{
		if(v[i]==dato)
			pos=i;
		else
			i++;
	}
	return pos;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------





























