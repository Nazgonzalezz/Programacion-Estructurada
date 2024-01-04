/*dado un listado de alumnos vAlumnos[5][11] con datos unicos y una cadena sAlu[11], confeccionar un programa que cargue por 
extension el listado y una funcion que busque el apellido en el listado de alumnos mostrando el orden en que aparece el listado*/
#include <stdio.h>
#include <string.h>
int busqueda(char[][11],char[],int);
int main()
{
	char vAlumnos[5][11]={"ara","emi","manu","pablo","mati"}, sAlu[11];
	int flag=-1,pos,i;
	
	printf("listado de alumnos:\n-----------------\nNUMERO ALUMNO\n");
	for(i=0;i<5;i++)
	{
		printf(" %d\t %s\n",i+1,vAlumnos[i]);
	}
	
	do{
		if(flag==-1)
		{
			printf("Ingrese el nombre del alumno ");
			flag=2;
		}
		else
			printf("\nError, ese alumno no esta en la lista.Ingreselo devuelta ");
		scanf("%s",sAlu);
		pos=busqueda(vAlumnos,sAlu,5);
		if(pos!=-1)
			printf("El alumno esta en la posicion %d",pos+1);
	}while(pos==-1);
	return 0; 
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int busqueda(char vAlumnos[][11],char sAlu[],int num)
{
	int i=0,pos=-1; 
	while(i<num && pos==-1)
	{
		if(strcmp(vAlumnos[i],sAlu)==0)
			pos=i;
		else
			i++;
	}
	return pos;
}























