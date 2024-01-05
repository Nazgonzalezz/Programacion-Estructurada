/////////////////////////////////////////////////// MODELO DEL SEGUNDO PARCIAL ////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#define ARCHIVO "PEDIDOS_SEM.dat"
typedef struct	{
					int numPedido;
					int codigoVendedor;
					float importe;
					char estado;
				}T_PEDIDOS;

typedef struct	{
					int codigoVendedor;
					float importe;
					float porcentaje;
				}T_NUEVOARCHIVO;
void ordenar();
void generarArchivo();
void MostrarPedidoSemana();
void MostrarNuevoArch();
int LeerYvalidar(int,int);
int EstaDentroDelRango(int,int,int);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int cant,i,j,pedidoCan,cantRegistros;
	FILE * arch, *arch2;
	//----------------------------------------------------------------------------------------------------------------------------------------------------------
	T_PEDIDOS aux, vec[]={ //todo esto es para generar el archivo 
		{1,444,343.50,'P'},
		{2,666,20.90,'P'},
		{3,444,3434.30,'P'},
		{4,111,1000.50,'P'},
		{5,333,992.45,'P'},
		{6,666,3232.000,'P'},
		{7,999,204.90,'P'},
		{8,111,2333,'P'},
		{9,111,2000.30,'P'},
		{10,111,8000,'P'},
		{11,555,660,'P'},
		{12,222,200.9,'P'},
		{13,888,1.33,'P'},
		{14,777,3000,'P'},
		{15,555,3,'P'}
	};
	cant=sizeof(vec)/sizeof(T_PEDIDOS);
	arch=fopen("PEDIDOS_SEM.dat","wb");
	if(arch==NULL)
	{
		printf("error al generar el archivo");
		exit(1);
	}
	for(i=0;i<cant;i++)
	{
		fwrite(&vec[i],sizeof(T_PEDIDOS),1,arch);
	}
	fclose(arch);
	MostrarPedidoSemana();
	//----------------------------------------------------------------------------------------------------------------------------------------------------------
	arch=fopen("PEDIDOS_SEM.dat","r+b");
	arch2=fopen("Depurado.dat","wb");
	if(arch==NULL || arch2==NULL )
	{
		printf("eror al abrir el archivo");
		exit(1);
		
	}
	fseek(arch,sizeof(T_PEDIDOS)*0,2);
	cantRegistros=ftell(arch)/sizeof(T_PEDIDOS);
	
	pedidoCan=LeerYvalidar(cantRegistros,1);
	while( pedidoCan!=0 )
	{
		rewind(arch); 
		fseek(arch,sizeof(T_PEDIDOS)*(pedidoCan-1),1);
		aux.estado='C';
		fwrite(&aux,sizeof(T_PEDIDOS),1,arch);
		
		pedidoCan=LeerYvalidar(cantRegistros,1);
	}
	fclose(arch);
	arch=fopen("PEDIDOS_SEM.dat","rb");
	if(arch==NULL)
	{
		printf("error");
		exit(1);
	}
	fread(&aux,sizeof(T_PEDIDOS),1,arch);
	while(!feof(arch))
	{
		if(aux.estado=='P')
		{
			fwrite(&aux,sizeof(T_PEDIDOS),1,arch2);
		}
		fread(&aux,sizeof(T_PEDIDOS),1,arch);
	}
	fclose(arch);
	fclose(arch2);
	i=remove("PEDIDOS_SEM.dat");
	if(i==0)
		printf("\nEl archivo PEDIDOS_SEM.dat se a eliminado correctamente"); 
	j=rename("Depurado.dat","PEDIDOS_SEM.dat");
	if(j==0)
		printf("\nSe cambio bien el nombre de Depurado.dat por PEDIDOS_SEM.dat  ");
	ordenar();
	MostrarPedidoSemana();
	generarArchivo();
	MostrarNuevoArch();
	
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ordenar()
{
	T_PEDIDOS auxActual,auxVieja;
	int ordenado, cont, primerRecorrido=1,ultimoIntercambio,intercambio; 
	FILE * arch;
	arch=fopen("PEDIDOS_SEM.dat","r+b");
	if(arch==NULL)
	{
		printf("error de archivo ");
		exit(1);
	}
	printf("\n\n");
	do{
		ordenado=1;
		fread(&auxVieja,sizeof(T_PEDIDOS),1,arch);
		cont=1;
		while( (primerRecorrido && !feof(arch))    ||   (!primerRecorrido && cont<=ultimoIntercambio) )
		{
			fread(&auxActual,sizeof(T_PEDIDOS),1,arch);
			cont++;
			if(!feof(arch))
			{
				if(auxActual.codigoVendedor <auxVieja.codigoVendedor)
				{
					fseek(arch,sizeof(T_PEDIDOS)*(-2),SEEK_CUR);
					fwrite(&auxActual,sizeof(T_PEDIDOS),1,arch); 
					fwrite(&auxVieja,sizeof(T_PEDIDOS),1,arch);
					fflush(arch);
					intercambio=cont;
					ordenado=0;
				}
				else
					auxVieja=auxActual;
			}
		}
		ultimoIntercambio=intercambio;
		primerRecorrido=0;
		rewind(arch);
	}while(!ordenado);
	fclose(arch); 
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
void generarArchivo()
{
	int codigoActual,acu,cont;
	T_PEDIDOS aux;
	T_NUEVOARCHIVO aux2;
	FILE *arch,*arch2;
	
	arch=fopen("PEDIDOS_SEM.dat","rb");
	arch2=fopen("pedidos.dat","wb");
	if(arch2== NULL || arch==NULL)
	{
		printf("error de archivo");
		exit(1);
	}
	fread(&aux,sizeof(T_PEDIDOS),1,arch);
	while( !feof(arch))
	{
		codigoActual=aux.codigoVendedor;
		acu=0;
		cont=0;
		while(!feof(arch) && codigoActual==aux.codigoVendedor)
		{
			cont++;
			acu+=aux.importe ;
			fread(&aux,sizeof(T_PEDIDOS),1,arch);
		}
		aux2.codigoVendedor=codigoActual;
		aux2.importe=acu;
		aux2.porcentaje=acu/cont;
		fwrite(&aux2,sizeof(T_NUEVOARCHIVO),1,arch2);
	}
	fclose(arch);
	fclose(arch2);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void MostrarPedidoSemana()
{
	T_PEDIDOS aux;
	FILE * arch;
	arch=fopen("PEDIDOS_SEM.dat","rb");
	if(arch==NULL)
	{
		printf("error de archivo ");
		exit(1);
	}
	printf("\n\n");
	printf(" %-12s %-12s %-12s %-10s\n","NUM PEDIDO","COD VENDEDOR","IMPORTE","ESTADO");
	printf("*****************************************************\n");
	fread(&aux,sizeof(T_PEDIDOS),1,arch);
	while(!feof(arch))
	{
		printf(" %-12d %-12d %-12.2f %-10c\n",aux.numPedido,aux.codigoVendedor,aux.importe,aux.estado);
		fread(&aux,sizeof(T_PEDIDOS),1,arch);
	}
	fclose(arch);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
void MostrarNuevoArch()
{
	T_NUEVOARCHIVO aux;
	FILE * arch;
	arch=fopen("pedidos.dat","rb");
	if(arch==NULL)
	{
		printf("error de archivo ");
		exit(1);
	}
	printf("\n\n");
	printf(" %-12s %-12s %-12s\n","COD VENDEDOR","IMPORTE","PORCENTAJE");
	printf("************************************\n");
	fread(&aux,sizeof(T_NUEVOARCHIVO),1,arch);
	while(!feof(arch))
	{
		printf(" %-12d %-12.2f %-12.2f\n",aux.codigoVendedor,aux.importe,aux.porcentaje);
		fread(&aux,sizeof(T_NUEVOARCHIVO),1,arch);
	}
	fclose(arch);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
int EstaDentroDelRango(int ls, int li,int num)
{
	if(num>=li-1 && num<=ls) //le resto uno al limite inferior para que me pase el cero por la validacion 
		return 1;
	else 
		return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
int LeerYvalidar(int ls ,int li)
{
	int num;
	do{
		printf("Ingrese el numero de pedido a cancelar(1.....) ");
		scanf("%d",&num);
		if(EstaDentroDelRango( ls,li,num)==0)
			printf("error, ingreso mal el numero\n ");
	}while( EstaDentroDelRango( ls,li,num)==0);
	return num;
}











