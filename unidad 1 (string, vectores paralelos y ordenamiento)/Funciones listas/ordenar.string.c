#include <stdio.h>
void ordenar(char[][],int};
int main()
{
	
	return 0;
}
void ordenar (char vn[][11],int cant)
{
	int i,j;
	char aux[11];
	for (i=0;i<cant-1;i++)
	{
		for (j=0;j<cant-1-i;j++)
		{
			if (strcmpi(vn[j],vn[j+1]) > 0)
			{
				strcpy(aux, vn[j]);
				strcpy(vn[j],vn[j+1]);
				strcpy(vn[j+1], aux);
			}
		}
	}
}
