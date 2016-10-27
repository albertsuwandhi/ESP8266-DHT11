// Date : 1 June 2016
// Desc : DHT11 Testing

#include "DHT.h"
#define DHTPIN D6    
#define DHTTYPE DHT11  
#define LED D5
DHT dht(DHTPIN, DHTTYPE);
int ledstate=LOW;
void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println("DHT11 test!");
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  //int analogread=analogRead(A0);
  //Serial.print("Analog: ");
  //Serial.print(analogread);
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
  //ledstate=!ledstate;
  //digitalWrite(LED,ledstate);
  //analogWrite(D7,analogread);
  delay(500);
}
