//============================================================================
// Name        : Lab9.cpp
// Author      : Zach Taylor
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unistd.h>		// sleep, usleep functions
#include <wiringPi.h>	// needed for the wiringPi functions

#define LED1  8
#define LED2  9
#define LED3  7
#define LED4  21
// wiringPi number corresponding to GPIO2.
					//Check Figures 2 and 3 in the Lab9 guide.

int main(int argc, char **argv)
{
	wiringPiSetup();	// wiringPiSetupGpio() could be used. The numbers for the ports would
						// need to match the RPi GPIO pinout.
	int i =0;
	pinMode(LED4, OUTPUT);
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);// Configure GPIO2, which is the one connected to the red LED.

	// The program will turn off the red LED, sleep for a while, then on, sleep, off, on and off.
	// You could use loops, if you wanted/needed.
	while(i <= 3)
	{
		digitalWrite(LED1, LOW);
		sleep(1);	// How can you sleep for less than a second?
		digitalWrite(LED2, LOW);
		sleep(1);
		digitalWrite(LED3, LOW);
		sleep(1);
		digitalWrite(LED4, LOW);
		sleep(1);
		digitalWrite(LED4, HIGH);
		sleep(1);
		digitalWrite(LED3, HIGH);
		sleep(1);
		digitalWrite(LED2, HIGH);
		sleep(1);
		digitalWrite(LED1, HIGH);
		sleep(1);
		i++;
	}
    return 0;
}
