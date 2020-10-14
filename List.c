#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* To compile you can use: */
/* gcc -o elementos List.c -fsanitize=address */

/* 
*
* author: Katiuska Marín S.
*
*/

typedef struct listPeriodicTable{ 
	char *name; 
	char *Symbol;
	double peso;
	struct listPeriodicTable *next;
} element;

int isEmpty(const element *l){
	return( l == NULL);
}

void print_list(element *h, char *title){
	printf("%s\n", title);
	int cont = 1;
	while( h != NULL){
		printf("[* %d - %f, %s, %s *] \n", cont, h->peso, h->Symbol, h->name);
		h = h->next;
		cont++;
	}
}

element* create_list(char *n, char *s, double p){
	element* head = malloc(sizeof(element));
	head -> name = n;
	head -> Symbol = s;
	head -> peso = p;
	head -> next = NULL;
	return head;
}

element* add_to_front(char *n, char *s, double p, element* h){
	element* head = create_list(n, s, p);
	head -> next = h;
	return head;
}

element* array_to_list(char **n, char **s, double *p){
	element* head = create_list(n[0], s[0], p[0]);
	int i;
	for( i = 1; i < 10; i++){
		head = add_to_front(n[i], s[i], p[i], head);
	}
	return head;
}

int main(){

	element *head = NULL;
	head = malloc(sizeof(element));
	//printf("sizeof(element) = %lu\n", sizeof(element)); //unsigned long

	/* example element */
	head = create_list("Hydrogen", "H",1.008);
	
	printf("[* 1 - %f, %s, %s *] \n\n", head->peso, head->Symbol, head->name);

	/* lista de elementos */
	char *name[10] = {"Hydrogen ", "Helium   ", "Lithium  ", "Beryllium", "Boron    ", "Carbon   ", "Nitrogen ", "Oxygen   ", 
	"Fluorine ", "Neon     "};
	char *symbol[10] = {"H ", "He", "Li", "Be", "B ", "C ", "N ", "O ", "F ", "Ne"};
	double weight[10] = {1.008, 4.003, 6.941, 9.012, 10.811, 12.011, 14.007, 15.999, 18.998, 20.180};

	element *list_init = NULL;
	list_init = malloc(sizeof(element)); 
	list_init = array_to_list(name, symbol, weight);
	print_list(list_init, "Elementos de la tabla");


	/* Leak Sanitizer */
	free(head);
	while( list_init != NULL){
		element *nodo = list_init;
		list_init = list_init->next;
		free(nodo);
	}
	free(list_init);
	return 1;
}