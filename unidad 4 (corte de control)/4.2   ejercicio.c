/*4.2 Se dispone de un archivo con las ventas del mes de cada una de las sucursales de una empresa. El archivo se
encuentra ordenado por sucursal y contiene la siguiente estructura:
		• Sucursal (15 caracteres máximo)
		• Código de producto (entero)
		• Cantidad (entero)
Por otro lado, se dispone de un archivo de los productos que vende la empresa y el estado del stock al mes
pasado con la siguiente estructura:
		• Código de producto (entero)
		• Descripción (20 caracteres máximo)
		• Precio (float)
		• Stock (entero)
		• Punto de pedido (entero)
		• Cantidad para pedido (entero)
No se sabe la cantidad exacta de productos, pero sí se sabe que no hay más de 200. Se desea:
		a. Mostrar el importe total vendido en cada sucursal.
		b. Mostrar la recaudación total de la empresa en el mes.
		c. Determinar la sucursal que vendió mayor cantidad de productos.
		d. Actualizar el archivo de productos con el nuevo stock.
		e. Realizar un archivo llamado pedidos.dat que incluya aquellos productos que deben solicitarse
		(código y cantidad) de aquellos productos que al finalizar de procesar las ventas del mes queden
		con stock menor al punto de pedido. */

#include <stdio.h>
#include <string.h>
typedef struct	{
					char sucursal[16];
					int codigoProducto;
					int cantidad;
				}T_VENTAS;
				
typedef struct	{
					int codigoProducto;
					char descripcion[21];
					float precio;
					int stock;
					int puntoDePedido;
					int cantidadParaPedido;
				}T_PRODUCTOS;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int buscar(int,int,T_PRODUCTOS[]);
int main()
{
	T_PRODUCTOS vProductos[200],auxProdu;
	T_VENTAS auxVentas;
	char sucursalActual[16],mayorSucursal[16];
	int i=0,acu,recaudacionTotal=0,pos,mayorVenta=-1,cantProdu;
	FILE *arch;
	//----------------------------------------------------------------------------------------------------------------------------------------------------------
	arch=fopen("productos.dat","rb");
	if(arch==NULL)
	{
		printf("error de archivo");
		exit(1);
	}
	fread(&auxProdu,sizeof(T_PRODUCTOS),1,arch);//aca bajo los datos de los productos a un vector 
	while(!feof(arch))
	{
		vProductos[i]=auxProdu;
		i++;
		fread(&auxProdu,sizeof(T_PRODUCTOS),1,arch);
	}
	fclose(arch);
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	
	//----------------------------------------------------------------------------------------------------------------------------------------------------------
	arch=fopen("ventas.dat","rb");//aca voy a hacer el bucle con el corte de control por sucursal
	if(arch==NULL)
	{
		printf("error de archivo");
		exit(1);
	}
	fread(&auxVentas,sizeof(T_VENTAS),1,arch);
	while(!feof(arch))
	{
		strcpy(sucursalActual,auxVentas.sucursal);
		acu=0;
		cantProdu=0;
		//---------------------------------------------------------------------------------------------------------------------------------------------------
		while(!feof(arch)&& strcmpi(sucursalActual,auxVentas.sucursal)==0)
		{
			pos=buscar(200,auxVentas.codigoProducto,vProductos);
			if(pos!=-1)
			{
				acu+=auxVentas.cantidad*vProductos[pos];
				cantProdu+=auxVentas.cantidad;
			}
			fread(&auxVentas,sizeof(T_VENTAS),1,arch);
		}
		//--------------------------------------------------------------------------------------------------------------------------------------------------
		recaudacionTotal+=acu;
		printf("\nSUCURSAL %s importe total:$ %d\n",sucursalActual,acu);
		if(mayorVenta==-1||cantProdu>mayor)
		{
			mayorVenta=cantProdu;
			strcpy(mayorSucursal,sucursalActual);
		}
	}	
	fclose(arch);
	//--------------------------------------------------------------------------------------------------------------------------------------------------------
	printf("\nRecaudacion total de la empresa en el mes:$ %d",recaudacionTotal);
	printf("\nLa sucursal que realizo la mayor venta es %s y vendio %d",mayorSucursal,mayorVenta);
	
	
	
	
	
	
	
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int buscar(int num,int dato, T_PRODUCTOS vProductos[])
{
	int pos=-1,i=0;
	while(i<num && pos==-1)
	{
		if(dato==vProductos[i])
			pos=i;
		else
			i++;	
	}
	return pos;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------






































