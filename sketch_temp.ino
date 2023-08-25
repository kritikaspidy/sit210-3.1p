#include <WiFiNINA.h>
#include <ThingSpeak.h>
#include <DHT.h>

#define DHTPIN 7         // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11    // DHT 11

char SSID[] = "Tenda_0A9868";         
char PASW[] = "1122334455";     
unsigned long channelId = 2251042;   
const char *APIkey = " ERU8L9QRKM5ZBVZF ";

WiFiClient clients;
DHT dht(7, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();

  while (WiFi.status() != WL_CONNECTED) {
  Serial.print("Connecting to WiFi:  ");
  Serial.println(SSID);
  WiFi.begin(SSID, PASW);

}

Serial.println("WiFi Connected Succesfully");

  ThingSpeak.begin(clients);

}

void loop() {
  
  float temperature = dht.readTemperature();
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  ThingSpeak.writeField(channelId, 1, temperature, APIkey);
  Serial.print("Data sent succesfully: ");
  

  // // Check if any reads failed and exit early (to try again).
  // if (isnan(temperature)) {
  //   Serial.println(" data loss! ");
  //   return;
  // }

  

delay(2000);
  
}
