#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

struct JugadorE; //Estructura Inicial

typedef struct JugadorE *Jugador; //Puntero a estructura para optimizar cargas

//CONSTRUCTOR
Jugador crearJugador(char nombre[],char alias[],int dni);

//DESTRUCTOR
void destruirJugador(Jugador x);

//MOSTRAR
void mostrarJugador(Jugador x);

//FUNCIONES PRINCIPALES
int elegirCantCarton();

//METODOS SET
void setNombre(Jugador x, char nombre[]);
void setAlias(Jugador x, char alias[]);
void setDni(Jugador x, int dni);
void setCantCartones(Jugador x, int cantCartones);

//METODOS GET
char *getNombre(Jugador x);
char *getAlias(Jugador x);
int getDni(Jugador x);
int getCantCartones(Jugador x);

#endif

