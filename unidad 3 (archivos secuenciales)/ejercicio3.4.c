/*3.4 Realizar un programa que permite actualizar una lista de precios en forma masiva, ingresando un porcentaje
de incremento. El archivo original se llama precios.dat y fue generado utilizando la siguiente estructura:
			• Código (entero)
			• Precio (float)
			• Descripción (de hasta 50 caracteres)
No se sabe la cantidad de registros del archivo.
Se solicita generar un nuevo archivo llamado Precios_actualizados.dat.
*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
typedef struct 
{
	int codigo;
	float precio;
	char descripcion[51];
}T_LISTA;

int main()
{
	T_LISTA lista;
	int porcentaje; 
	FILE *arch; 
	FILE * arch2;
	
	arch=fopen("precios.dat","rb");
	arch2=fopen("Precios_actualizados.dat","wb");
	
	if(arch==NULL||arch2==NULL)
	{
		printf("Ocurrio un error");
		exit(1);
	}
	printf("Ingrese el porcentaje que desea incrementar:%");
	scanf("%d",&porcentaje); 
	
	fread(&lista,sizeof(T_LISTA),1,arch);
	while(!feof(arch))
	{
		lista.precio*=porcentaje;
		fwrite(&lista,sizeof(T_LISTA),1,arch2);
		fread(&lista,sizeof(T_LISTA),1,arch);
	}
	fclose(arch);
	fclose(arch2);

    arch2=fopen("Precios_actualizados.dat","rb");
	if(arch2==NULL)
	{
		printf("Error. no existe");
		exit(1);
	}
	
	printf("\n\n%6s  %-6s   %-50s\n","CODIGO","PRECIO","DESCRIPCION");
	fread(&lista,sizeof(T_LISTA),1,arch2);
	while(!feof(arch2))
	{
		printf("%-6d  %-6.2f   %-50s\n",lista.codigo,lista.precio,lista.descripcion);
		fread(&lista,sizeof(T_LISTA),1,arch2);
	}
	fclose(arch2);
	
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

























