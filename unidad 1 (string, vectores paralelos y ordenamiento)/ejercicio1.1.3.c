/*1.1.3 Se ingresan los códigos de 15 productos de una empresa (números de 3 dígitos). Luego se ingresan las
ventas realizadas durante el día. Por cada venta se ingresa código de vendedor, código de artículo y cantidad.
Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005. Se puede recibir más de una venta
de un mismo vendedor y artículo. El ingreso de datos finaliza con código de vendedor igual a 0. Se desea:
a. Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas de cada producto.
b. Indicar el/los vendedores que realizaron menor cantidad de ventas (no de unidades).*/
#include <stdio.h>
void cargarcodigoproducto(int[],int);
void ordenarBurbuja(int[],int[],int);
int ValidarCodigo(int,int,int);
int buscarMenorVenta(int[],int);
int EstaDentroDelRango(int,int,int);
int buscar(int[],int,int);
int LeerYvalidar(int,int);
int validarcero(int);
int main()
{
	int vVendedores[5]={0}, vCodProd[6],vVentasDeProduc[6]={0}, codiVendedor,min,venta,art, pos,i ;
	cargarcodigoproducto(vCodProd, 6);//aca cargo en el vector de productos los codigos
	printf("ingrese el codigo de vendedor de 1001 a 1005 - 0 para finalizar ");
	codiVendedor=ValidarCodigo(1001, 1005, 0);
	while (codiVendedor!=0) //la carga finaliza con un codigo de ventas igual a cero
    {
        do
        {
            printf("\ningrese el codigo de articulo:");//aca el usuario ingresa el codigo del producto(me fijo que coincida con los que estan en el vector)
            scanf("%d",&art);
            pos=buscar(vCodProd, art,6 );
            if(pos==-1)
                printf("\nerror, reingrese");
        }while(pos==-1);
        do
        {
            printf("\ningrese la cantidad vendida:");//aca valido que la venta sea mayor a cero
            scanf("%d",&venta);
            if(venta<=0)
                printf("\nerror, reingrese");
        }while(venta<=0);
        vVentasDeProduc[pos]+=venta;//guardo en la misma posicion que el codigo de producto la cantidad vendida(en este vector acumulo las ventas)
        vVendedores[codiVendedor-1001]+=1; //aca cuento cuanto vende cada vendedor
        printf("ingrese el codigo de vendedor - 0 para finalizar ");//vuelvo a preguntar para que no se cree un bucle infinito
	    codiVendedor=ValidarCodigo(1001, 1005, 0);
    }
    ordenarBurbuja(vCodProd,vVentasDeProduc,6);
    printf("\n\n\nCANT UNIDADES\t\tCODIGO\n");
    for(i=0;i<6;i++)
    {
    	printf("\t%d\t\t%d\n",vVentasDeProduc[i],vCodProd[i]);
	}
    min=buscarMenorVenta(vVendedores,5);
    if(min!=-1)
    {
    	printf("La minima venta es %d y las hicieron los vendedores con los codigos:\n",min);
    	for(i=0;i<5;i++)
    	{
    		if(vVendedores[i]==min)
    			printf("%d\n",i+1001);
		}
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////// FUNCIONES /////////////////////////////////////////////////////////////////////////////////////
int ValidarCodigo(int li,int ls,int f)
{
	int num, i;
	do{

        scanf("%d",&num);
        i=EstaDentroDelRango(num,li, ls);
		if(i==0&&num!=f)
			printf("eror.lo ingreso mal\n");
	}while(i==0&&num!=f );
	return num;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int EstaDentroDelRango(int num,int li,int ls)
{
	if(num>=li && num<=ls)
		return 1;
	else
		return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
void cargarcodigoproducto (int v[], int num)
{
 int i, pos, aux;
 for (i=0; i<num; i++)
 {
     do
     {
         printf("\ningrese un codigo de producto de 100 a 999:");

         aux=LeerYvalidar(100, 999);
         pos=buscar(v, aux, i);
         if(pos!=-1)
            printf("\ndato duplicado, reingrese:");

     }while(pos!=-1);
     v[i]=aux;
 }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
int buscar(int v[], int dato, int num )
{
    int i=0, pos=-1;
    while(pos==-1 && i<num)
    {
        if (v[i]==dato)
            pos=i;
        else i++;
    }
    return pos;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
int LeerYvalidar(int li,int ls)
{
	int num;
	do{
		scanf("%d",&num);
		if(EstaDentroDelRango(num,li,ls)==0)
			printf("eror.lo ingreso mal\n");
	}while(EstaDentroDelRango(num,li,ls)==0);
	return num;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
void ordenarBurbuja(int vCodProd[],int vVentasDeProduc[], int tamano)
{
	int i,desordenado,aux,limite=tamano-1;
	do{
		desordenado=0;
		for(i=0;i<limite;i++) 
		{
			if (vVentasDeProduc[i]>vVentasDeProduc[i+1])
			{
				aux=vVentasDeProduc[i];
				vVentasDeProduc[i]=vVentasDeProduc[i+1];
				vVentasDeProduc[i+1]=aux;
				
				aux=vCodProd[i];
				vCodProd[i]=vCodProd[i+1];
				vCodProd[i+1]=aux;
				desordenado=i; 
			}
		}
		limite=desordenado; 
	}while(desordenado);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
int buscarMenorVenta(int vVendedores[],int num)
{
	int i,min=-1;
	for(i=0;i<num;i++)
	{
		if(vVendedores[i]!=0)
		{
			if(min==-1|| vVendedores[i]<min)
				min=vVendedores[i];
		}
	
	}
	return min;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------






































