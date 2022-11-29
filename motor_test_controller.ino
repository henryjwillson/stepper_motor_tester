// Include the AccelStepper Library
#include <AccelStepper.h>

// Define pin connections
const int dirPin = 3;
const int stepPin = 2;
int pin_switch0 = 4;
int pin_switch = 5;


// Define motor interface type
#define motorInterfaceType 1

// Creates an instance
AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
  // set the maximum speed, acceleration factor,
  // initial speed and the target position
  myStepper.setMaxSpeed(1000);
  myStepper.setAcceleration(3000);
  myStepper.setSpeed(600);
  myStepper.moveTo(200);

  pinMode(pin_switch0, INPUT);
  pinMode(pin_switch, INPUT);
}

void loop() {
  // Change direction once the motor reaches target position
  
  if (digitalRead(pin_switch) == HIGH){
    myStepper.move(-2000);  
    // Move the motor one step
    myStepper.run();
  }
  else if (digitalRead(pin_switch0) == HIGH){
      myStepper.move(2000);
      myStepper.run();
  }
}
