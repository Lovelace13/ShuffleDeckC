#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

/* 
*
* author: Katiuska Marín S.
*
*/

typedef enum direccion { forward, reverse } way;

typedef struct listdouble{ 
	int data;
	struct listdouble *next;
	struct listdouble *prev;
} number;

int isEmpty(const number *n){
	return( n == NULL);
}

int contador(number *h){
	int cont = 1;
	while(h->next != NULL){
		h = h -> next;
		cont++;
	}
	return cont;
}

number *last_n(number *h)
{
	number *ultimo = NULL;
	while(h->next != NULL){
		ultimo = h;
		h = h->next;
	}
	ultimo = h;
	return ultimo;
} 

number *first_n(number *h)
{
	number *primero =NULL;
	while(h->prev != NULL){
		primero = h;
		h = h -> prev;
	}
	primero = h;
	return primero;
}

void print_list(number *h, char *title){
	int cont = 0;
	printf("%s\n", title);
	printf("[ ");
	while( h != NULL){
		if(cont == 20 || cont == 40 || cont == 60 || cont == 80 || cont == 100 || cont == 120
			|| cont == 140 || cont == 160 || cont == 180) // row with 20 elements
			printf("\n");
		printf("%d ", h->data);
		h = h->next;
		if(h == NULL)
			printf("]\n");
		cont++;
	}
}

number* create_head(int n){
	number* head = (number *) malloc(sizeof(number));
	head -> data = n;
	head -> next = NULL;
	head -> prev = NULL;
	return head;
}

number* push_number(int d, number* head)
{
	if( head == NULL)
		return NULL;

	number* new = create_head(d);
	new -> next = head;
	head -> prev = new;
	return new;
}

number* fill_doubleList(number* head, int loop)
{
	number *list = head;

	for(int i = 1; i < loop; i++){
		int data = rand()%50;
		list = push_number(data, list);
	}

	return list;
}

number* remove_number(number* l, int f){
	number* previous = l->prev;
	number* siguiente = l->next;

	l->next = NULL;
	l->prev = NULL;

	free(l);

	if ( f == forward){ //Indicate the direcction
		if(previous != NULL){
			previous -> next = siguiente;		
		}
		if(siguiente != NULL){
			siguiente -> prev = previous;	
			return siguiente;
		}	

		siguiente = previous;
		return siguiente;		
	}else{

		if(previous != NULL){
			previous -> next = siguiente;		
		}
		if(siguiente != NULL){
			siguiente -> prev = previous;	
			return previous;	
		}
		previous = siguiente;
		return previous;	
	}
}

number* remove_sameData(number* list)
{
	for(int i = 0; i < 50; i++)
	{
		int flag = 0; // indicate that is the first time
		while(list->next != NULL)
		{		
			if((i == list->data && flag == 0))
			{
				flag = 1; //first time, the next time is delete
				list = list->next;	
			}
			else if(i == list->data && flag == 1)
			{
				list = remove_number(list, forward);
			}
			else
			{
				list = list->next;
			}					
			
		}
		if(list->data == i)
			list = remove_number(list, forward);
		list = first_n(list);
	}
	return list;	
}

int main(){

	/* Initializes random number generator */
	time_t t;
	srand((unsigned) time(&t));
	int init = rand()%50;

	/* Initializes nodes */
	number *head = NULL;
	head = create_head(init);
	
	number *list = fill_doubleList(head, 200);
	print_list(list, "	Lista de 200 elementos:");
	printf("total de elementos: %d\n", contador(list));

	number *list_reduced = remove_sameData(list);
	print_list(list_reduced, "	Lista without equeal elements:");
	printf("total de elementos de nueva lista: %d\n", contador(list));
	/* Leak Sanitizer */
	while( list_reduced != NULL){
		number *nodo = list_reduced;
		list_reduced = list_reduced->next;
		free(nodo);
	}

	return 1;
}