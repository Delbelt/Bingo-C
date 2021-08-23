#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "jugador.h" //CLASE JUGADOR
#include "carton.h" //CLASE CARTON

int main() {
	
	Jugador j1 = crearJugador("Nombre","Alias",999999999);
	
	//mostrarJugador(j1);
	//mostrarCartones(j1);		
	
	return 0;
}
