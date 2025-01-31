int brightness = 0;
int fadeAmount = 5;
int appstate = 0;
int compteur = 0;

const int LED_PIN = 13;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (appstate == 0) {
    led_on_task();
    appstate = 1;
  } else if (appstate == 1) {
    blink_task();
    appstate = 2;
  } else if (appstate == 2) {
    fade_task();
    appstate = 3;
  } else if (appstate == 3) {
    led_off_task();
    appstate = 0;
  }
}

//fonction pour allumer la led
void led_on_task() {
  Serial.println("Allume – 2255309");
  digitalWrite(LED_PIN, HIGH);
  delay(2000);
}

//fonction du clignotement
//=PLAFOND.MATH(2255309 /2) + 1 = 11276[5]6 (5 fois)
void blink_task() {
  Serial.println("Clignotement – 2255309");
  for (int i = 0; i < 5; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(250);
    digitalWrite(LED_PIN, LOW);
    delay(250);
  }
}

//fonction de la variation
void fade_task() {
  Serial.println("Variation – 2255309");
  for (brightness = 255; brightness >= 0; brightness -= fadeAmount) {
    analogWrite(LED_PIN, brightness);
    delay(40);
  }
}

// fonction du eteint
void led_off_task() {
  Serial.println("Éteint – 2255309");
  digitalWrite(LED_PIN, LOW);
  delay(2000);
}
