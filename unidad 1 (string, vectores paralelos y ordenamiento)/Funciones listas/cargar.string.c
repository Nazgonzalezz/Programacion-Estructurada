#include <stdio.h>
int main()
{
	
	return 0;
	
}
void carga(char vn[][11],int cant)
{
	int i;
	for (i=0;i<cant;i++)
	{
		printf ("Ingrese el nombre numero %d: ", i+1);
		gets(vn[i]);
	}
}

