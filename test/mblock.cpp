#include <ESP32Servo.h>
#include <Arduino.h>
#include <Wire.h>
void init_servo();
void stylo_1();
void stylo_2();
void non_stylo();
void init_moteur();
void step_gauche_N(double steps_to_move);
void step_droite_N(double steps_to_move);
void stepMotor_N_N_N_N_N(double thisStep, double pin1, double pin2, double pin3, double pin4);
void avancer_N(double distance);
void reculer_N(double distance);
void Tourner_gauche_N(double angle);
void Tourner_droite_N(double angle);
void Faire_un_heptagone_de_rayon_N(double r);
void pavage_N_N(double ar_C3_AAte, double nombre_d_ar_C3_AAtes_spirale);
void pavage_triangle_N_N(double longueur, double r_C3_A9p_C3_A9tition);
void Carre_de_cote_N(double ar_C3_AAte);
void Decagone_N(double longueur);
float getDistance(int trig,int echo);
void MesureDeVide();

void _delay(float seconds) ;

void _loop() ;
// generated by mBlock5 for <your product>
// codes make you happy





float longueur = 0;
float temps = 0;
float distance = 0;
float vitesse = 0;
float angle_rad = 0;
float diam_C3_A8tre = 0;
float compteur = 0;
float temp = 0;
float angle_degr_C3_A9 = 0;
float pas_restants_gauche = 0;
float direction = 0;
float pas_actuel_gauche = 0;
float nb_pas = 0;
float pin1_gauche = 0;
float pin2_gauche = 0;
float pin3_gauche = 0;
float pin4_gauche = 0;
float steps = 0;
float sens = 0;
float pos = 0;
float pin_servo = 0;
float pas_actuel_droit = 0;
float pas_restants_droit = 0;
float pin1_droit = 0;
float pin2_droit = 0;
float pin3_droit = 0;
float pin4_droit = 0;
float pin1 = 0;
float pin2 = 0;
float pin3 = 0;
float pin4 = 0;

