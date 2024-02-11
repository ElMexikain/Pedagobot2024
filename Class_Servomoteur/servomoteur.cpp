#include "servomoteur.h"
#include "Arduino.h" 
#include "math.h"
#include <ESP32Servo.h>

Servo myservo; //créer un objet appelé myservo à partir du module Servo

void servomoteur::init()
{
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);
  myservo.attach(A0,1000,2000); on associe la broche A0 au servomoteur
}


void servomoteur::stylo_1()
{
  if(pos==0){ //Si aucun des stylos ne fonctionnait, on le ramène à la position du stylo 1
    for(pos=0;pos>-60;pos-=1){
      myservo.write(pos);
      delay(15);
    }
  }

  if(pos==60){ //Si le stylo 2 fonctionnait, on le ramène à la position du stylo 1
    for(pos=60;pos>-60;pos-=1){
      myservo.write(pos);
      delay(15);
    }  
  }

}

void servomoteur::stylo_2()
{
  if(pos==0){ //Si aucun des stylos ne fonctionnait, on le raméne à la position du stylo 2
    for(pos=0;pos<60;pos+=1){
      myservo.write(pos);
      delay(15);
    }
  }

  if(pos==-60){ //Si le stylo 1 fonctionnait, on le raméne à la position du stylo 2
    for(pos=-60;pos<60;pos+=1){
      myservo.write(pos);
      delay(15);
    }  
  }

}

void servomoteur::non_stylo()
{
  if(pos==-60){ //Si le stylo 1 fonctionnait, on le remonte
    for(pos=-60;pos<0;pos+=1){
      myservo.write(pos);
      delay(15);
    }
  }

  if(pos==60){ //Si le stylo 2 fonctionnait, on le remonte
    for(pos=-60;pos>0;pos-=1){
      myservo.write(pos);
      delay(15);
    }  
  }

}
