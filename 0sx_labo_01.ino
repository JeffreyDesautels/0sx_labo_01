const int LED_PIN = 13;
int brightness = 0;
int fadeAmount = 5;
int appstate = 0;

void allume() {

}

void clignotement() {

}

void variation() {

}

void eteint() {

}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(250);
  digitalWrite(LED_PIN, LOW);
  delay(250);
}
