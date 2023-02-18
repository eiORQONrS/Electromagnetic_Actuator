#include "Actuator.h"

#define NUM 16                                         
Actuator motor[NUM];

void setup() {
  for (int i = 0; i < NUM; i++)
    motor[i].attach(22 + i * 2, 23 + i * 2, A0 + i);
  Serial.begin(115200);
}

void loop() {
  for (int i = 0; i < NUM; i++)
    motor[i].up();
  delay(2000);
  for (int i = 0; i < NUM; i++)
    motor[i].down();
  delay(2000);
}                                                                                                                                                                                                
