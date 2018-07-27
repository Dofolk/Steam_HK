int relay_pin = D5;
void setup() {
  Serial.begin(115200);
  pinMode(relay_pin,OUTPUT);
  digitalWrite(relay_pin , LOW);
}

void loop() {
  if(Serial.available())
  {
    char cmd = Serial.read();
    if(cmd == '1')
    {
      Serial.println("open");
      digitalWrite(relay_pin,HIGH);
    }
    else
    {
      Serial.println("close");
      digitalWrite(relay_pin,LOW);
    }
  }
  delay(500);
}
