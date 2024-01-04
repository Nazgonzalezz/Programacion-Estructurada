/*Se ingresan c�digo y precio unitario de los productos que vende un negocio. No se sabe la cantidad
exacta de productos, pero s� se sabe que son menos de 50. El c�digo es alfanum�rico de 3 caracteres y
la carga de los datos de productos termina con un c�digo igual al �FIN�. Luego se registran las ventas del
d�a y por cada venta se ingresa el c�digo de producto y cantidad de unidades vendidas terminando con
una cantidad igual a 0. Se solicita:
c. Calcular la recaudaci�n total del d�a y el producto del cual se vendi� menor cantidad de unidades.
d. Mostrar el listado de productos con su precio ordenado en forma alfab�tica por c�digo de producto.*/
#include <stdio.h>
#include <string.h>
int cargarVec(char[][4],int[],int);
int buscar(char[][4],char[],int);
void ordenaR(char[][4],int[],int);
int menor(int[],int);
int main()
{
	char vsCodiProd[50][4],codi[4];
	int vPrecioProduc[50]={0},vUnidadesVendidas[50]={0},cVendida,ultimPos,pos,Menor,i,acu=0;
	
	ultimPos=cargarVec(vsCodiProd,vPrecioProduc,50);
	
	printf("\nIngrese la cantidad vendida (ingrese cero para terminar)");
	scanf("%d",&cVendida);

	while(cVendida!=0)
	{
		fflush(stdin);
		do{
			printf("Ingrese el codigo del producto ");
			scanf("%s",codi);
			pos=buscar(vsCodiProd,codi,ultimPos);
			if(pos==-1)
			{
				printf("Error.lo ingreso mal\n");
				fflush(stdin);
			}
		}while(pos==-1);
		
		vUnidadesVendidas[pos]+=cVendida;
		printf("\nIngrese la cantidad vendida (ingrese cero para terminar)");
		scanf("%d",&cVendida);	
	}
	
	Menor=menor(vUnidadesVendidas,ultimPos);
	printf("Los codigos de los productos que se vendieron en menor cantidad son:\n");

	for(i=0;i<ultimPos;i++)
	{
		if(vUnidadesVendidas[i]==Menor)
			printf("%s\n",vsCodiProd[i]);
	}
	
	for(i=0;i<ultimPos;i++)
	{
		acu+=vPrecioProduc[i]*vUnidadesVendidas[i];
	}
	printf("\nEl total vendido es de %d",acu);
	ordenaR(vsCodiProd,vPrecioProduc,ultimPos);
	printf("\nCODIGO PRECIO\n");
	for(i=0;i<ultimPos;i++)
	{
		printf("%s\t%d\n",vsCodiProd[i],vPrecioProduc[i]);
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int cargarVec(char vsCodiProd[][4], int vPrecioProduc[],int num)
{
	int i=0,aux;
	char sAux[3];
	
	printf("Ingrese los codigos de los productos(para terminar de cargar escriba fin) ");
	gets(sAux);
	
	while(i<50 &&  strcmpi(sAux,"fin")!=0 )
	{
		strcpy(vsCodiProd[i],sAux);
		printf("Ingrese el precio del producto ");
		scanf("%d",&aux);
		vPrecioProduc[i]=aux;
		fflush(stdin);
		
		printf("Ingrese los codigos de los producto ");
		gets(sAux);
		i++;
	}
	return i;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
int buscar(char vsCodiProd[][4],char dato[],int num)
{
	int i=0,pos=-1;
	while(i<num && pos==-1)
	{
		if(strcmpi(vsCodiProd[i],dato) == 0)
			pos=i;
		else
			i++;
	}
	return pos;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
int menor(int v[],int num)
{
	int i=0,menor=-1;
	while(i<num)
	{
		if(v[i]!=0)
		{
			if(v[i<menor || menor==-1])
				menor=v[i];
		}
		i++;
	}
	return menor;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
void ordenaR (char vsCodigoProd[][4],int vPrecio[],int cant)
{
	int i,j,auxN;
	char aux[4];
	for (i=0;i<cant-1;i++)
	{
		for (j=0;j<cant-1-i;j++)
		{
			if (strcmpi(vsCodigoProd[j],vsCodigoProd[j+1]) > 0)
			{
				strcpy(aux, vsCodigoProd[j]);
				strcpy(vsCodigoProd[j],vsCodigoProd[j+1]);
				strcpy(vsCodigoProd[j+1], aux);
				
				auxN=vPrecio[j];
				vPrecio[j]=vPrecio[j+1];
				vPrecio[j+1]=auxN;
			}
		}
	}
}














































