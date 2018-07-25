#include "MFRC522.h"
#define RST_PIN  D3 
#define SS_PIN  D8 
#define relay_pin D2
MFRC522 mfrc522(SS_PIN, RST_PIN); 
void setup() {
  Serial.begin(115200);    
  SPI.begin();           
  mfrc522.PCD_Init();    
  pinMode(relay_pin , OUTPUT);
}
void loop() { 
  String ans = "";
  
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    delay(500);
    return;
  }
  
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    delay(500);
    return;
  }
  
  Serial.print(F("Card UID:"));
  ans = dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
  Serial.println();
  
  if(ans == "6294F28B")
    digitalWrite(relay_pin , HIGH);
  else
    digitalWrite(relay_pin , LOW);
}


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
