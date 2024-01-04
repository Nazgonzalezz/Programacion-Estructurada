/*3.5 Se dispone de un archivo llamado Stock.dat que contiene la información de los 10 productos que vende una
fábrica. En el archivo se guarda:
			• Código de artículo (entero)
			• Descripción (50 caracteres máximo)
			• Stock (entero)
Luego se ingresan por teclado las ventas a realizar indicando:
			• Código de artículo
			• Cantidad
La carga por teclado de las ventas finaliza con un código de artículo igual a 0.
 
Por cada venta se debe controlar si hay stock suficiente y si lo hay, restar el stock de dicho producto, sino
hay stock se debe vender lo que quede disponible y grabar un registro en un archivo Faltantes.dat con la
cantidad que no pudo venderse, dicho registro debe contener:
			• Código de artículo
			• Cantidad
Se genera un registro por cada venta que no pudo concretarse, pudiendo quedar en el archivo varios
registros faltantes del mismo producto.
Al finalizar actualizar el archivo Stock.dat con el stock actualizado luego de procesar las ventas
*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct{
				int codigo;
				char descripcion[51];
				int stock;
			  } T_PRODUCTO;

typedef struct{
			   int codigo;
			   int cantidad;
			  } T_CODIyCANT;
#include <stdio.h>
int buscar(T_PRODUCTO[],int,int);

int main()
{
	T_PRODUCTO vSTOCK[10];
	T_CODIyCANT FALTANTES;
	int i,codi,cant,pos,aux,cuantoFalta=-1;
	FILE * arch;
	
	//-------------------------------------------------------------------------------------------------------------------------------------------------------
	//aca copio el archivo a un vector
	arch=fopen("Stock.dat","rb");
	if(arch==NULL)
	{
		printf("error. no se encontro el archivo ");
		exit(1);
	}
	for(i=0;i<10;i++)
	{
		
		fread(&vSTOCK[i],sizeof(T_PRODUCTO),1,arch);
	}
	fclose(arch); 
	//----------------------------------------------------------------------------------------------------------------------------------------------------------
	
	//---------------------------------------------------------------------------------------------------------------------------------------------------------
	//aca muestro los codigos para saber cuales son (porque los profes crearon el archivo, asi que no se xd)
	printf("%7s  %8s  %-51s \n","CODIGOS","CANTIDAD","DESCRIPCION"); 
	for(i=0;i<10;i++)
	{
		printf("%-7d  %-8d  %-51s\n",vSTOCK[i].codigo,vSTOCK[i].stock,vSTOCK[i].descripcion);
	}
	//---------------------------------------------------------------------------------------------------------------------------------------------------------
	
	//-------------------------------------------------------------------------------------------------------------------------------------------------------
	//creo el archivo con los faltantes.Voy a hacer un bucle donde voy a actualizar el vector donde tengo los datos del stock, y ademas voy a ir escribiendo 
	//el archivo con los faltantes
	arch=fopen("Faltantes.dat", "wb");
	if(arch==NULL)
	{
		printf("error. no se encontro el archivo ");
		exit(1);
	}
	do{
		printf("Ingrese el codigo de articulo ");
		printf("\n(La carga por teclado de las ventas finaliza con un codigo de articulo igual a 0) ");
		scanf("%d",&codi); 
		pos=buscar(vSTOCK,codi,10);
		if(pos==-1&&codi!=0)
			printf("error. el codigo no existe ni es cero\n");
	}while(pos==-1&&codi!=0);
	
	while(codi!=0)
	{
		printf("Ingrese la cantidad vendida ");
		scanf("%d",&cant);	 
		if(vSTOCK[pos].stock>=cant)
		{
			vSTOCK[pos].stock-=cant;
		}
		else
		{
			cuantoFalta=0;
			aux=vSTOCK[pos].stock; //como se que la cantidad que tengo es menos que lo que quiero vender lo copio en una variable al valor
			aux-=cant; //le resto la cantidad que quiero vender. me va a quedar un numero negativo
			while(aux<0)//hago un bucle para que vaya contando hasta llegar a cero, asi se cuanto me falta
			{
				cuantoFalta++;
				aux++;
			}
			vSTOCK[pos].stock-=(cant-cuantoFalta);//aca vendo lo que puedo vender
			FALTANTES.codigo=vSTOCK[pos].codigo;
			FALTANTES.cantidad=cuantoFalta;
			fwrite(&FALTANTES,sizeof(T_CODIyCANT),1,arch);	
		}
		do{ 
			printf("Ingrese el codigo de articulo ");
			scanf("%d",&codi); 
			pos=buscar(vSTOCK,codi,10);
			if(pos==-1&&codi!=0)
				printf("error. el codigo no existe ni es cero\n");
		}while(pos==-1&&codi!=0);
	}
	fclose(arch);
	//---------------------------------------------------------------------------------------------------------------------------------------------------------
	
	
	//---------------------------------------------------------------------------------------------------------------------------------------------------------
	//uso la variable cuantofalta como bandera. si no hubo ningun faltante no muestro nada. si hubo un faltante lo muestro. 
	if(cuantoFalta!=-1)
	{
		arch=fopen("Faltantes.dat", "rb");
		if(arch==NULL)
		{
			printf("error. no se encontro el archivo ");
			exit(1);
		}
		printf("FALTANTES:\n----------\n\n");
		printf("%-7s  %-8s\n","CODIGO","CANTIDAD");
		fread(&FALTANTES,sizeof(T_CODIyCANT),1,arch);
		while(!feof(arch))
		{
			printf("%-7d  %-8d\n",FALTANTES.codigo,FALTANTES.cantidad);
			fread(&FALTANTES,sizeof(T_CODIyCANT),1,arch);
		}
		fclose(arch); 
	}
	//---------------------------------------------------------------------------------------------------------------------------------------------------------
	
	
	//---------------------------------------------------------------------------------------------------------------------------------------------------
	//aca copio el vector stock al archivo (esto es para actualizar el archivo) y despues muestro el contenido actualizado 
	arch=fopen("Stock.dat","wb");
	if(arch==NULL)
	{
		printf("error. no se encontro el archivo ");
		exit(1);
	}
	for(i=0;i<10;i++)
	{	
		fwrite(&vSTOCK[i],sizeof(T_PRODUCTO),1,arch);
	}	 
	fclose(arch);
	printf("\n  STOCK ACTUALIZADO\n-------------------\n");
	printf("%7s  %8s  %-51s \n","CODIGOS","CANTIDAD","DESCRIPCION");
	for(i=0;i<10;i++)
	{
		printf("%-7d  %-8d  %-51s\n",vSTOCK[i].codigo,vSTOCK[i].stock,vSTOCK[i].descripcion);
	}
	//---------------------------------------------------------------------------------------------------------------------------------------------------------
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int buscar(T_PRODUCTO v[],int dato,int num)
{
	int pos=-1,i=0;
	while(pos==-1 && i<num )
	{
		if(v[i].codigo ==dato)
			pos=i;
		else
			i++;
	}
	return pos;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------







