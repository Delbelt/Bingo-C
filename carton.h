#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED

struct CartonE; //Estructura Inicial

typedef struct CartonE *Carton; //Puntero a estructura para optimizar cargas

//CONSTRUCTOR
Carton crearCarton();

//MOSTRAR
void mostrarCarton(Carton x);

//FUNCIONES PRINCIPALES
void cargarCarton(int carton[3][5]);

//DESTRUCTOR
void destruirCarton(Carton x);

#endif
