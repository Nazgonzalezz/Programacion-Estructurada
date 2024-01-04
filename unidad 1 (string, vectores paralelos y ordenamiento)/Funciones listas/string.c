#include <stdio.h>
int main()
{
	/////////////////////////////////////////////////////////// Lectura por teclado de strings///////////////////////////////////////////////////////////
	//------------------------- 1)scanf     ----------------------------------------------------------------------------------------------------------------
	char nombre[20];
	printf ("Ingrese un nombre: ");
	scanf("%s", nombre);
	printf ("El nombre ingresado es: %s", nombre);
	//lo que tiene el scanf es que cuando el usuario aprieta la tecla enter (un espacio) me va a dejar de guardar lo que este en el buffer. 
	//Entonces todo lo que el usuario ingrese despues del espacio se va a perder
	
	//-------------------------- 2)gets    -----------------------------------------------------------------------------------------------------------------
	char nombre2[20];
	printf ("Ingrese un nombre: ");
	gets(nombre);
	printf ("El nombre ingresado es: %s", nombre);
	//lo que tiene la funcion gets es que no me controla el limite de letras que puede ingresar el usuario.Entonces, si el usuario ingresa mas 
	//letras de las que puede ingresar el "gets" me las va a guardar igual(utiliza espacio no reservado, lo que produce un error)
	
	//---------------------- 3) fgets     ----------------------------------------------------------------------------------------------------------------------
	char nombre3[20];
	printf ("Ingrese un nombre: ");
	fgets(nombre,20,stdin);
	printf ("El nombre ingresado es: %s", nombre);
	//Esta funcion si tiene en cuenta el limite de letras que puede ingresar el usuario. Lo bueno es que cuando el usuario se pasa de las letras el "fgets"
	//no me las guarda. Lo unico malo que tiene es que me guarda un "\n" (es el que el usuario ingresa para terminar de cargar datos )
	
	////////////////////////////////////////////////////////  Mostrar strings por pantalla ////////////////////////////////////////////////////////////////////
	puts(nombre);
	printf (“%s\n”, nombre2);
	
	return 0;
