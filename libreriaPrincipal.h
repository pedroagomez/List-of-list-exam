#ifndef LIBRERIAPRINCIPAL_H_INCLUDED
#define LIBRERIAPRINCIPAL_H_INCLUDED
#include "libreriaSecundaria.h"



/// PUNTO 1 : DECIDI USAR LISTAS DE LISTAS YA QUE CONSIDERE QUE LA CANTIDA DDE EQUIPOS PUEDEN IR VARIANDO
/// Y HACIENDOLO CON LISTAS PUEDO IR ADAPTANDOLO. SUPONGAMOS QUE INICIAN 10 EQUIPOS, SI LO HICIERA CON ARREGLO TENDRIA QUE IR MODIFICANDO

typedef struct
{
    int idEquipo;
    char nombreEquipo[30];
}stEquipo;


typedef struct
{
    stEquipo equipo;
    nodoListaSecundaria* second;
    struct nodoListaPrincipal* siguiente;
}nodoListaPrincipal;



nodoListaPrincipal* inicListaPrincipal();
nodoListaPrincipal* crearNodo(char nombreEquipo[], int idEquipo);
nodoListaPrincipal* agregarAlFinalPrincipal(nodoListaPrincipal* lista, nodoListaPrincipal* nuevo);
nodoListaPrincipal* buscarPos(nodoListaPrincipal* lista,int idEquipo);
nodoListaPrincipal* alta(nodoListaPrincipal* lista, stJugadorEquipo registro);
nodoListaPrincipal* deArchivoAlista(char nombreArchivo[], nodoListaPrincipal* lista);
void mostrarNodoPrincipal(nodoListaPrincipal* lista);
void mostrarListaDeListas(nodoListaPrincipal* lista);
nodoListaPrincipal* agregarManualmente(nodoListaPrincipal* lista);
int pasarAarregloDeJugador(stJugador arreglo[], int dim, nodoListaPrincipal* lista);
void mostrarJugadores(stJugador arreglo[], int i);
void mostrarArregloGoleadores(stJugador arreglo[],int validos);
int cantidadTotalJugadores(nodoListaPrincipal* lista);
float porcentajeEquipo(nodoListaPrincipal* lista, char equipo[]);
void buscarEnListaSecundaria(nodoListaSecundaria* lista, int nroCamiseta, FILE* archi);
void guardarEnArchivo(nodoListaPrincipal* lista,int nroCamiseta);
#endif // LIBRERIAPRINCIPAL_H_INCLUDED
