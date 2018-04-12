//============================================================================
// Name        : Lab7.cpp
// Author      : Zach Taylor
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>

using namespace std;

char letters[]=
{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u', 'v','w','x','y','z',};
string morse[] =
{".-","-..","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.",
"---",".--.","--.-",".-.","...","-","..-","..-","...-",".--","-..-","-.--","--.."};

class Message{
protected:
	string message;
public:
	Message();
	Message(string s);
	~Message();
	void Print();
};
void Message:: Print(void){
    cout<<"The untranslated string is "<< message<<endl;
}
Message::Message( string input )
{

    message = input;

}
Message::Message(){

    cout<<"Enter a string or word you would like to convert enter a * to end it:  "<<endl;

}

Message::~Message(){
    //no memory is allocated.
}


class MorseCodeMessage: public Message{ //class to store and translate morse code
public:
	MorseCodeMessage(string input);
	void translate(string input);
	void printmorse();
	string message;
	~MorseCodeMessage();
};
void MorseCodeMessage::printmorse(){

    cout<<"Translated is:"<<message<<endl;
}
MorseCodeMessage::MorseCodeMessage(string input) : Message(input) {

    translate(input);

}
void MorseCodeMessage::translate( string input)// translate this stuff muffins
{
    locale loc;

    for(int i = 0; i < input.length(); i++)
    {
        if( input[i] == ' ')
        {
            message += "    ";
        }
        for( int j = 0; j < 26; j++)
        {
           input[i] = tolower(input[i], loc);
            if( input[i] == letters[j])
            {
                message += morse[j];
            }
        }
    }
   // cout<<""<<message<<endl; for testing purpose
}
MorseCodeMessage::~MorseCodeMessage() {
    // no memory allocated
}



class MessageStack{// pushes on to a vector string
    private:
            string* stack_message;
            string* stack[20];
    public:
            MessageStack();
            ~MessageStack();
            void pushstack( string *stack_message, int c);
            void popstack(int c);
            void print( int c);
};

MessageStack :: MessageStack(){
    stack_message = new string;
}
void MessageStack :: pushstack(string *stack_message, int c){
    stack[c] = new string;
    *stack[c] = *stack_message;
}
void MessageStack :: popstack(int c){
    cout << "Element " << c << " was popped from the stack" << endl;
}
void MessageStack :: print(int c){
    int i;
    cout << "Printing Stack: " << endl;
    for(i=0;i<c;i++){
        cout << "Element " << (i+1) << ": " << *stack[i] << endl;
    }
}
MessageStack :: ~MessageStack(){
}


int main() {
	string input;
	int choice = 1;
	int trans = 0;
	int i = 0;
	while(choice!=0)
	{
		Message();
		getline(cin,input,'*');
		Message user(input);
		MorseCodeMessage convert(input);
		convert.printmorse();
		cout << "To exit press 0" << endl << "Anything else will continue"<< endl;
		cin >> choice;
	}
	MessageStack stack;
	while(choice !=4){
		cout << "Stack Menu:" << endl;
		cout << "1: Push Message" << endl;
		cout << "2. Pop Message" << endl;
		cout << "3. Print Stack" << endl;
		cout << "4. Exit the program" << endl;
		cin  >> choice;
		while(choice > 4 || choice < 1)
		{
			cout << "Please enter a valid choice" << endl;
			cin >> choice;
		}
		switch(choice){
			case 1:
				cout<<"Enter a message to push end with *"<<endl;
                getline(cin,input,'*');
                cout << "Would you like to translate this sentence?" << endl;
                cout << "1. Yes" << endl << "2.NAHHHHHHHH" << endl;
                cin >> trans;
                while(trans > 2 || trans < 1)
                {
                	cout << "1. Yess 2. Nah " << endl << trans << "This isn't a 1 or 2" << endl;
                	cin >> trans;
                }
                if(trans == 2)
                {
                	stack.pushstack(&input, i);
                	i++;
                }
                else
                {
                	MorseCodeMessage convert(input);
                	convert.printmorse(); // testing purposes
                	stack.pushstack(&convert.message,i);
                	i++;
                }
                break;
			case 2:
				if(i == 0)
				{
					cout << "Stack is empty" << endl;
				}
				else
				{
					stack.popstack(i);
					i--;
				}
				break;
			case 3:
				stack.print(i);
				break;
		}
	}
	cout << "This is the end" << endl;
	return 0;
}
