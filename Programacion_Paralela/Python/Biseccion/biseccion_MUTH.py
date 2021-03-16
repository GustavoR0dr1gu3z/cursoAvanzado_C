import threading as Th
import biseccion as Bi

threads = []

for i in range(4):
    inicio = float(i*1 + 0.5)
    fin = inicio+1
    t = Th.Thread(target=Bi.bisec, args=(inicio,fin))
    threads.append(t)
    t.start()
    t.join()