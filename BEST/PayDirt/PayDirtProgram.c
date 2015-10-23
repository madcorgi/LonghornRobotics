#pragma config(Motor,  port2,           RightDriveMotor, tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           LeftDriveMotor, tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port4,           LiftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           OpenClawServo, tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           RotateClawServo, tmotorServoStandard, openLoop)
#pragma config(Motor,  port7,           TrapDoorServo, tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void moveServo(int servoId, bool moveClockwise)
{
	short increment;
	short position;
	if (moveClockwise == true)
	{
		increment = 10;
	}
	else
	{
		increment = -10;
	}

	position = motor[servoId] + increment;

	if (position < 128 && position > -128)
	{
		motor[servoId] += increment;
	  wait1Msec(50);
	}
}

task main()
{

	while (1 == 1)
	{
		motor[LeftDriveMotor] = vexRT[Ch3];
		motor[RightDriveMotor] = vexRT[Ch2];

		//wait1Msec(100);
		if (vexRT[Btn5U] == 1)
		{
			motor[LiftMotor] = 100;
		}
		else if (vexRT[Btn5D] == 1)
		{
			motor[LiftMotor] = -100;
		}
		else
    {
			motor[LiftMotor] = 0;
		}

		if (vexRT[Btn6U] == 1)
		{
			moveServo(OpenClawServo, false);
		}
		else if (vexRT[Btn6D] == 1)
		{
			moveServo(OpenClawServo, true);
		}

		if (vexRT[Btn7L] == 1)
		{
			moveServo(RotateClawServo, true);
		}
		else if (vexRT[Btn7R] == 1)
		{
			moveServo(RotateClawServo, true);
		}

		if (vexRT[Btn6U] == 1)
		{
			moveServo(TrapDoorServo, false);
		}
		else if (vexRT[Btn6D] == 1)
		{
			moveServo(TrapDoorServo, true);
		}
	}//end of loop
}
