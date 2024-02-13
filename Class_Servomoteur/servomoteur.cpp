#include "servomoteur.h"
#include "Arduino.h" 
#include "math.h"
#include <ESP32Servo.h>

Servo myservo; //créer un objet appelé myservo à partir du module Servo
int pos =90;
void servomoteur::init()
{
  myservo.setPeriodHertz(50);
  myservo.attach(A0);// on associe la broche A0 au servomoteur
  myservo.write(pos);
}


void servomoteur::stylo_1()
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

void servomoteur::stylo_2()
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

void servomoteur::non_stylo()
{
  if(pos==90){ //Si le stylo 1 fonctionnait, on le remonte
    for(pos=90;pos<30;pos++){
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
