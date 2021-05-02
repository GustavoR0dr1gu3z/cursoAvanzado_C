// Hecho por: Gustavo Rodriguez Calzada
// El dia: 16 de Abril 2021
// Se compila como: g++ -o version2Compilado version2Compilado.cpp -fopenmp
// Se ejecuta como: ./version2Compilado

// Resultado: OpenMP version: 201511
// Resultado: Version 4.5

#include <unordered_map>
#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char* argv[]){
unordered_map<unsigned, string > map {
    {200505,"2.5"},{200805,"3.0"},{201107,"3.1"},{201307,"4.0"},{201511,"4.5"},{201811,"5.0"},{202011,"5.1"}};
    cout<<"Tienes instalado la versión de OpenMp: "<<map.at(_OPENMP)<<".\n";
    return 0;
}
