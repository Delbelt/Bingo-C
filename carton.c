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
	
	//FUNCION QUE CARGUE LA MATRIZ CON NUMEROS ALEATORIOS QUE NO SE REPITAN	
	//cargarCarton(x->matriz)
	//GENERA LA MATRIZ ALEATORIA PARA EL BINGO
	
	return x; //RETORNA CARTON X QUE FUE GUARDADO EN MEMORIA PARA LA ASIGNACION DE DATOS
	
}

//DESTRUCTOR
void destruirCarton(Carton x)
{
	free(x);
}
