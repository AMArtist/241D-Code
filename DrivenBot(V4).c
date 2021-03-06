#pragma config(Motor,  port2,           DriveR,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           DriveL,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,	LiftRU,	tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,	LiftRD,	tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,	LiftRS,	tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,	LiftLU,	tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,	LiftLD,	tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,	LiftLS,	tmotorVex393_MC29, openLoop, reversed)
// Ports one through nine are all lift
//  Y-cables for the left and right side of the drive
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma CompetitionControl(Competition)

#pragma autonomousDuration(15)
#pragma UserControlDuration(120)

#include "Vex_Competition_Includes.c"

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void pre_auton (){
}

/* ^ im pretty sure the void pre_auton has to be here, not quite sure why yet ^
// \/ This Here is just a test autonomous to see if it works, we will be changing this */

task autonomous()
{
	motor[DriveR]= -127;
	motor[DriveL]= -127;
	wait1Msec(2400);

	motor[DriveR]= 0;
	motor[DriveL]= 0;
	wait1Msec(20);

	motor[LiftRU]=127;
	motor[LiftRD]=127;
	motor[LiftRS]=127;
	motor[LiftLU]=127;
	motor[LiftLD]=127;
	motor[LiftLS]=127;
	wait1Msec(1000);

	motor[LiftRU]=0;
	motor[LiftRD]=0;
	motor[LiftRS]=0;
	motor[LiftLU]=0;
	motor[LiftLD]=0;
	motor[LiftLS]=0;
	wait1Msec(20);
}
/*  moves back for 2 sec & 400 Msec's, then moves the lift up for a second*/
task usercontrol()
{while (1==1)
	{
		//Right joystick controls right wheels
		motor[DriveR] = vexRT[Ch2];
		//Left joystick controls left wheels
		motor[DriveL] = vexRT[Ch3];
		int x = 0;
		if(vexRT[Btn8D])
		{
			startTask(autonomous);
			while(x <= 15000){
				wait1Msec(1);
				x++;
			}
		}
		/* press the bottom button of the 4 right buttons to
		start the autonomous (it will stop you from being able to control
		the bot in any other way for 15 seconds*/
		if (vexRT[Btn6U] == 1)
		{
			motor[LiftRU] = 127;
			motor[LiftRD] = 127;
			motor[LiftLU] = 127;
			motor[LiftLD] = 127;
			motor[LiftRS] = 127;
			motor[LiftLS] = 127;
			/*this will move both sides of the lift down when
			button 6D ( the upper right button on the back)
			is pressed*/
		}
		else if (vexRT[Btn6D] == 1)
		{
			motor[LiftRU] = -127;
			motor[LiftRD] = -127;
			motor[LiftLU] = -127;
			motor[LiftLD] = -127;
			motor[LiftRS] = -127;
			motor[LiftLS] = -127;
			/* this will move both sides of the lift up when
			button 6U ( the lower right button on the back)
			is pressed */
		}
		else
		{
			motor[LiftRU] = 0;
			motor[LiftRD] = 0;
			motor[LiftLU] = 0;
			motor[LiftLD] = 0;
			motor[LiftRS] = 0;
			motor[LiftLS] = 0;
			/* this will stop the lift when neither of those
			buttons are being pressed */
		}
	}
}
/* So now we will be using Y-cables for each side of the drive. 10/26/16 */
