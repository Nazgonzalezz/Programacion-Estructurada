/*
2.1 Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes
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
DESCRIPCION CANTIDAD UNIDADES
VENDIDAS
IMPORTE TOTAL
VENDIDO
XXXXXXX XXXX $XXXXX,XX
*/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {char codigo[6];
                float precio;
                char descripccion [31];
                int cantvendida;
                float totalvendido}T_neumatico;

int main()
{
    int i=0;
    T_neumatico V_neumatico [50];
    T_neumatico aux;

    printf("ingrese descripcion del producto (FIN para terminar):\n");
    gets(aux.descripccion);

    while (strcmpi(S_aux,"fin")!=0&&i<50)
    {
        printf("ingresar codigo:\n");
        fflush(stdin);
        if (i==0)
        gets(aux.codigo)
        else
        {
            do
            {
                gets(aux.codigo);
                if (buscar (V_neumatico.codigo, aux.codigo)==-1)
                    printf("codigo repetido, ingrese denuevo\n");

            }while (buscar (V_neumatico.codigo, aux.codigo)==-1);

        }


        gets(aux.codigo)

        do
        {
            printf("ingrese precio total vendido:\n");
            scanf("%f",&aux.totalvendido);

        }while (aux.totalvendido>=0);

        do
        {
            printf("ingrese precio del producto:\n");
            scanf("%f",&aux.precio);
        }while (aux.precio>0);

        do
        {
            printf("ingrese cantidad de unidades ya vendidas:\n");
            scanf("%d",&aux.cantvendida);
        }while (aux.cantvendida>=0);


        printf("ingrese descripcion del producto (FIN para terminar):\n");
        fflush(stdio)
        gets(aux.descripccion);
        i++;
    }

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int buscar(char vn[],char buscado[], int cant)
{
	int i=0, pos=-1;
	while (pos==-1 && i<cant)
	{
		if (strcmpi(vn[i], buscado)==0)
 			pos =i;
		else
 			i++;
	}
	return pos;
}
