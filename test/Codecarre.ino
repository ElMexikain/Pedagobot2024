#include <Deplacement.h>
Deplacement carre(0,0);
unsigned long debut;
unsigned long fin;
unsigned long distance;

Deplacement * robot = new Deplacement();
void setup() {
  // put your setup code here, to run once:
  (*robot).init();
  Serial.begin(9600);

}

void loop() {
    robot.avancer(distance);
    robot.tourner_gauche(90);
    robot.avancer(distance);
    robot.tourner_gauche(90);
    robot.avancer(distance);
    robot.tourner_gauche(90);
    robot.avancer(distance);
}
