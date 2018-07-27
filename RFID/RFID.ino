#include "MFRC522.h"
#define RST_PIN  D3 // 設定RST腳位
#define SS_PIN  D8 // 設定SDA腳位 
MFRC522 mfrc522(SS_PIN, RST_PIN); // 宣告一個MFRC522的物件
void setup() {
  Serial.begin(115200);    // 初始化序列埠
  SPI.begin();           // 初始化SPI
  mfrc522.PCD_Init();    // 初始化MFRC522
}
void loop() { 
  if ( ! mfrc522.PICC_IsNewCardPresent()) {     // 持續讀入附近有無卡片
    delay(500);
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {     // 選擇訊號強的一張卡片並讀取資料
    delay(500);
    return;
  }
  // 秀出卡片資料
  Serial.print(F("Card UID:"));
  dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
  Serial.println();
}
// 讀取卡號的HEX值
void dump_byte_array(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}
