/*1.2.1 Ingresar una frase de hasta 500 caracteres y contar cu�ntas palabras contiene dicha frase.
a. Considerar que las palabras est�n separadas por un �nico espacio.
b. Considerar que las palabras pueden estar separadas por m�s de un espacio consecutivo.*/
#include<stdio.h>
#include<string.h>
int buscarYdevolver(char[],int);
int main()
{
	char vFrase[500];
	int palabras,aux;
	printf("Ingrese una frase ");
	gets(vFrase);
	/*fgets(vFrase,500,stdin);
	aux=strlen(vFrase);
	if(vFrase[aux-1]=='\n')
		vFrase[aux-1]='\0';*/
	palabras=buscarYdevolver(vFrase,strlen(vFrase));
	printf("La frase ingresada tiene %d palabras ",palabras);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int buscarYdevolver(char vFrase[],int cant)
{ 
	int cont=0,i=0;	
	while(i<cant)
	{
		if(vFrase[i]==' ')
		{
			cont=cont+1;
			if(vFrase[i+1]==' ')
				cont=cont-1;
		}
		i++;
	}
	return  cont;
}
















