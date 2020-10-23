#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
* The ADT list
* author: Katiuska Marín Suárez
* 22 -Oct - 2020
*/

typedef struct list
{
	int data;
	struct list *next;
}list;

int isEmpty(const list *l){
	return (l == NULL);
}

list *create_list(int d){
	list * head = malloc(sizeof(list));
	head -> data = d;
	head -> next = NULL;
	return head;
}

list* add_to_front(int d, list* h){
	list* head = create_list(d);
	head -> next = h;
	return head;
}

list* array_to_list(int d[], int size){
	list* head = create_list(d[0]);
	int i;
	for( i = 1; i < size; i++){
		head = add_to_front(d[i], head);
	}
	return head;
}

void print_list(list *h, char *title){
	printf("%s\n", title);
	while( h != NULL){
		printf("%d :", h -> data);
		h = h -> next;
	}
}

int count(list *h){
	while( h != NULL){
		cnt++;
		h = h -> next;
	}
	return cnt;
}

void delete(list *elem, list **prev, list **h){
	if( *hd = *prev)
		*hd = elem -> next;
	else
		(*prev) -> next = elem -> next;
	free(elem);
}

void delete_list(list *h){
	list *temp;
	if ( h != NULL){
		temp = h;
		delete_list(h = h -> next);
		free(temp);
	}
}

void concat(list *h1, list *h2){
	
	if ( h1 != NULL)
		h1 = h2;
	else if(h1 -> next == NULL)
		h1 -> next = h2;
	else
		concat(h1 -> next, h2);
}
