#include "Actuator.h"

#define NUM 16                                         
Actuator motor[NUM];

void setup() {
  for (int i = 0; i < NUM; i++)
    motor[i].attach(22 + i * 2, 23 + i * 2, A0 + i);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      Serial.println("LED 灯已打开");
    } else if (command == '0') {
      Serial.println("LED 灯已关闭");
    }
  }
}                                                                                                                                                                                                
