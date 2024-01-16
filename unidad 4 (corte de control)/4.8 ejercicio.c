/*Una empresa dispone de un archivo ARTIC_PRECIO, con los siguientes datos de sus casi 500 artículos:
• Número de Artículo (entero, de 8 cifras)
• Precio Unitario (real, mayor que cero)
Existe un segundo archivo PROVIN, con los siguientes datos de sus 30 vendedores:
• Nombre del Vendedor (alfanumérico de 30 caracteres)
• Número de Provincia (entero, de 1 a 24)
Se tiene un tercer archivo llamado VTA_CANT, ordenado por región del país, con las ventas realizadas. Por
cada venta se informa lo siguiente:
• Región del país (alfanumérico de 3 caracteres)
• Nombre de Vendedor
• Mes (entero, de 1 a 12)
• Número de Artículo
• Unidades Vendidas (entero mayor que cero)
Confeccionar un programa que partiendo de la información suministrada permita determinar e informar:
a. Un listado con el importe de las ventas realizadas en cada provincia en cada uno de los meses:
PROVINCIA MES 1 MES 2 .... MES 12
XX      XXXXXX XXXXXXX XXXXXXXX
b. Un listado con los nombres de los vendedores que no han tenido ventas en más de 3 meses consecutivos.
c. Informar en qué región del país se vendió menos (en importe).
*/
#include<stdio.h>
#include<string.h>

typedef struct{
    int nmrArt;
    float precio;
}Artic_Precio;

typedef struct{
    char nombreVendedor[31];
    int provincia;
} Provin;

typedef struct{
    char region[4],nombreVendedor[31];
    int mes, nmrArt,uniVend;
} Vta_Cant;


int Buscarchar (char [], Provin [], int );
int Buscarint (int , Artic_Precio [], int );

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int i=0, j=0, k=0, cont=0, art, vend, mVendxMes[30][12]={{0}};
    char Regionact[4], Regionmenor[4];
    float mProvxMes[24][12]={{0}}, preciomenor=-1, acu;

    Artic_Precio auxart[500], aux1;
    Provin auxprovin[30], aux2;
    Vta_Cant aux;

    FILE *arch1, *arch2, *arch3;
    arch1=fopen("ARTIC_PRECIO.dat","rb");
    arch2=fopen("PROVIN.dat","rb");
    arch3=fopen("VTA_CANT.dat","rb");
    if(arch1==NULL||arch2==NULL||arch3==NULL)
    {
        exit(1);
    }


    fread(&aux1,sizeof(Artic_Precio),1,arch1);
    while(!feof(arch1))
    {
        auxart[i]=aux1;
        i++;
        fread(&aux1,sizeof(Artic_Precio),1,arch1);
    }
    fclose(arch1);
    fread(&aux2,sizeof(Provin),1,arch2);
    while(!feof(arch1))
    {
        auxprovin[j]=aux2;
        j++;
        fread(&aux2,sizeof(Provin),1,arch2);
    }
    fclose(arch2);
    fread(&aux,sizeof(aux),1,arch3);
    while(!feof(arch3))
    {
        strcpy(Regionact,aux.region);
        acu=0;
        while(!feof(arch3)&&strcmpi(Regionact,aux.region)==0)
        {
            vend=Buscarchar(aux.nombreVendedor,auxprovin, j);
            art=Buscarint(aux.nmrArt,auxart,i);
            if(vend!=-1&&art!=-1)
            {
                mProvxMes[auxprovin[vend].provincia-1][aux.mes-1]+=auxart[art].precio*aux.uniVend;
                acu+=auxart[art].precio*aux.uniVend;
                mVendxMes[vend][aux.mes-1]++;
            }

            fread(&aux,sizeof(aux),1,arch3);
        }
        if(preciomenor==-1||preciomenor<acu)
            preciomenor=acu;
            strcpy(Regionmenor,Regionact);
    }
    fclose(arch3);
    printf("Listado de Vendedores sin ventas en 3 meses consecutivos:\n");
    for(i=0;i<j;i++)
    {
        while(k<12&&cont<3)
        {
            if(mVendxMes[i][k]==0)
                cont++;
            else
                cont=0;
            k++;
        }
        if(cont>=3)
            printf("%s\n", auxprovin[i].nombreVendedor);
    }
    printf("La region con menos ventas es: %s", Regionmenor);


    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Buscarchar (char buscado[], Provin Vector[], int cant)
{
    int pos=-1, i=0;
    while(i<cant&&pos==-1)
    {
        if(strcmpi(buscado,Vector[i].nombreVendedor)==0)
            pos=i;
        else
            i++;
    }

    return pos;
}

int Buscarint (int buscado, Artic_Precio Vector[], int cant)
{
    int pos=-1, i=0;
    while(i<cant&&pos==-1)
    {
        if(buscado==Vector[i].nmrArt)
            pos=i;
        else
            i++;
    }

    return pos;
}

