#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
*	Program: Calculate average and Max from file 
*	author: Katiuska Marín
*	date: 15/10/2020
*/

#define MAX 20

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
	rewind(file);
	while(fscanf(file, "%d", &d[*size]) != EOF)
		(*size)++;
}

void print_data(int d[], int size){
	int i;
	for( i = 0; i < size; i++){
		printf("%d ", d[i]);
		if((i+1)%10 == 0)
			printf("\n");
	}
}

double average(int d[], int size){
	int i;
	double avg = 0.0;
	int s = size - 1;
	for( i = 1; i < size; i++){
		avg += d[i];
	}

	return (avg/s);
}

int max_int(int d[], int size){
	int i;
	int max = 0;
	for( i = 1; i < size; i++){
		if(d[i]>max)
			max = d[i];
	}

	return max;
}
/* Abra y lea un archivo de numeros enteros en un array que se crea con el primer numero como size, luego calcuse su promedio 
y su maximo como int . Imprimz todo esto de manera ordenada en la pantalla y en un archivo de salida llamado answer-hw3*/

int main(int argc, char *argv[]){
	
	int maximo; 
	int sz = MAX; /* Tamaño del archivo */
	double promedio;

	FILE *ifp, *ofp;
	int data[MAX] = {100, 0};

	if(argc != 2){
		printf("Falta argumentos\n");
		exit(1);
	}

	ifp = fopen(argv[1], "r");	
	read_data(ifp, data, &sz);
	fclose(ifp);

	printf("my file %s content: ", argv[1]);
	
	print_data(data, sz);
	
	data[sz] = max_int(data, sz);
	promedio = average(data, sz);
	char a[]= "Average score was: ";

	printf("\n");
	printf("%s %10f \n\n", a, average(data, sz));
	printf("MAX int is: %d\n\n", max_int(data, sz));

 	printf("Guardando data en file: 'answer-hw3'\n");
 	
 	char text1[] = "Number of elements:";
	char text2[] = "Max: ";
	
	ofp = fopen("answer-hw3.txt", "w+");
	
	//fwrite(data, 4, sizeof(data), ofp);

	for(int i = 0; i <= sz; i++){
		if( i ==  0){
			
			printf("%s %d\n", text1, data[i]);
			fwrite(text1, 1, sizeof(text1), ofp);
			fwrite(&data[i], sizeof(int), 1, ofp);
			putc('\n', ofp);
		}
		if( i == sz){
			printf("%s %d\n", text2, data[sz]);
			fwrite(text2, 1, sizeof(text2), ofp);
			fwrite(&data[i], sizeof(int), 1, ofp);
			putc('\n', ofp);
		}
		if( i != 0 && i != sz){
			printf("%d\n", data[i]);
		}
		fwrite(&data[i], sizeof(int), 1, ofp);
		putc(' ', ofp);
	}
	
	fwrite(a, 1, sizeof(a), ofp);
	putc(promedio, ofp);
	
	fclose(ofp);
	return 0;
}