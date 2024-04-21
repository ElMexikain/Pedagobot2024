#ifndef Moteur_h
#define Moteur_h

// library interface description
class Moteur {
  public:
    Moteur(int nb_pas, int pin1, int pin2, int pin3, int pin4);
    void setSpeed(long whatSpeed);
    void step(int number_of_steps);
    void stepMotor(int thisStep);

    int nb_pas;
    int pin1;
    int pin2;
    int pin3;
    int pin4;
    int direction;
    int pas_actuel;
    long delai;
  private:
};

#endif
