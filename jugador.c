#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "jugador.h"

#define CANT_CARTONES 3 //GLOBAL PARA DEFINIR LA CANT DE CARTONES MAXIMOS POR JUGADOR


	struct JugadorE{ 
		
		char nombre[30];	
		char alias[15];
		int dni;		
		int cantCartones;	
		//int bola[90];			
		
	};
	
//CONSTRUCTOR
Jugador crearJugador(char nombre[],char alias[],int dni)
{
	Jugador x = malloc(sizeof(struct JugadorE)); //Asigno memoria en el sistema para crear el jugador
	
	//GUARDO LAS VARIABLES ASIGNADAS EN LOS PARAMETROS
	strcpy(x->nombre,nombre); //STRING
	strcpy(x->alias,alias);	//STRING
	x->dni = dni; //INT
	
	int i; //INDICE
	
	for(i=0;i<CANT_CARTONES;i++) //CARGA EL MAXIMO DE CARTONES PERMITIDOS POR JUGADOR A ASIGNAR POR SISTEMA
	{
		//x->cartones[i] = crearCartones(DATOS); //CREA TODOS LOS CARTONES VACIOS.
	}
	
	return x; //RETORNA JUGADOR X QUE FUE GUARDADO EN MEMORIA PARA LA ASIGNACION DE DATOS
	
}

//DESTRUCTOR
void destruirJugador(Jugador x)
{
    free(x);
}
