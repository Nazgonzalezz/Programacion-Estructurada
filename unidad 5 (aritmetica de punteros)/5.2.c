/* Dado el archivo EMPLEADOS.DAT con el siguiente formato de registro:
• Legajo (entero)
• Apellido (texto de 15 caracteres máximo)
• Nombre (texto de 30 caracteres máximo)
• Fecha de Ingreso (Estructura con 3 enteros día, mes y año)
• Categoría (entero del 1 al 4)
Se solicita ingresar la fecha del día y realizar un proceso que actualice la categoría de los empleados según la
antigüedad en la empresa según la siguiente escala:
Categoría 1: de 0 a 2 años de antigüedad
Categoría 2: de 3 a 5 años de antigüedad
Categoría 3: de 6 a 10 años de antigüedad
Categoría 5: más de 10 años de antigüedad*/


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










