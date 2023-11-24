#include "libreriaPrincipal.h"

///PUNTO 1

nodoListaPrincipal* inicListaPrincipal()
{
    return NULL;
}

/// PUNTO 1
nodoListaPrincipal* crearNodo(char nombreEquipo[], int idEquipo)
{
    nodoListaPrincipal* lista=(nodoListaPrincipal*)malloc(sizeof(nodoListaPrincipal));
    lista->equipo.idEquipo=idEquipo;
    strcpy(lista->equipo.nombreEquipo,nombreEquipo);
    lista->second=NULL;
    lista->siguiente=NULL;
    return lista;
}

/// PUNTO 1
nodoListaPrincipal* agregarAlFinalPrincipal(nodoListaPrincipal* lista, nodoListaPrincipal* nuevo)
{
    nodoListaPrincipal* seguidora=lista;
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

/// PUNTO 2
nodoListaPrincipal* buscarPos(nodoListaPrincipal* lista,int idEquipo)
{
    nodoListaPrincipal* seguidora=lista;
    while(seguidora!=NULL && seguidora->equipo.idEquipo !=idEquipo)
    {
        seguidora=seguidora->siguiente;
    }
    return seguidora;
}
/// PUNTO 2
nodoListaPrincipal* alta(nodoListaPrincipal* lista, stJugadorEquipo registro)
{
    nodoListaSecundaria* nuevo=crearNodoSecundaria(registro);

    nodoListaPrincipal* buscar=buscarPos(lista,registro.idEquipo);
    if(buscar==NULL)
    {

        buscar=crearNodo(registro.nombreEquipo,registro.idEquipo);
        lista=agregarAlFinalPrincipal(lista,buscar);

    }
    buscar->second=agregarFinalListaSecundaria(buscar->second,nuevo);
    return lista;
}

/// PUNTO 2
nodoListaPrincipal* deArchivoAlista(char nombreArchivo[], nodoListaPrincipal* lista)
{
    stJugadorEquipo aux;
    FILE* archi=fopen(nombreArchivo,"rb");
    if(archi)
    {
        while(fread(&aux,sizeof(stJugadorEquipo),1,archi)>0)
        {

            lista=alta(lista,aux);

        }
        fclose(archi);
    }
    return lista;
}

/// PUNTO 3


nodoListaPrincipal* agregarManualmente(nodoListaPrincipal* lista)
{
    stJugadorEquipo aux;
    printf("Ingrese el id del equipo :");
    scanf("%d",&aux.idEquipo);

    printf("Ingrese el nombre del equipo : ");
    fflush(stdin);
    gets(aux.nombreEquipo);

    printf("Ingrese id de jugador :");
    scanf("%d",&aux.idJugador);

    printf("Ingrese numero de camiseta :");
    scanf("%d",&aux.nroCamisetaJugador);

    printf("Ingrese nombre de jugador  :");
    fflush(stdin);
    gets(aux.nombreJugador);

    printf("Ingrese los puntos anotados :");
    scanf("%d",&aux.puntosAnotados);

    lista=alta(lista,aux);

    return lista;
}







/// PUNTO 4
void mostrarNodoPrincipal(nodoListaPrincipal* lista)
{
    printf("============================================= \n");
    printf("ID equipo.................................... :%d\n",lista->equipo.idEquipo);
    printf("Nombre equipo................................ :%s\n",lista->equipo.nombreEquipo);
}
/// PUNTO 4
void mostrarListaDeListas(nodoListaPrincipal* lista)
{
    while(lista)
    {
        mostrarNodoPrincipal(lista);
        mostrarListaSecundaria(lista->second);
        lista=lista->siguiente;
    }
}

///PUNTO 5 ( pasar GOLEADORES)
int pasarAarregloDeJugador(stJugador arreglo[], int dim, nodoListaPrincipal* lista)
{
    int i=0;
    nodoListaSecundaria* mayor=NULL;
    while(lista && i<dim)
    {
        mayor=recorrerListaSecundaria(lista->second);
        arreglo[i]=mayor->jugador;
        lista=lista->siguiente;
        i++;
    }
    return i;
}

/// PUNTO 5
void mostrarJugadores(stJugador arreglo[], int i)
{
    printf("======================================== \n");
    printf("Id jugador........................... :%d\n",arreglo[i].idJugador);
    printf("Nro Camiseta Jugador................. :%d\n",arreglo[i].nroCamisetaJugador);
    printf("Nombre Jugador....................... :%s\n",arreglo[i].nombreJugador);
    printf("Puntso anotados...................... :%d\n",arreglo[i].puntosAnotados);
}
/// PUNTO 5
void mostrarArregloGoleadores(stJugador arreglo[],int validos)
{
    int i=0;
    while(i<validos)
    {
        mostrarJugadores(arreglo,i);
        i++;
    }
}


/// PUNTO 6


int cantidadTotalJugadores(nodoListaPrincipal* lista)
{
    int cantidad=0;
    while(lista)
    {
        cantidad=cantidad + contarCantidadJugadores(lista->second);
        lista=lista->siguiente;
    }
    return cantidad;
}

///PUNTO 6
float porcentajeEquipo(nodoListaPrincipal* lista, char equipo[])
{
    int total=cantidadTotalJugadores(lista);
    int cantidadEquipo=0;
    float porcentaje;

    while(lista)
    {
        if(strcmp(lista->equipo.nombreEquipo,equipo)==0)
        {
            cantidadEquipo=contarCantidadJugadores(lista->second);
        }
        lista=lista->siguiente;
    }
    porcentaje=(float)cantidadEquipo*100/total;
    return porcentaje;
}


/// PUNTO 7


void buscarEnListaSecundaria(nodoListaSecundaria* lista, int nroCamiseta, FILE* archi)
{
    stJugadorEquipo aux;
    while(lista)
    {
        if(lista->jugador.nroCamisetaJugador == nroCamiseta)
        {
            aux.idJugador=lista->jugador.idJugador;
            aux.puntosAnotados=lista->jugador.puntosAnotados;
            aux.nroCamisetaJugador=lista->jugador.nroCamisetaJugador;
            strcpy(aux.nombreJugador,lista->jugador.nombreJugador);
            fwrite(&aux,sizeof(stJugadorEquipo),1,archi);
        }
        lista=lista->siguiente;
    }
}


void guardarEnArchivo(nodoListaPrincipal* lista,int nroCamiseta)
{
    char nombreArchivo[20];
    strcpy(nombreArchivo,"camisetas.bin");
    FILE *archi=fopen(nombreArchivo,"wb");
    if(archi)
    {
        while(lista)
        {
            buscarEnListaSecundaria(lista->second,nroCamiseta,archi);
            lista=lista->siguiente;
        }
        fclose(archi);
    }
}


void mostrarArchivoCamiseta(char nombreArchivo[])
{
    stJugadorEquipo aux;
    FILE* archi=fopen(nombreArchivo,"rb");
    if(archi)
    {
        while(fread(&aux,sizeof(stJugadorEquipo),1,archi)>0)
        {
            printf("================================================= \n");
            printf("Nombre................... :%s\n",aux.nombreJugador);
            printf("Id Jugador............... :%d\n",aux.idJugador);
            printf("Numero de camiseta....... :%d\n",aux.nroCamisetaJugador);
            printf("Puntos Anotados.......... :%d\n",aux.puntosAnotados);
        }
        fclose(archi);
    }
}

///INTENTO FALLIDO DE REALIZAR LA FUNCION ( FUNCIONA, NO ROMPE PERO NO COPIA EL ID NI EL NOMBRE DEL EQUIPO)
/*
void guardarEnArchivo(nodoListaPrincipal* lista,int nroCamiseta)
{
    stJugadorEquipo aux;
    char nombreArchivo[20];
    strcpy(nombreArchivo,"camisetas.bin");
    FILE *archi=fopen(nombreArchivo,"wb");
    if(archi)
    {
        while(lista)
        {
            while(lista->second)
            {
                if(lista->second->jugador.nroCamisetaJugador == nroCamiseta)
                {
                    aux.idEquipo=lista->equipo.idEquipo;
                    strcpy(aux.nombreEquipo,lista->equipo.nombreEquipo);
                    aux.idJugador=lista->second->jugador.idJugador;
                    aux.puntosAnotados=lista->second->jugador.puntosAnotados;
                    aux.nroCamisetaJugador=lista->second->jugador.nroCamisetaJugador;
                    strcpy(aux.nombreJugador,lista->second->jugador.nombreJugador);
                    fwrite(&aux,sizeof(stJugadorEquipo),1,archi);
                }
                lista->second=lista->second->siguiente;

            }
            lista=lista->siguiente;
        }
        fclose(archi);
    }
}
*/
