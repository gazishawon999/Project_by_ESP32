# 🏠 Multilayered Smart Home Security System

This repository contains projects and lab work for the **Microcontroller and Interfacing Laboratory** course.  
The main highlight is a real-time embedded system project based on **ESP32**, focusing on a **multi-layered smart home security and automation system**.

---

## 🎓 Course Information

- **Course Name:** Microcontroller and Interfacing Laboratory  
- **Instructor:** Tazeen Tasneem  
- **University:** Eastern University  
- **Department:** Computer Science & Engineering  

---

## 🔍 Project Overview

### 🚀 Multilayered Smart Home Security System

This project is an **automated smart home solution** integrating multiple sensors, security layers, and control mechanisms.  
It is designed to enhance **home security, automation, and intelligent monitoring** using ESP32.

---

## 🧠 Key Features

### 🚗 1. Smart Parking Gate System
- Uses **dual IR sensors** to calculate vehicle speed  
- Displays speed on **16x2 I2C LCD**  
- If speed exceeds limit:
  - ❌ Gate remains closed  
  - ⚠️ Warning displayed on LCD  
  - 🔊 Buzzer alarm activated  
- If speed is within limit:
  - ✅ Gate opens (Servo motor: 0° → 90°)  
  - ✅ LCD shows “Welcome”  

---

### 🔐 2. Smart Door Lock System
- Controlled via **mobile application** (Arduino-based interface)  
- User enters **PIN (1234)** from mobile  

#### ✅ Correct PIN:
- Door unlocks (Servo rotates 0° → 90°)  
- Countdown shown on LCD (3 → 2 → 1 → 0)  
- Door automatically locks again  

#### ❌ Wrong PIN:
- Access denied  
- After 3 consecutive wrong attempts:
  - 🔊 Buzzer alarm activated  
  - ⚠️ Warning message displayed on LCD  

---

### 💡 3. Automatic Room Lighting
- Uses **Ultrasonic Sensor**  
- Detects human presence  
- Automatically turns **LED light ON/OFF**  

---

### 🚨 4. Laser Security System
- Laser-based intrusion detection system  
- Detects unauthorized movement behind walls/secure area  

#### Triggered Action:
- 🔊 Buzzer alarm activated  
- ⚠️ Warning displayed on LCD  

---

### ⚡ 5. Priority-Based Alarm System
- If multiple events occur simultaneously:
  - 🚨 **Laser security alarm gets highest priority**  
  - Other alarms are suppressed  

---

## 🛠️ Components Used

### 🔌 Hardware
- ESP32 Microcontroller  
- IR Sensors (2 units)  
- Ultrasonic Sensor  
- Laser Sensor Module  
- Servo Motors  
- 16x2 I2C LCD Display  
- Buzzer  
- LED  

---

### 💻 Software & Tools
- Arduino IDE  
- Wokwi Simulation Platform  
- Embedded C / Arduino Programming  

---

## 📊 Simulation

- Project circuits and testing were implemented using **Wokwi Online Simulator**  
- Includes:
  - Sensor integration  
  - Logic testing  
  - Real-time behavior simulation  

---

## 📂 Repository Contents

- 📁 Simulation images (Wokwi)  
- 📜 Complete project source code  
- 📑 Project documentation  

---

## 👥 Team Members

- **SHAWON GAZI** (ID: 241400031)  
- **TAMANNA AHMED TASIN** (ID: 241400033)  
- **AL-SHARIF** (ID: 241400037)  

---

## 🎯 Project Goals

- Develop a **multi-layered security system**  
- Implement **real-time sensor-based automation**  
- Integrate **IoT and mobile-based control**  
- Enhance system reliability using **priority-based logic**  

---

## 🚀 Future Improvements

- Mobile app with advanced UI  
- Cloud-based monitoring system  
- Facial recognition security  
- Integration with IoT platforms  

---

## 📌 Note

This project is developed for **academic and educational purposes only** as part of coursework.

---

## 👤 Maintained By

**Shawon Gazi**  
Department of Computer Science & Engineering  
Eastern University  
