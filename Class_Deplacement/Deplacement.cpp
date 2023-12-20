#include "Deplacement.h"
#include "Arduino.h"


// Moteur Droit
int in4 = D5;
int in3 = D6;
// Moteur Gauche
int in2 = D3;
int in1 = D2;

const int trigPin = 11; // Trigger (emission)
const int echoPin = 12; // Echo (réception)
long temps;
float distance;

//Valeur pour tourner a la bonne vitesse
const int val = 50;
const int vitesse = 7 * M_PI * 1.23 * 10 / 42;

void Deplacement::init(){
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
}

void Deplacement::avancer(int distance){
  // Le robot avance pendant la durée lui permettant de parcourir <distance> cm 
  int temps = abs(distance * 1000 / vitesse); //en milisecondes
  if (distance > 0){
    // Le moteur gauche tourne vers l'avant
    analogWrite(in1, 0);
    analogWrite(in2, val);
    // Le moteur droit tourne vers l'avant
    analogWrite(in3, 0);
    analogWrite(in4, val);
    delay(temps);
  }
  else{
    // Le moteur gauche tourne vers l'arrière
    analogWrite(in1, val);
    analogWrite(in2, 0);
    // Le moteur droit tourne vers l'arrière
    analogWrite(in3, val);
    analogWrite(in4, 0);
    delay(temps);
  }
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
}

void Deplacement::reculer(int distance){
  avancer(-distance);
}

void Deplacement::tourner_gauche(int angle){
  // Le robot tourne à gauche autour du milieu entre les deux roues 
  // Un peu difficle de savoir si le stylo restera effectivement immobile durant la rotation
  // angle en degré
  int diam = 23; //distance entre les roues en cm
  double ang_rad = abs(angle*2*M_PI/360);
  double dist = diam/2 * ang_rad;
  int temps = abs(dist/vitesse) * 1000; // arc parcouru par les roues selon l'angle donné en paramètre * perimetre / (2*pi*vitesse)
  if (angle > 0){
    // La moteur gauche tourne vers l'arrière
    analogWrite(in1,val);
    analogWrite(in2,0);
    // Le moteur droit tourne vers l'avant
    analogWrite(in3,0);
    analogWrite(in4,val);
    delay(temps);
  }
  else{
    // de même mais dans l'autre sens
    analogWrite(in1,0);
    analogWrite(in2,val);
    analogWrite(in3,val);
    analogWrite(in4,0);
    delay(temps);
  }
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
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

