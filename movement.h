#pragma config(Sensor, in6,    clawAngle,      sensorPotentiometer)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  sonarInput,     sensorSONAR_inch)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           claw,          tmotorVex393, openLoop)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393, openLoop)

int x;

int y;

int z;

int sensorLeft;

int sensorRight;

int sensorMiddle;

void rightAngleTurnRight();

void rightAngleTurnLeft();

void straightLine(int distance);

void straightLine();

void pause(int seconds);

void followLine();
