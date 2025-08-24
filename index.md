---
layout: default
title: Image Transmission
---

# Small Rocket – Image Transmission (LoRa 434 MHz)

This project demonstrates **image transmission** for a small experimental rocket, using an **ESP32-CAM** for image capture and **Arduino MKR WAN 1300** for LoRa-based transmission and reception.  
Instead of a live video stream, the system captures **JPEG snapshots** and sends them as **255-byte fragments** over **434 MHz** LoRa.

> 🔗 Full code live in this repository on [GitHub](https://github.com/fizera-gi/TX_RX_esp32CAM_MKRWAN).

---

## 🚀 Quick Links
- 📄 **Project README**: [README.md](./README.md)  
- 📷 **ESP32-CAM (Capture + UART TX)**: [`ESP32_TX.ino`](./ESP32_TX.ino)  
- 📡 **MKR WAN (LoRa Transmitter)**: [`MKRWAN_TX.ino`](./MKRWAN_TX.ino)  
- 📥 **MKR WAN (LoRa Receiver)**: [`MKRWAN_RX.ino`](./MKRWAN_RX.ino)  
- 🧾 **Project Report (FR)**: [`Projet_thematique.pdf`](./Projet_thematique.pdf)

---

## ⚙️ Key Settings


Frequency            :   **434 MHz** 

Packet size          :  **255 bytes** 

Inter-packet delay   :  **~200–400 ms** (tuned to reduce losses & respect duty-cycle) 

Typical time per image : **~30–40 s** 

Reliability            : **~80%** 

---

## 📸 Results

- Successful reception and reconstruction of JPEG snapshots  
- Reliability ~80% after tuning delays and filtering duplicates  

<div style="display:flex; gap:16px; flex-wrap:wrap;">
  <div style="flex:1; min-width:280px;">
    <img src="{{ '/assets/first_successful_pic.jpg' | relative_url }}" alt="First successful received image" style="width:100%; max-width:400px; border-radius:8px;">
    <p align="center"><em>First successful received image</em></p>
  </div>
  <div style="flex:1; min-width:280px;">
    <img src="{{ '/assets/photo_receiverd1.jpg' | relative_url }}" alt="Another captured image" style="width:100%; max-width:400px; border-radius:8px;">
    <p align="center"><em>First successful captured image</em></p>
  </div>
</div>

---

## 👥 Team & Context
My teammate and I developed this project as part of the **EIRSPACE** association team.  
It was carried out as a **thematical project** during our **second year (Master 1 equivalent)** at **ENSEIRB-MATMECA** (Bordeaux, France).

---

## 📬 Contact / Credits
- **Authors:** Fatimazahra El Meady, Anass El Kabbaj  
- **Association:** EIRSPACE 2025
