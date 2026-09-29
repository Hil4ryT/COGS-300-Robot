// MyRobot-V1.ino
// This file must be named the same as your sketch folder
/**
 * @file Motor.ino
 * @brief Simple H-bridge motor control helpers.
 *
 * Provides a minimal interface for driving a DC motor using
 * digital GPIO pins (e.g. Arduino-style platforms).
 *
 * The motor direction is controlled via two input pins,
 * while a separate enable pin turns the motor on or off.
 *
 * @author Paul Bucci
 * @date 2026
 */


/**
 * @brief Drives a DC motor in a fixed direction using an H-bridge.
 *
 * @param in1 GPIO pin connected to motor driver input 1 (direction control)
 * @param in2 GPIO pin connected to motor driver input 2 (direction control)
 * @param enA GPIO pin connected to motor driver enable pin (motor on/off)
 */
void drive(int in1, int in2, int enA) {
    digitalWrite(in1, LOW);   // Direction control: IN1
    digitalWrite(in2, HIGH);  // Direction control: IN2 (sets rotation direction)
    digitalWrite(enA, HIGH);  // Enable motor driver
}

void stop(int in1, int in2, int enA) {
    digitalWrite(in1, LOW);   // Direction control: IN1
    digitalWrite(in2, HIGH);  // Direction control: IN2 (sets rotation direction)
    digitalWrite(enA, LOW);   // Disable motor driver
}

int enA = 9;   // Enable pin for Motor A — must be a PWM-capable pin
int in1 = 2;   // Direction control pin 2 for Motor A
int in2 = 3;   // Direction control pin 3 for Motor A

int enB = 10;   // Enable pin for Motor B — must be a PWM-capable pin
int in3 = 4;   // Direction control pin 4 for Motor B
int in4 = 5;   // Direction control pin 5 for Motor B

void setup() {
    // Set motor control pins as outputs
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);

    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
}

void loop() {
    digitalWrite(in1, LOW);  // direction
    digitalWrite(in2, HIGH); // direction
    digitalWrite(enA, HIGH); // enable
    
    digitalWrite(in3, LOW);  // direction
    digitalWrite(in4, HIGH); // direction
    digitalWrite(enB, HIGH); // enable
}



    // TODO: add your own driving functions here
}
