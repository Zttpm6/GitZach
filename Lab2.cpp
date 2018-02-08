//============================================================================
// Name        : Lab2.cpp
// Author      : Zach Taylor
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
	int x = 0;
	int num = 0;
	unsigned short num1 = 1;
	unsigned long answer1 = 1;
	unsigned int year = 0;
	float max1, max2;
	int div1, div2;
	float danswer = 0;

	while(x == 0){
		cout << "Main Menu" << endl << "For Factorial---1 "<<endl;
		cout << "For Leap Year --2"<< endl << "For Maximum--3"<<endl;
		cout << "For Division-- 4"<< endl << "For Exit --5" << endl; // prints
		cin >> num;
		cout << "Git hub practice" << endl;
		while(num > 5 || num < 1)
		{
			cin >> num;
		}
		switch(num){
			case 1:
				cout << "Enter a number for factorial" << endl;
				cin >> num1;
				answer1 = 1;
				while(num1 < 0 || num1 > 20){
					cout << "Please enter a number between 1-12" << endl;
					cin >> num1;
				}
				for(int i = 1; i <=num1; ++i)
				{
					answer1 *= i;
				}
				cout << "Factorial of " << num1 << " is " << answer1 << endl;
			break;
			case 2:
				cout << "Enter a year you would like to check if a leap-year or not"<< endl;
				cin >> year;
				while(year < 1){
					cout << "Please enter a valid year"<< endl;
					cin >> year;
				}
				if( year % 4 == 0)
				{
					if (year %100 ==0)
					{
						if(year % 400==0)
						{
							cout << "The year " << year << " is a leap year" << endl;
						}
						else
						{
							cout << "The year " << year << " is not a leap year" << endl;
						}
					}
					else
					{
						cout << "The year " << year << " is a leap year" << endl;
					}
				}
				else
				{
					cout << "The year " << year << " is not a leap year" << endl;
				}
			break;
			case 3:
				cout << "Enter two numbers to see which one is max" << endl;
				cin >> max1 >> max2;
				cout << (max1 > max2 ? max1 : max2) << " is greater." << endl;
			break;
			case 4:
				cout << "Enter two numbers to divide" << endl;
				cin >> div1 >> div2;
				while(div2 == 0){
					cout << "Can't divide by zero" << endl;
					cin >> div2;
				}
				danswer = static_cast<float> (div1) / static_cast<float> (div2);
				cout << div1 << " divided by " << div2 << " is " << danswer << endl;
			break;
			case 5:
				return 0;
			break;
			}

		}
	return 0;
	}
