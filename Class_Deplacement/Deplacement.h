#ifndef Deplacement_h
#define Deplacement_h
#include "Arduino.h" 
#include "math.h"

class Deplacement(){		
public:
        void init(int vitesse);
        void avancer(int distance);
        void reculer(int distance);
        void tourner_gauche(int angle);
        void tourner_droite(int angle);
        
private:
};
#endif
