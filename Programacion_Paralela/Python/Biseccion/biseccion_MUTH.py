import numpy as np
from threading import Thread as Th
from numpy import linspace,sin,cos,pi
import time
import math
import os
import biseccion as bt

os.system("clear")
print("------------------------------------------------")
print("---------------METODO DE BISECCION--------------")
print("------------------USANDO HILOS------------------")
print("------------------------------------------------")
print('Digite los extremos del intervalo: ')
a = float(input('Extremo derecho: '))
b = float(input('Extremo izquierdo: '))
sol = float(abs(b-a)/4)
nth = 4

threads = []

for i in range(4):
    lizq = a+(i*sol)
    lder = a+(i+1)*sol
    t = Th(target = bt.bisecc, args=(lizq,lder))
    threads.append(t)
    t.start()
    t.join()    