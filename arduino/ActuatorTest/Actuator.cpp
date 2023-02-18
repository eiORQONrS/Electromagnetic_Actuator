#include "Actuator.h"

#define NOT_ATTACHED      (-1)
#define ACTUATOR_PWM      512
#define ACTUATOR_DURATION 2

Actuator::Actuator() {
  this->pinIn = NOT_ATTACHED;
  this->pinOut = NOT_ATTACHED;
  this->pinPW = NOT_ATTACHED;
}

bool Actuator::attach(int pinIn, int pinOut, int pinPW) {
  pinMode(pinIn, OUTPUT);
  pinMode(pinOut, OUTPUT);
  pinMode(pinPW, OUTPUT);

  this->pinIn = pinIn;
  this->pinOut = pinOut;
  this->pinPW = pinPW;

  return true;
}


void Actuator::up() {
  analogWrite(this->pinPW, ACTUATOR_PWM);
  digitalWrite(this->pinIn, HIGH);
  digitalWrite(this->pinOut, LOW);
  delay(ACTUATOR_DURATION);
  digitalWrite(this->pinIn, LOW);
  digitalWrite(this->pinOut, LOW);
}

void Actuator::down() {
  analogWrite(this->pinPW, ACTUATOR_PWM);
  digitalWrite(this->pinIn, LOW);
  digitalWrite(this->pinOut, HIGH);
  delay(ACTUATOR_DURATION);
  digitalWrite(this->pinIn, LOW);
  digitalWrite(this->pinOut, LOW);
}
