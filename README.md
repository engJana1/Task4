# Task4
Algorithm For Controlling The Leg Movement Of Robot
# Explanation
Initialization:
- attachServos(): Connects the hip and knee servos to the specified pins on the microcontroller.
- setInitialPositions(): Sets the initial position of both the hip and knee servos to 90 degrees.

Parameters:
- stepLength: Length of each step.
- footLiftHeight: Height of the foot lift (not directly used in this code but can influence how high the leg lifts).
- movementSpeed: Determines how fast the servo motors move between angles (time in milliseconds).
- Leg Movement Loop: The loop continuously performs a walking cycle for the left and right legs, with actions mirrored for the opposite leg.

Functions:
- incrementallyRotate(): Smoothly rotates a servo from one angle to another.
- incrementAngle(): Gradually increases the angle of a servo.
- decrementAngle(): Gradually decreases the angle of a servo.
- maintainAngle(): Keeps a servo at a fixed angle with a short stabilization delay.
