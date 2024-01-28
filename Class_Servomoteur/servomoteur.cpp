#include "servomoteur.h"
#include "Arduino.h" 
#include "math.h"
#include <Servo.h>

Servo myservo; //créer un objet appelé myservo à partir du module Servo

//declaration des variables

int pos=0; //variable pour stocker la position courante du servo
int buttonState=0; //variable qui sera utilisée pour stocker l'état du button

//initialisationdes constantes
const int buttonPin=2; //numéro de la broche à laquelle est connectée le bouton poussoir
//const int ledVertPin=3; //numéro de la broche à laquelle est connectée la led verte
//const int ledJaunePin=4; //numéro de la broche à laquelle est connectée la led jaune
//const int ledRougePin=5; //numéro de la broche à laquelle est connectée la led rouge


void servomoteur::init()
{
  //pinMode(ledVertePin,OUTPUT); //indique que la broche ledVertePin est en sortie
  //pinMode(ledJaunePin,OUTPUT); //indique que la broche ledJaunePin est en sortie
  //pinMode(ledRougePin,OUTPUT); //indique que la broche ledRougePin est en sortie
  //pinMode(buttonPin,INPUT); //indique que la broche buttonPin est en entrée
  buttonState=digitalRead(buttonPin);//lecture de l'état de buttonPin et stocke sa valeur dans buttonState
  myservo.attach(9);//attaché notre objet myservo au servomoteur branché sur la broche 9
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

