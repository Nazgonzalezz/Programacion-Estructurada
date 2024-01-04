/*5.1 
Se dispone del archivo binario PRECIOS.DAT con datos de productos según la siguiente estructura:
		• Código de Producto (entero)
		• Descripción (texto de 20 caracteres máximo)
		• Precio (float)
Realizar un programa que permita modificar el precio y/o la descripción de productos dado su código.
El programa debe permitir modificar varios precios finalizando con un código de producto igual a 0.
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct	{
					int codiProducto;
					char descripcion[21];
					float precio;
				}T_PRODUCTOS;
#include <stdio.h>
#include <string.h>
void mostrar();
int main()
{
	T_PRODUCTOS auxProdu;
	int band,codi;
	float precio;
	char descrip[21];
	FILE * arch;
	arch=fopen("precios.dat","r+b");	
	if(arch==NULL)
	{
		printf("error de archivo");
		exit(1);
	}
	mostrar();//aca muestro el contenido del archivo, para saber los codigos
	printf("\ningrese el codigo ");
	scanf("%d",&codi);
	
	//-------------------------------------------------------------------------------------------------------------------------------------------------------
	while(codi!=0)
	{
		rewind(arch);
		band=-1;
		fread(&auxProdu,sizeof(T_PRODUCTOS),1,arch);
		while(!feof(arch) && band==-1)
		{
			if(codi==auxProdu.codiProducto)
				band=1;
			else
				fread(&auxProdu,sizeof(T_PRODUCTOS),1,arch);
		}
		if(band==1)
		{
			fseek(arch,sizeof(T_PRODUCTOS)*(-1),1);
			do{
				printf("(si no quiere cambiar el precio escriba 0)\n");
				printf("Ingrese el nuevo precio del producto con el codigo %d: ",auxProdu.codiProducto);
				scanf("%f",&precio);
			}while(precio<0);
			
			printf("\n(si no quiere cambiar la descripcion escriba solo la letra n)\n");
			printf("Ingrese la nueva descripcion del producto: ");
			fflush(stdin);
			gets(descrip);
			if(precio!=0)
				auxProdu.precio=precio;
			if(strcmpi(descrip,"n")!=0)
				strcpy(auxProdu.descripcion,descrip);
			fwrite(&auxProdu,sizeof(T_PRODUCTOS),1,arch);
		}
		printf("\ningrese el codigo ");
		scanf("%d",&codi);
	}
	fclose(arch);
	//--------------------------------------------------------------------------------------------------------------------------------------------------------
	mostrar();//aca muestro devuelta el contenido del archivo, por si se efectuo algun cambio
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrar()
{
	T_PRODUCTOS aux;
	FILE * arch;
	arch=fopen("precios.dat","rb");
	if(arch==NULL)
	{
		printf("error de archivo");
		exit(1);
	}
	printf(" %-10s %-21s %-10s\n","CODIGO","DESCRIPCION","PRECIO");
	fread(&aux,sizeof(T_PRODUCTOS),1,arch);
	while(!feof(arch))
	{
		printf(" %-10d %-21s %-10.2f\n",aux.codiProducto,aux.descripcion,aux.precio);
		fread(&aux,sizeof(T_PRODUCTOS),1,arch);
	}
	fclose(arch);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------





