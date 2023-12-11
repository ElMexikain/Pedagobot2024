#ifndef Dessin_h
#define Dessin_h
#include "Arduino.h" 
#include "math.h"
#include "Deplacement.h"
class Dessin(){
    public:
        void polygone_regulier(int côté, double longueur);
        void pavage_carre(double longueur);
        void pavage_heptagone(double rayon_interieur);
        void pavage_triangle(double longueur);
        void pavage_cercle(double rayon);
        private: 

};
#endif
