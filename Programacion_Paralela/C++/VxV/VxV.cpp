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

char nombre1[20]="vectorA.txt";
char nombre2[20]="vectorB.txt";

int f=10;//numero de filas de matriz
int c=1;//numeor de columnas de vector(siempre es 1)

int fv=10;//nuemro de filas de vector
int cv=1;//numeor de columnas de vector(siempre es 1)

int** total;

//definicion de structura de hilos
struct operacion{
     int inicio=0,fin=0;//parametros de inicio y fin
};


//prototipos de funciones
int multiplica();
void* suma(void* parameters);

void crear_vector(int fil, int col, char *nom);
int** leer_vector(int fil, int col, char *nom);

int** llenar_vector(int fil, int col);
void imp_vector(int **vector);

void imprime(int **matriz);



int main(){
	t0=clock();
	srand(time(NULL));

     	struct operacion record[4];//estructura definida con 4 espacios
	//crear_matriz(f, c);
	
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
	//v1=llenar_vector(fv,cv);//se llena el vector
	//m1=llenar_vector(fv,cv);

	crear_vector(fv,cv,nombre1);
	crear_vector(fv,cv, nombre2);

	
	v1=leer_vector(fv, cv, nombre1);
	m1=leer_vector(fv, cv, nombre2);

	
	//m1=leer_matriz(f,c);	//se leen los datos del archivo   ORIGINAL Y BORRAR
	//imp_vector(v1);		//imrpime los datos del vector
	cout<<"vector 1: \n";
	imp_vector(v1);

	cout<<"vector 2: \n";
	imp_vector(m1);

	
	int mult = multiplica();
	cout<<"Resultado:"<< mult<<" \n";
	//imrpime el vector resultante



	cout<<"\n";
	t1=clock();
	double time =(double(t1-t0)/CLOCKS_PER_SEC);
	cout<< "tiempo de ejecucion = "<< time << endl;
	return 0;	
}

//funcion multiplica() 'multiplica una matriz por 1 vector'
int multiplica(){
	
	int suma=0;
	//for que multiplica la matriz y el vector y despues guarda la suma en mtre[][]
	for (int a = 0; a < cv; a++){
		for (int i = 0; i < f; i++){
			
			for (int j = 0; j < c; j++){
				suma = suma + m1[j][a]*v1[i][j];			
			}
		}	
	}
	
	printf("\n");
	return suma;//regresamos mtre
}


void crear_vector(int fil, int col, char* nom){

	ofstream file (nom);
	for (int i = 0; i < fil; i++) {
		
		int r=rand();
		for (int j = 0; j < col; j++) {
			r=rand() % 10;
			//file<< 1 <<" ";  para numeros random
			file<< 1 <<" ";
		}
		file<<"\n";
	}
  	file.close();
	return;

}

int** leer_vector(int fil, int col, char* nom){
	printf("Leer matriz de un archivo\n");	
	int y=0;//variable que contendra el valor de lo escrito

	FILE* ar;//se crea y se abre el archivo ar en modo lectura
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

//llena un vector con el numero que se desee
int** llenar_vector(int fil, int col){
	int **v = new int*[fil];
	for (int i = 0; i < fil; i++) {
		v[i] = new int[col];
		for (int j = 0; j < col; j++) {
			v[i][j]=1;//llena el vector con los datos 
		}
	}
	return v;//regresa vector v[][]
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

void imp_vector(int **vector){
	
	for (int i = 0; i < fv; i++) {
		printf(" %d", vector[i][0]);//se imprimen los datos de V
		printf("\n");
	}
	printf("\n");
}

void imprime(int **matriz){
			//se imprime la matriz que paso por parametro
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d", matriz[i][j]);//se imprimen todos los datos
		}
		printf("\n");
	}
	printf("\n");
}
