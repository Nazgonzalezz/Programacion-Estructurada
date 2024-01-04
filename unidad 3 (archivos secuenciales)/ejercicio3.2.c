/*3.2 Tomando como base el archivo ALUMNOS.DAT creado en el ejercicio anterior se desea desarrollar un
programa que, basado en la información del archivo, genere 3 archivos:
		• Uno con los alumnos PROMOCIONADOS (ambas notas mayores o igual a 7).
		• Otro archivo con los alumnos en condición CURSADO (ambas notas mayores o igual a 4 pero no
		promocionados).
		• Y un tercer archivo con los REPROBADOS (al menos una nota, menor que 4).
Para comprobar los datos guardados realizar una función que reciba por parámetro el nombre del archivo
a mostrar, lo abre y muestre su contenido. Se debe invocar a la función 3 veces para mostrar todos los
archivos generados.
*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include <string.h>

typedef struct
{
	int dni;
	char nombreYapellido[81];
	int nota1;
	int nota2;
	float promedio;
} T_AlumCompu;

void  LECTURA(char []);

int main ()
{
    char promocionados [20], cursados [20], reprobodas [20];
    T_AlumCompu ALUMNOS;
	FILE * arch;
	FILE * arch2;
	FILE * arch3;
	FILE * arch4;
    strcpy (cursados,"CURSADOS.dat");
    strcpy (reprobodas,"REPROBADOS.dat");
    strcpy (promocionados,"PROMOCIONADOS.dat");
	arch=fopen("ALUMNOS.dat","rb");
    arch2=fopen("PROMOCIONADOS.dat","wb");
    arch3=fopen("CURSADOS.dat","wb");
    arch4=fopen("REPROBADOS.dat","wb");

	if(arch==NULL||arch2==NULL||arch3==NULL||arch4==NULL)
	{
		printf("Ocurrio un error");
		exit(1);
	}
    fread(&ALUMNOS,sizeof(ALUMNOS),1,arch);
	while (!feof(arch))
    {

        if (ALUMNOS.nota1>6&&ALUMNOS.nota2>6)
            fwrite(&ALUMNOS,sizeof(T_AlumCompu),1,arch2);
        else if (ALUMNOS.nota1>3&&ALUMNOS.nota2>3)
            fwrite(&ALUMNOS,sizeof(T_AlumCompu),1,arch3);
        else
            fwrite(&ALUMNOS,sizeof(T_AlumCompu),1,arch4);
        fread(&ALUMNOS,sizeof(ALUMNOS),1,arch);
    }
    fclose(arch);
    fclose(arch2);
    fclose(arch3);
    fclose(arch4);

    printf("\npromocionados: ");
    LECTURA(promocionados);
    printf("\ncursados:");
    LECTURA(cursados);
    printf("\nreprobados:");
    LECTURA(reprobodas);
    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LECTURA (char stringg [])
{
    T_AlumCompu ALUMNOS;
    FILE *arch;
    arch=fopen(stringg,"rb");
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

