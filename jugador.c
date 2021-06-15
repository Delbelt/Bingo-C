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
		Carton CartonesH[CANT_CARTONES];
		Carton CartonesB[CANT_CARTONES];	
		//int bola[90];	POSIBLE A AGREGAR		
		
	};
	
//CONSTRUCTOR HUMANO
Jugador crearJugador(char nombre[],char alias[],int dni)
{
	Jugador x = malloc(sizeof(struct JugadorE)); //Asigno memoria en el sistema para crear el jugador
	
	//GUARDO LAS VARIABLES ASIGNADAS EN LOS PARAMETROS
	strcpy(x->nombre,nombre); //STRING
	strcpy(x->alias,alias);	//STRING
	x->dni = dni; //INT
	
	int i; //INDICE
	
	//CANTIDAD DE CARTONES
	int CantCartones=elegirCantCarton();	
	setCantCartones(x,CantCartones);
	
	for(i=0;i<getCantCartones(x);i++) //CARGA EL MAXIMO DE CARTONES PERMITIDOS POR JUGADOR A ASIGNAR POR EL USUARIO
	{
		x->CartonesH[i] = crearCarton(); //CREA LOS CARTONES HUMANO
		x->CartonesB[i] = crearCarton(); //CREA LOS CARTONES BOT
	}	
	
	return x; //RETORNA JUGADOR X QUE FUE GUARDADO EN MEMORIA PARA LA ASIGNACION DE DATOS	
}

//MOSTRAR
void mostrarJugador(Jugador x)
{
	
	printf ("NOMBRE JUGADOR: [%s]\n",getNombre(x));	
	printf ("NICK NAME: [%s]\n",getAlias(x));
	printf ("DNI JUGADOR: [%d]\n",getDni(x));	
	printf ("CANTIDAD DE CARTONES ASIGNADOS: [%d]\n\n",getCantCartones(x));
	
	int i;	
	
	//MUESTRA LOS CARTONES DEL JUGADOR
	
	printf ("CARTONES DEL JUGADOR:\n\n");
	
	for(i=0;i<getCantCartones(x);i++)
	{
		printf ("Carton Humano numero: [%d]\n",i+1);
		mostrarCarton(x->CartonesH[i]);
		printf("\n");	
	}
	
	//MUESTRA LOS CARTONES DEL BOT
	
	printf ("CARTONES DEL BOT:\n\n");
	
	for(i=0;i<getCantCartones(x);i++)
	{
		printf ("Carton Bot numero: [%d]\n",i+1);
		mostrarCarton(x->CartonesB[i]);
		printf("\n");	
	}
}

//FUNCIONES PRINCIPALES
int elegirCantCarton()
{
	int cantCartones=0;
	
	printf ("Elija con cuantos cartones quiere jugar (Min 1 - Max 3): "); scanf ("%d",&cantCartones);
	
			while (cantCartones<1 || cantCartones>3)
		{		
			if (cantCartones != 1 && cantCartones != 2 && cantCartones != 3)
			{
				system("cls");
				printf ("ELIGIO MAL!!!\n");			
				printf ("Elija con cuantos cartones quiere jugar (Min 1 - Max 3): "); scanf ("%d",&cantCartones);
				system("cls");
			}					
		}				
	
	return cantCartones;
}

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

