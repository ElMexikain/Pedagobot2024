#include "Deplacement.h"
#include "Arduino.h"
//#include "ArduinoOTA.h"
//#include "WiFi.h"

// Moteur Gauche
int in4 = D5;
int in3 = D6;
// Moteur Droit
int in2 = D3;
int in1 = D2;
double h = 10;

const int trigPin = 11; // Trigger (emission)
const int echoPin = 12; // Echo (réception)
//Valeur pour tourner a la bonne vitesse
const int val = 50;
const int correction = 5;
const double corr_angle = 0.23;
const double vitesse = 7.9;

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
    analogWrite(in1, val);
    analogWrite(in2, 0);
    // Le moteur droit tourne vers l'avant
    analogWrite(in3, val+correction);
    analogWrite(in4, 0);
    delay(temps);
  }
  else{
    // Le moteur gauche tourne vers l'arrière
    analogWrite(in1, 0);
    analogWrite(in2, val);
    // Le moteur droit tourne vers l'arrière
    analogWrite(in3, 0);
    analogWrite(in4, val+correction);
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
  double ang_rad = abs(angle * (1 + corr_angle)*2*M_PI/360);
  double dist = diam * ang_rad / 2; // arc parcouru par les roues selon l'angle donné en paramètre * perimetre / (2*pi*vitesse)
  int temps = abs(dist/vitesse) * 1000; 
  Serial.println(temps);
  if (angle > 0){
    // La moteur gauche tourne vers l'arrière
    analogWrite(in1,val);
    analogWrite(in2,0);
    // Le moteur droit tourne vers l'avant
    analogWrite(in3,0);
    analogWrite(in4,val+correction);
    delay(temps);
  }
  else{
    // de même mais dans l'autre sens
    analogWrite(in1,0);
    analogWrite(in2,val);
    analogWrite(in3,val+correction);
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

/*double Deplacement::calculDistance(){
double distance;
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
