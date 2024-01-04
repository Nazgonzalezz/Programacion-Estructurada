/*3.1 Los datos de los alumnos de una comisión de Computación Transversal son:
		• Número de DNI (entero)
		• Nombre y Apellido (80 caracteres)
		• Nota1, Nota2 (entero)
		• Nota Promedio (real, calculado según Nota1 y Nota2)

		a. Declarar un tipo de dato que contenga la información del alumno.
		b. Con la información indicada para los alumnos. Grabar los datos en el archivo “ALUMNOS.dat”. Esta
		información de grabación finaliza con DNI cero.
		c. Leer los datos del archivo, mediante la Función LECTURA.
*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
typedef struct
{
	int dni;
	char nombreYapellido[81];
	int nota1;
	int nota2;
	float promedio;
} T_AlumCompu;

int LeerYvalidar(int,int);
int EstaDentroDelRango(int,int,int);
void  LECTURA();
int main()
{
	int aux,i=0;

	T_AlumCompu ALUMNOS;
	FILE * arch;
	arch=fopen("ALUMNOS.dat","wb"); //el modo wb no solo crea el archivo, sino que pisa el archivo que existia
	if(arch==NULL)
	{
		printf("Ocurrio un error");
		exit(1);
	}

	printf("Ingrese el dni del alumno (para terminar de cargar escriba cero):");
	aux=LeerYvalidar(10000000,99999999);

	while(aux!=0)
	{
		ALUMNOS.dni=aux;
		fflush(stdin);
		printf("Ingrese el nombre y apellido del alumno :");
		gets(ALUMNOS.nombreYapellido);
		printf("Ingrese la nota 1 del alumno :");
		scanf("%d",&ALUMNOS.nota1);
		printf("Ingrese la nota 2 del alumno :");
		scanf("%d",&ALUMNOS.nota2);
		ALUMNOS.promedio= (ALUMNOS.nota1+ALUMNOS.nota2)/2;
		fwrite(&ALUMNOS,sizeof(T_AlumCompu),1,arch);
		i++;


		printf("\nIngrese el dni del alumno (para terminar de cargar escriba cero):");
		aux=LeerYvalidar(10000000,99999999);
	}
	fclose(arch);
    LECTURA ();
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////// FUNCIONES  ////////////////////////////////////////////////////////////////////////////////////
int LeerYvalidar(int li,int ls)
{
	int num;
	do{
		scanf("%d",&num);
		if(EstaDentroDelRango(num,li,ls)==0 && num!=0)
			printf("Error, lo cargo mal. Ingreselo devuelta ");
	}while( EstaDentroDelRango(num,li,ls)==0 && num!=0);
	return num;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
int EstaDentroDelRango(int num,int li,int ls)
{
	if(num>=li && num<=ls)
		return 1;
	else
		return 0;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
void LECTURA ()
{
    T_AlumCompu ALUMNOS;
    FILE *arch;
    arch=fopen("ALUMNOS.dat","rb");
	if(arch==NULL)
	{
		printf("Error. no existe");
		exit(1);
	}
	printf("\n\n %-8s  %8s  %-50s\n","DNI","PROMEDIO","NOMBRE Y APELLIDO");
	fread(&ALUMNOS,sizeof(ALUMNOS),1,arch);
	while(!feof(arch))
	{
		printf(" %-8d  %8.2f  %-80s\n",ALUMNOS.dni,ALUMNOS.promedio,ALUMNOS.nombreYapellido);
		fread(&ALUMNOS,sizeof(ALUMNOS),1,arch);
	}
	fclose(arch);

}

















