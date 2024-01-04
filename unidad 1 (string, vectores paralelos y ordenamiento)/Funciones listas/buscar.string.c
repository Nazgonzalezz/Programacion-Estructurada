#include <stdio.h>
int main()
{
	
	return 0;
}
int buscar(char vn[][11],char buscado[], int cant)
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

