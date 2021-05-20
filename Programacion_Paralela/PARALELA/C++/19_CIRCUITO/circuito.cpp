/* EJERCICIO 19 -> Circuito

Hecho por: Gustavo Rodriguez Calzada
El dia: 17 de Abril del 2021


Se compila como: g++ -o circuitoCompilado circuito.cpp -fopenmp
Se ejecuta como: ./circuitoCompilado
*/
#include <iostream>
#include <stdio.h>
#include <omp.h>

using namespace std;

// Regresa 1 si el bit i de n es 1, de lo contrario regresa 0
#define EXTRACT_BIT(n, i) ((n&(1<<i))?1:0)

void test_circuito(int, int);

int main(int argc, char *argv[]){
	int i;
	int id;
	int p;
	omp_set_num_threads(10);
	p = omp_get_num_threads();
	id = omp_get_thread_num();
	#pragma omp parallel for simd
	for(i = id; i < 65536; i += p){
		test_circuito(id, i);
	}
	cout<<"El proceso " <<id<<" ha terminado"<<endl;
	fflush(stdout);
	return 0;

}

void test_circuito(int id, int z){
	int v[16];
	int i;

	for(i = 0; i < 16; i++) v[i] = EXTRACT_BIT(z,i);

	if((v[0] || v[1]) && (!v[1] || !v[3])
	    &&(v[2] || v[3]) && (!v[3] || !v[4])
	    &&(v[4] || !v[5]) && (v[5] || !v[6])
	    &&(v[5] || v[6]) && (v[6] || !v[15])
	    &&(v[7] || !v[8]) && (!v[7] || !v[13])
	    &&(v[8] || v[9]) && (v[8] || !v[9])
	    &&(!v[9] || !v[10]) && (v[9] || v[11])
	    &&(v[10] || v[11]) && (v[12] || v[13])
	    &&(v[13] || !v[14]) && (v[14] || v[15])){
		
		cout<<id<<") "<<v[0]<<v[1]<<v[2]<<v[3]<<v[4]<<v[5]<<v[6]<<v[7]<<v[8]<<v[9]<<v[10]<<v[11]<<v[12]<<v[13]<<v[14]<<v[15]<<v[16]<<endl;
		fflush(stdout);
	}


}