Servo servo_19;
void init_servo(){
  pos = 90;
  pin_servo = 19;
  servo_19.write(90);

}
void stylo_1(){
  if(pos == 90.000000){
    while(!(pos == 30.000000))
    {
      _loop();
      servo_19.write(pos);
      pos += -1;
      _delay(0.015);

    }

  }
  if(pos == 150.000000){
    while(!(pos == 30.000000))
    {
      _loop();
      servo_19.write(pos);
      pos += -1;
      _delay(0.015);

    }

  }

}
void stylo_2(){
  if(pos == 90.000000){
    while(!(pos == 150.000000))
    {
      _loop();
      servo_19.write(pos);
      pos += 1;
      _delay(0.015);

    }

  }
  if(pos == 30.000000){
    while(!(pos == 150.000000))
    {
      _loop();
      servo_19.write(pos);
      pos += 1;
      _delay(0.015);

    }

  }

}
void non_stylo(){
  if(pos == 30.000000){
    while(!(pos == 90.000000))
    {
      _loop();
      servo_19.write(pos);
      pos += 1;
      _delay(0.015);

    }

  }
  if(pos == 150.000000){
    while(!(pos == 90.000000))
    {
      _loop();
      servo_19.write(pos);
      pos += -1;
      _delay(0.015);

    }

  }

}
void init_moteur(){
  nb_pas = 2048;
  pin1_gauche = 10;
  pin2_gauche = 12;
  pin3_gauche = 11;
  pin4_gauche = 13;
  pin1_droit = 5;
  pin2_droit = 7;
  pin3_droit = 6;
  pin4_droit = 8;
  digitalWrite(5,0);
  digitalWrite(7,0);
  digitalWrite(6,0);
  digitalWrite(8,0);
  digitalWrite(10,0);
  digitalWrite(12,0);
  digitalWrite(11,0);
  digitalWrite(13,0);

}
void step_gauche_N(double steps_to_move){
  pas_restants_gauche = abs(steps_to_move);
  direction = 1;
  if(steps_to_move < 0){
    direction = 0;

  }
  while(!(pas_restants_gauche < 0))
  {
    _loop();
    if(direction == 1.000000){
      if(pas_actuel_gauche == nb_pas){
        pas_actuel_gauche = 0;

      }
      pas_actuel_gauche += 1;

    }else{
      if(pas_actuel_gauche == 0.000000){
        pas_actuel_gauche = nb_pas;

      }
      pas_actuel_gauche += -1;

    }
    pas_restants_gauche += -1;
    stepMotor_N_N_N_N_N(fmod(pas_actuel_gauche, 4), 10, 12, 11, 13);
    _delay(0.003);

  }

}
void step_droite_N(double steps_to_move){
  pas_restants_droit = abs(steps_to_move);
  direction = 1;
  if(steps_to_move < 0){
    direction = 0;

  }
  while(!(pas_restants_droit < 0))
  {
    _loop();
    if(direction == 1.000000){
      if(pas_actuel_droit == nb_pas){
        pas_actuel_droit = 0;

      }
      pas_actuel_droit += 1;

    }else{
      if(pas_actuel_droit == 0.000000){
        pas_actuel_droit = nb_pas;

      }
      pas_actuel_droit += -1;

    }
    pas_restants_droit += -1;
    stepMotor_N_N_N_N_N(fmod(pas_actuel_droit, 4), 5, 7, 6, 8);
    _delay(0.003);

  }

}
void stepMotor_N_N_N_N_N(double thisStep, double pin1, double pin2, double pin3, double pin4){
  if(thisStep == 0.000000){
    digitalWrite(pin1,1);
    digitalWrite(pin2,0);
    digitalWrite(pin3,1);
    digitalWrite(pin4,0);

  }
  if(thisStep == 1.000000){
    digitalWrite(pin1,0);
    digitalWrite(pin2,1);
    digitalWrite(pin3,1);
    digitalWrite(pin4,0);

  }
  if(thisStep == 2.000000){
    digitalWrite(pin1,0);
    digitalWrite(pin2,1);
    digitalWrite(pin3,0);
    digitalWrite(pin4,1);

  }
  if(thisStep == 3.000000){
    digitalWrite(pin1,1);
    digitalWrite(pin2,0);
    digitalWrite(pin3,0);
    digitalWrite(pin4,1);

  }

}
void avancer_N(double distance){
  steps = floor((abs(distance) / 25.13) * 2048);
  sens = 1;
  if(distance < 0){
    sens = -1;

  }
  for(int count=0;count<int(steps);count++){
    step_gauche_N(-1 * sens);
    step_droite_N(sens);
  }

}
void reculer_N(double distance){
  avancer_N(-1 * distance);

}
void Tourner_gauche_N(double angle){
  steps = floor(15.2 * abs(angle));
  sens = 1;
  if(angle < 0){
    sens = -1;

  }
  for(int count2=0;count2<int(steps);count2++){
    step_gauche_N(sens);
    step_droite_N(sens);
  }

}
void Tourner_droite_N(double angle){
  Tourner_gauche_N(-1 * angle);

}
void Faire_un_heptagone_de_rayon_N(double r){
  angle_degr_C3_A9 = 51.43;
  longueur = r * 0.867;
  for(int count3=0;count3<7;count3++){
    avancer_N(longueur);
    Tourner_droite_N(angle_degr_C3_A9);
  }

}
void pavage_N_N(double ar_C3_AAte, double nombre_d_ar_C3_AAtes_spirale){
  compteur = 2;
  while(!(compteur == 10.000000))
  {
    _loop();
    temp = 1;
    for(int count7=0;count7<2;count7++){
      for(int count6=0;count6<int(compteur);count6++){
        Carre_de_cote_N(ar_C3_AAte);
        avancer_N(ar_C3_AAte);
      }
      Tourner_droite_N(90);
    }
    compteur += 1;

  }

}
void pavage_triangle_N_N(double longueur, double r_C3_A9p_C3_A9tition){
  Tourner_droite_N(60);
  avancer_N(longueur);
  Tourner_gauche_N(60);
  while(!((compteur > r_C3_A9p_C3_A9tition / 2)  ||  (compteur == r_C3_A9p_C3_A9tition / 2)))
  {
    _loop();
    avancer_N(((r_C3_A9p_C3_A9tition - compteur)) * longueur);
    Tourner_gauche_N(120);
    avancer_N(compteur * longueur);
    Tourner_gauche_N(120);
    avancer_N(((r_C3_A9p_C3_A9tition - compteur)) * longueur);
    if((fmod(r_C3_A9p_C3_A9tition, 2) == 0.000000)  &&  (compteur == r_C3_A9p_C3_A9tition / 2)){
      Tourner_gauche_N(120);
      avancer_N(longueur);

    }else{
      Tourner_gauche_N(120);
      avancer_N(compteur * longueur);
      Tourner_gauche_N(120);
      avancer_N(((r_C3_A9p_C3_A9tition - compteur)) * longueur);
      Tourner_gauche_N(120);
      avancer_N(compteur * longueur);
      Tourner_gauche_N(60);
      avancer_N(longueur);
      Tourner_gauche_N(60);

    }

  }
  if(fmod(r_C3_A9p_C3_A9tition, 2) == 1.000000){
    Tourner_droite_N(60);
    avancer_N(((r_C3_A9p_C3_A9tition - 1)) / (2 * longueur));
    Tourner_gauche_N(120);
    avancer_N(longueur);
    Tourner_gauche_N(120);
    avancer_N(longueur);

  }

}
void Carre_de_cote_N(double ar_C3_AAte){
  for(int count8=0;count8<4;count8++){
    avancer_N(ar_C3_AAte);
    Tourner_droite_N(90);
  }

}
void Decagone_N(double longueur){
  longueur = longueur;
  for(int count10=0;count10<20;count10++){
    for(int count9=0;count9<10;count9++){
      avancer_N(longueur);
      Tourner_gauche_N(36);
    }
    avancer_N(longueur / 2);
    Tourner_gauche_N(-18);
    longueur = 0.95 * longueur;
  }

}
float getDistance(int trig,int echo){
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    pinMode(echo, INPUT);
    return pulseIn(echo,HIGH,30000)/58.0;
}
void MesureDeVide(){
  while(1) {
      digitalWrite(11,1);
      _delay(float(pow(10,-5)));
      digitalWrite(11,0);
      temps = getDistance(11,12);
      distance = sqrt((temps * 0.034 - 0.1 * 0.1));
      Serial.println(distance);
      if(distance < 3){
        avancer_N(0);

      }

      _loop();
  }

}

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
}

void setup() {
  servo_19.attach(19);
  pinMode(5,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  Serial.begin(115200);
  init_moteur();
  init_servo();
  avancer_N(10);

}

void _loop() {
}

void loop() {
  _loop();
}