#include "Deplacement.h"
#include "Arduino.h"
#include "Dessin.h"
#include "Servo.h"
#include "math.h"
// Moteur Droit
const int in4 = 6;
const int in3 = 7;
// Moteur Gauche
const int in2 = 8;
const int in1 = 9;
// Servo
Servo Stylo;
Stylo.attach(10);

void cercle(float rayon){
    int distance = 
    int temps = abs(1000*distance/2); //en milisecondes
    // le moteur droit tourne vers l'avant
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    //le moteur droit est à l'arrêt
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW)
    delay(temps);
    
void polygone_regulier(int Nbcôté, float longueur){
    for (int i = 0; i < NbCôté; i++){									// Pour chacun des côtés,
      avancer(longueur);											// on avance de la taille donnée
		  tournerDroite(360 / Nbcôté);									// et on tourne de l'angle 360° / nbCôtés.
	}
}

void pavage_carre(float longueur, int Nbrepetitions){
  descendre_stylo1;
  for(int compteur = 2;compteur<Nbrepetitions;compteur++){
    for(int i=0;i<2;i++){
      for(int k=0;k<compteur;k++){
        polygone_regulier(4,longueur);
        avancer(longueur);
      }
      tournerDroite(90);
    }

  }
  position_intermediaire();
}


void pavage_heptagone(float longueur){
  descendre_stylo1();
  for(int i=0;i<5;i++){
    polygone_regulier(7,longueur);
    avancer(longueur);
    tournerGauche(79);
  }
  position_intermediaire();
}


void pavage_cercle(float rayon){
  for(int i=0;i<4;i++){
    avancer(longueur);
    tournerGauche(79);
  }
}
