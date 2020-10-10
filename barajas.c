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

	carta *baraja = (carta *) malloc(53*sizeof(carta));

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
			printf("[%d de corazon]\n", n);
			break;
		case(diamante):
			printf("[%d de diamante]\n", n);
			break;
		case(trebol):
			printf("[%d de trebol]\n", n);
			break;
		case(espada):
			printf("[%d de corazon]\n", n);
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
				if(contCor < 14){
					pip = rand()%13 + 1;
					contCor++;
					c.palo = corazon;
					c.pip = pip;
					cont++;	
				}
				else
				{
					fillC = 1;
				}
				break;
			case(diamante):
				if(contDia < 14){
					pip = rand()%13 + 1;
					contDia++;
					c.palo = diamante;
					c.pip = pip;
					cont++;	
				}
				else
				{
					fillD = 1;
				}
				break;
			case(trebol):
				if(contTre < 14){
					pip = rand()%13 + 1;
					contTre++;
					c.palo = trebol;
					c.pip = pip;
					cont++;	
				}
				else
				{
					fillT = 1;
				}
				break;
			case(espada):
				if(contEsp < 14){
					pip = rand()%13 + 1;
					contEsp++;
					c.palo = espada;
					c.pip = pip;
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
		
		baraja[cont] = c;
	}
}