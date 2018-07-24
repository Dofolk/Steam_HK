#include "MFRC522.h"
#define RST_PIN  D3 // RST-PIN for RC522 - RFID - SPI - Modul GPIO5 
#define SS_PIN  D8 // SDA-PIN for RC522 - RFID - SPI - Modul GPIO4 
#define relay_pin D2
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance
void setup() {
  Serial.begin(115200);    // Initialize serial communications
  SPI.begin();           // Init SPI bus
  mfrc522.PCD_Init();    // Init MFRC522
  pinMode(relay_pin , OUTPUT);
}
void loop() { 
  String ans = "";
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    delay(500);
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    delay(500);
    return;
  }
  // Show some details of the PICC (that is: the tag/card)
  Serial.print(F("Card UID:"));
  ans = dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
  Serial.println();
  
  if(ans == "6294F28B")
    digitalWrite(relay_pin , HIGH);
  else
    digitalWrite(relay_pin , LOW);
}

// Helper routine to dump a byte array as hex values to Serial
String dump_byte_array(byte *buffer, byte bufferSize) {
  String content = "";
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
    content.concat(String(buffer[i] < 0x10 ? "0" : ""));
    content.concat(String(buffer[i], HEX));
  }
  content.toUpperCase();
  return content;
}
