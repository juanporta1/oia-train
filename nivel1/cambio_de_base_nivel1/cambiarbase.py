def cambiar_base(numeros, base):
    nuevos_numeros = []
    for num in numeros:
        longitud = len(num)-1
        total = 0       
        cadena = ""
        for digito in num:
            
            digito = int(digito)
            total += digito * (base ** longitud)
            
            if longitud != 0:
                cadena = cadena +  f"{digito} * {base}^{longitud} + "
            else:
                cadena = cadena + f"{digito} * {base}^{longitud} = {total}"
                
            longitud -= 1
        nuevos_numeros.append(cadena)
        
    return nuevos_numeros
            

num = 1
while True:
    numeros = []
    while num != 0:
        num = input("Ingrese un numero: ")

        while not num.isdigit():
            num = input("Ingreselo nuevamente: ")
            
        numeros.append(num)
        if num == "0": break
        
    
    base = input("Ingrese la base: ")

    while not base.isdigit():
        base = input("Ingresela nuevamente: ")

    base = int(base)
    if base == 0: break
    
    print(cambiar_base(numeros,base))
    