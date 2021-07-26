#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "jugador.h" //CLASE JUGADOR
#include "carton.h" //CLASE CARTON

int main() {
	
	printf ("NAHUEL FLORES\n");
	printf ("SEXTO COMMIT - TERMINANDO FUNCIONES PRINCIPALES\n\n\n");
	
	Jugador j1 = crearJugador("Nahuel","Delbelt",40667557);
	//mostrarJugador(j1);
	
	mostrarCartones(j1,0);	
	
	//mostrarBolilla(j1);
	
	//reiniciarJuego(j1);
	//mostrarJugador(j1);
	//mostrarBolilla(j1);
		
	
	return 0;
}
