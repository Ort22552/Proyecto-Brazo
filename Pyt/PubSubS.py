# Import standard python modules.
import sys
import time
import random
import serial


# This example uses the MQTTClient instead of the REST client
from Adafruit_IO import MQTTClient

# holds the count for the feed
global run_count

ADAFRUIT_IO_USERNAME = "ort22552"
ADAFRUIT_IO_KEY      = "aio_gJZP04ZgZ0yTCverc8UFu9XMbRfN"

# Set to the ID of the feed to subscribe to for updates.
#feedContador = 'contador'
feedModo = 'modo'
feedPotB = 'potbase'
feedPot1 = 'pot1'
feedPot2 = 'pot2'
feedPotg = 'potgarra'
feedPosicion = 'posicion'
#feeds pasados
fModo = "0"
fPotB = "000"
fPot1 = "000"
fPot2 = "000"
fPotg = "000"
fPosicion = "0"
#bloque al nano
bus='00000000000000'
#bloque del nano
modo="0"
Potb="000"
Pot1="000"
Pot2="000"
Potg="000"
Posicion="0"
cad=''

def test(Value):
    match int(Value):
        case 0:
            print("Modo=", modo)
            client.publish(feedModo, modo)
            print("Posicion", Posicion)
            client.publish(feedPosicion, Posicion)
        case 1:
            print("Potb=", Potb)
            client.publish(feedPotB, Potb)
        case 2:
            print("Pot1=", Pot1)
            client.publish(feedPot1, Pot1)
        case 3:
            print("Pot2=", Pot2)
            client.publish(feedPot2, Pot2)
        case 4:
            print("Potg=", Potg)
            client.publish(feedPotg, Potg)
        case 5:
            print("Posicion=", Posicion)
            client.publish(feedPosicion, Posicion)
        case _:
                print("nel mi loko")

def prueba(Feed, pay):
    global fModo 
    global fPotB 
    global fPot1 
    global fPot2 
    global fPotg 
    global fPosicion
    match (Feed):
        case 'modo':
            fModo=pay
            print("Posicion", fModo)
            #client.publish(feedPosicion, Posicion)
        case 'potbase':
            if (int(pay)<100) & (pay[0] != '0'):
                fPotB='0', pay[0], pay[1]
                fPotB=''.join(fPotB)
            else:
                fPotB=pay
            print("Potb=", fPotB)
            #client.publish(feedPotB, Potb)
        case 'pot1':
            if (int(pay)<100) & (pay[0] != '0'):
                fPot1='0', pay[0], pay[1]
                fPot1=''.join(fPot1)
            else:
                fPot1=pay
            print("Pot1=", fPot1)
            #client.publish(feedPot1, Pot1)
        case 'pot2':
            if (int(pay)<100) & (pay[0] != '0'):
                fPot2='0', pay[0], pay[1]
                fPot2=''.join(fPot2)
            else:
                fPot2=pay
            print("Pot2=", fPot2)
            #client.publish(feedPot2, Pot2)
        case 'potgarra':
            if (int(pay)<100) & (pay[0] != '0'):
                fPotg='0', pay[0], pay[1]
                fPotg=''.join(fPotg)
            else:
                fPotg=pay
            print("Potg=", fPotg)
            #client.publish(feedPotg, Potg)
        case 'posicion':
            fPosicion=pay
            print("Posicion=", fPosicion)
            #client.publish(feedPosicion, Posicion)
        case _:
                print("nel mi loko")
   # Define callback functions which will be called when certain events happen.
def connected(client):
    """Connected function will be called when the client is connected to
    Adafruit IO.This is a good place to subscribe to feed changes.  The client
    parameter passed to this function is the Adafruit IO MQTT client so you
    can make calls against it easily.
    """
    # Subscribe to changes on a feed named Counter.
    #print('Subscribing to Feed {0} and {1}'.format(feedLed, feedContador))
    client.subscribe(feedModo)
    client.subscribe(feedPotB)
    client.subscribe(feedPot1)
    client.subscribe(feedPot2)
    client.subscribe(feedPosicion)
    client.subscribe(feedPotg)
    print('Waiting for feed data...')

def disconnected(client):
    """Disconnected function will be called when the client disconnects."""
    sys.exit(1)

def message(client, feed_id, payload):
    """Message function will be called when a subscribed feed has a new value.
    The feed_id parameter identifies the feed, and the payload parameter has
    the new value.
    """
    print('Feed {0} received new value: {1}'.format(feed_id, payload))
    prueba(feed_id, payload)
    bus= fModo[0], fPotB[0],fPotB[1],fPotB[2], fPot1[0], fPot1[1], fPot1[2], fPot2[0], fPot2[1], fPot2[2], fPotg[0], fPotg[1], fPotg[2], fPosicion[0]
    bus=''.join(bus)
    print(bus)
    serialArduino.write(bytes(bus, 'ascii'))
#    if(feed_id == feedModo):
#             serialArduino.write(bytes('1\n', 'utf-8'))
#    if(feed_id == feedPotB):
#             serialArduino.write(bytes('0\n', 'utf-8'))
#    if(feed_id == feedPot1):
#             serialArduino.write(bytes('0\n', 'utf-8'))
#    if(feed_id == feedPot2):
#             serialArduino.write(bytes('0\n', 'utf-8'))
#    if(feed_id == feedPotg):
#             serialArduino.write(bytes('0\n', 'utf-8'))
#    if(feed_id == feedPocision):
#             serialArduino.write(bytes('0\n', 'utf-8'))



    
    


try:
    client = MQTTClient(ADAFRUIT_IO_USERNAME, ADAFRUIT_IO_KEY)

    # Setup the callback functions defined above.
    client.on_connect = connected
    client.on_disconnect = disconnected
    client.on_message = message

    # Connect to the Adafruit IO server.
    client.connect()
    client.loop_background()
              
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
                #client.publish(feedModo, modo)
                print("Potb=", Potb)
                #client.publish(feedPotB, Potb)
                print("Pot1=", Pot1)
                #client.publish(feedPot1, Pot1)
                print("Pot2=", Pot2)
                #client.publish(feedPot2, Pot2)
                print("Potg=", Potg)
                #client.publish(feedPotg, Potg)
                print("Posicion=", Posicion)
                #client.publish(feedPosicion, Posicion)
                test(Cambio)
    time.sleep(3)
        
        
except KeyboardInterrupt:
    print("Salimos del programa")
    if serialArduino.is_open:
        serialArduino.close()
    sys.exit(1)   