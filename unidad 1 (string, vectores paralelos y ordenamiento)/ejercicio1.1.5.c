/*1.1.5 La librería Libreto S.A. desea analizar las ventas realizadas por cada una de sus sucursales.
Existen 7 sucursales codificadas con los números 10, 20, 30, 40, 50, 60 y 70.
No se sabe la cantidad de libros que vende la empresa pero sí se sabe que no son más de 100. Se debe
realizar una carga inicial solicitando al usuario que ingrese por teclado los códigos de libros disponibles (los códigos
son de 4 dígitos).
Luego se ingresan por teclado las ventas realizadas, ingresando por cada venta los siguientes datos:
• Código de sucursal (entero 10, 20, 30, 40, 50, 60 o 70)
• Código de libro (entero de 4 cifras)
• Cantidad Vendida (entero mayor a 0)
Puede ingresarse más de una venta por libro/sucursal. Si un libro no se vendió en la sucursal no se informa.
La carga de datos finaliza al ingresar un código de libro igual a 0.
1. Cargar los libros disponibles en la empresa mediante la función CargaLibros, esta función debe asegurar
que se ingresen código de 4 cifras y no debe permitir ingresar códigos repetidos.
2. Mostrar el detalle de cantidad de libros vendidas en cada sucursal con el siguiente formato:
Libro/Sucursal 10 20 30 40 50 60 70
xxxx xx xx xx xx xx xx xx
xxxx xx xx xx xx xx xx xx
xxxx xx xx xx xx xx xx xx
…
xxxx xx xx xx xx xx xx xx
3. Mostrar la o las sucursales que vendieron mayor cantidad de libros
4. Mostrar aquellos libros que NO fueron vendidos en ninguna sucursal*/
#include <stdio.h>
int CargaLibros(int[],int);
int buscar(int[],int,int);
int mayor(int[],int);
int LeerYvalidar(int,int,int);
int EstaDentroDelRango(int,int,int);
int main()
{
	int vCodigoLib[100],ultPosLibro, LibrosPorSucursal[100][7]={0},vCodiSucur[]={10,20,30,40,50,60,70},vVentasPorSucur[7]={0};
	int codiLib,cantvendi,codisucur,codiSucur,posCodiSucur,posCodiLib,i,j,mayorVenta,flag;
	ultPosLibro=CargaLibros(vCodigoLib,100); //funcion para cargar los codigos de libros no repetidos 
	do{
		printf("Ingrese el codigo del libro "); 
		scanf("%d",&codiLib);
		posCodiLib=buscar(vCodigoLib,codiLib,ultPosLibro);
		if(posCodiLib==-1&&codiLib!=0)
			printf("El codigo ingresado no existe\n");
	}while(posCodiLib==-1&&codiLib!=0);
	
	while(codiLib!=0)
	{
		do{
			printf("Ingrese el codigo de sucursal (10,20...70) ");//valido el ingreso del codigo de sucursal (10,20....70)
			scanf("%d",&codiSucur);
			posCodiSucur=buscar(vCodiSucur,codiSucur,7);
			if(posCodiSucur==-1)
				printf("El codigo ingresaso no es valido\n");
		}while(posCodiSucur==-1);
		do{ //valido que el ingreso de la cantidad que se vende sea mayor a cero 
			printf("Ingrese la cantidad vendida ");
			scanf("%d",&cantvendi);
			if(cantvendi<=0)
				printf("Recuerde que tiene que ser mayor a cero\n");
		}while(cantvendi<=0);
		vVentasPorSucur[posCodiSucur]+=cantvendi;//acumulo todos los libros que se venden por sucursal 
		LibrosPorSucursal[posCodiLib][posCodiSucur]+=cantvendi; //aca cargo la matriz
		do{ //se pide de vuelta para que no se cree un bucle infinito 
			printf("Ingrese el codigo del libro "); 
			scanf("%d",&codiLib);
			posCodiLib=buscar(vCodigoLib,codiLib,ultPosLibro);
			if(posCodiLib==-1&&codiLib!=0)
				printf("El codigo ingresado no existe\n");
		}while(posCodiLib==-1&&codiLib!=0);
	}
	printf("\n\n\nLibro/Sucursal\t10\t20\t30\t40\t50\t60\t70\n");
	//ACA PRESTAR ATENCION. le tengo que restar un numero PORQUE cuando cargo el vector dejo para el cero (que es la condicion de fin del while) y me lo carga
	//en el vector (en la ultima posicion)
	for(i=0;i<ultPosLibro-1;i++)
	{
		printf("%d\t\t",vCodigoLib[i]);
		for(j=0;j<7;j++)
		{
			printf("%d\t",LibrosPorSucursal[i][j]);
		}
		printf("\n");
	}
	mayorVenta=mayor(vVentasPorSucur,7);
	printf("\nLa maxima venta es %d y la hicieron las sucursales: \n",mayorVenta);
	for(i=0;i<7;i++)
	{
		if(vVentasPorSucur[i]==mayorVenta)
			printf("%d\t",(i+1)*10);
	}
	printf("\nLos codigos de los libros que no fueron vendidos por ninguna sucursal son \n");
	for(i=0;i<ultPosLibro-1;i++)
	{
		flag=0;
		for(j=0;j<7;j++)
		{
			if(LibrosPorSucursal[i][j]==0)
				flag++;
		}
		if(flag==7)
			printf("%d",vCodigoLib[i]);
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////// FUNCIONES ////////////////////////////////////////////////////////////////////////////////
int LeerYvalidar(int li,int ls,int n)
{
	int num,aux; 
	do{
		scanf("%d",&num);
		aux=EstaDentroDelRango(num,li,ls);
		if(aux==0&&num!=n)
			printf("eror.El numero ingresado no esta dentro del rango establecido\n");
	}while(aux==0&&num!=n);
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
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
int CargaLibros(int vCodigLib[],int num)
{
	int aux,i=0,pos ;
	printf("Cargue los codigos de los libros(cuatro numeros) (para dejar de cargar libros escriba 0)");
	aux=LeerYvalidar(1000,9999,0);
	vCodigLib[i]=aux;
	i++;
	while(i<num&&aux!=0)
	{
		do
		{
			printf("Cargue los codigos de los libros(cuatro numeros) (para dejar de cargar libros escriba 0)");
			aux=LeerYvalidar(1000,9999,0);
			pos=buscar(vCodigLib,aux,i);
			if(pos!=-1)
				printf("Ingreso un codigo de libro que ya existe\n");
		}while(pos!=-1);
		vCodigLib[i]=aux;
		i++;
	}
	return i;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
int buscar(int v[],int dato,int num)
{
	int pos=-1,i=0;
	while(i<num&&pos==-1)
	{
		if(v[i]==dato)
			pos=i;
		i++;
	}
	return pos; 
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
int mayor(int v[],int num)
{
	int i,mayor=v[0];
	for(i=1;i<num;i++)
	{
		if(v[i]>mayor)
			mayor=v[i];
	}
	return mayor;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------

























