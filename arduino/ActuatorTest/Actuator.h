#ifndef ACTUATOR_H
#define ACTUATOR_H
#include <Arduino.h>

class Actuator {
  public:
    Actuator();
    bool attach(int pinIn, int pinOut, int pinPW);

    void up();
    void down();
    
  private:
    uint8_t pinIn;
    uint8_t pinOut;
    uint8_t pinPW;
};

#endif
