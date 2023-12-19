#include "Deplacement.h"
#include "Arduino.h"
#include "math.h"
// Moteur Droit
const int  in4 = 6;//Broche sens anti-horaire
const int in3 = 7;//Broche sens horaire
// Moteur Gauche
const int in2 = 8;//Broche sens anti-horaire
const int in1 = 9;//Broche sens horaire
const int trigPin = 11; // Trigger (emission)
const int echoPin = 12; // Echo (réception)
long temps;
float distance;
void Deplacement::init(){
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
}

void Deplacement::avancer(int distance){
  // Le robot avance pendant la durée lui permettant de parcourir <distance> cm 
  int temps = abs(1000*distance/2); //en milisecondes
  if (distance > 0){
    // Le moteur gauche tourne vers l'avant
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Le moteur droit tourne vers l'avant
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(temps);
  }
  else{
    // Le moteur gauche tourne vers l'arrière
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Le moteur droit tourne vers l'arrière
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(temps);
  }
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void Deplacement::reculer(int distance){
  avancer(-distance);
}

void Deplacement::tourner_gauche(int angle){
  // Le robot tourne à gauche autour du milieu entre les deux roues 
  // Un peu difficle de savoir si le stylo restera effectivement immobile durant la rotation
  // angle en degré
  int diam = 15; //distance entre les roues en cm
  double ang_rad = abs(angle*2*M_PI/360);
  int temps = (int) 1000*ang_rad*diam/(2*2); // arc parcouru par les roues selon l'angle donné en paramètre * perimetre / (2*pi*vitesse)
  if (angle > 0){
    // La moteur gauche tourne vers l'arrière
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    // Le moteur droit tourne vers l'avant
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    delay(temps);
  }
  else{
    // de même mais dans l'autre sens
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    delay(temps);
  }
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void Deplacement::tourner_droite(int angle){
  tourner_gauche(-angle);
}

void Deplacement::calculDistance(){
// Émission d'un signal de durée 10 microsecondes
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
 
// Écoute de l'écho
temps = pulseIn(echoPin, HIGH);
// Calcul de la distance
distance = pow(temps*0.034-h*h,0.5)/2;
// Affichage de la distance dans le Moniteur Série
Serial.println("Distance: ");
Serial.println(distance);
Serial.println(" cm");
}
