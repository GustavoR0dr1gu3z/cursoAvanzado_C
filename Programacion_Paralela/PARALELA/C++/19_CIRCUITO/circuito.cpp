/* EJERCICIO 19 -> Circuito

Hecho por: Gustavo Rodriguez Calzada
El dia: 17 de Abril del 2021


Se compila como: g++ -o circuitoCompilado circuito.cpp -fopenmp
Se ejecuta como: ./circuitoCompilado 10000
*/
#include <iostream>
#include <stdio.h>
#include <omp.h>

using namespace std;

//1 si el bit i de n es 1
//0 si el bit i de n es 0
#define EXTRACT_BIT(n, i) ((n&(1<<i))?1:0)

void test_circuito(int, int);

int main(int argc, char *argv[]){
	int i;
	int idHilos;
	int numHilos;
	int nHilosT;
	nHilosT = atoi(argv[1]);
	omp_set_num_threads(nHilosT);
	numHilos = omp_get_num_threads();
	idHilos = omp_get_thread_num();
	#pragma omp parallel for simd
	for(i = idHilos; i < 65536; i += numHilos){
		test_circuito(idHilos, i);
	}
	cout<<"ID del Hilo: " <<idHilos<<" ya terminó"<<endl;
	fflush(stdout);
	return 0;

}

void test_circuito(int idHilo, int z){
	int c[16];
	int i;

	for(i = 0; i < 16; i++){
		c[i] = EXTRACT_BIT(z,i);
	}

	if((c[0] || c[1]) && (!c[1] || !c[3]) && (c[2] || c[3]) && (!c[3] || !c[4]) && (c[4] || !c[5]) && (c[5] || !c[6])
		&&(c[5] || c[6]) && (c[6] || !c[15]) && (c[7] || !c[8]) && (!c[7] || !c[13]) && (c[8] || c[9]) && (c[8] || !c[9])
		&&(!c[9] || !c[10]) && (c[9] || c[11]) && (c[10] || c[11]) && (c[12] || c[13]) && (c[13] || !c[14]) && (c[14] || c[15])){
			cout<<idHilo<<") "<<c[0]<<c[1]<<c[2]<<c[3]<<c[4]<<c[5]<<c[6]<<c[7]<<c[8]<<c[9]<<c[10]<<c[11]<<c[12]<<c[13]<<c[14]<<c[15]<<c[16]<<endl;
			fflush(stdout);
		}


}
