#include "Deplacement.h"
#include "Arduino.h"
#include "Moteur.h"
//#include "ArduinoOTA.h"
//#include "WiFi.h"


float h = 10;
float temps;
const int trigPin = 11; // Trigger (emission)
const int echoPin = 12; // Echo (réception)
const int stepsPerRevolution	=	64 * 64 / 2;	// Nombre de pas par tour de
const float	PERIMETER	=	M_PI * 8;
const float BRAQUAGE	=	10.7;
Moteur stepperLeft = Moteur(stepsPerRevolution, D7, D9, D8, D10);	// sert à contrôler le moteur pas-à-pas de gauche, branché des broches 10 à 13
Moteur stepperRight = Moteur(stepsPerRevolution, D2, D4, D3, D5);	 // sert à contrôler le moteur pas-à-pas de droite, branché des broches 5 à 8

int Deplacement::distanceToStep(float distance) {
	return (int)(distance / PERIMETER * stepsPerRevolution);
}

void Deplacement::avancer(float distance){
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

void Deplacement::reculer(float distance){
  avancer(-distance);
}

void Deplacement::tourner_gauche(float angle){
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

void Deplacement::tourner_droite(float angle){
  tourner_gauche(-angle);
}
/*
float Deplacement::calculDistance(){
float distance;
// Émission d'un signal de durée 10 microsecondes
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Écoute de l'écho
temps = pulseIn(echoPin, HIGH);
// Calcul de la distance
distance = pow(temps*0.034-h*h,0.5)/2;
// Affichage de la distance dans le Moniteur Série
Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");
return distance;
}*/
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
/*void Deplacement::mesureDeVide(){
if (calculDistance()<=3){
avancer(0);
}
}*/
