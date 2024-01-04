/*2.1 Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes
de sus productos. Para ello primeramente se ingresan la información de los productos formados por:
	• Código (5 caracteres).
	• Precio (real).
	• Descripción (30 caracteres).
	• Cantidad de unidades vendidas (al mes anterior, entero).
	• Importe Total Vendido (al mes anterior, real).
Se sabe que la empresa no vende más de 50 productos. El ingreso de la carga de productos finaliza con un
producto con descripción “FIN”.
Luego ingresan las ventas del mes:
	• Código de Producto (5 caracteres).
	• Cantidad pedida.
El ingreso de datos de las ventas finaliza con una cantidad igual a 0. Se solicita:
	a. Actualizar la información de los productos con las ventas realizadas en el mes.
	b. Al finalizar, mostrar el listado de productos actualizado, informando:
		DESCRIPCION		CANTIDAD UNIDADES VENDIDAS		IMPORTE TOTAL VENDIDO
		XXXXXXX 					XXXX 					$XXXXX,XX                                     
		
*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct {char codigo[6];
				float precio;
				char descripccion[31];
				int cantvendida;
				float totalvendido;
				}T_neumatico;
#include<stdio.h>
#include <string.h>
int buscar (T_neumatico[],char[],int);
int main()
{
    int i=0,pos,j;
    T_neumatico vNEUMATICOS[50],aux;
    
    printf("ingrese descripcion del producto (FIN para terminar): ");
    gets(aux.descripccion);

    while (strcmpi(aux.descripccion,"fin")!=0&&i<50)
    {
        strcpy(vNEUMATICOS[i].descripccion,aux.descripccion);
		do{
        	fflush(stdin); 
			printf("Ingrese el codigo del producto ");
        	gets(aux.codigo);
        	if(buscar(vNEUMATICOS,aux.codigo,i)!=-1)
        		printf("error, ese codigo ya existe\n");
		}while(buscar(vNEUMATICOS,aux.codigo,i)!=-1);
		strcpy(vNEUMATICOS[i].codigo,aux.codigo);
		
        do
        {
            printf("ingrese precio total vendido: ");
            scanf("%f",&aux.totalvendido);
			if(aux.totalvendido<0)
				printf("error. el numero ingresado debe ser mayor o igual a cero\n");
        }while(aux.totalvendido<0);
		vNEUMATICOS[i].totalvendido=aux.totalvendido;
		
        do
        {
            printf("ingrese precio del producto:");
            scanf("%f",&aux.precio);
            if(aux.precio<=0)
				printf("error. el numero ingresado debe ser mayor a cero\n");
        }while (aux.precio<=0);
		vNEUMATICOS[i].precio=aux.precio;
		
        do
        {
            printf("ingrese cantidad de unidades ya vendidas: ");
            scanf("%d",&aux.cantvendida);
            if(aux.cantvendida<0)
				printf("error. el numero ingresado debe ser mayor o igual a cero\n");
        }while (aux.cantvendida<0);
		vNEUMATICOS[i].cantvendida=aux.cantvendida;

		fflush(stdin);
        printf("\ningrese descripcion del producto (FIN para terminar): ");
        gets(aux.descripccion);
        i++;
    }
    
    printf("\n\nVENTAS DE ESTE MES\ningrese la cantidad vendida (el ingreso finaliza con una cantidad igual a cero )");
    scanf("%d",&aux.cantvendida);
    while(aux.cantvendida!=0)
    {
		do{
			fflush(stdin);
			printf("Ingrese el codigo del producto ");
			gets(aux.codigo);
			pos=buscar(vNEUMATICOS,aux.codigo,i);
			if(pos==-1)
				printf("El codigo ingresado no existe\n");
		}while(pos==-1);
		
		vNEUMATICOS[pos].cantvendida+=aux.cantvendida;
		vNEUMATICOS[pos].totalvendido+=(aux.cantvendida*vNEUMATICOS[pos].precio);
		do{
    		printf("\n\nIngrese la cantidad vendida(el ingreso finaliza con una cantidad igual a cero )");
   			scanf("%d",&aux.cantvendida);
   			if(aux.cantvendida<0)
   				printf("error. tiene que ser mayor o igual a cero\n");
   		}while(aux.cantvendida<0);
	}
	
	printf("\n%-30s   %26s   %21s\n","DESCRIPCION","CANTIDAD UNIDADES VENDIDAS","IMPORTE TOTAL VENDIDO");
	for(j=0;j<i;j++)
	{
		printf("%-30s   %-26d   $%-21.2f \n",vNEUMATICOS[j].descripccion,vNEUMATICOS[j].cantvendida,vNEUMATICOS[j].totalvendido);
	}
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////  FUNCIONESSS ///////////////////////////////////////////////////////////////////////////////////////////
int buscar(T_neumatico vNEUMATICO[],char buscado[], int cant)
{
	int i=0, pos=-1;
	while (pos==-1 && i<cant)
	{
		if (strcmpi(vNEUMATICO[i].codigo, buscado)==0)
 			pos=i;
		else
 			i++;
	}
	return pos;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------





