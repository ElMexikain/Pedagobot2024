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
    int distance = abs(2*M_PI*rayon)
    int temps = abs(1000*distance/2); //en milisecondes
	descendre_stylo1();
    if(distance >0){
    // le moteur droit tourne vers l'avant
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    //le moteur droit est à l'arrêt
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW)
    delay(temps);
    }
position_intermediaire();
}
    
void polygone_regulier(int Nbcote, float longueur){
    for (int i = 0; i < Nbcote; i++){									// Pour chacun des côtés,
      avancer(longueur);											// on avance de la taille donnée
		  tourner_droite(360 / Nbcote);									// et on tourne de l'angle 360° / nbCôtés.
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
      tourner_droite(90);
    }

  }
  position_intermediaire();
}


void pavage_heptagone(float longueur){
  descendre_stylo1();
  for(int i=0;i<5;i++){
    polygone_regulier(7,longueur);
    avancer(longueur);
    tourner_gauche(79);
  }
  position_intermediaire();
}


void pavage_cercle(float rayon){
	for(int i=0;i<4;i++){
	  cercle(rayon);
	  tourner_droite(90);
	  avancer(2*rayon);
  }
}
void pavage_triangle(float longueur, int repetitions){
	int n = repetitions;
	tourner_gauche(60);
	avancer(longueur);
	tourner_droite(60);
	for (int i=1;i<n//2+1;i++){
		avancer((n-i)*longueur);
		tourner_droite(120);
		avancer(i*longueur);
		tourner_droite(120);
		avancer((n-i)*longueur);
		if(n%2 ==0 and i==n/2){
			tourner_droite(60);
			avancer(longueur);
		}
		else{
			tourner_droite(120);
			avancer(i*longueur);
			tourner_droite(120);
			avancer((n-i)*longueur);
			tourner_droite(120);
			avancer(i*longueur);
			tourner_droite(60);
			avancer(longueur);
			tourner_droite(60);
		}
	}
	if (n%2==1){
		tourner_gauche(60);
	}
	avancer((n-1)/2*longueur);
	tourner_droite(120);
	avancer(n*longueur);
	tourner_droite(120);
	avancer(n*longueur);
}

void pointe(int longueur){
	int x = longueur;
	if(x > 5){
		pointe(x/3)
	}
			
			
	
			
