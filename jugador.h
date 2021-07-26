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
void mostrarCartones(Jugador x, int lugar);

//FUNCIONES PRINCIPALES
int elegirCantCarton();
int comprobarBolilla(int vector[],int num);
void sacarBolilla(int vector[]);
void mostrarBolilla(Jugador x, int jugada);
void reiniciarBola(int bolilla[]);

//JUEGO
//VOID CINCO EN LINEA
//VOID 3 EN COLUMNA
//VOID BINGO
//void marcarCarton(int carton[], int bolilla[], int jugada)

//MODERACION DEL JUEGO
void reiniciarJuego(Jugador x); //REINICIAR JUEGO

//PUNTAJE

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

