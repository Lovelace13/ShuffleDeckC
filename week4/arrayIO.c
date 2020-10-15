#include <stdio.h>
#include <stdlib.h>

/*
*	Program: double space and average
*	author: Katiuska Marín
*	date: 15/10/2020
*/

#define MAX 20;

void printf_file(FILE *fptr){
	int c;
	rewind(fptr); //similar seek
	while((c = getc(fptr)) != EOF){
		putc(c, stdout);
	} 
}

/* Me sirve para ver el tamaño del archivo */
void read_data(FILE *file, int d[], int *size){
	*size = 0;
	while(fscanf(ptr, "%d", &d[*size]) == 1)
		(*size)++;
}

void print_data(int d[], int size){
	int i;
	for( i = 0; i < size; i++){
		printf("%d\t", d[i]);
		if((i+1)%10 == 0)
			printf("\n");
	}
}

void double_space(FILE *ifp, FILE *ofp){
	int c;
	rewind(ifp);
	while((c = getc(ifp)) != EOF){
		putc(c, ofp);
		if (c == '\n')
			putc('\n', ofp);
	}
}

double average(int d[], int size){
	int i;
	double avg = 0.0;
	for( i = 0; i < size; i++){
		avg += d[i];
	}

	return (avg/size);
}

/* Abra y lea un archivo de numeros enteros en un array que se crea con el primer numero como size, luego calcuse su promedio 
y su maximo como int . Imprimz todo esto de manera ordenada en la pantalla y en un archivo de salida llamado answer-hw3*/

int main(int argc, char *argv[]){
	
	int i, sz = MAX;
	FILE *ifp, *ofp;
	int data[MAX] = {100, 0};

	if(argc != 2){
		printf("Falta argumentos\n");
		exit(1);
	}

	ifp = fopen(argv[1], "r");
	read_data(ipf, data, &sz);
	printf("my %s file as score are: ", argv[1]);
	print_data(data, sz);
	printf("\n");
	printf("Average score was %10f \n\n", average(data, sz));

	fclose(ifp);
	return 0;
}