#ifndef Dessin_h
#define Dessin_h
#include "Arduino.h" 
#include "math.h"
#include "Deplacement.h"
#include "Moteur.h"

class Dessin {
    public:
        void polygone_regulier(int Nbcote, float longueur);
        void cercle_gauche();
        void cercle_droite();
        void pavage_cercle();
        void pointe(float longueur);
        void flocon(float longueur);
        void pavage_carre(float longueur, int Nbrepetitions);
        void pavage_heptagone(float longueur);
        void pavage_triangle(float longueur, int repetitions);
    private: 

};
#endif
