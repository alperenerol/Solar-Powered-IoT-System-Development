#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>
#include <WiFi.h>
#include <PubSubClient.h>

#define DHTPIN 19
//my sensor is DHT11 type
#define DHTTYPE DHT11
//create an instance of DHT sensor
DHT sense(DHTPIN, DHTTYPE);

 // Time to sleep (in seconds):
const int sleepTimeS = 3660;
const char* ssid = "SU-IoT";
//const char* password =  "alpelike";
const char* mqttServer = "uskumru.sabanciuniv.edu";
const int mqttPort = 1883;
long imagTemp;
char msg[50];
byte mac[6];
 
WiFiClient espClient;
PubSubClient client(espClient);
 
void setup() {
 
  Serial.begin(115200);
  WiFi.begin(ssid); // To connect a wireless network with ssid and password use WiFi.begin(ssid, password);
   
  pinMode(DHTPIN, INPUT);
  sense.begin();
     
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  
  Serial.println("Connected to the WiFi network");

  Serial.println("WiFi began");
    WiFi.macAddress(mac);  //I find my ESP device`s MAC address to conenct SU-IoT network in campus
    
    Serial.print("MAC: ");
    Serial.print(mac[0],HEX);
    Serial.print(":");
    Serial.print(mac[1],HEX);
    Serial.print(":");
    Serial.print(mac[2],HEX);
    Serial.print(":");
    Serial.print(mac[3],HEX);
    Serial.print(":");
    Serial.print(mac[4],HEX);
    Serial.print(":");
    Serial.println(mac[5],HEX);
 
  client.setServer(mqttServer, mqttPort);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP32Client")) {
 
      Serial.println("connected");
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
     
}
 
void loop() {      
      
      float t = sense.readTemperature();
    //  float h = sense.readHumidity();
      if (isnan(t)) {
        Serial.println("Failed to read from DHT sensor!");
        delay(100);
        return;
      }
             
       char buffer[10];
       dtostrf(t,0, 0, buffer);
       //client.publish("ESPTemp", buffer);  
       client.publish("ESPTemp1", buffer);     
       Serial.print("Temperature: ");
       Serial.print(buffer);
       Serial.println(" *C ");

//       dtostrf(h,0, 0, buffer);
//       client.publish("ESP", buffer);       
//       Serial.print("Humidity: ");
//       Serial.print(buffer);
//       Serial.println(" % ");
       
     
      Serial.println("ESP32 in sleep mode");
      ESP.deepSleep(sleepTimeS * 1000000);    
          
}
