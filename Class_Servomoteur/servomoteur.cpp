#include "servomoteur.h"
#include "Arduino.h" 
#include "math.h"
#include <ESP32Servo.h>

Servo myservo; //créer un objet appelé myservo à partir du module Servo

//declaration des variables

int pos=0; //variable pour stocker la position courante du servo
int buttonState=0; //variable qui sera utilisée pour stocker l'état du button

//initialisationdes constantes
const int buttonPin=2; //numéro de la broche à laquelle est connectée le bouton poussoir



void servomoteur::init()
{
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);
  myservo.attach(2,1000,2000);//attaché notre objet myservo au servomoteur branché sur la broche 2
}


void servomoteur::stylo_1()
{
  
  //digitalWrite(ledVertePin,HIGH);//On allume la led Verte
  //digitalWrite(ledJaunePin,LOW);//On éteind la led Jaune
  //digitalWrite(ledRougePin,LOW);//On éteind la led Rouge
  
  if(pos==0){ //Si aucun des stylos ne fonctionnait, on le raméne à la position du stylo 1
    for(pos=0;pos>-60;pos-=1){
      myservo.write(pos);
      delay(15);
    }
  }
    
  if(pos==60){ //Si le stylo 2 fonctionnait, on le raméne à la position du stylo 1
    for(pos=60;pos>-60;pos-=1){
      myservo.write(pos);
      delay(15);
    }  
  }
  
}
 
void servomoteur::stylo_2()
{
  
  //digitalWrite(ledRougePin,HIGH);//On allume la led Rouge
  //digitalWrite(ledJaunePin,LOW);//On éteind la led Jaune
  //digitalWrite(ledVertePin,LOW);//On éteind la led Verte
  
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
  
  //digitalWrite(ledJaunePin,HIGH);//On allume la led Jaune
  //digitalWrite(ledVertePin,LOW);//On éteind la led Verte
  //digitalWrite(ledRougePin,LOW);//On éteind la led Rouge
  
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
