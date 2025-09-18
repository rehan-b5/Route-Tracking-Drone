#include <Adafruit_MotorShield.h>

//Defining motors
#define Motor_Terminal_A 1
#define Motor_Terminal_B 2
#define Motor_Terminal_C 3
#define Motor_Terminal_D 4

//Define IR sensors
#define IR1 9
#define IR2 10

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *MOTOR_A = AFMS.getMotor(Motor_Terminal_A);
Adafruit_DCMotor *MOTOR_B = AFMS.getMotor(Motor_Terminal_B);
Adafruit_DCMotor *MOTOR_C = AFMS.getMotor(Motor_Terminal_C);
Adafruit_DCMotor *MOTOR_D = AFMS.getMotor(Motor_Terminal_D);

void setup() {
  AFMS.begin();

  //Resetting motors
  MOTOR_A->setSpeed(0);
  MOTOR_A->run(RELEASE);

  MOTOR_B->setSpeed(0);
  MOTOR_B->run(RELEASE);

  MOTOR_C->setSpeed(0);
  MOTOR_C->run(RELEASE);

  MOTOR_D->setSpeed(0);
  MOTOR_D->run(RELEASE);

  //Setting IR sensor pins
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
}

void loop() {
  int sensor_A = digitalRead(IR1);
  Serial.println(sensor_A);
  int sensor_B = digitalRead(IR2);
  Serial.println(sensor_B);

  if(sensor_A==0 && sensor_B==0){
    MOTOR_A->setSpeed(255);
    MOTOR_A->run(FORWARD);

    MOTOR_B->setSpeed(255);
    MOTOR_B->run(FORWARD);

    MOTOR_C->setSpeed(255);
    MOTOR_C->run(FORWARD);

    MOTOR_D->setSpeed(255);
    MOTOR_D->run(FORWARD);   
  }else if(sensor_A==1 && sensor_B==0){
    //Turns right
    MOTOR_A->setSpeed(255);
    MOTOR_A->run(FORWARD);

    MOTOR_B->setSpeed(255);
    MOTOR_B->run(FORWARD);

    MOTOR_C->setSpeed(0);
    //MOTOR_C->run(BACKWARD);

    MOTOR_D->setSpeed(0);
    //MOTOR_D->run(BACKWARD); 
  }else if(sensor_A==0 && sensor_B==1){
    //Turns left
    MOTOR_A->setSpeed(0);
    //MOTOR_A->run(BACKWARD);

    MOTOR_B->setSpeed(0);
    //MOTOR_B->run(BACKWARD);

    MOTOR_C->setSpeed(255);
    MOTOR_C->run(FORWARD);

    MOTOR_D->setSpeed(255);
    MOTOR_D->run(FORWARD); 
  }else{
    MOTOR_A->setSpeed(0);
    MOTOR_A->run(RELEASE);

    MOTOR_B->setSpeed(0);
    MOTOR_B->run(RELEASE);

    MOTOR_C->setSpeed(0);
    MOTOR_C->run(RELEASE);

    MOTOR_D->setSpeed(0);
    MOTOR_D->run(RELEASE);
  }
}
