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

//MODIFICAR
void modificarJugador(Jugador x)
{		
		int opc;
		char auxNombre[30];
		char auxAlias[30];
		int auxDni;
		
		do
		{//INICIO BUCLE	"MENU"
			system("cls");
			printf ("1.-Nombre\n");
			printf ("2.-Alias\n");		
			printf ("3.-DNI\n");
			printf("4.-Modificar todo\n");
			printf("5.-Ver Datos\n");
			printf ("0.-Salir\n\n");
			printf ("Ingrese la opcion que quiere modificar:"); scanf ("%d",&opc);
			system("cls");
			switch (opc)
	
			{//INICIO SWITCH
				case 1:					
						fflush(stdin);
					    printf("Ingrese su nombre:"); gets(auxNombre);
					    fflush(stdin);
					    setNombre(x,auxNombre); break;
					    
				case 2:					
						fflush(stdin);
					    printf("Ingrese su Alias:"); gets(auxAlias);
					    fflush(stdin);		    
		
				case 3:
						printf ("Ingrese su DNI:"); scanf ("%d",&auxDni); 
						setDni(x,auxDni);
						break;
						
				case 4:
					
						fflush(stdin);
					    printf("Ingrese su nombre:"); gets(auxNombre);
					    fflush(stdin);
					    setNombre(x,auxNombre);
					    fflush(stdin);
					    printf("Ingrese su Alias:"); gets(auxAlias);
					    fflush(stdin);
					    printf ("Ingrese su DNI:"); scanf ("%d",&auxDni); 
						setDni(x,auxDni);
						break;
						
				case 5: mostrarJugador(x); system("pause"); break;
						
				case 0: printf ("TERMINO LA MODIFICACION!\n\n"); break;
				
				default: printf ("Opcion incorrecta, elija una opcion correcta\a\n\n"); break; 
				
			}//FIN SWITCH
	
		}	while (opc!=0); 	
}

//MOSTRAR
void mostrarJugador(Jugador x)
{

	printf ("NOMBRE JUGADOR: [%s]\n",getNombre(x));
	printf ("NICK NAME: [%s]\n",getAlias(x));	
	printf ("DNI JUGADOR: [%d]\n",getDni(x));	
	printf ("CANTIDAD DE CARTONES ASIGNADOS: [%d]\n\n",getCantCartones(x));	

}

void mostrarCartones(Jugador x)
{	
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

void moderadorInferiorLento(Jugador x, int lugar) //TEST DEL JUEGO, MODIFICAR MAS ADELANTE
{
		int i,j;
		
		int bandera[3]={};
		int banderaBot[3]={};
		
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
			mostrarCartonMarcado(matriz);
			printf("\n");
			mostrarBolilla(x,i);
			printf("\n");
			
			system("pause");
			system("cls");
						
			if(bandera[0] == 0)
			{
				cincoLinea(x->CartonesH[lugar],x->bola,i,bandera);						
			}
			
			if(banderaBot[0] == 0)
			{
				cincoLinea(x->CartonesB[lugar],x->bola,i,banderaBot);				
			}
			
			if(bandera[1] == 0)
			{
				tresColumna(x->CartonesH[lugar],x->bola,i,bandera);
			}
			
			if(banderaBot[1] == 0)
			{
				tresColumna(x->CartonesB[lugar],x->bola,i,banderaBot);
			}
			
			if(bandera[2] == 0)
			{
				bingo(x->CartonesH[lugar],x->bola,i,bandera);
			}	
			
			if(banderaBot[2] == 0)
			{
				bingo(x->CartonesB[lugar],x->bola,i,banderaBot);
			}					
			
		}				
			setJugadas(x->CartonesH[lugar],0,bandera[0]);
			setJugadas(x->CartonesH[lugar],1,bandera[1]);
			setJugadas(x->CartonesH[lugar],2,bandera[2]);
			
			setJugadas(x->CartonesB[lugar],0,banderaBot[0]);
			setJugadas(x->CartonesB[lugar],1,banderaBot[1]);
			setJugadas(x->CartonesB[lugar],2,banderaBot[2]);
}

