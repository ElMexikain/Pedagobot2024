#ifndef Robot_h
#define Robot_h
#include "Arduino.h" 
#include "math.h"
#include "Moteur.h"
#include <ESP32Servo.h>

class Robot{		
public:
        int distanceToStep(float distance);
        void arc_Gauche(float angle);
        void arc_Droite(float angle);
        void avancer(float distance);
        void reculer(float distance);
        void tourner_gauche(float angle);
        void tourner_droite(float angle);
        float calculDistance();
        bool mesureDeVide();
        static void init();
        static void stylo_1();
        static void stylo_2();
        static void non_stylo();

        float braquage = 10.7;
private:
};
#endif
