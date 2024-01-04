/* Dado el archivo EMPLEADOS.DAT con el siguiente formato de registro:
� Legajo (entero)
� Apellido (texto de 15 caracteres m�ximo)
� Nombre (texto de 30 caracteres m�ximo)
� Fecha de Ingreso (Estructura con 3 enteros d�a, mes y a�o)
� Categor�a (entero del 1 al 4)
Se solicita ingresar la fecha del d�a y realizar un proceso que actualice la categor�a de los empleados seg�n la
antig�edad en la empresa seg�n la siguiente escala:
Categor�a 1: de 0 a 2 a�os de antig�edad
Categor�a 2: de 3 a 5 a�os de antig�edad
Categor�a 3: de 6 a 10 a�os de antig�edad
Categor�a 5: m�s de 10 a�os de antig�edad*/


#include<stdio.h>
typedef struct{
    int dia;
    int mes;
    int ano;
}T_FECHA;
typedef struct  {
                    int legajo;
                    char apellido [16];
                    char nombre [31];
                    T_FECHA fecha;
                    int categoria;
                }T_EMPLEADO;


void mostrararchivo();
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int antiguedad;
    T_EMPLEADO aux;
    T_FECHA auxfecha;
    FILE * arch;
    arch=fopen("empleados.dat","r+b");
    if(arch==NULL)
    {
        printf("error de archivo");
        exit(1);
    }
    mostrararchivo();
    do
    {
        printf("\nIngrese el anio de la fecha: ");
        scanf("%d", &auxfecha.ano);
    }while(auxfecha.ano<1980);
    do
    {
        printf("\nIngrese el mes de la fecha: ");
        scanf("%d", &auxfecha.mes);
    }while(auxfecha.mes<1&&auxfecha.mes>12);
    do
    {
        printf("\nIngrese el dia de la fecha: ");
        scanf("%d", &auxfecha.dia);
    }while(auxfecha.dia<1&&auxfecha.dia>31);

    fread(&aux,sizeof(T_EMPLEADO),1,arch);
    while(!feof(arch))
    {
        antiguedad=auxfecha.ano-aux.fecha.ano;
        fseek(arch,sizeof(T_EMPLEADO)*(-1), 1 );
        if(antiguedad<3)
            aux.categoria=1;
        else
        {
            if(antiguedad<6)
                aux.categoria=2;
            else
            {
                if(antiguedad<=10)
                    aux.categoria=3;
                else
                    aux.categoria=5;
            }
        }

        fwrite(&aux,sizeof(T_EMPLEADO),1,arch);
        fflush(arch);
        fread(&aux,sizeof(T_EMPLEADO),1,arch);
    }
    fclose(arch);
    mostrararchivo();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrararchivo()
{
    T_EMPLEADO aux;
    FILE * arch;
    arch=fopen("empleados.dat","rb");
    if(arch==NULL)
    {
        printf("error de archivo");
        exit(1);
    }
    printf("%5s %10s %15s","Legajo","Fecha", "Categoria");
    fread(&aux, sizeof(T_EMPLEADO),1,arch);
    while(!feof(arch))
    {
        printf("\n%5d    %2d/%2d/%4d %8d", aux.legajo,aux.fecha.dia,aux.fecha.mes,aux.fecha.ano,aux.categoria);
        fread(&aux, sizeof(T_EMPLEADO),1,arch);
    }
    printf("\n");
    fclose(arch);
}










