#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
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

// the code inside loop() has been updated by Robojax
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

/*
 * angleToPulse(int ang)
 * gets angle in degree and returns the pulse width
 * also prints the value on seial monitor
 * written by Ahmad Nejrabi for Robojax, Robojax.com
 */
int angleToPulse(int ang){
   int pulse = map(ang,-90, 90, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}

 
  
//PCA6985 16 channel 12 bits servo controller simple code
//this is the code to controll one or more servos using PCA6
