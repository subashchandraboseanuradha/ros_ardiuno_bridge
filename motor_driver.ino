#include <Arduino.h>

/***************************************************************
   Motor driver definitions

   Pin Connections:
   - Motor Driver (L298N or similar):
     * LEFT_MOTOR_FORWARD  -> IN1 of left motor driver
     * LEFT_MOTOR_BACKWARD -> IN2 of left motor driver
     * RIGHT_MOTOR_FORWARD -> IN3 of right motor driver
     * RIGHT_MOTOR_BACKWARD-> IN4 of right motor driver
     * Motor driver ENA/ENB pins should be connected to 5V
     * Motor driver VCC to 12V power supply
     * Motor driver GND to ESP32 GND
   
   - Encoder Connections:
     * LEFT_ENCODER_A -> GPIO pin for left encoder channel A
     * LEFT_ENCODER_B -> GPIO pin for left encoder channel B
     * RIGHT_ENCODER_A-> GPIO pin for right encoder channel A
     * RIGHT_ENCODER_B-> GPIO pin for right encoder channel B
     * Encoder VCC to 3.3V
     * Encoder GND to ESP32 GND

   Note: Make sure to define these pins in your main sketch:
   #define LEFT_MOTOR_FORWARD    GPIO_NUM_XX
   #define LEFT_MOTOR_BACKWARD   GPIO_NUM_XX
   #define RIGHT_MOTOR_FORWARD   GPIO_NUM_XX
   #define RIGHT_MOTOR_BACKWARD  GPIO_NUM_XX
   #define LEFT_ENCODER_A        GPIO_NUM_XX
   #define LEFT_ENCODER_B        GPIO_NUM_XX
   #define RIGHT_ENCODER_A       GPIO_NUM_XX
   #define RIGHT_ENCODER_B       GPIO_NUM_XX
   #define PWM_freq             1000  // PWM frequency in Hz

   *************************************************************/

void initMotorController() {
  // Set motor control pins as outputs
  pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);
  pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);

  // Initialize PWM for motor control
  ledcAttach(LEFT_MOTOR_BACKWARD, PWM_freq, 8);  // IN2 of left motor
  ledcAttach(LEFT_MOTOR_FORWARD, PWM_freq, 8);   // IN1 of left motor
  ledcAttach(RIGHT_MOTOR_BACKWARD, PWM_freq, 8); // IN4 of right motor
  ledcAttach(RIGHT_MOTOR_FORWARD, PWM_freq, 8);  // IN3 of right motor
}

void setMotorSpeeds(int leftSpeed, int rightSpeed) {
  if (leftSpeed > 0) {
    ledcWrite(LEFT_MOTOR_FORWARD, leftSpeed);
    ledcWrite(LEFT_MOTOR_BACKWARD, 0);
  }
  else if (leftSpeed < 0) {
    ledcWrite(LEFT_MOTOR_BACKWARD, -leftSpeed);
    ledcWrite(LEFT_MOTOR_FORWARD, 0);
  } else {
    ledcWrite(LEFT_MOTOR_BACKWARD, 0);
    ledcWrite(LEFT_MOTOR_FORWARD, 0);
  }

  if (rightSpeed > 0) {
    ledcWrite(RIGHT_MOTOR_FORWARD, rightSpeed);
    ledcWrite(RIGHT_MOTOR_BACKWARD, 0);
  }
  else if (rightSpeed < 0) {
    ledcWrite(RIGHT_MOTOR_BACKWARD, -rightSpeed);
    ledcWrite(RIGHT_MOTOR_FORWARD, 0);
  } else {
    ledcWrite(RIGHT_MOTOR_BACKWARD, 0);
    ledcWrite(RIGHT_MOTOR_FORWARD, 0);
  }
}
