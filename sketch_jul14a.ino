#include <SoftwareSerial.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

SoftwareSerial pmsSerial(4, 5); // RX, TX

void setup() {
  Serial.begin(9600);      
  pmsSerial.begin(9600);   
  dht.begin();
  delay(1000);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int pm25 = readPM25();

  if (isnan(temp)) temp = -999;
  if (isnan(hum)) hum = -999;
  if (pm25 == -1) pm25 = 999;

  // New format: PM2.5,Temp,Hum
  Serial.print(pm25);
  Serial.print(",");
  Serial.print(temp);
  Serial.print(",");
  Serial.println(hum);

  delay(30000); 
}

int readPM25() {
  if (pmsSerial.available() >= 32) {
    byte buffer[32];
    pmsSerial.readBytes(buffer, 32);

    if (buffer[0] == 0x42 && buffer[1] == 0x4D) {
      int pm25 = (buffer[12] << 8) + buffer[13];
      return pm25;
    }
  }
  return -1;
}
