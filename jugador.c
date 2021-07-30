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
		int bola[90];	
		
	};
	
//CONSTRUCTOR HUMANO
Jugador crearJugador(char nombre[],char alias[],int dni)
{
	Jugador x = malloc(sizeof(struct JugadorE)); //Asigno memoria en el sistema para crear el jugador
	
	srand(time(NULL)); //PARA GENERAR NUMEROS ALEATORIOS
	
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
	
	sacarBolilla(x->bola);	
	
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
		printf ("Carton numero: [%d]\n",i+1);
		mostrarCarton(x->CartonesH[i]);
		printf("\n");	
	}
	
	//MUESTRA LOS CARTONES DEL BOT
	
	printf ("CARTONES DEL BOT:\n\n");
	
	for(i=0;i<getCantCartones(x);i++)
	{
		printf ("Carton numero: [%d]\n",i+1);
		mostrarCarton(x->CartonesB[i]);
		printf("\n");	
	}
}

void mostrarCartones(Jugador x, int lugar) //TEST DEL JUEGO, MODIFICAR MAS ADELANTE
{
		int i,j;
		
		int bandera[3]={};
		
		printf ("\nCarton numero: [%d]\n",lugar+1);		
		printf("\n");
		
		int matriz[3][5]={};
		
		for(i=0;i<3;i++)
		{
			for(j=0;j<5;j++)
			{
				matriz[i][j] = getCarton(x->CartonesH[lugar],i,j);
			}	
		}
				
		for(i=0;i<90;i++)
		{
			//marcarCarton(x->CartonesH[lugar],x->bola,i);
			marcarCarton(matriz,x->bola,i);
			mostrarCarton(matriz);
			//mostrarCarton(x->CartonesH[lugar]);
			//mostrarBolilla(x,i);
			
			system("pause");
			system("cls");
						
			if(bandera[0] == 0)
			{
				cincoLinea(x->CartonesH[lugar],x->bola,i,bandera);				
			}
			
			if(bandera[1] == 0)
			{
				tresColumna(x->CartonesH[lugar],x->bola,i,bandera);
			}
			
			if(bandera[2] == 0)
			{
				bingo(x->CartonesH[lugar],x->bola,i,bandera);
			}			
			
		}
		
			setJugadas(x->CartonesH[lugar],0,bandera[0]);
			setJugadas(x->CartonesH[lugar],1,bandera[1]);
			setJugadas(x->CartonesH[lugar],2,bandera[2]);
		
			printf("EL VALOR DE 5 EN LINEA: %d\n",getJugadas(x->CartonesH[lugar],0));
			printf("EL VALOR DE 3 EN COLUMNA ES: %d\n",getJugadas(x->CartonesH[lugar],1));
			printf("EL VALOR DE BINGO ES: %d\n",getJugadas(x->CartonesH[lugar],2));

			//printf("EL VALOR DE BANDERA ES: %d\n",bandera[0]);
			
			//setJugadas(x->CartonesH[0],0,bandera[0]);
			
			//printf("EL VALOR DE BANDERA REAL ES: %d",getJugadas(x->CartonesH[0],0));
			
			
					
			//printf(getJugadas(x->CartonesH[0],0));	

		
		//mostrarCarton(x->CartonesH[lugar]);
}

void moderadorInferiorLento(Jugador x, int lugar) //TEST DEL JUEGO, MODIFICAR MAS ADELANTE
{
		int i,j;
		
		int bandera[3]={};
		
		//printf ("\nCarton numero: [%d]\n",lugar+1);		
		
		int matriz[3][5]={};
		
		for(i=0;i<3;i++)
		{
			for(j=0;j<5;j++)
			{
				matriz[i][j] = getCarton(x->CartonesH[lugar],i,j);
			}	
		}
		
		//AGREGARLE CONTEXTO	
		system("cls");	
			
		for(i=0;i<90;i++)
		{			
			printf ("\nCarton H numero: [%d]\n",lugar+1);	
			marcarCarton(matriz,x->bola,i);
			mostrarCarton(matriz);
			printf("\n");
			mostrarBolilla(x,i);
			printf("\n");
			
			system("pause");
			system("cls");
						
			if(bandera[0] == 0)
			{
				cincoLinea(x->CartonesH[lugar],x->bola,i,bandera);				
			}
			
			if(bandera[1] == 0)
			{
				tresColumna(x->CartonesH[lugar],x->bola,i,bandera);
			}
			
			if(bandera[2] == 0)
			{
				bingo(x->CartonesH[lugar],x->bola,i,bandera);
			}			
			
		}
		
			setJugadas(x->CartonesH[lugar],0,bandera[0]);
			setJugadas(x->CartonesH[lugar],1,bandera[1]);
			setJugadas(x->CartonesH[lugar],2,bandera[2]);
		
			printf("EL VALOR DE 5 EN LINEA: %d\n",getJugadas(x->CartonesH[lugar],0));
			printf("EL VALOR DE 3 EN COLUMNA ES: %d\n",getJugadas(x->CartonesH[lugar],1));
			printf("EL VALOR DE BINGO ES: %d\n",getJugadas(x->CartonesH[lugar],2));
}

