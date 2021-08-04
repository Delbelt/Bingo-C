#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "jugador.h"
#include "carton.h"

struct CartonE{
	
		int matrizCarton[3][5];
		int posJugadas[3]; // 0 = 5 EN LINEA, 1 = 3 EN COLUMNA, 2 = BINGO;
		float puntaje;
};

//CONSTRUCTOR
Carton crearCarton()
{
	Carton x = malloc(sizeof(struct CartonE)); //Asigno memoria en el sistema para crear el Carton
	
	cargarCarton(x->matrizCarton);
	
	x->puntaje=0;
	
	int i;
	
	for(i=0;i<3;i++)
	{
		x->posJugadas[i]=0;
	}
	
	return x; //RETORNA CARTON X QUE FUE GUARDADO EN MEMORIA PARA LA ASIGNACION DE DATOS	
}

//MOSTRAR
void mostrarCarton(Carton x)
{
	int i,j;
	
	int indice = 3;
	int subIndice = 5;
	
	printf (" --------------------\n");
	
	for(i=0;i<indice;i++)
	{		
		printf ("|");
		for(j=0;j<subIndice;j++)
		{	
		
			if(x->matrizCarton[i][j]<10 && x->matrizCarton[i][j]>0)
			{
				printf ("  %d ",x->matrizCarton[i][j]);	
			}
			
			else if(x->matrizCarton[i][j]<0)
			{
				printf (" %d  ",x->matrizCarton[i][j]);	
			}
			
			else
			{
				printf (" %d ",x->matrizCarton[i][j]);		
			}		
			
		}
						
			printf ("| \n");
	}
	
	printf (" --------------------\n");
	
}

//MOSTRAR
void mostrarCartonMarcado(Carton x)
{
	int i,j;
	
	int indice = 3;
	int subIndice = 5;
	
	printf (" ------------------------------ \n");
	
	for(i=0;i<indice;i++)
	{		
		printf ("|");
		for(j=0;j<subIndice;j++)
		{	
		
			if(x->matrizCarton[i][j]<10 && x->matrizCarton[i][j]>0)
			{
				printf ("  %d ",x->matrizCarton[i][j]);	
			}	

			
			if(x->matrizCarton[i][j]<0 && x->matrizCarton[i][j]>-10)
			{
				printf ("  %d  ",x->matrizCarton[i][j]);	
			}
			
			if(x->matrizCarton[i][j]<=-10)
			{
				printf (" %d  ",x->matrizCarton[i][j]);	
			}
			
			if(x->matrizCarton[i][j]>=10)
			{
				printf (" %d ",x->matrizCarton[i][j]);		
			}	
	
			
		}
						
			printf ("|\n");
	}
	
	printf (" ------------------------------ \n");
}

//////////FUNCIONES PRINCIPALES//////////
void cargarCarton(int carton[][5])
{		
	int i,j;
	
	int numTest = 0; //VARIABLE PARA TESTEAR SI REPITEN LOS NUMEROS
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{			
			numTest = 1+rand()%90;
	
			while (comprobarRepeticion(carton,numTest) == 1) //SI ES IGUAL, VUELVE A ELEGIR UN ALEATORIO Y VUELVE A PREGUNTAR HASTA QUE NO SEAN IGUALES
			{
				numTest = 1+rand()%90;								
			}			
				carton[i][j]=numTest; //UNA VEZ VERIFICADO QUE NO SON IGUALES LOS NUMEROS, SE GUARDA EN LA MATRIZ							
		}
	}
}

int comprobarRepeticion (int carton[][5],int numVerificar)//COMPRUEBA SI HAY REPETICIONES EN LOS NUMEROS (MATRIZ) CARTON
{	
	int i,j;
		
	for (i=0;i<3;i++)
	{//INICIO i
	
		for (j=0;j<5;j++)
		{//INICIO j	
		
			if(numVerificar==carton[i][j])
			{//INICIO if				
				return 1; //TRUE
			}//FIN if		
		}		
	}		
			return 0; //FALSE
}

void marcarCarton(int carton[], int bolilla[], int jugada)
{
	
	int i;	
	
	for (i=0;i<15;i++)
	{
	
		if (carton[i]==bolilla[jugada])
		{
			carton[i] = carton[i] * -1;
		}
	}
}

void posJugadas(int posJug[],int posicion,int numero) //Para guardar la Bandera //TESTEAR Y CORREGIR
{

	posJug[numero] = posicion;
	
}

