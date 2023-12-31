//This sketch makes the robot avoid obstacles
// AFMotor Library : https://www.arduino.cc/reference/en/libraries/adafruit-motor-shield-library/
#include <AFMotor.h> 
AF_DCMotor R_motor(2);           // defines Right motor connector
AF_DCMotor L_motor(3);           // defines Left motor connector
// declare variables
int distancecm=0;
const int trigPin = A0;
const int echoPin = A1;
// defines variables
long duration;
int distance;
void setup() {
  Serial.begin(9600);           // sets up Serial library at 9600 bps
//changes the following values to make the robot  drive as straight as possible  
 
  L_motor.setSpeed(200);        // sets L motor speed
  R_motor.setSpeed(140);        // sets R motor speed

  R_motor.run(RELEASE);         //turns L motor on
  L_motor.run(RELEASE);         //turns R motor on
   pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
   pinMode(echoPin, INPUT); // Sets the echoPin as an Input  
}

void loop() {
  distancecm=mdistance();
  if(distance >0 && distance<8){
    R_motor.run(RELEASE);         
    L_motor.run(RELEASE); 
  
  //go backward 
  R_motor.run(BACKWARD);        
  L_motor.run(BACKWARD);
    delay(1000);
  R_motor.run(FORWARD);         
  L_motor.run(BACKWARD);
    delay(1000);
  }
  else{
  L_motor.run(FORWARD);      //moves motor L Forward
  R_motor.run(FORWARD);  
  }
}
int mdistance()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.print(distance);
  }
