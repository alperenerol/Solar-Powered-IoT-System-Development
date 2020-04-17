import paho.mqtt.client as mqtt
import time
import datetime
import logging

def on_connect(client, userdata, flags, rc):
    if rc == 0:

        print("Connected to broker")

        global Connected  
        Connected = True  

    else:

        print("Connection failed")


def on_message(client, userdata, message):
    now = datetime.datetime.now()
    if now.hour == 0 :  # this if deletes all values in text file at a certain day time.
        f = open("tempdata.txt", "w")        
        f.close()
        topic = message.topic
        msg = str(message.payload.decode("utf-8"))
        f = open("tempdata.txt", "a")
        f.write(msg + "\n")  
        f.close()
        print(now.hour)
        print("Message Received topic=" + topic + " message =" + msg)
    else: 

       topic = message.topic
       msg = str(message.payload.decode("utf-8"))
       f = open("tempdata.txt", "a")
       f.write(msg + "\n")  # we write the text file with incoming messages from mqtt in here.
       # f.truncate(0) for deleting 0th cursor value
       f.close()
       print("Message Received topic=" + topic + " message =" + msg)


Connected = False  

broker_address = "uskumru.sabanciuniv.edu"  # Broker address
port = 1883  # Broker port


client = mqtt.Client("Python")  # create new instance

client.on_connect = on_connect  # attach function to callback
client.on_message = on_message  # attach function to callback

client.connect(broker_address, port=port)  # connect to broker

client.loop_start()  # start the loop

while Connected != True:  # Wait for connection
    time.sleep(0.1)

client.subscribe("ESPTemp1")

try:
    while True:
        time.sleep(1)

except KeyboardInterrupt:
    print("exiting")

    client.disconnect()
    client.loop_stop()