#define hell_pin D5
#define relay_pin D6
void setup() {
  Serial.begin(115200);
  pinMode(hell_pin , INPUT);
  pinMode(relay_pin , OUTPUT);
  digitalWrite(relay_pin , LOW);
}

void loop() {
  int sta;
  sta = digitalRead(hell_pin);
  Serial.println(sta);
  sta = (sta+1)%2;
  digitalWrite(relay_pin , sta);
  delay(1000);
}
//1 is high, 0 is low, if sensed, report as 0 
