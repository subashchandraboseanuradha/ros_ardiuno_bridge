/***************************************************************
   Motor driver function definitions - by James Nugen
   *************************************************************/

#ifdef L298_MOTOR_DRIVER
// Right Motor (Channel B)
#define RIGHT_MOTOR_BACKWARD 5   // IN4 (D5)
#define RIGHT_MOTOR_FORWARD 9    // IN3 (D9)
#define RIGHT_MOTOR_ENABLE 3     // ENB (PWM)

// Left Motor (Channel A)
#define LEFT_MOTOR_BACKWARD 10   // IN2 (D10)
#define LEFT_MOTOR_FORWARD 6     // IN1 (D6)
#define LEFT_MOTOR_ENABLE 11     // ENA (PWM)
#endif


void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);
