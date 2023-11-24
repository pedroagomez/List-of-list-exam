#include <stdio.h>
#include <stdlib.h>
#include "libreriaPrincipal.h"
#include "libreriaSecundaria.h"


int main()
{
    char nombreArchivo[20];
    strcpy(nombreArchivo,"registroJugador.dat");
    //mostrarArchivo(nombreArchivo);
    nodoListaPrincipal* lista=inicListaPrincipal();
    /// punto 2( PASO DE ARCHIVO A LISTA )

    lista=deArchivoAlista("registroJugador.dat",lista);
    mostrarListaDeListas(lista);
    /// PUNTO 3 ( AGREGO MANUALMENTE )
    printf("\n PUNTO 3 : cargo manualmente \n");
    lista=agregarManualmente(lista);
    mostrarListaDeListas(lista);

    /// PUNTO 4 ES MOSTRAR

    /// PUNTO 5
    printf("\n Punto 5 : Pasar goleadores \n");
    stJugador arreglo[15];
    int validos;
    printf("\n Estos son los goleadores del torneo : \n");
    validos=pasarAarregloDeJugador(arreglo,15,lista);
    mostrarArregloGoleadores(arreglo,validos);

    /// PUNTO 6
    int total;
    char equipo[15];
    printf(" \nPunto 6: Porcentajes \n");
    total=cantidadTotalJugadores(lista);
    printf("La cantidad total de jugadores en el torneo es :%d\n",total);
    printf("Ingrese el nobmre del equipo :");
    fflush(stdin);
    gets(equipo);
    float porcentaje=porcentajeEquipo(lista,equipo);
    printf("El porcentaje es :%f",porcentaje);


    ///PUNTO 7
    printf(" \n \n Punto 7 : Camisetas \n");
    int camiseta;
    printf("Ingrese la camiseta :");
    scanf("%d",&camiseta);
    guardarEnArchivo(lista,camiseta);
    mostrarArchivoCamiseta("camisetas.bin");


}