void moderadorInferiorRapido(Jugador x, int lugar) //TEST DEL JUEGO, MODIFICAR MAS ADELANTE
{
		int i,j;
		
		int bandera[3]={};
		int banderaBot[3]={};		

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
			
			if(banderaBot[0] == 0)
			{
				cincoLinea(x->CartonesB[lugar],x->bola,i,banderaBot);				
			}
			
			if(bandera[1] == 0)
			{
				tresColumna(x->CartonesH[lugar],x->bola,i,bandera);
			}
			
			if(banderaBot[1] == 0)
			{
				tresColumna(x->CartonesB[lugar],x->bola,i,banderaBot);
			}
			
			if(bandera[2] == 0)
			{
				bingo(x->CartonesH[lugar],x->bola,i,bandera);
			}	
			
			if(banderaBot[2] == 0)
			{
				bingo(x->CartonesB[lugar],x->bola,i,banderaBot);
			}					
			
		}		
			setJugadas(x->CartonesH[lugar],0,bandera[0]);
			setJugadas(x->CartonesH[lugar],1,bandera[1]);
			setJugadas(x->CartonesH[lugar],2,bandera[2]);
			
			setJugadas(x->CartonesB[lugar],0,banderaBot[0]);
			setJugadas(x->CartonesB[lugar],1,banderaBot[1]);
			setJugadas(x->CartonesB[lugar],2,banderaBot[2]);
}

void moderadorSuperiorLento(Jugador x)
{	
	int i;

	
		for(i=0;i<x->cantCartones;i++)
		{	
					printf ("\n\nCARTON JUGADOR HUMANO NUMERO [%d]\n",i+1);	
					moderadorInferiorLento(x,i);						
		}
					
		Calcularpuntajes(x);	
		guardarPuntajes(x);
}

void moderadorSuperiorRapido(Jugador x)
{	
	int i;
	
	//AGREGAR CONTEXTO
	system("cls");
	
		for(i=0;i<x->cantCartones;i++)
		{
			printf ("CARTON JUGADOR HUMANO NUMERO [%d]\n",i+1);	
			moderadorInferiorRapido(x,i);
			system("cls");						
		}	
	
	Calcularpuntajes(x);
	
	//
	
	resumen(x);	
	
	guardarPuntajes(x);
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
			}					
		}		
				system("cls");
				printf("Seleccion correcta! Cartones en juego: [%d]\n",cantCartones);
				system("pause");
				system("cls");			
	
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
	
	//MODIFICAR JUGADOR PARA QUE ELIJA EL USUARIO
	
	int CantCartones=elegirCantCarton();	
	setCantCartones(x,CantCartones);
		
		for (i=0;i<getCantCartones(x);i++)
		{
			x->CartonesH[i] = crearCarton(); //REINICIA LOS CARTONES HUMANO
			x->CartonesB[i] = crearCarton(); //REINICIA LOS CARTONES BOT			
		}		
		
			reiniciarBola(x->bola);
			sacarBolilla(x->bola);
				
			setJugadas(x->CartonesH[0],0,0);
			setJugadas(x->CartonesH[0],1,0);
			setJugadas(x->CartonesH[0],2,0);			
}

void ganadorJuego(Jugador x)
{	
	int i;
	
	float puntajeH=getPuntaje(x->CartonesH[0]);
	float puntajeB=getPuntaje(x->CartonesB[0]);
	
	for(i=0;i<x->cantCartones;i++)
	{
		if(getPuntaje(x->CartonesH[i])>puntajeH)
		{
			puntajeH=getPuntaje(x->CartonesH[i]);
		}
		
		if(getPuntaje(x->CartonesB[i])>puntajeB)
		{
			puntajeB=getPuntaje(x->CartonesB[i]);
		}
	}
	
	if(puntajeH > puntajeB)
	{
		printf("Gano el jugador [%s], FELICITACIONES!!!\n\n",getAlias(x));
		printf("Con una puntuacion total de: [%.2f]\n",puntajeH);
		printf("Contra una puntuacion total de: [%.2f]\n",puntajeB);
	}
	else
	{
		printf("Gano la maquina, SUERTE LA PROXIMA!!!\n\n");
		printf("Con una puntuacion total de: [%.2f]\n",puntajeB);
		printf("Tu puntuacion fue de: [%.2f]\n",puntajeH);
	}
}

void resumen(Jugador x)
{
	int i;
	
	for(i=0;i<x->cantCartones;i++)
	{
		
		printf("\nRESUMEN DE LA PARTIDA:\n\n");
		
		printf ("JUGADOR [%s], Carton numero [#%d]\n",getAlias(x),i+1);
		printf ("5 EN LINEA: %d\n",getJugadas(x->CartonesH[i],0));
		printf ("3 EN COLUMNA: %d\n",getJugadas(x->CartonesH[i],1));
		printf ("BINGO: %d\n",getJugadas(x->CartonesH[i],2));
		
		printf ("\n");
		
		printf ("JUGADOR [BOT], Carton numero [#%d]\n",i+1);
		printf ("5 EN LINEA: %d\n",getJugadas(x->CartonesB[i],0));
		printf ("3 EN COLUMNA: %d\n",getJugadas(x->CartonesB[i],1));
		printf ("BINGO: %d\n",getJugadas(x->CartonesB[i],2));
		printf ("\n");
	}
	
		ganadorJuego(x);
	
}