void moderadorInferiorRapido(Jugador x, int lugar) //TEST DEL JUEGO, MODIFICAR MAS ADELANTE
{
		int i,j;
		
		int bandera[3]={};		

		printf ("\nCarton H numero: [%d]\n",lugar+1);	
		mostrarCarton(x->CartonesH[lugar]);	
		printf("\n");
		
		int matriz[3][5]={};
		
		for(i=0;i<3;i++)
		{
			for(j=0;j<5;j++)
			{
				matriz[i][j] = getCarton(x->CartonesH[lugar],i,j);
			}	
		}
				
		for(i=0;i<90;i++)
		{
								
			if(bandera[0] == 0)
			{
				cincoLinea(x->CartonesH[lugar],x->bola,i,bandera);				
			}
			
			if(bandera[1] == 0)
			{
				tresColumna(x->CartonesH[lugar],x->bola,i,bandera);
			}
			
			if(bandera[2] == 0)
			{
				bingo(x->CartonesH[lugar],x->bola,i,bandera);
			}			
			
		}		
			setJugadas(x->CartonesH[lugar],0,bandera[0]);
			setJugadas(x->CartonesH[lugar],1,bandera[1]);
			setJugadas(x->CartonesH[lugar],2,bandera[2]);
		
			printf("EL VALOR DE 5 EN LINEA: %d\n",getJugadas(x->CartonesH[lugar],0));
			printf("EL VALOR DE 3 EN COLUMNA ES: %d\n",getJugadas(x->CartonesH[lugar],1));
			printf("EL VALOR DE BINGO ES: %d\n",getJugadas(x->CartonesH[lugar],2));
}

void moderadorSuperiorLento(Jugador x)
{	
	int i;

	
		for(i=0;i<x->cantCartones;i++)
					{	
					printf ("\n\nCARTON JUGADOR HUMANO NUMERO [%d]\n",i+1);	
					moderadorInferiorLento(x,i);
					//printf ("CARTON BOT NUMERO [%d]\n\n",i+1);
					//moderadorInferiorRapido(cartonBot[a].banderaPos,cartonBot[a].matriz,jugador.bola);						
					}
}

void moderadorSuperiorRapido(Jugador x)
{	
	int i;
	
	//AGREGAR CONTEXTO
	system("cls");
	
		for(i=0;i<x->cantCartones;i++)
					{
					printf ("CARTON JUGADOR HUMANO NUMERO [%d]\n",i+1);	
					//mostrarCartones(x,i);
					moderadorInferiorRapido(x,i);
					//printf ("CARTON BOT NUMERO [%d]\n\n",i+1);
					//moderadorInferiorRapido(cartonBot[a].banderaPos,cartonBot[a].matriz,jugador.bola);						
					}
}

//////////FUNCIONES PRINCIPALES//////////

//ELIGE CON CUANTOS CARTONES QUERES JUGAR 1 MIN - 3 MAX
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

//COMPRUEBA QUE NO SE REPITAN NUMEROS EN LAS BOLILLAS (VECTOR)
int comprobarBolilla(int vector[],int num)
{
	int i=0;
	
	for (i=0;i<90;i++)
	{
		if (num==vector[i])
		{		
			return 0;
		}
	}
			return 1;
}

//SACA LAS 90 BOLILLAS ALEATORIAS SIN REPETIR
void sacarBolilla(int vector[])
{
		int i;
		int numAleatorio=0;
		
		for (i=0;i<90;i++)
		{		
			numAleatorio = 1+rand()%90;
			
			while (comprobarBolilla(vector,numAleatorio) ==0) //COMPRUEBA QUE LOS NUMEROS NO SE REPITAN CON LA FUNCION
			{			
				numAleatorio = 1+rand()%90;				
			}		
				vector[i]=numAleatorio;			
		}
}

//MUESTRA LAS BOLILLAS QUE SALIERON <<<MODIFICAR>>>
void mostrarBolilla(Jugador x, int jugada)
{
		//int i;		
	
		//for (i=0;i<90;i++)
		//{	
			//printf ("la bolilla que salio es:[%d] de la jugada:[%d]\n", getBolilla(x,i),i+1);
			printf ("la bolilla que salio es:[%d] de la jugada:[%d]\n", getBolilla(x,jugada),jugada+1);							
		//}
}

//REINICIA LAS BOLILLAS EN CASO DE REINICIAR EL JUEGO
void reiniciarBola(int bolilla[])
{
	int i;
	
	for (i=0;i<90;i++)	
	{
		bolilla[i] = -1;
	}
}

//////////MODERACION DEL JUEGO//////////

void reiniciarJuego(Jugador x)
{	
	
	int i;	
	
	int CantCartones=elegirCantCarton();	
	setCantCartones(x,CantCartones);
		
		for (i=0;i<getCantCartones(x);i++)
		{
			x->CartonesH[i] = crearCarton(); //REINICIA LOS CARTONES HUMANO
			x->CartonesB[i] = crearCarton(); //REINICIA LOS CARTONES BOT			
		}		
		
			reiniciarBola(x->bola);
			sacarBolilla(x->bola);				
}

//////////PUNTAJE//////////

//////////METODOS GET - SET//////////

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

int getBolilla(Jugador x,int i)
{
	return x->bola[i];	
}

