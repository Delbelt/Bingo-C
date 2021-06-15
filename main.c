#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "jugador.h" //CLASE JUGADOR
#include "carton.h" //CLASE CARTON

int main() {
	
	printf ("NAHUEL FLORES\n");
	printf ("CUARTO COMMIT - FUNCIONES PRINCIPALES\n\n\n");
	
	Jugador j1 = crearJugador("Nahuel","Delbelt",40667557);
	mostrarJugador(j1);
	
	return 0;
}
