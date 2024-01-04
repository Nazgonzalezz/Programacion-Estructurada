#include <stdio.h>
int LeerYvalidar(int,int);
int EstaDentroDelRango(int,int,int);
int main()
{
	int num;
	num=LeerYvalidar(100,999);
	return 0;
}
int LeerYvalidar(int li,int ls)
{
	int num; 
	do{
		printf("\nIngrese un numero ");
		scanf("%d",&num);
		//if(EstaDentroDelRango(num,li,ls)==0)
		//	printf("eror.lo ingreso mal\n");
	}while(EstaDentroDelRango(num,li,ls)==0);
	return num;
}
int EstaDentroDelRango(int num,int li,int ls)
{
	if(num>=li && num<=ls)
		return 1;
	else
		return 0;
}
