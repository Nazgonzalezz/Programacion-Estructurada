#include <stdio.h>
#include <string.h>
int main()
{
	///////////////////////////////////////////////// . Biblioteca para el manejo de texto (string.h)////////////////////////////////////////////////////////
	//strlen Determina la longitud de una cadena
	char cadena [21];
	printf ("Ingrese una cadena de no m�s de 20 caracteres \n");
	fgets (cadena,20,stdin);
	printf ("La cadena ingresada contiene: %d caracteres", strlen(cadena) ); //(me guarda el \n al final, y me lo cuenta como un caracter)

	//strcpy Copia una cadena a otra
	char original [15], copia [15];
	printf ("Ingrese una cadena que sera luego copiada \n");
	gets (original);
	strcpy (copia, original);
	printf ("La cadena original es: %s y la copia es: %s", original, copia );
	
	//strcat Concatena dos cadenas dejando el resultado en la primera
	char receptor [40] = "Se agrego lo siguiente", dador [] =", me agregue";
	printf ("Las cadenas por separado son: \n\t %s\n\t %s", receptor, dador)
	strcat (receptor, dador);
	printf ("\nLas cadenas unificadas son: \n\t %s ", receptor );

	//strcmp Compara dos cadenas
	/*Si las cadenas son iguales devolver� un cero (0)
	Si la cadena 1 es mayor que la cadena 2 devolver� un valor positivo
	Si la cadena 1 es menor que la cadena 2 devolver� un valor negativo*/
	char cadena1[30], cadena2[30];
	printf ("Ingrese la primer cadena:");
	gets(cadena1);
	printf ("Ingrese la segunda cadena:");
	gets(cadena2);
	if (strcmp (cadena1, cadena2) == 0)
		printf ("\nAmbas cadenas son iguales " );
	else
	if (strcmp (cadena1, cadena2) > 0 )
		printf ("\nLa cadena1 es mayor que la cadena2");
	else
		printf ("\nLa cadena2 es mayor que la cadena1");
		
	//strcmpi Compara dos cadenas ignorando si son may�sculas o min�sculas
	/*Es exactamente igual a la funci�n strcmp pero ignora si son may�sculas o min�sculas es decir que
	el string �ANA� es igual al string �ana� y tambi�n es igual al string �anA� o cualquiera de sus
	variantes.*/
	
	return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