void cincoLinea(int vector[][5],int bolilla[],int jugadas,int bandera[]) //HACE LA COMPROBACION DE 5 EN LINEA
{	
	
	int x,j;
	int pos[5]={};		
	int largo=0;
	int intentos=0;
		

	 while (intentos<3) //DE ESTA FORMA EN CASO DE NO COMPROBAR SALE DE LA FUNCION
	 {
	
	intentos++;
	largo=intentos-1;
		
	if(largo >=0 && largo<3)
	{	

	for (x=0;x<jugadas;x++)
	{			
		for(j=0;j<5;j++)
		{		
						
			if (vector[largo][j]==bolilla[x])
			{
				pos[0]=x;
				x=15;
				j=5;
						
	for (x=0;x<jugadas;x++)
	{
		for(j=0;j<5;j++)
		{		
			if (vector[largo][j]==bolilla[x] && vector[largo][j]!=bolilla[pos[0]])
			{
				pos[1]=x;
				x=15;
				j=5;
				
		for (x=0;x<jugadas;x++)
		{
			for(j=0;j<5;j++)
			{		
				if (vector[largo][j]==bolilla[x] && vector[largo][j]!=bolilla[pos[0]] && vector[largo][j]!=bolilla[pos[1]])
				{
					pos[2]=x;
					x=15;
					j=5;
				
		for (x=0;x<jugadas;x++)
		{
			for(j=0;j<5;j++)
			{		
				if (vector[largo][j]==bolilla[x] && vector[largo][j]!=bolilla[pos[0]] && vector[largo][j]!=bolilla[pos[1]] && vector[largo][j]!=bolilla[pos[2]])
				{
					pos[3]=x;
					x=15;
					j=5;
				
		for (x=0;x<jugadas;x++)
		{
			for(j=0;j<5;j++)
			{
		
			if (vector[largo][j]==bolilla[x] && vector[largo][j]!=bolilla[pos[0]] && vector[largo][j]!=bolilla[pos[1]] && vector[largo][j]!=bolilla[pos[2]] && vector[largo][j]!=bolilla[pos[3]])
			{							

				printf ("5 EN LINEA! DE LA FILA: %d",largo+1);
				printf ("\nJUGADAS NECESARIAS PARA 5 EN LINEA: %d\n\n",jugadas);
				
				posJugadas(bandera,x+1,0);
						
				x=99;
				j=99;
				largo=99;
				
			}
		
			}
		}
				}
			}
		}
				}	
			}
		}
			}
		}
	}
			}
		}
	}
	
	}
	
	}//FIN While	

}//FIN CINCO EN LINEA

void tresColumna(int vector[][5],int bolilla[],int jugadas, int bandera[]) //COMPRUEBA SI HAY 3 EN LINEA
{
	int x,j;
	int pos[3]={};		
	int largo=0;
	int intentos=0;			

	 while (intentos<5) //EN CASO DE NO COMPROBARLO, SALE DE LA FUNCION
	 {
	
	intentos++;
	largo=intentos-1;
		
	if(largo >=0 && largo<5)
	{	

	for (x=0;x<jugadas;x++)
	{			
		for(j=0;j<3;j++)
		{		
						
			if (vector[j][largo]==bolilla[x])
			{

				pos[0]=x;
				x=15;
				j=5;
						
	for (x=0;x<jugadas;x++)
	{
		for(j=0;j<3;j++)
		{
			
			if (vector[j][largo]==bolilla[x] && vector[j][largo]!=bolilla[pos[0]])
			{
				pos[1]=x;
				x=15;
				j=5;
				
		for (x=0;x<jugadas;x++)
		{
			for(j=0;j<3;j++)
			{	
				if (vector[j][largo]==bolilla[x] && vector[j][largo]!=bolilla[pos[0]] && vector[j][largo]!=bolilla[pos[1]])
				{
					printf ("3 EN COLUMNA! DE LA COLUMNA: %d",largo+1);
					printf ("\nJUGADAS NECESARIAS PARA 3 EN COLUMNA: %d\n\n",jugadas);	
					
					posJugadas(bandera,x+1,1); //MODIFICAR MAS ADELANTE (POSIBLEMENTE AGREGAR AL CARTON O AL JUGADOR UN ATRIBUTO "BANDERA" 		
					x=99;
					j=99;
					largo=99;
				}
			}
		}
			}
		}
	}
		}
		}
	}
	}

	}//Fin While	

}//FIN TRES EN COLUMNA

void bingo(int vector[][5],int bolilla[],int jugadas, int bandera[]) //COMPRUEBA SI HAY BINGO
{
	int x,i,j;
	int intentos=0;

	
		for (x=0;x<=jugadas;x++)
		{
			for(i=0;i<3;i++)
			{
				for (j=0;j<5;j++)
				{							
					if (vector[i][j]==bolilla[x])
					{
						intentos ++;
						
						if (intentos==15)
						{
							printf ("BINGOOOOOOOOOOO!!!!");	
							printf ("\nLAS JUGADAS PARA EL BINGO: %d\n\n",x+1);																			
							posJugadas(bandera,x+1,2);
													
							x=99;
							i=99;
							j=99;
						}
					}		
				}
			}
		}	
}

//METODOS SET
void setJugadas(Carton x, int pos, int valor)
{
	x->posJugadas[pos] = valor;
}

void setPuntaje(Carton x, float puntaje)
{
	x->puntaje = puntaje;
}

//METODOS GET
int getCarton(Carton x, int i, int j)
{
	return x->matrizCarton[i][j];
}

int getJugadas(Carton x, int posJugada)
{
	return x->posJugadas[posJugada];
}

float getPuntaje(Carton x)
{
	return x->puntaje;
}

//DESTRUCTOR
void destruirCarton(Carton x)
{
	free(x);
}
