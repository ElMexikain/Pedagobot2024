#ifndef Deplacement_h
#define Deplacement_h
#include "Arduino.h" 
#include "math.h"
#include "Moteur.h"
//#include "ArduinoOTA.h"
//#include "WiFi.h

class Deplacement{		
public:
        int distanceToStep(float distance);
        void avancer(float distance);
        void reculer(float distance);
        void tourner_gauche(float angle);
        void tourner_droite(float angle);
        float calculDistance();
        //void iniOTA();
        void mesureDeVide();
private:
};
#endif
