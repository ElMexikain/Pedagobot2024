//Deplacement.cpp
#include "Arduino.h"
#include "Deplacement.h"
Deplacement::Deplacement(double dist; double ang) {
  distance = dist;
  angle = ang;
}
void avancer(){
        int pos=0;
        for(pos=0;pos<=distance;pos++){
            
            pos = 
            
            delay(5);
        }
}
void tourner(){
        int pos=0;
        const int rayon = 3.2*0.01;
          for(pos=0;pos<=angle*rayon;pos++){
              pos =
              delay(5);

        }
}
