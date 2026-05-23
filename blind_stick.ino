#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER_PIN 3
#define LED_PIN 5

long duration;
int distance;

void setup() {

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= 20){

    digitalWrite(LED_PIN, HIGH);

    tone(BUZZER_PIN, 1000);
    delay(100);
    
    noTone(BUZZER_PIN);
    delay(100);
  }
  else if (distance > 20 && distance <=50) {

    digitalWrite(LED_PIN, HIGH);

    tone(BUZZER_PIN, 700);
    delay(300);

    noTone(BUZZER_PIN);
    delay(300);
  }
  else if (distance > 50 && distance <=100) {
    digitalWrite(LED_PIN, HIGH);

    tone(BUZZER_PIN, 500);
    delay(600);

    noTone(BUZZER_PIN);
    delay(600);
  }

  else {

    digitalWrite(LED_PIN, LOW);

    noTone(BUZZER_PIN);

    delay(200);
  }
}
