// Hecho por: Gustavo Rodriguez Calzada
// El dia: 16 de Abril 2021

// Se compila como: g++ -o versionOpenMPCompilado versionOpenMP.cpp -fopenmp
// Se ejecuta como: ./versionOpenMPCompilado

// Resultado: OpenMP version: 201511
// Resultado: Version 4.5

#include <stdio.h>

int main(int argc, char **argv){
    printf("OpenMP version: %d", _OPENMP);
    return 0;
}