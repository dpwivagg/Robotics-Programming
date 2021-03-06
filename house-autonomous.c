#pragma config(Sensor, in1,    sensorLeft,     sensorLineFollower)
#pragma config(Sensor, in2,    sensorMiddle,   sensorLineFollower)
#pragma config(Sensor, in3,    sensorRight,    sensorLineFollower)
#pragma config(Sensor, in4,    clawAngle,      sensorPotentiometer)
#pragma config(Sensor, in5,    armAngle,       sensorPotentiometer)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  sonarInput,     sensorSONAR_inch)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393, openLoop)
#pragma config(Motor,  port5,           arm,           tmotorVex393, openLoop)
#pragma config(Motor,  port6,           claw,          tmotorVex393, openLoop)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393, openLoop, reversed)

int armAngleInt = 0;
int clawAngleInt = 0;
int encoderRightInt = 0;
int encoderLeftInt = 0;
int placeholder = 0;
int sensorLeftInt = 0;
int sensorRightInt = 0;
int sensorMiddleInt = 0;

//++++++++++++++++++++++ Travel in a straight line until intersection left ++++++++++++++++++++

void lineUIL() {
	
	while(placeholder == 0){
		sensorLeftInt = SensorValue[sensorLeft];
		sensorRightInt = SensorValue[sensorRight];
		sensorMiddleInt = SensorValue[sensorMiddle];

		if(sensorMiddleInt > 2000){
			motor[leftMotor] = 90;
			motor[rightMotor] = 90;
		}

		if(sensorRightInt > 2000){
			motor[leftMotor] = 100;
			motor[rightMotor] = 60;
		}

		if(sensorLeftInt > 2000){
			motor[leftMotor] = 60;
			motor[rightMotor] = 100;
		}

		if(sensorLeftInt > 2000 && sensorMiddleInt > 2000){
			wait1Msec(500);
			motor[leftMotor] = motor[rightMotor] = 0;
			placeholder++;
		}
	}
	
}

//++++++++++++++++++++++ Travel in a straight line until intersection right ++++++++++++++++++++

void lineUIR() {
	
	while(placeholder == 0){
		sensorLeftInt = SensorValue[sensorLeft];
		sensorRightInt = SensorValue[sensorRight];
		sensorMiddleInt = SensorValue[sensorMiddle];

		if(sensorMiddleInt > 2000){
			motor[leftMotor] = 90;
			motor[rightMotor] = 90;
		}

		if(sensorRightInt > 2000){
			motor[leftMotor] = 100;
			motor[rightMotor] = 60;
		}

		if(sensorLeftInt > 2000){
			motor[leftMotor] = 60;
			motor[rightMotor] = 100;
		}

		if(sensorRightInt > 2000 && sensorMiddleInt > 2000){
			wait1Msec(500);
			motor[leftMotor] = motor[rightMotor] = 0;
			placeholder++;
		}
	}
	
}

//+++++++++++++++++++++++++++++++++++++++ Turn right +++++++++++++++++++++++++++++++++++++++++

void rightTurn() {
	
	while(placeholder == 0){
	
		sensorLeftInt = SensorValue[sensorLeft];
		sensorRightInt = SensorValue[sensorRight];
		sensorMiddleInt = SensorValue[sensorMiddle];

		motor[leftMotor] = 50;
		motor[rightMotor] = -50;

		if(sensorRightInt > 2000){
			wait1Msec(100);
			motor[leftMotor] = -80;
			motor[rightMotor] = 80;
			wait1Msec(45);
			placeholder++;
		}
	}
	
}

//+++++++++++++++++++++++++++++++++++++++ Turn left +++++++++++++++++++++++++++++++++++++++++

void leftTurn() {
	
	while(placeholder == 0){
	
		sensorLeftInt = SensorValue[sensorLeft];
		sensorRightInt = SensorValue[sensorRight];
		sensorMiddleInt = SensorValue[sensorMiddle];

		motor[leftMotor] = -50;
		motor[rightMotor] = 50;

		if(sensorLeftInt > 2000){
			wait1Msec(100);
			motor[leftMotor] = 80;
			motor[rightMotor] = -80;
			wait1Msec(45);
			placeholder++;
		}
	}
	
}

//+++++++++++++++++++++++++++++++++++++++ Pause +++++++++++++++++++++++++++++++++++++++++

void pauseReset(int seconds) {
	motor[leftMotor] = motor[rightMotor] = 0;

	wait1Msec(seconds * 1000);

	sensorLeftInt = 0;
	sensorRightInt = 0;
	sensorMiddleInt = 0;

	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	
	encoderLeftInt = 0;
	encoderRightInt = 0;
	
	placeholder = 0;
}

//+++++++++++++++++++++++++++++++++++++++ Object Check +++++++++++++++++++++++++++++++++++++++++

void objectCheck() {
	if(SensorValue[sonarInput] > 4 && SensorValue[sonarInput] < 15){
		armAngleInt = SensorValue[armAngle];
		while(armAngleInt > 325){
			armAngleInt = SensorValue[armAngle];
			motor[arm] = -70;
		}
	}
}

//+++++++++++++++++++++++++++++++++++++++ MAIN +++++++++++++++++++++++++++++++++++++++++

task main() {
	
	lineUIR();
	
	pauseReset(1);
	
	lineUIR();
	
	pauseReset(1);
	
	lineUIR();
	
	pauseReset(1);
	
	rightTurn();
	
	pauseReset(1);
	
	objectCheck();
	
}
