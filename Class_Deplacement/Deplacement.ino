#include "Arduino.h"
#include "Deplacement.h"


Deplacement * test = new Deplacement();
void setup() {
  // put your setup code here, to run once:
  (*test).init();

}

void loop() {
  // put your main code here, to run repeatedly:
  (*test).avancer(10);
  delay(100);
  (*test).tourner_gauche(90);
  delay(100);
  (*test).avancer(10);
  delay(100);
  (*test).tourner_gauche(90);
  delay(100);
  (*test).avancer(10);
  delay(100);
  (*test).tourner_gauche(90);
  delay(100);
  (*test).avancer(10);
  delay(100);
  (*test).tourner_gauche(90);
  delay(10000);

}
