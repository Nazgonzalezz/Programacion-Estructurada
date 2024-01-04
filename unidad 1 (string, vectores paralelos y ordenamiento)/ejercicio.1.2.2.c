/*Ingresar dos Strings, uno con el nombre y el otro con el apellido de una persona. Utilizando las
funciones de la biblioteca string.h generar un tercer string formado por: NOMBRE, APELLIDO (nombre
coma espacio y apellido) y mostrarlo*/
#include <stdio.h>
#include <string.h>
int main()
{
	char sNombre[20],sApellido[20];
	printf("ingrese su nombre ");
	gets(sNombre);
	printf("Ingrese su apellido ");
	gets(sApellido);
	strcat(sNombre," ");
	strcat(sNombre,sApellido);
	printf("Su nombre y apellido son: %s",sNombre);
	return 0;
}
