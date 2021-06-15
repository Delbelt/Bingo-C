#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "jugador.h"
#include "carton.h"

struct CartonE{
	
		int matrizCarton[3][5];	
};

//CONSTRUCTOR
Carton crearCarton()
{
	Carton x = malloc(sizeof(struct CartonE)); //Asigno memoria en el sistema para crear el Carton
	
	cargarCarton(x->matrizCarton);
		
	//FUNCION QUE CARGUE LA MATRIZ CON NUMEROS ALEATORIOS QUE NO SE REPITAN	
	//cargarCarton(x->matriz)
	//GENERA LA MATRIZ ALEATORIA PARA EL BINGO
	
	return x; //RETORNA CARTON X QUE FUE GUARDADO EN MEMORIA PARA LA ASIGNACION DE DATOS	
}

//MOSTRAR
void mostrarCarton(Carton x)
{
	int i,j;
	
	int indice = 3;
	int subIndice = 5;
	
	printf (" ---------------\n");
	
	for(i=0;i<indice;i++)
	{		
		printf ("|");
		for(j=0;j<subIndice;j++)
		{
			printf (" %d ",x->matrizCarton[i][j]);
		}		
			printf ("|\n");
	}
	
	printf (" ---------------\n");
}

//FUNCIONES PRINCIPALES
void cargarCarton(int carton[3][5])
{
	int i,j;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			carton[i][j]=5;
		}
	}
}

//DESTRUCTOR
void destruirCarton(Carton x)
{
	free(x);
}
