#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "jugador.h"
#include "carton.h"

#define CANT_CARTONES 3 //GLOBAL PARA DEFINIR LA CANT DE CARTONES MAXIMOS POR JUGADOR


	struct JugadorE{ 
		
		char nombre[30];	
		char alias[15];
		int dni;		
		int cantCartones;
		Carton Cartones[CANT_CARTONES];	
		//int bola[90];	POSIBLE A AGREGAR		
		
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
	
	//int cantCartones = CantCartones();
	//CON CUANTOS CARTONES QUIERE JUGAR? = 2
	//cantCartones = 2;
	//SE CREAN POR ENDE SOLO N CARTONES.
	
	//REEMPLAZAR CANT_CARTONES POR UNA FUNCION QUE PREGUNTE CON CUANTOS CARTONES QUIERE JUGAR 1 MIN 3 MAX.	
	
	for(i=0;i<CANT_CARTONES;i++) //CARGA EL MAXIMO DE CARTONES PERMITIDOS POR JUGADOR A ASIGNAR POR SISTEMA
	{
		x->Cartones[i] = crearCarton(); //CREA LOS CARTONES
	}
	
	return x; //RETORNA JUGADOR X QUE FUE GUARDADO EN MEMORIA PARA LA ASIGNACION DE DATOS
	
}

//POSIBLEMENTE UN CONSTRUCTOR APARTE PARA EL BOT SIN EL DNI

//DESTRUCTOR
void destruirJugador(Jugador x)
{
    free(x);
}

//METODOS SET
void setNombre(Jugador x, char nombre[])
{
	strcpy (x->nombre,nombre);
}

void setAlias(Jugador x, char alias[])
{
	strcpy (x->alias,alias);
}

void setDni(Jugador x, int dni)
{
	x->dni = dni;
}

void setCantCartones(Jugador x, int cantCartones)
{
	x->cantCartones = cantCartones;
}

//METODOS GET
char *getNombre(Jugador x)
{
	return x->nombre;
}

char *getAlias(Jugador x)
{
	return x->alias;
}

int getDni(Jugador x)
{
	return x->dni;	
}

int getCantCartones(Jugador x)
{
	return x->cantCartones;	
}

