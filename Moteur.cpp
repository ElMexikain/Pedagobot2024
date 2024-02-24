#include "Arduino.h"
#include "Moteur.h"


Moteur::Moteur(int nb_pas, int pin1, int pin2,int pin3, int pin4) {
  this->direction = 0;      // motor direction
  this->nb_pas = nb_pas; // total number of steps for this motor
  this->delai=10;

  // Arduino pins for the motor control connection:
  this->pin1 = pin1;
  this->pin2 = pin2;
  this->pin3 = pin3;
  this->pin4 = pin4;

  
}

void Moteur::step(int steps_to_move)
{
  int pas_restants = abs(steps_to_move); 

  // determine direction based on whether steps_to_mode is + or -:
  if (steps_to_move > 0) { this->direction = 1; }
  if (steps_to_move < 0) { this->direction = 0; }


  // decrement the number of steps, moving one step each time:
  while (pas_restants > 0)
  {
      if (this->direction == 1)
      {
        if (this->pas_actuel == this->nb_pas) {
          this->pas_actuel = 0;
        }
        this->pas_actuel++;
      }
      else
      {
        if (this->pas_actuel == 0) {
          this->pas_actuel = this->nb_pas;
        }
        this->pas_actuel--;
      }
      // decrement the steps left:
      pas_restants--;
      stepMotor(this->pas_actuel % 4);
      delay(delai);
  }
}

/*
 * Moves the motor forward or backwards.
 */
void Moteur::stepMotor(int thisStep)
{
    switch (thisStep) {
      case 0:  // 1010
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
      break;
      case 1:  // 0110
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
      break;
      case 2:  //0101
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
      break;
      case 3:  //1001
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
      break;
    }
}