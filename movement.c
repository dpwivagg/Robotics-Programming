#include "movement.h" 

x = 0;

y = 0;

z = 0;

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

void pause(int seconds) {
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
	wait1Msec(seconds * 1000);
}

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
