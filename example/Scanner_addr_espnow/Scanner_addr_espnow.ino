void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_MODE_STA);
}

void loop() {
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());
  delay(1000);
}