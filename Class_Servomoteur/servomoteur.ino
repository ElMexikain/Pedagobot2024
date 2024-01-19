
#include "servomoteur.h"
#include "Arduino.h"

Deplacement *test = new servomoteur();

void setup() {
 

  (*test).init();

}

void loop() {
  
  (*test).stylo_1;
  delay(5000);
  (*test).stylo_2;
  delay(5000);

}