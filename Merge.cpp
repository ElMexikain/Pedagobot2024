#include "servomoteur.h"
#include "Arduino.h" 
#include "math.h"
#include <ESP32Servo.h>
#include "Moteur.h"

Servo myservo; //créer un objet appelé myservo à partir du module Servo
int pos =90;
float h = 10;
const int trigPin = D8; // Trigger (emission)
const int echoPin = D9; // Echo (réception)
const int stepsPerRevolution	=	64 * 64 / 2;	// Nombre de pas par tour de
const float	PERIMETER	=	M_PI * 8;
const float BRAQUAGE	=	10.7;
// sert à contrôler le moteur pas-à-pas de gauche, branché des broches 10 à 13
Moteur stepperLeft = Moteur(stepsPerRevolution, D7, D9, D8, D10);	
// sert à contrôler le moteur pas-à-pas de droite, branché des broches 5 à 8
Moteur stepperRight = Moteur(stepsPerRevolution, D2, D4, D3, D5);	 
void servo_init()
{
  myservo.setPeriodHertz(50);
  myservo.attach(A0);// on associe la broche A0 au servomoteur
  pos = 90;
  myservo.write(pos);
}


void stylo_1()
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

void stylo_2()
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

void non_stylo()
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

  }

}


int distanceToStep(float distance) {
	return (int)(distance / PERIMETER * stepsPerRevolution);
}

void avancer(float distance){
  // Le robot avance pendant la durée lui permettant de parcourir <distance> cm 
	int steps = distanceToStep(fabs(distance));							// On convertit la distance en nombre de pas à faire;
	int sens = 1;														// et on met le sens par défaut vers l'avant.
	if (distance < 0) {													// Si la distance est négative,
		sens = -1;														// on met le sens vers l'arrière.
	}

	for (int i = 0; i < steps; i++) {									// On fait tous les pas à réaliser un par un :
		stepperRight.step(sens);										// la roue gauche d'abord,
		stepperLeft.step(-sens);										// la droite ensuite.
	}
}

void reculer(float distance){
  avancer(-distance);
}

void tourner_gauche(float angle){
	int steps = distanceToStep(M_PI / 180 * fabs(angle)* BRAQUAGE);	// On récupère le nombre de pas correspondant à la longueur de l'arc décrit par l'angle donné
	int sens = 1;														// et on met le sens par défaut vers la gauche.
	if (angle < 0) {													// Si l'angle est négatif,
		sens = -1;														// on met le sens vers la droite.
	}

	for (int i = 0; i < steps; i++) {									// On fait tous les pas à réaliser un par un :
		stepperRight.step(sens);										// la roue droite d'abord,
		stepperLeft.step(sens);											// la gauche ensuite.
	}
}

void tourner_droite(float angle){
  tourner_gauche(-angle);
}

float calculDistance(){
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Écoute de l'écho
int duree = pulseIn(echoPin, HIGH);
// Calcul de la distance
float distance = duree*0.034/2;
// Affichage de la distance dans le Moniteur Série
Serial.print("Distance : ");
Serial.print(distance);
Serial.println("cm");
return distance;
}
/*void Deplacement::initOTA() {
  // Port defaults to 3232
  // ArduinoOTA.setPort(3232);

  // Hostname defaults to esp3232-[MAC]
  ArduinoOTA.setHostname("ESP32");

  // No authentication by default
  // ArduinoOTA.setPassword("admin");

  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  ArduinoOTA
  .onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH)
      type = "sketch";
    else // U_SPIFFS
      type = "filesystem";

    // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
    Serial.println("Start updating " + type);
  })
  .onEnd([]() {
    Serial.println("\nEnd");
  })
  .onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  })
  .onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });

  ArduinoOTA.begin();
}*/
void mesureDeVide(){
if (calculDistance()<=3){
avancer(0);
}
}



// Servo
//Servo Stylo;
//Stylo.attach(10);

    
void polygone_regulier(int Nbcote, float longueur){
    for (int i = 0; i < Nbcote; i++){									// Pour chacun des côtés,
      avancer(longueur);											// on avance de la taille donnée
		  tourner_droite(360 / Nbcote);									// et on tourne de l'angle 360° / nbCôtés.
	}
}

void pavage_carre(float longueur, int Nbrepetitions){
  for(int compteur = 2;compteur<Nbrepetitions;compteur++){
    for(int i=0;i<2;i++){
      for(int k=0;k<compteur;k++){
        polygone_regulier(4,longueur);
        avancer(longueur);
      }
      tourner_droite(90);
    }
  }
}

void pavage_carre2(float longueur,int Nbr){
	carre(longueur);
	avancer(longueur);
	for(int i=1;i<Nbr+1;i++){
		for(int j=0;j<4;j++){
			creneau(longueur);
			for(int k=0;k<i-1;k++){
				demicarre(longueur);
			}
		}
		avancer(longueur);
	}
}

void carre(float longeur){
	for(int i=0;i<3;i++){
		avancer(longueur);
		tourner_gauche(90);
	}
}

void creneau(float longueur){
	avancer(longueur);
	tourner_gauche(90);
	avancer(longueur);
	tourner_gauche(90);
	avancer(longueur);
	tourner_droite(90);
}

void demicarre(float longueur){
	avancer(longueur);
	tourner_gauche(90);
	avancer(longueur);
	tourner_droite(90);
}


void pavage_heptagone(float longueur){
  for(int i=0;i<5;i++){
    polygone_regulier(7,longueur);
    avancer(longueur);
    tourner_gauche(79);
  }
}


void pavage_cercle(){
	for(int i=0;i<4;i++){
	  arc_Droite(360);
	  tourner_droite(90);
	  avancer(2*braquage);
  }
}

void pointe(float longueur){
	float x = longueur;
	if(x > 5){
		pointe(x/3);
		tourner_gauche(60);
		pointe(x/3);
		tourner_droite(120);
		pointe(x/3);
		tourner_gauche(60);
	}
	else{
		avancer(x);
	}
}

void flocon(float longueur){
	for(int i=0;i<6;i++){
		pointe(longueur);
		tourner_droite(120);
		pointe(longueur);
		tourner_gauche(60);
	}
}

void pavage_triangle(float longueur, int repetitions){
	int n = repetitions;
	tourner_gauche(60);
	avancer(longueur);
	tourner_droite(60);
	for (int i=1;i<n/2+1;i++){
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

void cercle(float R,float erreur){
	int n = 3.14/(2*erreur)**0.5;
	float x=2*R*np.sin(3.14/n);
	for(int i=0;i<n;i++){
		avancer(x);
		left(360/n);
	}
}




