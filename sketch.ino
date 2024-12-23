#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define BLYNK_TEMPLATE_ID "TMPL3QJQivVfd"
#define BLYNK_TEMPLATE_NAME "soil nutrition"
#define BLYNK_AUTH_TOKEN "8iOetXtUc-o9pArkfeM0FSC6W2ewjBoV"
#define SOIL_MOISTURE_PIN 32
#define TEMPERATURE_PIN 34
#define HUMIDITY_PIN 35
#define NITROGEN_PIN 33
#define PHOSPHORUS_PIN 36
#define POTASSIUM_PIN 39
#define WATER_PUMP_LED 12
#define BUZZER_LED 13

LiquidCrystal_I2C LCD(0x27, 16, 2);

const int moistThreshold = 60;

void setup() {
  Serial.begin(115200);
  pinMode(WATER_PUMP_LED, OUTPUT);
  pinMode(BUZZER_LED, OUTPUT);
  LCD.init();
  LCD.backlight();
}

void loop() {
  int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);
  int temperatureValue = analogRead(TEMPERATURE_PIN);
  int humidityValue = analogRead(HUMIDITY_PIN);
  int nitrogenValue = analogRead(NITROGEN_PIN);
  int phosphorusValue = analogRead(PHOSPHORUS_PIN);
  int potassiumValue = analogRead(POTASSIUM_PIN);

  float soilMoisture = map(soilMoistureValue, 0, 4095, 0, 100);  // Simulated soil moisture
  float temperature = map(temperatureValue, 0, 4095, -10, 50);   // Simulated temperature
  float humidity = map(humidityValue, 0, 4095, 0, 100);          // Simulated humidity
  float nitrogen = map(nitrogenValue, 0, 4095, 0, 100);          // Simulated nitrogen
  float phosphorus = map(phosphorusValue, 0, 4095, 0, 100);      // Simulated phosphorus
  float potassium = map(potassiumValue, 0, 4095, 0, 100);        // Simulated potassium

  // Display values on LCD
  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("Moist: ");
  LCD.print(soilMoisture);
  LCD.print("%");

  LCD.setCursor(0, 1);
  LCD.print("Temp: ");
  LCD.print(temperature);
  LCD.print("C");

  delay(2000);  // Display for 2 seconds

  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("Hum: ");
  LCD.print(humidity);
  LCD.print("%");

  LCD.setCursor(0, 1);
  LCD.print("N: ");
  LCD.print(nitrogen);
  LCD.print("%");

  delay(2000);  // Display for 2 seconds

  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("P: ");
  LCD.print(phosphorus);
  LCD.print("%");

  LCD.setCursor(0, 1);
  LCD.print("K: ");
  LCD.print(potassium);
  LCD.print("%");

  delay(2000);  // Display for 2 seconds

  // Control water pump and buzzer
  if (soilMoisture < moistThreshold) {
    digitalWrite(WATER_PUMP_LED, HIGH);
    digitalWrite(BUZZER_LED, HIGH);
  } else {
    digitalWrite(WATER_PUMP_LED, LOW);
    digitalWrite(BUZZER_LED, LOW);
  }

  delay(1000); // Update every second
}


