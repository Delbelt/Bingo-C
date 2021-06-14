#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include "jugador.h"

struct JugadorE; //Estructura Inicial

typedef struct JugadorE *Jugador; //Puntero a estructura para optimizar cargas

//CONSTRUCTOR
Jugador crearJugador(char nombre[],char alias[],int dni);

//DESTRUCTOR
void destruirJugador(Jugador x);

#endif

