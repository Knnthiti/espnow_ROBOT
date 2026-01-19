# espnow_ROBOT

https://youtu.be/bEKjCDDUPaU?si=O57gGXYSjQzTxcqc

A simple and efficient wrapper library for **ESP-NOW** communication on ESP32. Designed specifically for **Robot Controllers**, handling complex data structures (Joysticks, Buttons, Bitfields) with ease.

---

## ⚠️ CRITICAL: Board Version Requirement

**This library requires ESP32 Board Version 2.0.17**

Newer versions (3.0.0+) introduced breaking changes to the ESP-NOW API.
If you compile with version 3.x, you will encounter errors.

### How to install the correct version:
1. Open Arduino IDE.
2. Go to **Tools** > **Board** > **Boards Manager...**
3. Search for **"esp32"** (by Espressif Systems).
4. Select version **2.0.17** from the dropdown list.
5. Click **Install**.

---

## Usage Guide (3 Steps)

To establish communication, the **Sender (Controller)** must know the **MAC Address** of the **Receiver (Robot)**.

### Step 1: Get the Receiver's MAC Address
To find the MAC address of your Receiver board, open the example file included in this library.

**Navigate to:** `File` > `Examples` > `espnow_ROBOT` > `Scanner_addr_espnow`

1. Upload the code to your **Receiver ESP32**.
2. Open the **Serial Monitor** (set baud rate to **115200**).
3. **Copy the MAC Address** displayed (e.g., `F4:65:0B:59:3B:C8`).

---

### Step 2: Receiver Code (The Robot)
Next, upload the receiver code to your **Robot ESP32**.

**Navigate to:** `File` > `Examples` > `espnow_ROBOT` > `ESP_NOW_receive`

1. Upload this code to the Robot board.
2. This code is pre-configured to listen for incoming commands using the `ControllerData` structure.

---

### Step 3: Sender Code (The Controller)
Finally, upload the sender code to your **Remote Controller ESP32**.

**Navigate to:** `File` > `Examples` > `espnow_ROBOT` > `ESP_NOW_send`

1. Open the file.
2. **IMPORTANT:** Look for the line: `uint8_t broadAddress[6] = { ... };`
3. **Replace the address** inside the brackets with the MAC Address you found in **Step 1**.
4. Upload the code to your Controller board.

---

## Function Library

| Function | Description |
| :--- | :--- |
| `ESPNOW_ROBOT(mac_addr)` | Constructor for **Sender**. Pass the receiver's MAC address array. |
| `ESPNOW_ROBOT()` | Constructor for **Receiver**. |
| `Setup_send_ESPNOW()` | Initializes ESP-NOW as Station, sets Channel 5, pairs with receiver. |
| `Sendvalue_ESPNOW(*data, len)` | Sends the struct data. <br>Usage: `joy.Sendvalue_ESPNOW((uint8_t*)&data, sizeof(data));` |
| `Setup_receive_ESPNOW()` | Initializes ESP-NOW as Station, sets Channel 5 for listening. |
