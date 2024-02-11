#include "servomoteur.h"
#include "Arduino.h" 
#include "math.h"
#include <ESP32Servo.h>

Servo myservo; //créer un objet appelé myservo à partir du module Servo

//declaration des variables
double vitesseCCW=26;//vitesse clock wise
double vitesseCW=-26;//vitesse counter clockcwise
double zero=0; // on défini un zéro :)
double stop=map(zero,-100,100,0,180); //on redéfini le zéro sur la plage 0, 180 du servo
double vitesse_adjCCW=map(vitesseCCW,-100,100,0,180);//on redéfini la vitesse CCW sur la plage 0, 180 du servo
double vitesse_adjCW=map(vitesseCW,-100,100,0,180);//on redéfini la vitesse CCW sur la plage 0, 180 du servo
double angle=180; //angle demandé en degrés
double coeff= 5.9;//nb secondes par degré pour une vitesse de 26
double temps = angle*coeff; // temps nécessaire pour tourner de l'angle défini
int pos=0;//position du servomoteur
void servomoteur::init()
{
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);
  myservo.attach(A0,1000,2000);//attaché notre objet myservo au servomoteur branché sur la broche A0
}


void servomoteur::stylo_1()
{
  if(pos==0){ //Si aucun des stylos ne fonctionnait, on le raméne à la position du stylo 1
    myservo.write(vitesse_adjCCW);
    delay(temps);
    myservo.write(stop);
    pos=-angle;
  }
    
  if(pos==angle){ //Si le stylo 2 fonctionnait, on le raméne à la position du stylo 1
    myservo.write(vitesse_adjCCW);
    delay(2*temps);
    myservo.write(stop);
    pos=-angle;
  }
  
}
 
void servomoteur::stylo_2()
{ 
  if(pos==0){ //Si aucun des stylos ne fonctionnait, on le raméne à la position du stylo 2
     myservo.write(vitesse_adjCW);
    delay(temps);
    myservo.write(stop);
    pos=angle;
  }
    
  if(pos==-angle){ //Si le stylo 1 fonctionnait, on le raméne à la position du stylo 2
    myservo.write(vitesse_adjCW);
    delay(2*temps);
    myservo.write(stop);
    pos=angle;
  }
  
}

void servomoteur::non_stylo()
{
  if(pos==-angle){ //Si le stylo 1 fonctionnait, on le remonte
    myservo.write(vitesse_adjCW);
    delay(temps);
    myservo.write(stop);
    pos=0;
  }
    
  if(pos==angle){ //Si le stylo 2 fonctionnait, on le remonte
    myservo.write(vitesse_adjCCW);
    delay(temps);
    myservo.write(stop);
    pos=0;
  }
  
}
