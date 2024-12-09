#include <DHT.h>

// Definícia pinu, kde je pripojený DHT11
#define DHTPIN 2 // Pripojenie na digitálny pin 2
#define DHTTYPE DHT11 // Typ senzora: DHT11

// Inicializácia senzora DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Inicializácia senzora DHT11...");
  dht.begin();
}

void loop() {
  // Počkajte na stabilizáciu senzora
  delay(2000);

  // Prečítanie teploty a vlhkosti
  float vlhkost = dht.readHumidity();
  float teplota = dht.readTemperature();

  // Kontrola, či čítanie prebehlo správne
  if (isnan(vlhkost) || isnan(teplota)) {
    Serial.println("Chyba pri čítaní údajov zo senzora!");
    return;
  }

  // Zobrazenie údajov v konzole
  Serial.print("Vlhkosť: ");
  Serial.print(vlhkost);
  Serial.println(" %");
  
  Serial.print("Teplota: ");
  Serial.print(teplota);
  Serial.println(" °C");
}
