/*
El INTA desea conocer las plantaciones existentes en una zona determinada
y para ello recorre cada chacra/estancia y consulta qué tienen sembrado.
No se conoce ni la cantidad de establecimientos a censar ni la cantidad
posible de especies de cultivo para la zona.
Para ello ingresará por teclado los datos necesarios para completar el
archivo SIEMBRA.DAT que posee la siguiente estructura:
    Especie          --> (string 20 caracteres máximo)
    Establecimientos --> (contador entero)
    Hectareas 		  -->(Acumulador flotante)
En el archivo se cuentan y acumulan tipos de sembradío y hectáreas
sembradas del mismo en el total de establecimientos censados.
Si la especie sembrada no existe previamente se agregará al archivo y si
ya existe, se cuenta como un nuevo establecimiento sembrado y se acumulan
las hectáreas sembradas.
La carga culmina con una especie llamada “FIN”
Al finalizar:
    1) Mostrar un listado con los datos cargados Indicando Especie sembrada,
       cantidad de establecimientos que la sembraron y cantidad de hectáreas
       sembradas.
    2) Indicar cuántos cultivos distintos existen en la zona.
    3) Antes de cerrar el programa cambiar el nombre del archivo por otro
       que se ingresa por teclado

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char especie[21];
    int cont;
    float Acum;

} T_especie;

//No se usaron funciones para facilitar la lectura

int main()
{
    FILE *pf;
    T_especie reg;  //Auxiliar para descarga y carga de registros
    int band;
    char especie[21], nombre [20]; //Nombre es para luego cambiar nombre archivo
    float cant;  //Para cantidad de hectareas sembradas

    pf=fopen("SIEMBRA.dat","w+b");
     if(pf==NULL)
     {
        printf("\nNo abrio el archivo SIEMBRA.dat...");
        exit(1);
     }
    printf("\nIngrese especie o FIN para terminar:  ");
    fflush(stdin);
    gets(especie);

     while(strcmpi(especie, "FIN")!=0)
    {
        do
        {
            printf("\nIngrese cantidad de hectareas sembradas: ");
            scanf ("%f", &cant);
        }while (cant<=0);

        band=0;  //Comienzo suponiendo que no existe la especie

        rewind(pf); //regresa el puntero al principio para
                    //asegurarse de buscar desde el principio en cada ciclo
                    //también limpia buffer de datos y pone modo neutro


    //Búsqueda dentro del archivo que no retorna posición sino cambia bandera

        fread(&reg, sizeof(T_especie),1,pf);

        while (band==0 && !feof(pf))  //hasta que encuentra o termina archivo
        {
            if(strcmpi(reg.especie,especie)==0)
            {
                 band=1;   //Al cambiar indica que encontró y no vuelve a entrar
                           //Recordar que el puntero quedó corrido 1 registro
            }
            else
                fread(&reg, sizeof(T_especie),1,pf);
        }

        if (band==0)   //Es nueva especie
        {
            strcpy(reg.especie, especie);
            reg.cont=1;
            reg.Acum=cant;

            fflush(pf); //Ponemos el archivo en modo neutro
                        //para cambiar de lectura a escritura
                        //sin cambiar el puntero del lugar
                        //ya que quedó al final (eof)

            fwrite(&reg,sizeof(T_especie),1,pf);
        }
        else  //Encuentró la especie
        {
            fseek(pf,sizeof( T_especie)*(-1), 1 ); /*Por puntero pasado 1
                                                    registro*/
            reg.cont++;
            reg.Acum+=cant;
            fwrite(&reg,sizeof(T_especie),1,pf);
        }

        printf("\nIngrese especie o FIN para terminar:  ");
        fflush(stdin);
        gets(especie);
    }

    fseek(pf,0,0); //Alternativa del rewind()

    band=0; //Reutilizo para mensaje si no hay registros que leer

    fread(&reg, sizeof(reg),1,pf);
    while (!feof(pf)) //Listado
    {
        band++; /*Solo para mostrar una alternativa de reutilización de variable
                cuenta distintos cultivos*/
        printf("\nCultivo %20s en %d establecimientos con un total de %.2f hectareas",reg.especie,reg.cont,reg.Acum);
        fread(&reg, sizeof(reg),1,pf);
    }
    if(!band)
        printf("\n\nNo se censo ningun cultivo\n");
    else
        printf("\n\nSe censaron %d distintos tipos de cultivos\n",band);
         /*Alternativa printf("\n\nSe censaron %d distintos tipos de cultivos\n"
                              ,ftell(pf)/sizeof(T_especie));*/

    fclose(pf); //Cierre para poder cambiar nombre

    printf("\n");
    system("pause");

    printf ("\nIngrese un nuevo nombre para el archivo SIEMBRA.dat: ");
    fflush(stdin);
    gets(nombre);

    if(rename("SIEMBRA.dat", nombre)==0)
        printf("\nNombre cambiado satisfactoriamente a %s ", nombre );
    else
        printf("\nEl nombre no pudo ser cambiado" );

    return 0;
}
