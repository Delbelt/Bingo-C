#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED

struct CartonE; //Estructura Inicial

typedef struct CartonE *Carton; //Puntero a estructura para optimizar cargas

//CONSTRUCTOR
Carton crearCarton();

//MOSTRAR
void mostrarCarton(Carton x);
void mostrarCartonMarcado(Carton x);

//FUNCIONES PRINCIPALES
void cargarCarton(int carton[][5]);
int comprobarRepeticion (int carton[][5],int numVerificar);
void marcarCarton(int carton[], int bolilla[], int jugada);
void posJugadas(int posJug[],int posicion,int numero);

//JUEGO

void cincoLinea(int vector[][5],int bolilla[],int jugadas,int bandera[]);
void tresColumna(int vector[][5],int bolilla[],int jugadas, int bandera[]);
void bingo(int vector[][5],int bolilla[],int jugadas, int bandera[]);

//SET

void setJugadas(Carton x, int pos, int valor);
void setPuntaje(Carton x, float puntaje);

//GET
float getPuntaje(Carton x);
int getJugadas(Carton x, int posJugada);
int getCarton(Carton x, int i, int j);

//DESTRUCTOR
void destruirCarton(Carton x);

#endif
