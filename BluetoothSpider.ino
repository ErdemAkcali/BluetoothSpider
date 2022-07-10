#include <SoftwareSerial.h> //Interface with bluetooth module
#include <NewPing.h> //Interface with ultrasonic distance sensor HC-SR04 //Version 1.9.4 by Tim Eckel
#include <Servo.h>   

NewPing Sonar(A3, A2, 200); // trigger pin, echo pin, and optional maximum distance
SoftwareSerial bluetoothSerial(A0, A1); // RX, TX

char w = ' ';
String data;
boolean NL = true;

Servo servo[4][3];
const int servo_pin[4][3] = { {2, 3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13} };

void setup() {
  Serial.begin(9600);
  bluetoothSerial.begin(9600);

  //Init servos:
    for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      servo[i][j].attach(servo_pin[i][j]);
      //delay(20);
    }
  }

  stand();
}

void loop() {
  softSerial();
}

void stand(){
      for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      servo[i][j].write(90);
      //delay(20);
    }
  }

  //delay(20);

  servo[2][2].write(45); //fix later
  
  servo[0][0].write(45);
  servo[1][0].write(135);
  servo[2][0].write(45);
  servo[3][0].write(135);

  
}
