#include <iostream>
#include <fstream>
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

float pi (int count){
    float dpi = 0.0,t;
    #pragma omp parallel for simd private(t) reduction(+:dpi)
        for (int i=0; i<count;i++){
            t = (float)((i+0.5)/count);
            dpi += 4.0/(1.0+t*t);
            dpi /= count;
            
        }
        return dpi;
}

int main(int argc, char*argv[]){
    int count;
    count = int(argv[1]);
    float cpi =0;


}