#ifndef Deplacement_h
#define Deplacement_h
#include "Arduino.h"
class Deplacement {
  public:
      Deplacement(double dist; double ang);
      void avancer(double dist);
      void tourner(double ang);
}  
  private:
      double distance;
      double angle;
      
};
#endif