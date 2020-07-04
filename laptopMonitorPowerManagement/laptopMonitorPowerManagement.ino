#define slowStart 3
#define nineVIn 4
#define nineVOut 0
#define twoVOut 1

void setup() {
  pinMode(slowStart, OUTPUT);
  pinMode(nineVIn, INPUT);
  pinMode(nineVOut, OUTPUT);
  pinMode(twoVOut, OUTPUT);
}

void loop() {

  if (!digitalRead(nineVIn)) digitalWrite(twoVOut, LOW);
  else digitalWrite(twoVOut, HIGH);

  digitalWrite(nineVOut, !digitalRead(nineVIn));

  if (millis() == 500)
    digitalWrite(slowStart, HIGH);

}
