//============================================================================
// Name        : Lab2part2.cpp
// Author      : Zach Taylor
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;
const int SIZE = 16;
#include <bitset>

int main() {
	unsigned short dec = 0;
	int choice;
	int binary[SIZE];
	int remain = 0;
	int i = 1;
	cout << "Enter a decimal number:"; // prints
	cin >> dec;
	while(0 > dec || dec >65535)
	{
		cout << endl << "Please enter a valid input" << endl;
		cin >> dec;
	}
	cout << endl << "Please enter the desired way" << endl << "1- Arithmetic" << endl;
	cout << "2- Bitwise" << endl;

	cin >> choice;
	while( choice < 1 || choice > 2)
	{
		cout <<"Please enter a valid choice" << endl;
		cin >> dec;
	}
	switch(choice){
	case 1:
	{
		while(dec!=0)
		{
			remain = dec % 2;
			dec /= 2;
			binary[16-i] = remain;
			i++;

		}
		for(i=0; i<SIZE; i++)
		{
			if(binary[i] != 1)
			{
				cout << '0';
			}
			else
			{
				cout << binary[i];
			}
		}
		cout << endl;
		break;
	}
	case 2:
	{
		i = SIZE - 1;

		    while(i >= 0)
		    {
		        binary[i] = dec & 1;
		        i--;

		        dec >>= 1;
		    }
		    for(i=0; i<SIZE; i++)
		    {
		           cout << binary[i];
		    }
		    break;
	}

	return 0;
	}
}
