#include "Deplacement.h"
#include "Arduino.h"
#include "Moteur.h"
#include <ESP32Servo.h>


float h = 64;
const int trigPin = D12; // Trigger (emission)
const int echoPin = D13; // Echo (réception)
const int stepsPerRevolution	=	64 * 64 / 2;	// Nombre de pas par tour de
const float	PERIMETER	=	M_PI * 8;
const float BRAQUAGE	=	10.7;
Moteur stepperLeft = Moteur(stepsPerRevolution, D7, D9, D8, D10);	// sert à contrôler le moteur pas-à-pas de gauche, branché des broches 10 à 13
Moteur stepperRight = Moteur(stepsPerRevolution, D2, D4, D3, D5);	 // sert à contrôler le moteur pas-à-pas de droite, branché des broches 5 à 8
Servo myservo; //créer un objet appelé myservo à partir du module Servo
int pos =90;

int Deplacement::distanceToStep(float distance) {
	return (int)(distance / PERIMETER * stepsPerRevolution);
}

void Deplacement::arc_Gauche(float angle) {
  int steps = distanceToStep(M_PI / 180 * fabs(angle)* BRAQUAGE * 2);
  int sens = -1;														// et on met le sens par défaut vers l'avant.
	if (angle < 0) {													// Si la distance est négative,
		sens = 1;														// on met le sens vers l'arrière.
	}

	for (int i = 0; i < steps; i++) {	
    		
    if (mesureDeVide()) {
      break;
    }	
    						// On fait tous les pas à réaliser un par un :
		stepperRight.step(sens);										// la roue gauche d'abord,
	}
}

void Deplacement::arc_Droite(float angle) {
  int steps = distanceToStep(M_PI / 180 * fabs(angle)* BRAQUAGE * 2);
  int sens = 1;														// et on met le sens par défaut vers l'avant.
	if (angle < 0) {													// Si la distance est négative,
		sens = -1;														// on met le sens vers l'arrière.
	}

	for (int i = 0; i < steps; i++) {
    
    if (mesureDeVide()) {
      break;
    }
    										// On fait tous les pas à réaliser un par un :
		stepperLeft.step(sens);										// la roue gauche d'abord,
	}
}

void Deplacement::avancer(float distance){
  // Le robot avance pendant la durée lui permettant de parcourir <distance> cm 
	int steps = distanceToStep(fabs(distance));							// On convertit la distance en nombre de pas à faire;
	int sens = 1;														// et on met le sens par défaut vers l'avant.
	if (distance < 0) {													// Si la distance est négative,
		sens = -1;														// on met le sens vers l'arrière.
	}

	for (int i = 0; i < steps; i++) {	
    
    if (mesureDeVide()) {
      break;
    }
    									// On fait tous les pas à réaliser un par un :
		stepperRight.step(sens);										// la roue gauche d'abord,
		stepperLeft.step(-sens);										// la droite ensuite.
	}
}

void Deplacement::reculer(float distance){
  avancer(-distance);
}

void Deplacement::tourner_gauche(float angle){
	int steps = distanceToStep(M_PI / 180 * fabs(angle)* BRAQUAGE);	// On récupère le nombre de pas correspondant à la longueur de l'arc décrit par l'angle donné
	int sens = 1;														// et on met le sens par défaut vers la gauche.
	if (angle < 0) {													// Si l'angle est négatif,
		sens = -1;														// on met le sens vers la droite.
	}

	for (int i = 0; i < steps; i++) {		
    	
    if (mesureDeVide()) {
      break;
    }
    						
    // On fait tous les pas à réaliser un par un :
		stepperRight.step(sens);										// la roue droite d'abord,
		stepperLeft.step(sens);											// la gauche ensuite.
	}
}

void Deplacement::tourner_droite(float angle){
  tourner_gauche(-angle);
}

float Deplacement::calculDistance(){
// Émission d'un signal de durée 10 microsecondes
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
 
// Écoute de l'écho
float temps = pulseIn(echoPin, HIGH);
float distance1 = temps*0.0344/2 ;
// Calcul de la distance
float distance = pow(distance1*distance1-h*h,0.5)/2;
if (isnan(distance)) {
  distance = 0.0;
}
Serial.print("Temps : ");Serial.print(temps);
Serial.print("Distance1 : "); Serial.print(distance1); Serial.print(", Distance : "); Serial.println(distance);
// Affichage de la distance dans le Moniteur Série
return distance;
} 

bool Deplacement::mesureDeVide(){
  float dist = calculDistance();
  Serial.println(dist);
return (dist>6);

}

void Deplacement::init()
{
  myservo.setPeriodHertz(50);
  myservo.attach(A0);// on associe la broche A0 au servomoteur
  pos = 90;
  myservo.write(pos);
}


void Deplacement::stylo_1()
{
  if(pos==90){ //Si aucun des stylos ne fonctionnait, on le ramène à la position du stylo 1
    for(pos=90;pos>30;pos--){
      myservo.write(pos);
      delay(15);
    }
  }

  if(pos==150){ //Si le stylo 2 fonctionnait, on le ramène à la position du stylo 1
    for(pos=150;pos>30;pos--){
      myservo.write(pos);
      delay(15);
    }  
  }

}

void Deplacement::stylo_2()
{
  if(pos==90){ //Si aucun des stylos ne fonctionnait, on le raméne à la position du stylo 2
    for(pos=90;pos<150;pos++){
      myservo.write(pos);
      delay(15);
    }
  }

  if(pos==30){ //Si le stylo 1 fonctionnait, on le raméne à la position du stylo 2
    for(pos=30;pos<150;pos++){
      myservo.write(pos);
      delay(15);
    }  
  }

}

void Deplacement::non_stylo()
{
  if(pos==30){ //Si le stylo 1 fonctionnait, on le remonte
    for(pos=30;pos<90;pos++){
      myservo.write(pos);
      delay(15);
    }
  }

  if(pos==150){ //Si le stylo 2 fonctionnait, on le remonte
    for(pos=150;pos>90;pos--){
      myservo.write(pos);
      delay(15);
    }  
  }

}
