#include "DFRobot_ESP_PH.h"
#include <EEPROM.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// === Pin Definitions ===
#define ONE_WIRE_BUS 23  // The pin where your DS18B20 data wire is connected
#define PH_PIN 35        // The pin where your pH sensor is connected

// === Constants ===
#define ESPADC 4096.0    // The ESP32 ADC resolution value
#define ESPVOLTAGE 3300  // The ESP32 voltage supply value

DFRobot_ESP_PH ph;  // pH sensor object

// === Temperature Sensor Setup ===
OneWire oneWire(ONE_WIRE_BUS);  // Create OneWire instance
DallasTemperature tempSensor(&oneWire);  // Create DallasTemperature instance

float voltage, phValue, temperature = 25.0;

void setup()
{
  Serial.begin(115200);
  EEPROM.begin(32);       // Needed to store calibration K in EEPROM
  ph.begin();             // Initialize pH sensor
  
  tempSensor.begin();     // Initialize the temperature sensor
}

void loop()
{
  static unsigned long timepoint = millis();
  if (millis() - timepoint > 4000U) // Time interval: 1s
  {
    timepoint = millis();

    // === Read Voltage ===
    voltage = analogRead(PH_PIN) / ESPADC * ESPVOLTAGE; // Read voltage from analog pin and convert to volts (for ESP32)
    Serial.print("Voltage (V): ");
    Serial.println(voltage, 4);

    // === Read Temperature ===
    tempSensor.requestTemperatures();  // Request temperature from sensor
    temperature = tempSensor.getTempCByIndex(0);  // Get temperature (Celsius) from the first sensor
    Serial.print("Temperature: ");
    Serial.print(temperature, 1);
    Serial.println(" °C");

    // === Read pH Value ===
    phValue = ph.readPH(voltage, temperature); // Convert voltage to pH with temperature compensation
    Serial.print("pH Value: ");
    Serial.println(phValue, 4);
  }

  // Calibration process via Serial CMD
  ph.calibration(voltage, temperature);
}

float readTemperature()
{
  // This function is no longer needed since we are using the DallasTemperature library
  // You can remove this function if you don't need it anymore
}
