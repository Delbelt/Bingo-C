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
void mostrarCartones(Jugador x);

//FUNCIONES PRINCIPALES
void modificarJugador(Jugador x);
int elegirCantCarton();
int comprobarBolilla(int vector[],int num);
void sacarBolilla(int vector[]);
void mostrarBolilla(Jugador x, int jugada);
void reiniciarBola(int bolilla[]);

//MODERACION DEL JUEGO
void reiniciarJuego(Jugador x);
void moderadorInferiorLento(Jugador x, int lugar);
void moderadorInferiorRapido(Jugador x, int lugar);
void moderadorSuperiorLento(Jugador x);
void moderadorSuperiorRapido(Jugador x);
void ganadorJuego(Jugador x);
void resumen(Jugador x);

//PUNTAJE
void Calcularpuntajes(Jugador x);
void guardarPuntajes(Jugador x);
void mostrarPuntajes();

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
int getBolilla(Jugador x,int i);

#endif

