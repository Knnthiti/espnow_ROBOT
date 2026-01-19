#include"espnow_ROBOT.h"

uint8_t status_ESPNOW_Sent;

void OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status) {
#ifdef ESPNOW_Debug
  Serial.print(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success " : "Delivery Fail ");
#endif
  if(status == ESP_NOW_SEND_SUCCESS){
  status_ESPNOW_Sent = 1;
 }else{
  status_ESPNOW_Sent = 0;
 }
}

void ESPNOW_ROBOT ::Setup_send_ESPNOW() {

  WiFi.mode(WIFI_STA);

  esp_wifi_set_channel(5, WIFI_SECOND_CHAN_NONE);

  // Initilize ESP-NOW
  if (esp_now_init() != ESP_OK) {
#ifdef ESPNOW_Debug
    Serial.println("Error initializing ESP-NOW");
#endif
    Initializing_Send = 0;
    return;
  }else{
    Initializing_Send = 1;
  }

  // Register the send callback
  esp_now_register_send_cb(OnDataSent);

  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, sizeof(broadcastAddress));
  peerInfo.channel = 5;
  peerInfo.encrypt = false;

  // Add peer
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
#ifdef ESPNOW_Debug
    Serial.println("Failed to add peer");
#endif
    Add_peer = 0;
    return;
  }else{
    Add_peer = 1;
  }
}

void ESPNOW_ROBOT ::Sendvalue_ESPNOW(uint8_t* data, size_t len) {
  esp_err_t result = esp_now_send(broadcastAddress, data, len);

  if (result == ESP_OK) {
#ifdef ESPNOW_Debug
    Serial.println(" | Sending confirmed");
#endif
    Sending = 1;
  } else {
#ifdef ESPNOW_Debug
    Serial.println(" | Sending error");
#endif
    Sending = 0;
  }
}

void ESPNOW_ROBOT ::Setup_receive_ESPNOW() {
  // Set ESP32 as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  esp_wifi_set_channel(5, WIFI_SECOND_CHAN_NONE);

  // Initilize ESP-NOW
  if (esp_now_init() != ESP_OK) {
#ifdef ESPNOW_Debug
    Serial.println("Error initializing ESP-NOW");
#endif
    Initializing_Receive = 0;
    return;
  }else{
    Initializing_Receive = 1;
  }
}