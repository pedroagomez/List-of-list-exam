#include "libreriaSecundaria.h"

/// PUNTO 1
nodoListaSecundaria* inicListaSecundaria()
{
    return NULL;
}
/// PUNTO 1
nodoListaSecundaria* crearNodoSecundaria(stJugadorEquipo registro)
{
    nodoListaSecundaria* lista=(nodoListaSecundaria*)malloc(sizeof(nodoListaSecundaria));
    lista->jugador.idJugador=registro.idJugador;
    strcpy(lista->jugador.nombreJugador,registro.nombreJugador);
    lista->jugador.nroCamisetaJugador=registro.nroCamisetaJugador;
    lista->jugador.puntosAnotados=registro.puntosAnotados;
    lista->siguiente=NULL;
    return lista;
}
/// PUNTO 1
nodoListaSecundaria* agregarFinalListaSecundaria(nodoListaSecundaria* lista, nodoListaSecundaria* nuevo)
{
    nodoListaSecundaria* seguidora=lista;
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        while(seguidora->siguiente!=NULL)
        {
            seguidora=seguidora->siguiente;
        }
        seguidora->siguiente=nuevo;
    }
    return lista;
}

/// PUNTO 4
void mostrarUnNodo(nodoListaSecundaria* lista)
{
    if(lista)
    {
        printf("======================================== \n");
        printf("Id jugador........................... :%d\n",lista->jugador.idJugador);
        printf("Nro Camiseta Jugador................. :%d\n",lista->jugador.nroCamisetaJugador);
        printf("Nombre Jugador....................... :%s\n",lista->jugador.nombreJugador);
        printf("Puntso anotados...................... :%d\n",lista->jugador.puntosAnotados);
    }
}
/// PUNTO  4
void mostrarListaSecundaria(nodoListaSecundaria* lista)
{
    while(lista)
    {
        mostrarUnNodo(lista);
        lista=lista->siguiente;
    }
}

///PUNTO 5 ( pasar GOLEADORES)

nodoListaSecundaria* recorrerListaSecundaria(nodoListaSecundaria* lista)
{
    nodoListaSecundaria* mayor=lista;
    while(lista)
    {
         if(lista->jugador.puntosAnotados>mayor->jugador.puntosAnotados || lista->jugador.puntosAnotados == mayor->jugador.puntosAnotados && lista->jugador.nroCamisetaJugador>mayor->jugador.nroCamisetaJugador)
        {
            mayor=lista;
        }
        lista=lista->siguiente;
    }
    return mayor;
}

///PUNTO 6

int contarCantidadJugadores(nodoListaSecundaria* lista)
{
    int cantidad=0;
    while(lista)
    {
        cantidad++;
        lista=lista->siguiente;
    }
    return cantidad;
}


