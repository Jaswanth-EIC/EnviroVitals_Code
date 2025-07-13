# EnviroVitals Monitor

**EnviroVitals Monitor** is a wearable and portable system that monitors respiratory health and environmental conditions in real time.  
It is designed for early detection of respiratory risks due to environmental factors such as air pollution or high PM2.5 exposure.

## 📦 Features

- **Cough Detection** using onboard machine learning (Edge Impulse model on ESP32)
- **Air Quality Monitoring** (PM2.5 via PMS5003 sensor)
- **Environmental Monitoring** (Temperature & Humidity via DHT22)
- **ThingSpeak Integration** for real-time cloud data visualization

## 🔧 Hardware Components

- **ESP32** (for ML inference, data transmission, INMP441 mic input)
- **Arduino UNO** (for PMS5003 PM2.5 sensor & DHT22 sensor)
- **INMP441 Microphone** (I2S audio for cough detection)
- **PMS5003** (Particulate Matter Sensor)
- **DHT22** (Temperature & Humidity)

## 🌐 Data Fields (ThingSpeak)

| Field | Description        |
|--------|-------------------|
| Field 1 | PM2.5 (µg/m³)      |
| Field 2 | Temperature (°C)   |
| Field 3 | Humidity (%)       |
| Field 4 | Cough Detection    |

## 🚀 How It Works

1. **Arduino UNO** collects PM2.5, temperature, and humidity data and sends it to the **ESP32** via Serial.
2. **ESP32** performs audio-based cough detection using the onboard ML model.
3. All data is sent to **ThingSpeak** for cloud monitoring.

## 📁 Folders

- `ESP32_Code/` – ESP32 code with ML model integration
- `Arduino_UNO_Code/` – Arduino code for PMS5003 and DHT22 sensors

## 📊 Live Data Visualization

[**View ThingSpeak Channel**](https://thingspeak.com/channels/2994008)

## 🧑‍💻 Contributors

- Jaswanth Pudi  


