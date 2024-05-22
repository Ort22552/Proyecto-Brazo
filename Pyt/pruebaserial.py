import time
import serial
modo="0"
Potb="000"
Pot1="000"
Pot2="000"
Potg="000"
Posicion="0"
Cambio="0"
def test(Value):
    match int(Value):
        case 0:
            print("Modo=", modo)
        case 1:
            print("Potb=", Potb)
        case 2:
            print("Pot1=", Pot1)
        case 3:
            print("Pot2=", Pot2)
        case 4:
            print("Potg=", Potg)
        case 5:
            print("Posicion=", Posicion)
        case _:
                print("nel mi loko")
serialArduino= serial.Serial("COM3",9600, timeout=0.05)
time.sleep(1)
while True:
    cad = serialArduino.readline().decode('ascii')
    if len(cad)==15:
        modo=cad[0]
        Potb=cad[1], cad[2], cad[3]
        Potb=''.join(Potb)
        Pot1=cad[4], cad[5], cad[6]
        Pot1=''.join(Pot1)
        Pot2=cad[7], cad[8], cad[9]
        Pot2=''.join(Pot2)
        Potg=cad[10], cad[11], cad[12]
        Potg=''.join(Potg)
        Posicion=cad[13]
        Cambio = cad[14]
        print("Modo=", modo)
        print("Potb=", Potb)
        print("Pot1=", Pot1)
        print("Pot2=", Pot2)
        print("Potg=", Potg)
        print("Posicion=", Posicion)
        print("Cambio=", Cambio)
        test(Cambio)
