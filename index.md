---
layout: default
title: Home
---

# Small Rocket – Image Transmission (LoRa 434 MHz)

This project demonstrates **long-range image transmission** for a small experimental rocket, using an **ESP32-CAM** for image capture and **Arduino MKR WAN 1300** for LoRa-based transmission and reception.  
Instead of a live video stream, the system captures **JPEG snapshots** and sends them as **255-byte fragments** over **434 MHz** LoRa.

> 🔗 Full code & docs live in this repository on GitHub.

## Quick Links
- 📄 **Project README**: [README.md](./README.md)
- 📷 **ESP32-CAM (Capture + UART TX)**: [`ESP32_TX.ino`](./ESP32_TX.ino)
- 📡 **MKR WAN (LoRa Transmitter)**: [`MKRWAN_TX.ino`](./MKRWAN_TX.ino)
- 📥 **MKR WAN (LoRa Receiver)**: [`MKRWAN_RX.ino`](./MKRWAN_RX.ino)
- 🧾 **Report (FR)**: [`Projet_thematique.pdf`](./Projet_thematique.pdf)

## System Overview
