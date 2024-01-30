#ifndef Deplacement_h
#define Deplacement_h
#include "Arduino.h" 
#include "math.h"
//#include "ArduinoOTA.h"
//#include "WiFi.h

class Deplacement{		
public:
        void init();
        void avancer(int distance);
        void reculer(int distance);
        void tourner_gauche(int angle);
        void tourner_droite(int angle);
        double calculDistance();
        //void iniOTA();
        void mesureDeVide();
private:
};
#endif
