#include <math.h>
#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include<time.h>
#include<fstream>
#include <omp.h>
#include<cstdio>
#include<cstdlib>

using namespace std;
unsigned t0, t1;


//declaramos  los 2 vectores como variables globales
int **v1;
int **m1;

char nombre1[20]="matrizA.txt";
char nombre2[20]="matrizB.txt";

int f=10;//numero de filas de matriz
int c=10;//numero de columnas de matriz

int fv=10;//nuemro de filas de vector
int cv=10;//numeor de columnas de vector(siempre es 1)

int** total;

//definicion de structura de hilos
struct operacion{
     int inicio=0,fin=0;//parametros de inicio y fin
};


//prototipos de funciones
int** multiplica();
void* suma(void* parameters);

void crear_matriz(int fil, int col, char* nom);
int** leer_matriz(int fil, int col, char *nom);

void imprime(int **matriz);



int main(){
	srand(time(NULL));
	t0=clock();

     	struct operacion record[4];//estructura definida con 4 espacios
	
	
	int numval=1000; //valor del intervalo
	int hilos=numval/4;//optenemos el numero de hilos 


	int val = 0;//hacemos el recorrido de los hilos hasta sus limites
	for (int i = 0; i < 4;i++){
		record[i].inicio = val;
		val = val + hilos;
		if(i == 3){
			record[i].fin = val;
		}else{
			record[i].fin = val-1;
		}
	}

 	pthread_t th[4];//se crean los 4 hilos 
	for(int i = 0; i < 4; i++){
		pthread_create(&th[i], NULL, &suma, &record[i]);
		pthread_join(th[i], NULL);//se da orden con la funcion join
	}

	//llamado de funciones

	crear_matriz(f, c, nombre1);
	v1=leer_matriz(fv,cv,nombre1);  //se llena el vector

	printf("Matriz A\n");		
	imprime(v1);

	
	crear_matriz(f, c,nombre2);	
	m1=leer_matriz(f,c,nombre2);	//se leen los datos del archivo

	printf("Matriz B\n");
	imprime(m1);		//imprime los datos de la matriz

	
	int **mult = multiplica();
	imprime(mult);	//imrpime el vector resultante


	cout<<"\n";
	t1=clock();
	double time =(double(t1-t0)/CLOCKS_PER_SEC);
	cout<< "tiempo de ejecucion = "<< time << endl;
	return 0;	
}

//funcion multiplica() 'multiplica una matriz por 1 matriz'
int** multiplica(){
	cout<<"Resultado: \n";
	int **matriz = new int*[f];//matriz 

	for (int i = 0; i < f; i++) {//for que crea la matriz dinamica
		matriz[i] = new int[c];
	}

	int **mtre = new int*[f];//mtre es la matriz que devuelve la funcion

	for (int i = 0; i < f; i++){
		mtre[i] = new int[cv];//crea nuevas columnas
	}


	for (int a = 0; a < cv; a++){
		for (int i = 0; i < f; i++){
			int suma=0;
			for (int j = 0; j < c; j++){
				suma += m1[j][a]*v1[i][j];			
			}

			matriz[i][a]=suma;
		}	
	}
	
	printf("\n");
	return matriz;//regresamos mtre
}


void crear_matriz(int fil, int col, char* nom ){
		
  	ofstream file (nom);
	for (int i = 0; i < fil; i++) {
		
		int r=rand();
		for (int j = 0; j < col; j++) {
			r=rand() % 10;
			//file<< r<<" "; para numeros random
			file<< 1<<" ";
		}
		file<<"\n";
	}
  	file.close();
	return;

}

int** leer_matriz(int fil, int col, char *nom){
	//printf("Leer matriz de un archivo\n");	
	int y=0;//variable que contendra el valor de lo escrito

	FILE* ar;//se crea y se abre el archivo ar en modo lectura
    	//ar = fopen("matrizA.txt", "rt");
	ar = fopen(nom, "rt");
	
	int **m = new int*[fil];//matriz que contendra los datos del archivo
	for(int i=0; i<fil; i++){
		m[i] = new int[col];
		for(int j=0; j<col; j++){
			fscanf(ar, "%d", &y);//se leen los datos y 
			m[i][j]=y;  	     //se llenan en la matriz m
		}
	}

	fclose(ar);//se cierra el archivo
	return m;//manda m	
}



//funcion suma
void* suma(void* parameters){
	//estructura con los parametros de operacion
	struct operacion* p = (struct operacion*) parameters;
	
	for(int i = p->inicio; i <= p->fin; ++i){//for con inicio 
		for(int j = p->inicio; j <= p->fin; ++j){//y el fin de parametros		
		}
	}
	printf("\n");
}


void imprime(int **matriz){
			//se imprime la matriz que paso por parametro
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			printf(" %d", matriz[i][j]);//se imprimen todos los datos
		}
		printf("\n");
	}
	printf("\n");
}
