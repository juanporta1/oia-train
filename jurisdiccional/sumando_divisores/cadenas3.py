def cadenas_divisores(numeros):
    totales = []
    for numero in numeros:
        if numero != 0:
            divisor_actual = numero
            total = 0
            total += divisor_actual
            print(numero)
            while divisor_actual != 1:
                count = 2
                while True:
                    if divisor_actual % count == 0:
                        divisor_actual /= count
                        divisor_actual = int(divisor_actual)
                        break
                    else:
                        count += 1
                total += divisor_actual
                print(divisor_actual)
            totales.append(total)
    return totales

num = 1
while True:
    num = 1
    numeros = []
    while num != 0:
        num = input("Ingrese un numero: ")

        while not num.isdigit():
            num = input("Ingreselo nuevamente: ")
        num = int(num)
        if num == 0: break 
        numeros.append(num)
        
    
    if len(numeros) == 0: break
    
    print(cadenas_divisores(numeros))