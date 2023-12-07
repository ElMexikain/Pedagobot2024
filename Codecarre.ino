#include <Deplacement.h>
Deplacement carre(0,0);
unsigned long debut;
unsigned long fin;
unsigned long duree;
const int moteur_droite_pin1 = 7;
const int moteur_droite_pin2 = 6;
const int moteur_gauche_pin1 = 8;
const int moteur_gauche_pin2 = 9;
void setup() {
  pinMode(moteur_droite_pin1,OUTPUT);
  pinMode(moteur_droite_pin2,OUTPUT);
  pinMode(moteur_gauche_pin1,OUTPUT);
  pinMode(moteur_gauche_pin2,OUTPUT);
  int carre.distance = Serial.parseInt();
  int carre.angle = Serial.parseInt();
  Serial.begin(9600); 
}

void loop() {
    carre.avancer();
    carre.tourner();
    carre.avancer();
    carre.tourner();
    carre.avancer();
    carre.tourner();
    carre.avancer();
}
