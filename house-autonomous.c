#pragma config(Sensor, in6,    clawAngle,      sensorPotentiometer)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  sonarInput,     sensorSONAR_inch)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           claw,          tmotorVex393, openLoop)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393, openLoop)

#include "movement.h"

/*

//+++++++++++++++++++++++++++++++++++++++++++++| Public Integers |++++++++++++++++++++++++++++++++++++++++

int x = 0;
int y = 0;
int z = 0;

//+++++++++++++++++++++++++++++++++++++++++++++| Stop |++++++++++++++++++++++++++++++++++++++++++++++

void pause(int seconds) {
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
	wait1Msec(seconds * 1000);
}

//+++++++++++++++++++++++++++++++++++++++++++++| Straight Line |++++++++++++++++++++++++++++++++++++++++

void straightLine(int distance) {
	while(x < distance || y < distance) {

		x = SensorValue[rightEncoder];
		y = SensorValue[leftEncoder];

		motor[leftMotor] = 100;
		motor[rightMotor] = 100;

		if(x > y){
			motor[leftMotor] = 127;
			motor[rightMotor] = 50;
		}

		if(y > x){
			motor[leftMotor] = 50;
			motor[rightMotor] = 127;
		}

	}

	x = 0;
	y = 0;
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;

}

void straightLine() {

	x = SensorValue[rightEncoder];
	y = SensorValue[leftEncoder];

	motor[leftMotor] = 100;
	motor[rightMotor] = 100;

	if(x > y){
		motor[leftMotor] = 127;
		motor[rightMotor] = 50;
	}

	if(y > x){
		motor[leftMotor] = 50;
		motor[rightMotor] = 127;
	}



	x = 0;
	y = 0;
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;

}

//+++++++++++++++++++++++++++++++++++++++++++++| Right Angle Right Turn |+++++++++++++++++++++++++++++++++

void rightAngleTurnRight() {
	while(x > -492 && y < 492) {

		motor[leftMotor] = 90;
		motor[rightMotor] = -90;

		x = SensorValue[rightEncoder];
		y = SensorValue[leftEncoder];

	}

	x = 0;
	y = 0;
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;

}

//+++++++++++++++++++++++++++++++++++++++++++++| Right Angle Left Turn |+++++++++++++++++++++++++++++++++

void rightAngleTurnLeft() {
	while(x < 492 && y > -492) {

		motor[leftMotor] = -90;
		motor[rightMotor] = 90;

		x = SensorValue[rightEncoder];
		y = SensorValue[leftEncoder];

	}

	x = 0;
	y = 0;
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;

}

//+++++++++++++++++++++++++++++++++++++++++++++| Follow Line |+++++++++++++++++++++++++++++++++

void followLine() {

	while(sensorMiddle > 600) {

		sensorLeft = SensorValue[sensorLeft];
		sensorRight = SensorValue[sensorRight];
		sensorMiddle = SensorValue[sensorMiddle];

		motor[leftMotor] = 100;
		motor[rightMotor] = 100;

		if(sensorRight > 600){
			motor[leftMotor] = 127;
			motor[rightMotor] = 50;
		}

		if(sensorLeft > 600){
			motor[leftMotor] = 50;
			motor[rightMotor] = 127;
		}
		
	}

}

*/

//+++++++++++++++++++++++++++++++++++++++++++++| Route 1 |+++++++++++++++++++++++++++++++++++++++++++++

void route1() {

}

//+++++++++++++++++++++++++++++++++++++++++++++| Route 2 |+++++++++++++++++++++++++++++++++++++++++++++

void route2() {

}

//+++++++++++++++++++++++++++++++++++++++++++++| Route 3 |+++++++++++++++++++++++++++++++++++++++++++++

void route3() {

}

//+++++++++++++++++++++++++++++++++++++++++++++| Route 4 |+++++++++++++++++++++++++++++++++++++++++++++

void route4() {

}

//+++++++++++++++++++++++++++++++++++++++++++++| Route 5 |+++++++++++++++++++++++++++++++++++++++++++++

void route5() {

}


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |++++++++++++++++++++++++++++++++++++++++++++++++++

task main ()
{

	bool buttonPressed = false;
	
	while(buttonPressed == false) {
	
		if(vexRT[Btn7D] == 1) {
			route1();
			buttonPressed = true;
		}
		
		if(vexRT[Btn7L] == 1) {
			route2();
			buttonPressed = true;
		}
		
		if(vexRT[Btn7U] == 1) {
			route3();
			buttonPressed = true;
		}
		
		if(vexRT[Btn7R] == 1) {
			route4();
			buttonPressed = true;
		}
		
		if(vexRT[Btn8D] == 1) {
			route5();
			buttonPressed = true;
		}
		
	}

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++			
