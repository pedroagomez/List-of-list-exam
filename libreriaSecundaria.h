#ifndef LIBRERIASECUNDARIA_H_INCLUDED
#define LIBRERIASECUNDARIA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct
{
    int idEquipo;
    char nombreEquipo[30];
    int idJugador;
    int nroCamisetaJugador;
    char nombreJugador[30];
    int puntosAnotados;
}stJugadorEquipo;

typedef struct
{
    int idJugador;
    int nroCamisetaJugador;
    char nombreJugador[30];
    int puntosAnotados;
}stJugador;

typedef struct
{
    stJugador jugador;
    struct nodoListaSecundaria* siguiente;
}nodoListaSecundaria;


nodoListaSecundaria* inicListaSecundaria();
nodoListaSecundaria* crearNodoSecundaria(stJugadorEquipo registro);
nodoListaSecundaria* agregarFinalListaSecundaria(nodoListaSecundaria* lista, nodoListaSecundaria* nuevo);
void mostrarUnNodo(nodoListaSecundaria* lista);
void mostrarListaSecundaria(nodoListaSecundaria* lista);
nodoListaSecundaria* recorrerListaSecundaria(nodoListaSecundaria* lista);
int contarCantidadJugadores(nodoListaSecundaria* lista);
#endif // LIBRERIASECUNDARIA_H_INCLUDED
