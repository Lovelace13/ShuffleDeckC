#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//gcc -o deck barajas.c -fsanitize=address -g


typedef enum palos{ corazon, diamante, trebol, espada} palo;

typedef struct card
{
	int palo;
	int pip;
} carta;

typedef struct deck
{
	carta FirstCard;
	carta next;
} deck;

void shuffleDeck(carta *baraja);
void printCards(carta card);

int main()
{
	/* Initializes random number generator */
	time_t t;
	srand((unsigned) time(&t));

	carta *baraja = (carta *) malloc(52*sizeof(carta));

	shuffleDeck(baraja);

	//deck *mano = (deck *) malloc(7*sizeof(deck))
	
	/* Print the first hand (hand = mano) */
	for(int i = 0; i<7; i++){
		carta c = baraja[i];
		printCards(c);
	}

	//free(mano);
	free(baraja);

	return 0;
}

void printCards(carta card){
	palo p = card.palo;
	int n = card.pip;
	switch(p){
		case(corazon):
			if(n == 12){
				printf("[Q de corazon ]\n");
				break;
			}
			if(n == 11){
				printf("[J de corazon ]\n");
				break;
			}
			if(n == 13){
				printf("[K de corazon ]\n");
				break;
			}
			printf("[%d de corazon ]\n", n);
			break;
		case(diamante):
			if(n == 11){
				printf("[J de diamante]\n");
				break;
			}
			if(n == 12){
				printf("[Q de diamante]\n");
				break;
			}
			if(n == 11){
				printf("[K de diamante]\n");
				break;
			}
			printf("[%d de diamante]\n", n);
			break;
		case(trebol):
			if(n == 10){
				printf("[J de trebol  ]\n");
				break;
			}
			if(n == 11){
				printf("[Q de trebol  ]\n");
				break;
			}
			if(n == 12){
				printf("[K de trebol  ]\n");
				break;
			}
			printf("[%d de trebol  ]\n", n);
			break;
		case(espada):
			if(n == 10){
				printf("[J de espada  ]\n");
				break;
			}
			if(n == 11){
				printf("[Q de espada  ]\n");
				break;
			}
			if(n == 12){
				printf("[K de espada  ]\n");
				break;
			}
			printf("[%d de espada  ]\n", n);
			break;
		default: printf("ERROR");
	}
}

void shuffleDeck(carta *baraja){
	
	palo palos;
	int pip;
	int Full = 0;

	int cont = 0; int contCor = 0; int contDia = 0; int contTre = 0; int contEsp = 0;

	int fillC = 0; int fillD = 0; int fillT = 0; int fillE = 0;

	//fill cards
	while(Full == 0)
	{
		carta c;
		palos = rand()%4;
				
		switch(palos){
			case(corazon):
				if(contCor < 13){
					pip = rand()%12 + 1;
					++contCor;
					c.palo = corazon;
					c.pip = pip;
					baraja[cont] = c;
					cont++;	
				}
				else
				{
					fillC = 1;
				}
				break;
			case(diamante):
				if(contDia < 13){
					pip = rand()%12 + 1;
					++contDia;
					c.palo = diamante;
					c.pip = pip;
					baraja[cont] = c;
					cont++;	
				}
				else
				{
					fillD = 1;
				}
				break;
			case(trebol):
				if(contTre < 13){
					pip = rand()%12 + 1;
					++contTre;
					c.palo = trebol;
					c.pip = pip;
					baraja[cont] = c;
					cont++;	
				}
				else
				{
					fillT = 1;
				}
				break;
			case(espada):
				if(contEsp < 13){
					pip = rand()%12 + 1;
					++contEsp;
					c.palo = espada;
					c.pip = pip;
					baraja[cont] = c;
					cont++;	
				}
				else
				{
					fillE = 1;
				}
				break;
			default:
				printf("Baraja llena");

		}
		if(fillD == 1 && fillC == 1 && fillE == 1 && fillT == 1)
			Full = 1;

		//baraja[cont] = c;
	}
}