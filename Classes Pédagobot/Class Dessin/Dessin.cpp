#include "Robot.h"
#include "Arduino.h"
#include "Dessin.h"
//#include "Servo.h"
#include "math.h"
#include "Moteur.h"
#include "cmath"
#include <ESP32Servo.h>

// Servo
//Servo Stylo;
//Stylo.attach(10);
Deplacement * robot = new Robot();

void Dessin::init() {
  (*robot).init();
}
    
void Dessin::polygone_regulier(int Nbcote, float longueur){
    for (int i = 0; i < Nbcote; i++){									// Pour chacun des côtés,
      (*robot).avancer(longueur);											// on avance de la taille donnée
		  (*robot).tourner_droite(360 / Nbcote);									// et on tourne de l'angle 360° / nbCôtés.
	}
}

void Dessin::pavage_carre(float longueur, int Nbrepetitions){
  for(int compteur = 2;compteur<Nbrepetitions;compteur++){
    for(int i=0;i<2;i++){
      for(int k=0;k<compteur;k++){
        polygone_regulier(4,longueur);
        (*robot).avancer(longueur);
      }
      (*robot).tourner_droite(90);
    }
  }
}

void Dessin::pavage_carre2(float longueur,int Nbr){
	carre(longueur);
	(*robot).avancer(longueur);
	for(int i=1;i<Nbr+1;i++){
		for(int j=0;j<4;j++){
			creneau(longueur);
			for(int k=0;k<i-1;k++){
				demicarre(longueur);
			}
		}
		(*robot).avancer(longueur);
	}
}

void Dessin::carre(float longueur){
	for(int i=0;i<3;i++){
		(*robot).avancer(longueur);
		(*robot).tourner_gauche(90);
	}
}

void Dessin::creneau(float longueur){
	(*robot).avancer(longueur);
	(*robot).tourner_gauche(90);
	(*robot).avancer(longueur);
	(*robot).tourner_gauche(90);
	(*robot).avancer(longueur);
	(*robot).tourner_droite(90);
}

void Dessin::demicarre(float longueur){
	(*robot).avancer(longueur);
	(*robot).tourner_gauche(90);
	(*robot).avancer(longueur);
	(*robot).tourner_droite(90);
}


void Dessin::pavage_heptagone(float longueur){
  for(int i=0;i<5;i++){
    polygone_regulier(7,longueur);
    (*robot).avancer(longueur);
    (*robot).tourner_gauche(79);
  }
}


void Dessin::pavage_cercle(){
	for(int i=0;i<4;i++){
	  (*robot).arc_Droite(360);
	  (*robot).tourner_droite(90);
	  (*robot).avancer(2*(*robot).braquage);
  }
}

void Dessin::pointe(float longueur, int ordre){
	float x = longueur*pow(3,ordre);
	if(x > longueur){
		pointe(longueur,ordre-1);
		(*robot).tourner_gauche(60);
		pointe(longueur,ordre-1);
		(*robot).tourner_droite(120);
		pointe(longueur,ordre-1);
		(*robot).tourner_gauche(60);
		pointe(longueur,ordre-1);
	}
	else{
		(*robot).avancer(longueur);
	}
}

void Dessin::flocon(float longueur,int ordre){
	for(int i=0;i<6;i++){
		pointe(longueur,ordre);
		(*robot).tourner_droite(120);
		pointe(longueur,ordre);
		(*robot).tourner_gauche(60);
	}
}

void Dessin::pavage_triangle(float longueur, int repetitions){
	int n = repetitions;
	(*robot).tourner_gauche(60);
	(*robot).avancer(longueur);
	(*robot).tourner_droite(60);
	for (int i=1;i<n/2+1;i++){
		(*robot).avancer((n-i)*longueur);
		(*robot).tourner_droite(120);
		(*robot).avancer(i*longueur);
		(*robot).tourner_droite(120);
		(*robot).avancer((n-i)*longueur);
		if(n%2 ==0 and i==n/2){
			(*robot).tourner_droite(60);
			(*robot).avancer(longueur);
		}
		else{
			(*robot).tourner_droite(120);
			(*robot).avancer(i*longueur);
			(*robot).tourner_droite(120);
			(*robot).avancer((n-i)*longueur);
			(*robot).tourner_droite(120);
			(*robot).avancer(i*longueur);
			(*robot).tourner_droite(60);
			(*robot).avancer(longueur);
			if(n%2 ==0 or i!=n/2){
				(*robot).tourner_droite(60);
			}
		}
	}
	//if (n%2==1){
	//	(*robot).tourner_gauche(60);
	//}
	(*robot).avancer((n-1)/2*longueur);
	(*robot).tourner_droite(120);
	(*robot).avancer(n*longueur);
	(*robot).tourner_droite(120);
	(*robot).avancer(n*longueur);
}

void Dessin::cercle(float R, float erreur){
	int n = 3.14/pow((2*erreur),0.5);
	float x=2*R*sin(3.14/n);
	for(int i=0;i<n;i++){
		(*robot).avancer(x);
		(*robot).tourner_gauche(360/n);
	}
}
			
			
	
			
