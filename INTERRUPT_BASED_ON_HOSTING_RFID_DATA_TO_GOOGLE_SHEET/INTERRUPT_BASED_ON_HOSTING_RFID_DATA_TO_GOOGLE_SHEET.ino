#include <SPI.h>
#include <MFRC522.h>
#include <WiFi.h>
#include <HTTPClient.h>
#define SS_PIN 5  
#define RST_PIN 14 
#define WIFI_SSID "your_wifi_ssid"
#define WIFI_PASSWORD "your_wifi_password"
#define GOOGLE_SCRIPT_URL "https://script.google.com/macros/s/your_script_id/exec"
MFRC522 mfrc522(SS_PIN, RST_PIN);
WiFiClient client;
void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  connectToWiFi();
}
void loop() {
  String tagID = readRFID();
  if (tagID != "") {
    Serial.println("Tag ID: " + tagID);
    sendDataToGoogleSheets(tagID);
    delay(1000); 
  }
}
void connectToWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}
String readRFID() {
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial()) {
    return "";
  }
  String tagID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    tagID.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
    tagID.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  mfrc522.PICC_HaltA();
  return tagID;
}

void sendDataToGoogleSheets(String tagID) {
  if (client.connect(GOOGLE_SCRIPT_URL, 80)) {
    String postData = "tagID=" + tagID;
    client.println("POST " + String(GOOGLE_SCRIPT_URL) + " HTTP/1.1");
    client.println("Host: " + String(GOOGLE_SCRIPT_URL));
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.println("Connection: close");
    client.print("Content-Length:");
    client.println(postData.length());
    client.println();
    client.println(postData);
  }
}
