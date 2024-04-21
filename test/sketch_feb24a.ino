#include "Moteur.h"

const int tour = 2048;  // change this to fit the number of steps per revolution

Moteur myStepper(tour, D2, D3, D4, D5);

void setup() {
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);

  // initialize the serial port:

  Serial.begin(9600);
  Serial.println(myStepper.delai);

}


void loop() {

  // step one revolution  in one direction:
  Serial.println(myStepper.delai);
  Serial.println("clockwise");

  myStepper.step(tour/4);

  delay(500);

  Serial.println(myStepper.pas_actuel);
  // step one revolution in the other direction:

  Serial.println("counterclockwise");

  myStepper.step(-tour/4);

  delay(500);

}
