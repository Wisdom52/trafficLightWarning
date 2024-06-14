int Red = 2;
int Yellow = 1;
int Green = 0;
int piezoBuzzer = 3;
int photoResistor = 4;



void setup() {
  pinMode(Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(piezoBuzzer, OUTPUT);
  pinMode(photoResistor, INPUT);
  
  digitalWrite(Red, LOW);
  digitalWrite(Yellow, LOW);
  digitalWrite(Green, LOW);
  
  Serial.begin(9600);
}


void loop() {
  int photoValue = analogRead(photoResistor);
  Serial.println(photoValue); 
  
  if (photoValue < 500) {
    tone(piezoBuzzer, 1000);
    delay(200);
    noTone(piezoBuzzer);
  }
  
 turningOn(Red, 1000);
 turningOn(Yellow, 1000);
 turningOn(Green, 1000);
}

void turningOn(int ledPin, int duration) {
  if (ledPin == Red) {
    digitalWrite(Red, HIGH);
    digitalWrite(Yellow, LOW);
    digitalWrite(Green, LOW);
  } 
  else if (ledPin == Yellow) {
    digitalWrite(Red, LOW);
    digitalWrite(Yellow, HIGH);
    digitalWrite(Green, LOW);
  } 
  else if (ledPin == Green) {
    digitalWrite(Red, LOW);
    digitalWrite(Yellow, LOW);
    digitalWrite(Green, HIGH);
  } 
  else {
    digitalWrite(Red, LOW);
    digitalWrite(Yellow, LOW);
    digitalWrite(Green, LOW);
  }
  delay(duration);
}
