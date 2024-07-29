#include <Servo.h> 
 
// Define Servo objects for hip and knee servos 
Servo hipServoLeft; 
Servo kneeServoLeft; 
Servo hipServoRight; 
Servo kneeServoRight; 
 
// Define parameters for movement 
const int stepLength = 30;        // Length of each step (in degrees) 
const int footLiftHeight = 60;    // Height of foot lift (in degrees) 
const int movementSpeed = 50;     // Speed of movement (in milliseconds) 
 
// Function to attach servos 
void attachServos() { 
    hipServoLeft.attach(9);  // Attach left hip servo to pin 9 
    kneeServoLeft.attach(10); // Attach left knee servo to pin 10 
    hipServoRight.attach(11); // Attach right hip servo to pin 11 
    kneeServoRight.attach(12); // Attach right knee servo to pin 12 
} 
 
// Function to set initial positions of servos 
void setInitialPositions() { 
    hipServoLeft.write(90);  // Set left hip servo to 90 degrees 
    kneeServoLeft.write(90); // Set left knee servo to 90 degrees 
    hipServoRight.write(90); // Set right hip servo to 90 degrees 
    kneeServoRight.write(90); // Set right knee servo to 90 degrees 
} 
 
// Function to incrementally rotate a servo from a start angle to an end angle 
void incrementallyRotate(Servo &servo, int startAngle, int endAngle) { 
    int step = (startAngle < endAngle) ? 1 : -1; 
    for (int angle = startAngle; angle != endAngle; angle += step) { 
        servo.write(angle); 
        delay(10); // Small delay to smooth out the movement 
    } 
} 
 
// Function to increment the angle of a servo from a start angle to an end angle 
void incrementAngle(Servo &servo, int startAngle, int endAngle) { 
    for (int angle = startAngle; angle <= endAngle; angle++) { 
        servo.write(angle); 
        delay(10); 
    } 
} 
 
// Function to decrement the angle of a servo from a start angle to an end angle 
void decrementAngle(Servo &servo, int startAngle, int endAngle) { 
    for (int angle = startAngle; angle >= endAngle; angle--) { 
        servo.write(angle); 
        delay(10); 
    } 
} 
 
// Function to maintain the angle of a servo 
void maintainAngle(Servo &servo, int angle) { 
    servo.write(angle); 
    delay(100); // Short delay to stabilize 
} 
 
void setup() { 
    attachServos();        // Attach the servos 
    setInitialPositions(); // Set initial positions of servos 
} 
 
void loop() { 
    // Lift the Leg 
    incrementallyRotate(hipServoLeft, 90, 120); // Rotate left hip servo from 90 to 120 degrees 
    decrementAngle(kneeServoLeft, 90, 60);     // Decrease left knee servo angle from 90 to 60 degrees 
    delay(movementSpeed); 
 
    // Swing the Leg Forward 
    incrementallyRotate(hipServoLeft, 120, 90); // Rotate left hip servo from 120 back to 90 degrees 
    incrementAngle(kneeServoLeft, 60, 90);     // Increase left knee servo angle from 60 back to 90 degrees 
    delay(movementSpeed); 
 
    // Lower the Leg 
    incrementAngle(kneeServoLeft, 90, 120);   // Increase left knee servo angle from 90 to 120 degrees 
    maintainAngle(hipServoLeft, 90);           // Keep left hip servo at 90 degrees 
 
    // Shift Weight 
    incrementallyRotate(hipServoLeft, 90, 80); // Rotate left hip servo from 90 to 80 degrees 
 
    // Repeat for the Opposite Leg 
    incrementallyRotate(hipServoRight, 90, 120); // Rotate right hip servo from 90 to 120 degrees 
    decrementAngle(kneeServoRight, 90, 60);     // Decrease right knee servo angle from 90 to 60 degrees 
    delay(movementSpeed); 
 
    incrementallyRotate(hipServoRight, 120, 90); // Rotate right hip servo from 120 back to 90 degrees 
    incrementAngle(kneeServoRight, 60, 90);     // Increase right knee servo angle from 60 back to 90 degrees 
    delay(movementSpeed); 
 
    incrementAngle(kneeServoRight, 90, 120);   // Increase right knee servo angle from 90 to 120 degrees 
    maintainAngle(hipServoRight, 90);           // Keep right hip servo at 90 degrees 
 
    incrementallyRotate(hipServoRight, 90, 80); // Rotate right hip servo from 90 to 80 degrees 
}