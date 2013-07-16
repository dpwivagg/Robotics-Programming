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

//++++++++++++++++++++++++++++++++++++++++++ U-Turn Left +++++++++++++++++++++++++++++++++++++++++++

void uturnLeft() {
	
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

//++++++++++++++++++++++++++++++++++++++++++ U-Turn Right +++++++++++++++++++++++++++++++++++++++++++

void uturnRight() {
	
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

//++++++++++++++++++++++ Travel in a straight line until intersection left ++++++++++++++++++++

void lineUIL() {
	
	while(placeholder == 0){
		sensorLeftInt = SensorValue[sensorLeft];
		sensorRightInt = SensorValue[sensorRight];
		sensorMiddleInt = SensorValue[sensorMiddle];

		if(sensorMiddleInt > 2000){
			motor[leftMotor] = 90;
			motor[rightMotor] = 82;
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
			motor[rightMotor] = 82;
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


//+++++++++++++++++++++++++++++++++++++++++++++| Route 1 |+++++++++++++++++++++++++++++++++++++++++++++

void route1() {
	
	lineUIR();
	
	pauseReset(1);
	
	rightTurn();
	
	pauseReset(1);
	
	lineUIR();
	
	pauseReset(1);
	
	motor[leftMotor] = motor[rightMotor] = -50;
	
	wait1Msec(150);
	
	pauseReset(1);
	
	rightTurn();
	
	pauseReset(1);
	
	uturnRight();
	
	pauseReset(1);
	
	lineUIL();
	
	pauseReset(1);
	
	leftTurn();
	
	pauseReset(1);
	
	while(placeholder == 0){
		sensorLeftInt = SensorValue[sensorLeft];
		sensorRightInt = SensorValue[sensorRight];
		sensorMiddleInt = SensorValue[sensorMiddle];

		if(sensorMiddleInt > 2000){
			motor[leftMotor] = 90;
			motor[rightMotor] = 82;
		}

		if(sensorRightInt > 2000){
			motor[leftMotor] = 100;
			motor[rightMotor] = 60;
		}

		if(sensorLeftInt > 2000){
			motor[leftMotor] = 60;
			motor[rightMotor] = 100;
		}
		
		if(encoderRightInt > 75 || encoderLeftInt > 75) {
			motor[leftMotor] = motor[rightMotor] = 0;
			
			placeholder++;
			
		}

	}

}

//+++++++++++++++++++++++++++++++++++++++++++++| Route 2 |+++++++++++++++++++++++++++++++++++++++++++++

void route2() {
	
	lineUIL();
	
	pauseReset(1);
	
	leftTurn();
	
	pauseReset(1);
	
	motor[rightMotor] = 40;
	
	wait1Msec(150);
	
	pauseReset(1);
	
	lineUIL();
	
	pauseReset(1);
	
	leftTurn();
	
	pauseReset(1);
	
	lineUIR();
	
	rightTurn();
	
	pauseReset(1);
	
	uturnRight();
	
	pauseReset(1);
	
	lineUIL();
	
	pauseReset(1);
	
	leftTurn();
	
	pauseReset(1);
	
	lineUIR();
	
	pauseReset(1);
	
	rightTurn();
	
	pauseReset(1);
	
	lineUIR();
	
	pauseReset(1);
	
	while(placeholder == 0){
		sensorLeftInt = SensorValue[sensorLeft];
		sensorRightInt = SensorValue[sensorRight];
		sensorMiddleInt = SensorValue[sensorMiddle];

		if(sensorMiddleInt > 2000){
			motor[leftMotor] = 90;
			motor[rightMotor] = 82;
		}

		if(sensorRightInt > 2000){
			motor[leftMotor] = 100;
			motor[rightMotor] = 60;
		}

		if(sensorLeftInt > 2000){
			motor[leftMotor] = 60;
			motor[rightMotor] = 100;
		}
		if(encoderRightInt > 125 || encoderLeftInt > 125) {
			motor[leftMotor] = motor[rightMotor] = 0;
			
			placeholder++;
			
		}

	}

}

//+++++++++++++++++++++++++++++++++++++++++++++| Route 3 |+++++++++++++++++++++++++++++++++++++++++++++

void route3() {
	
	lineUIL();
	
	pauseReset(1);
	
	leftTurn();
	
	pauseReset(1);
	
	lineUIR();
	
	pauseReset(1);
	
	rightTurn();
	
	pauseReset(1);
	
	lineUIR();
	
	pauseReset(1);
	
	rightTurn();
	
	pauseReset(1);
	
	motor[leftMotor] = motor[rightMotor] = -60;
	
	wait1Msec(450);
	
	pauseReset(1);
	
	rightTurn();
	
	pauseReset(1);
	
	lineUIL();
	
	pauseReset(1);
	
	leftTurn();
	
	pauseReset(1);
	
	lineUIR();
	
	pauseReset(1);
	
	lineUIR();
	
	pauseReset(1);
	
	rightTurn();
	
	while(placeholder == 0){
		sensorLeftInt = SensorValue[sensorLeft];
		sensorRightInt = SensorValue[sensorRight];
		sensorMiddleInt = SensorValue[sensorMiddle];

		if(sensorMiddleInt > 2000){
			motor[leftMotor] = 90;
			motor[rightMotor] = 82;
		}

		if(sensorRightInt > 2000){
			motor[leftMotor] = 100;
			motor[rightMotor] = 60;
		}

		if(sensorLeftInt > 2000){
			motor[leftMotor] = 60;
			motor[rightMotor] = 100;
		}
		
		if(encoderRightInt > 125 || encoderLeftInt > 125) {
			motor[leftMotor] = motor[rightMotor] = 0;
			
			placeholder++;
			
		}

	}

}

//+++++++++++++++++++++++++++++++++++++++++++++| Route 4 |+++++++++++++++++++++++++++++++++++++++++++++

void route4() {
	
	lineUIR();
	
	pauseReset(1);
	/*
	if(SensorValue[sensorRight] < 2000 && SensorValue[sensorLeft] < 2000 && SensorValue[sensorMiddle] < 2000) {
		
		motor[leftMotor] = -50;
		motor[rightMotor] = 50;
		
		if(SensorValue[sensorLeft] > 2000) {
			
			motor[leftMotor] = 80;
			motor[rightMotor] = -80;
			wait1Msec(45);
			motor[leftMotor] = motor[rightMotor] = 0;
			
		}
		
	}
	
	pauseReset(1);
	*/
	lineUIR();
	
	pauseReset(1);
	
	lineUIR();
	
	pauseReset(1);
	
	if(SensorValue[sensorRight] > 2000) {
		
		motor[leftMotor] = 50;
		motor[rightMotor] = -50;
		
		if(SensorValue[sensorMiddle] > 2000) {
			
			motor[leftMotor] = -80;
			motor[rightMotor] = 80;
			wait1Msec(45);
			motor[leftMotor] = motor[rightMotor] = 0;
			
		}
		
	}
	
	pauseReset(1);
	
	rightTurn();
	
	pauseReset(1);
	
	uturnRight();
	
	pauseReset(1);
	
	while(placeholder == 0){
		sensorLeftInt = SensorValue[sensorLeft];
		sensorRightInt = SensorValue[sensorRight];
		sensorMiddleInt = SensorValue[sensorMiddle];

		if(sensorMiddleInt > 2000){
			motor[leftMotor] = 90;
			motor[rightMotor] = 82;
		}

		if(sensorRightInt > 2000){
			motor[leftMotor] = 100;
			motor[rightMotor] = 60;
		}

		if(sensorLeftInt > 2000){
			motor[leftMotor] = 60;
			motor[rightMotor] = 100;
		}
		
		if(encoderRightInt > 175 || encoderLeftInt > 175) {
			motor[leftMotor] = motor[rightMotor] = 0;
			
			placeholder++;
			
		}

	}

}

//+++++++++++++++++++++++++++++++++++++++++++++| Route 5 |+++++++++++++++++++++++++++++++++++++++++++++

void route5() {
	
	lineUIR();
	
	pauseReset(1);
	
	if(SensorValue[sensorRight] > 2000) {
		
		motor[leftMotor] = 50;
		motor[rightMotor] = -50;
		
		if(SensorValue[sensorMiddle] > 2000) {
			
			motor[leftMotor] = -80;
			motor[rightMotor] = 80;
			wait1Msec(45);
			motor[leftMotor] = motor[rightMotor] = 0;
			
		}
		
	}
	
	pauseReset(1);
	
	lineUIR();
	
	pauseReset(1);
	
	rightTurn();
	
	pauseReset(1);
	
	lineUIL();
	
	pauseReset(1);
	
	leftTurn();
	
	pauseReset(1);
	
	lineUIL();
	
	pauseReset(1);
	
	leftTurn();
	
	pauseReset(1);
	
	lineUIL();
	
	pauseReset(1);
	
		while(placeholder == 0){
		sensorLeftInt = SensorValue[sensorLeft];
		sensorRightInt = SensorValue[sensorRight];
		sensorMiddleInt = SensorValue[sensorMiddle];

		if(sensorMiddleInt > 2000){
			motor[leftMotor] = 90;
			motor[rightMotor] = 82;
		}

		if(sensorRightInt > 2000){
			motor[leftMotor] = 100;
			motor[rightMotor] = 60;
		}

		if(sensorLeftInt > 2000){
			motor[leftMotor] = 60;
			motor[rightMotor] = 100;
		}
		
		if(encoderRightInt > 200 || encoderLeftInt > 200) {
			motor[leftMotor] = motor[rightMotor] = 0;
			
			placeholder++;
			
		}

	}

}


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |++++++++++++++++++++++++++++++++++++++++++++++++++

task main ()
{

	int buttonPressed = 0;

	while(buttonPressed == 0) {

		if(vexRT[Btn7D] == 1) {
			route1();
			buttonPressed++;
		}

		if(vexRT[Btn7L] == 1) {
			route2();
			buttonPressed++;
		}

		if(vexRT[Btn7U] == 1) {
			route3();
			buttonPressed++;
		}

		if(vexRT[Btn7R] == 1) {
			route4();
			buttonPressed++;
		}

		if(vexRT[Btn8D] == 1) {
			route5();
			buttonPressed++;
		}

	}

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
