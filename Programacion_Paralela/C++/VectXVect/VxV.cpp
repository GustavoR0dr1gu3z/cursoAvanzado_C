#include <iostream>
#include <fstream>
#include <cstring>
#include <pthread.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int z;
float A [1000];
float B [1000];

struct parms{
    int a;
    int b;
};

void* mult(void* parameters);
void llenarVector(string nombre);

int main(){
    string vA = "vect1.txt";
    llenarVector(vA);

    string vB = "vect2.txt";
    llenarVector(vB);

    pthread_t hilos[4];
    struct parms hilos_args[4];

    hilos_args[0].a = 0;
    hilos_args[0].b = 254;
    pthread_create(&hilos[0], NULL, &mult, &hilos_args[0]);

    hilos_args[1].a = 255;
    hilos_args[1].b = 499;
    pthread_create(&hilos[1], NULL, &mult, &hilos_args[1]);

    hilos_args[2].a = 500;
    hilos_args[2].b = 754;
    pthread_create(&hilos[2], NULL, &mult, &hilos_args[2]);

    hilos_args[3].a = 755;
    hilos_args[3].b = 999;
    pthread_create(&hilos[3], NULL, &mult, &hilos_args[3]);

    pthread_join(hilos[0], NULL);
    pthread_join(hilos[1], NULL);
    pthread_join(hilos[2], NULL);
    pthread_join(hilos[3], NULL);

    cout<<"Resultado VxV: "<<z<<endl;
    return 0;
}

void* mult(void* parameters){
    struct parms* p = (struct parms*) parameters;
    pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
    int x, y, c, i;
    x = p -> a;
    y = p -> b;
    c = 0;

    for(i = x; i <= y; i++){
        c += A[i]*B[i];
    }
    pthread_mutex_lock(&mtx);
    z = z + c;
    pthread_mutex_unlock(&mtx);
    return NULL;
}

void llenarVector(string nombre){
    int num;
    int i = 0;
    char cadena[13];
    strcpy(cadena, nombre.c_str());
    ifstream input_file(cadena);

    while(input_file >> num){
        A[i] = num;
        B[i] = num;
        i++;
    }
    input_file.close();
}