#ifndef Dessin_h
#define Dessin_h
#include "Arduino.h" 
#include "math.h"
#include "Robot.h"
#include "Moteur.h"
#include "cmath"
#include <ESP32Servo.h>


class Dessin {
    public:
        void init();
        void polygone_regulier(int Nbcote, float longueur);
        void cercle_gauche();
        void cercle_droite();
        void pavage_cercle();
        void pointe(float longueur);
        void flocon(float longueur);
        void pavage_carre(float longueur, int Nbrepetitions);
        void pavage_heptagone(float longueur);
        void pavage_triangle(float longueur, int repetitions);
        void cercle(float R, float erreur);
        void pavage_carre2(float longueur,int Nbr);
        void carre(float longueur);
        void creneau(float longueur);
        void demicarre(float longueur);
    private: 

};
#endif
