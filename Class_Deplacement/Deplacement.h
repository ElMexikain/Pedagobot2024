#ifndef Deplacement_h
#define Deplacement_h
#include "Arduino.h" 
#include "math.h"
#include <Stepper.h>
//#include "ArduinoOTA.h"
//#include "WiFi.h

class Deplacement{		
public:
        void init();
        int distanceToStep(double distance);
        void avancer(double distance);
        void reculer(double distance);
        void vitesse(int v)
        void tourner_gauche(double angle);
        void tourner_droite(double angle);
        double calculDistance();
        //void iniOTA();
        void mesureDeVide();
private:
};
#endif
