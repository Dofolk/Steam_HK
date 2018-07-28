#define relay_pin D5
#define val_pin A0
void setup() {
  Serial.begin(115200);
  pinMode(relay_pin, OUTPUT);
  pinMode(val_pin, INPUT);
  digitalWrite(relay_pin, LOW);
}

void loop() {
  int analog_val = analogRead(A0);
  Serial.println(analog_val);
    if(analog_val > 600)
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
