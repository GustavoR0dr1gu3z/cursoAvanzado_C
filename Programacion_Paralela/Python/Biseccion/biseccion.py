import numpy as np
from numpy import linspace, sin, cos, pi 
import time 
import math
import os
import funcion 

def bisecc(a,b):
    a1 = a
    b1 = b
    
    if(a > b):
        a = b1
        b = a1
        print("Se invirtieron los extremos")
    iteraciones = 20
    k = 0
    tolerancia = float(pow(10,-5))
    error = float(1.0)
    fa = funcion.f0(a)
    fb = funcion.fp(b)
    print(fa)
    print(fb)

    if(fa * fb >= 0):
        if(fa == 0 or fb == 0):
            print("Hay una raiz en a o en b")
        else:
            print("En este intervalo no hay raiz")
    else:
        print("Calculando la raiz...")
        print("ITERACION \t a \t b \t c\t fc \t")
        
        while(k < iteraciones and error > tolerancia):
            k += 1
            c = float((a+b)/2.0)
            fc = funcion.f0(c)
            print('k, \t,a, \t,b, \t,c, \t,fc')

            if(fa * fc > 0):
                a = c
                fa = fc 
            else:
                b = c
                fb = fc
            error = abs((b-a)/2)
        print('La raiz es: ',c)