//////////PUNTAJE//////////

void Calcularpuntajes(Jugador x)
{
	int i;
	
	for (i=0;i<x->cantCartones;i++)
	{

		//El primer jugador que cante línea sumará 20 puntos, el otro 10.
		if(getJugadas(x->CartonesH[i],0) < getJugadas(x->CartonesB[i],0))
		{			
			setPuntaje(x->CartonesH[i],20);
			setPuntaje(x->CartonesB[i],10);
		}
		
		else
		{			
			setPuntaje(x->CartonesH[i],10);
			setPuntaje(x->CartonesB[i],20);
		}		
	}
	
		//////////////////////////////////////
	
	for (i=0;i<x->cantCartones;i++)
	{	
		//El primer jugador que cante Columna, sumará 10 puntos, el otro 5.
		if(getJugadas(x->CartonesH[i],1) < getJugadas(x->CartonesB[i],1))			
		{
			setPuntaje(x->CartonesH[i],getPuntaje(x->CartonesH[i])+10);
			setPuntaje(x->CartonesH[i],getPuntaje(x->CartonesB[i])+5);
		}
		
		else
		{
			setPuntaje(x->CartonesH[i],getPuntaje(x->CartonesH[i])+5);
			setPuntaje(x->CartonesB[i],getPuntaje(x->CartonesB[i])+10);
		}		
	}	
	
		//////////////////////////////////////
	
	for (i=0;i<x->cantCartones;i++)
	{		
		//El primero que complete un cartón cantará Bingo, sumando 70 puntos, el otro 35.
		if(getJugadas(x->CartonesH[i],2) < getJugadas(x->CartonesB[i],2))
		{
			setPuntaje(x->CartonesH[i],getPuntaje(x->CartonesH[i])+70);
			setPuntaje(x->CartonesH[i],getPuntaje(x->CartonesB[i])+35);
		}
		
		else
		{
			setPuntaje(x->CartonesH[i],getPuntaje(x->CartonesH[i])+35);
			setPuntaje(x->CartonesB[i],getPuntaje(x->CartonesB[i])+70);
		}		
	}			
	
	for(i=0;i<x->cantCartones;i++) //MULTIPLICA EL PUNTAJE POR LA CANTIDAD DE JUGADAS NECESARIAS PARA EL BINGO
	{			
			setPuntaje(x->CartonesH[i], getPuntaje(x->CartonesH[i])*getJugadas(x->CartonesH[i],2));
			setPuntaje(x->CartonesB[i], getPuntaje(x->CartonesB[i])*getJugadas(x->CartonesB[i],2));	
	}		

}

void guardarPuntajes(Jugador x) //GUARDA EL MEJOR PUNTAJE DE CADA JUGADOR (HUMANO Y MAQUINA)
{
	//AGREGAR
	FILE *puntero;
	
	int i;
	
	char aux[30] = "Bot";
	
	float puntajeH=getPuntaje(x->CartonesH[0]);
	float puntajeB=getPuntaje(x->CartonesB[0]);
	
	for(i=0;i<x->cantCartones;i++)
	{
		if(getPuntaje(x->CartonesH[i])>puntajeH)
		{
			puntajeH=getPuntaje(x->CartonesH[i]);
		}
		
		if(getPuntaje(x->CartonesB[i])>puntajeB)
		{
			puntajeB=getPuntaje(x->CartonesB[i]);
		}
	}
	
	puntero = fopen ("puntajes.txt","a");		
	

	fprintf(puntero,"%s, %.2f\n",getAlias(x), puntajeH);
	fprintf(puntero,"%s, %.2f\n",aux, puntajeB);
	
	fprintf(puntero,"\n");	
    
    fclose (puntero);
}

void mostrarPuntajes()
{
	//LEER
	FILE *puntero;
	puntero = fopen("puntajes.txt","r");
	
	while (!feof(puntero))
	{

	char aux[40]={};
	fgets (aux,40,puntero);		
	printf ("%s",aux);
	
	}
	
	fclose (puntero);	
}

//////////METODOS GET - SET//////////

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

//DESTRUCTOR
void destruirJugador(Jugador x)
{
    free(x);
}

