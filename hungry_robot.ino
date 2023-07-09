#include <Servo.h>

#define PIN_SERVO 3
#define SENSOR 2

Servo servo;

const int MOUNTH_CLOSED = 140;
const int MOUNTH_LITTLE_OPENED = 110;
const int MOUNTH_OPEN = 70;
const int MOUNTH_INTERALLY_OPEN = 65;

int sensorProximityValue;

void setup() {
  Serial.begin(9600);  
 
  //SETUP PINS
  pinMode(PIN_SERVO, OUTPUT);
  pinMode(SENSOR, INPUT);

  //ATACH SERVO PIN
  servo.attach(PIN_SERVO);

  //MOVE MOUNTH TO INITIAL POSITION
  servo.write(MOUNTH_CLOSED);
}

void loop() {
  sensorProximityValue = digitalRead(SENSOR);
  Serial.println(sensorProximityValue);

  if (sensorProximityValue == LOW) {
    objectIdentified();
  }
}


void objectIdentified() {
  delay(1000);
  //attach servo before start
  servo.attach(PIN_SERVO);
  
  //eat content
  servo.write(MOUNTH_OPEN);
  
  delay(300);
  
  //after ate content
  chewMovement();
   
  // release arm's torque
  servo.detach();  
}

void chewMovement() {
  delay(250);
  servo.write(MOUNTH_CLOSED);
  delay(250);
  servo.write(MOUNTH_LITTLE_OPENED);
  delay(250);
  servo.write(MOUNTH_CLOSED);
  delay(250);
  servo.write(MOUNTH_LITTLE_OPENED);
  delay(250);
  servo.write(MOUNTH_CLOSED);
  delay(250);
  servo.write(MOUNTH_LITTLE_OPENED);    
    
  // release arm's torque
  servo.detach();    
}
