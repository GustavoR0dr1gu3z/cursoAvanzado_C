//Programa 1 Hilos en c++
//Se ejecuta con: g++ -o nombreEjecutable archivo.cpp -lpthread

#include <pthread.h>
#include <cstdio>
#include <iostream>

using namespace std;

void* print_xs (void* unused){

    while(1)
        cout<<"X";
    return NULL;
}


int main(){

    pthread_t th1;

    pthread_create(&th1, NULL, &print_xs, NULL);

    while(1)
        cout<<"0";
    return 0;


}