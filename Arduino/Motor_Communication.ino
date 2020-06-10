#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

int sig;

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  pwm.setPWM(0,0, angleToPulse(0));
  pwm.setPWM(3,0, angleToPulse(0));
  pwm.setPWM(4,0, angleToPulse(0));

  //yield();
  //negative is up, positive down, base value of 30

 
}


void loop() {

if (Serial.available()){
  sig = Serial.read();
  switch (sig){
    case 'A':
    pwm.setPWM(0,0, angleToPulse(-50));
    pwm.setPWM(3,0, angleToPulse(-25));
    pwm.setPWM(4,0, angleToPulse(0));
    break;
    case 'B':
    pwm.setPWM(0,0, angleToPulse(-50));
    pwm.setPWM(3,0, angleToPulse(0));
    pwm.setPWM(4,0, angleToPulse(-25));
    break;
    case 'C':
    pwm.setPWM(0,0, angleToPulse(-60));
    pwm.setPWM(3,0, angleToPulse(0));
    pwm.setPWM(4,0, angleToPulse(0));
    break;
    case 'D':
    pwm.setPWM(0,0, angleToPulse(50));
    pwm.setPWM(3,0, angleToPulse(-25));
    pwm.setPWM(4,0, angleToPulse(0));
    break;
    case 'E':
    pwm.setPWM(0,0, angleToPulse(50));
    pwm.setPWM(3,0, angleToPulse(0));
    pwm.setPWM(4,0, angleToPulse(-25));
    break;
    case 'F':
    pwm.setPWM(0,0, angleToPulse(60));
    pwm.setPWM(3,0, angleToPulse(0));
    pwm.setPWM(4,0, angleToPulse(0));
    break;
    case 'G':
    pwm.setPWM(0,0, angleToPulse(0));
    pwm.setPWM(3,0, angleToPulse(-45));
    pwm.setPWM(4,0, angleToPulse(50));
    break;
    case 'H':
    pwm.setPWM(0,0, angleToPulse(0));
    pwm.setPWM(3,0, angleToPulse(50));
    pwm.setPWM(4,0, angleToPulse(-45));
    break;
    case 'I':
    pwm.setPWM(0,0, angleToPulse(0));
    pwm.setPWM(3,0, angleToPulse(0));
    pwm.setPWM(4,0, angleToPulse(0));
    break;
    
  }
delay(20);
}

}


int angleToPulse(int ang){
   int pulse = map(ang,-90, 90, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}

 

