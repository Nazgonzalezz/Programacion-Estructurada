/*Realizar un sistema completo de agenda telefónica básico donde por cada contacto se guarda el nombre y el
número de teléfono. Las funcionalidades a desarrollar son:
• Mostrar la cantidad de contactos guardados
• Alta de nuevos contactos
• Búsqueda secuencial de contactos por nombre
• Modificación de contactos
• Borrado de contactos (a elección si desea realizar borrado físico o lógico)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre [21];
    int telefono;
    int estado;
}T_NUMERO;

void mostrararchivo();
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    T_NUMERO aux;
    int menu, menu2, cant, band;
    char Nombre [21];
    FILE *arch;
    arch=fopen("contactos.dat","a+b");
    if(arch==NULL)
    {
        printf("error de archivo");
        exit(1);
    }
    do
    {
        system("cls");
        printf("AGENDA TELEFONICA\n");
        printf("********************");
        printf("\n1. Mostrar Cantidad Contactos");
        printf("\n2. Agregar Contactos");
        printf("\n3. Buscar Contacto");
        printf("\n4. Salir");
        printf("\n>>");
        scanf("%d", &menu);
    }while(menu<1&&menu>4);
        rewind(arch);
    while(menu!=4)
    {
        switch(menu)
        {
            case 1:
                fseek(arch,sizeof(T_NUMERO)*0,2);
                cant=ftell(arch)/sizeof(T_NUMERO);
                printf("\nLa cantidad de contactos guardadoes es: %d", cant);
                system("pause");
                break;


            case 2:
                fseek(arch,sizeof(T_NUMERO)*1,2);
                printf("Ingrese el Nombre del Nuevo Contacto: ");
                fflush(stdin);
                gets(aux.nombre);
                do
                {
                    printf("Ingrese el Numero del Nuevo Contacto: ");
                    scanf("%d", &aux.telefono);
                }while(aux.telefono<10000000&&aux.telefono>99999999);
                aux.estado=1;
                fwrite(&aux,sizeof(T_NUMERO),1,arch);
                fflush(arch);
                system("pause");
                break;


            case 3:
                rewind(arch);
                band=-1;
                printf("\nIngrese el Nombre del Contacto: ");
                fflush(stdin);
                gets(Nombre);

                fread(&aux,sizeof(T_NUMERO),1,arch);
                while(!feof(arch)&&band==-1)
                {
                    if(strcmpi(aux.nombre,Nombre)==0&&aux.estado==1)
                    {
                        band=1;
                        fseek(arch,sizeof(T_NUMERO)*(-1),1);
                    }
                    else
                        fread(&aux,sizeof(T_NUMERO),1,arch);
                }

                if(band==-1)
                    printf("No existe el contacto...");
                else
                {
                    do
                    {
                        system("cls");
                        printf("CONTACTO: ");
                        printf("\nNombre:");
                        printf("%s", aux.nombre);
                        printf("\nTelefono: ");
                        printf("%d", aux.telefono);
                        printf("\nOPCIONES\n");
                        printf("********************");
                        printf("\n1. Modificar Contacto");
                        printf("\n2. Eliminar Contacto");
                        printf("\n3. Salir");
                        printf("\n>>");
                        scanf("%d", &menu2);
                    }while(menu2<1&&menu2>3);
                    if(menu2==1)
                    {
                        printf("Ingrese el nuevo Nombre del Contacto: ");
                        fflush(stdin);
                        gets(aux.nombre);
                        do
                        {
                            printf("Ingrese nuevo el Numero del Contacto: ");
                            scanf("%d", &aux.telefono);
                        }while(aux.telefono<10000000&&aux.telefono>99999999);
                        fwrite(&aux,sizeof(T_NUMERO),1,arch);
                        fflush(arch);
                    }
                    else
                    {
                        if(menu2==2)
                        {
                            aux.estado=0;
                            printf("Se a eliminado este contacto...");
                        }
                    }
                }



                system("pause");
                break;


            case 4:

                break;
        }
        do
        {
            system("cls");
            printf("AGENDA TELEFONICA\n");
            printf("********************");
            printf("\n1. Mostrar Cantidad Contactos");
            printf("\n2. Agregar Contactos");
            printf("\n3. Buscar Contacto");
            printf("\n4. Salir");
            printf("\n>>");
            scanf("%d", &menu);
        }while(menu<1&&menu>4);
        rewind(arch);
    }

    fclose(arch);
}
