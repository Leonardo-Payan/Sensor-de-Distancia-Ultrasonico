//

int trig = 9;
int echo = 8;
int led = 13;
int buzzer = 10;

long tiempo;
int distancia;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  tiempo = pulseIn(echo, HIGH);
  distancia = tiempo / 58.2;
  
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia < 20 && distancia > 0) {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(distancia * 10);
    
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    delay(distancia * 10);
  } else {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }
  
  delay(100);
}