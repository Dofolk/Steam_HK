#define touch_pin D5
#define relay_pin D6
void setup() {
  Serial.begin(115200);
  pinMode(touch_pin , INPUT);
  pinMode(relay_pin , OUTPUT);
 digitalWrite(relay_pin , LOW); 
}

void loop() {
  int sta;
  sta = digitalRead(touch_pin);
  Serial.println(sta);
  digitalWrite(relay_pin , sta);
  delay(1000);
}
