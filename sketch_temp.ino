#include <WiFiNINA.h>
#include <ThingSpeak.h>
#include <DHT.h>

#define DHTPIN 7         // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11    // DHT 11

char SSID[] = "Tenda_0A9868";                //wi-fi network SSID
char PASW[] = "1122334455";                  //Wi-fi network password
unsigned long channelId = 2251042;           //thingspeak channel ID
const char *APIkey = " ERU8L9QRKM5ZBVZF ";   //thingspeak API key

WiFiClient clients;
DHT dht(7, DHT11);

void setup() {                          //initiate the serial communication, initialize the DHT sensor, and then attempt to connect to the specified Wi-Fi network. It waits in a loop until a successful connection is established and then prints a message.
  Serial.begin(9600);
  dht.begin();

  while (WiFi.status() != WL_CONNECTED) {
  Serial.print("Connecting to WiFi:  ");
  Serial.println(SSID);
  WiFi.begin(SSID, PASW);

}

Serial.println("WiFi Connected Succesfully");

  ThingSpeak.begin(clients); //initalizing the thingspeak library

}

void loop() {
  
  float temperature = dht.readTemperature();
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  ThingSpeak.writeField(channelId, 1, temperature, APIkey);   //  sends the temperature read and printed to your ThingSpeak channel
  Serial.print("Data sent succesfully: ");
  

  // // Check if any reads failed and exit early (to try again).
  // if (isnan(temperature)) {
  //   Serial.println(" data loss! ");
  //   return;
  // }

  

delay(2000);
  
}
