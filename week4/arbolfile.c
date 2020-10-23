#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* Honor Assigment week 4
* author: Katiuska Marín Suárez
* 22 - 10 - 2020
*/

/* ESTRUCTURAS */
#define MAX 20

typedef struct nodo {
	int data;
	struct nodo *izq;
	struct nodo *der;
}nodo;

struct nodo *root = NULL;

/* FUNCIONES */

void read_data(FILE *file, int d[], int *size);
void insertar(int x);
void printInOrder(nodo *r);
void borrar(nodo *h);
void printf_file(FILE *fptr);

int main(int argc, char *argv[]){

	/*file*/
	int sz = MAX; 
	FILE *ifp;	
	int data[MAX] = {100, 0};

	if(argc != 2){
		printf("Incomplete Arguments\n");
		exit(1);
	}
	printf("Leyendo la data del doc: %s\n", argv[1]);
	
	ifp = fopen(argv[1], "r");	
	read_data(ifp, data, &sz);
	printf_file(ifp);
	
	fclose(ifp);

	printf("\n");

	/*Input the data inside the tree*/
	int i;
	for(i = 0; i < sz; i++){
		insertar(data[i]);
	}

	printf("\nPrint inorder tree: \n");
	printInOrder(root);

	printf("\n");

	borrar(root);
	return 0;
}

void printf_file(FILE *fptr){
	int c;
	rewind(fptr); //similar seek
	while((c = getc(fptr)) != EOF){
		putc(c, stdout);
	} 
}

void read_data(FILE *file, int d[], int *size){
	*size = 0;
	rewind(file);
	while(fscanf(file, "%d", &d[*size]) != EOF)
		(*size)++;
}

void printInOrder(nodo *r){
	if (r != NULL){
		printf("%i-", r -> data);
		printInOrder(r->izq);
		printInOrder(r->der);
	}
}

void insertar(int x){
	nodo *nuevo = malloc(sizeof(nodo));
	nuevo -> data = x;
	nuevo -> izq = NULL;
	nuevo -> der = NULL;

	if( root == NULL)
		root = nuevo;
	else
	{
		nodo *prev, *temp;
		prev = NULL;
		temp = root;
		while(temp != NULL)
		{
			prev = temp;
			if( x < temp -> data)
				temp = temp -> izq;
			else
				temp = temp -> der;
		}

		if( x < prev -> data)
			prev->izq = nuevo;
		else
			prev->der = nuevo;

	}
}

void borrar(nodo *h){
	if( h != NULL){
		borrar(h -> izq);
		borrar(h -> der);
		free(h);
	}
}