#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define LDR_PIN 34     // ESP32: chân analog từ 32–39
#define MQ_PIN 35

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(LDR_PIN, INPUT);
  pinMode(MQ_PIN, INPUT);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  int lightValue = analogRead(LDR_PIN);
  int gasValue = analogRead(MQ_PIN);

  Serial.print("Nhiet do: ");
  Serial.print(t);
  Serial.print(" *C | Do am: ");
  Serial.println(h);

  Serial.print("Anh sang: ");
  Serial.println(lightValue);

  Serial.print("Khoi: ");
  Serial.println(gasValue);

  delay(1000);
}
