#define val_pin D5
#define relay_pin D6
//接通是1
void setup() {
  Serial.begin(115200);
  pinMode(val_pin , INPUT);
  pinMode(relay_pin , OUTPUT);
  digitalWrite(relay_pin , LOW);
}

void loop() {
  int val;
  val = digitalRead(val_pin);
  Serial.println(val);
  if( val == 0)
  {
    Serial.println("open");
    digitalWrite(relay_pin , HIGH);
  }
  else
  {
    Serial.println("close");
    digitalWrite(relay_pin , LOW);
  }
  delay(1000);
}
