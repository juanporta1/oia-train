import random
from copy import copy
def generala(a,b,c,d,e):
    valores = []
    numeros = [a,b,c,d,e]
    #? Suma de los dados
    puntos = [0,0,0,0,0,0]
    for numero in numeros:
        puntos[numero -1] += numero
        
    for punto in puntos:
        valores.append(punto)
    
    #? Escalera
    
    cantidades = []
    for i in range(1,7):
        cantidad = numeros.count(i)
        cantidades.append(cantidad)

    cantidades1 = copy(cantidades)
    cantidades1.pop(5)
    cantidades2 = copy(cantidades)
    cantidades2.pop(0)
    cantidades3 = copy(cantidades)
    cantidades3.pop(1)
    casos = (cantidades1,cantidades2,cantidades3)
    escalera = True
     
    for caso in casos:
        if not caso.count(0):
            escalera = True
        else:
            escalera = False
            
    if escalera: valores.append(20)
    else: valores.append(0)
            
        
       
    #? Full y Poker y Generala
    
    dos_iguales = False
    tres_iguales = False
    cuatro_iguales = False
    cinco_iguales = False
    for i,punto in enumerate(puntos):
        i += 1
        if punto == 0:
            continue
        elif punto / 2 == i:
            dos_iguales = True
        elif punto / 3 == i:
            tres_iguales = True
        elif punto / 4 == i:
            cuatro_iguales = True
        elif punto / 5 == i:
            cinco_iguales = True
            
    
    if dos_iguales and tres_iguales: valores.append(30)
    else: valores.append(0)
    
    if cuatro_iguales or cinco_iguales: valores.append(40)
    else: valores.append(0)
    
    if cinco_iguales: valores.append(50)
    else: valores.append(0)

    return valores

print(generala(3,3,3,3,3))
print(generala(1,5,6,3,4))
print(generala(3,2,2,3,2))