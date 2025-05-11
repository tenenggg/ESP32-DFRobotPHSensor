# 🌱 ESP32 pH and Temperature Monitoring System

This project reads water **pH levels** and **temperature** using an ESP32, DFRobot pH sensor, and DS18B20 waterproof temperature sensor. It's designed for hydroponics, aquaponics, and other water quality monitoring projects.

## 📦 Components Required

| Component                | Quantity |
|--------------------------|----------|
| ESP32 Dev Board          | 1        |
| DFRobot Analog pH Sensor | 1        |
| DS18B20 Temperature Sensor | 1        |
| 4.7kΩ Resistor (for DS18B20) | 1   |
| Breadboard + Jumper Wires| as needed|

---

## ⚙️ Circuit Diagram

| Sensor       | ESP32 Pin        |
|--------------|------------------|
| pH Sensor    | A0 (GPIO 35)     |
| DS18B20      | GPIO 23 (DATA)   |
| DS18B20 VCC  | 3.3V             |
| DS18B20 GND  | GND              |
| 4.7kΩ Resistor | Between DATA and VCC |

---

## 🧠 Libraries Required

Install the following libraries via the Arduino Library Manager:

- [DFRobot_ESP_PH](https://github.com/DFRobot/DFRobot_ESP_PH)
- OneWire by Paul Stoffregen
- DallasTemperature

---

## 🚀 Getting Started

### 1. Connect the Hardware

Connect your components to the ESP32 as shown in the circuit diagram above.

### 2. Upload the Code

- Open the Arduino IDE.
- Install the libraries listed above.
- Copy and upload the code from `main.ino`.

### 3. Open Serial Monitor

- Set baud rate to **115200**.
- You'll see voltage, temperature, and calculated pH values printed every ~4 seconds.

---

## 🔧 Calibration

To calibrate the pH sensor:

1. Open the **Serial Monitor**.
2. Prepare standard pH buffer solutions (e.g., pH 4.0 and pH 7.0).
3. Place the sensor in the solution.
4. Type the corresponding pH value in Serial Monitor (e.g., `calph4` or `calph7`) and press Enter.
5. The sensor saves calibration data in EEPROM.

---

## 🧪 Sample Output

Voltage (V): 1.6548
Temperature: 26.5 °C
pH Value: 6.7832

---

## 📝 Notes

- The analog pin resolution for ESP32 is 12-bit (0–4095).
- `ESPVOLTAGE` is 3300 mV (3.3V logic).
- EEPROM is used to store calibration data (no need to recalibrate every time).

---

## 📁 File Structure

📦 esp32-ph-temp-monitor
┣ 📜 main.ino
┣ 📜 README.md

---

## 📚 References

- [DFRobot pH Sensor Wiki](https://wiki.dfrobot.com/PH_meter_SKU__SEN0161_V2)
- [DS18B20 Datasheet](https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf)

---

## 💡 License

This project is open-source under the MIT License.
