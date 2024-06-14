def dividiendo(num,veces):
    for i in range(veces):
        num = int(num/2)
        print(num)
    return num
numero = 1
while numero != 0:
    numero = input("Ingrese un numero: ")

    while not numero.isdigit():
        numero = input("Ingreselo nuevamente: ")

    numero = int(numero)
    if numero == 0: break
    
    veces = input("Ingrese las veces que quiere dividir: ")
    while not veces.isdigit():
        veces = input("Ingrese nuevamente las veces: ")
    veces = int(veces)
    
    print(dividiendo(numero,veces))

