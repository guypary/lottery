#include "user.h"
#include <iostream>
#include <string>

using namespace std;

string user::getName(){
	return userName;
}

int* user::getNumbers(){
	return numbers;
}

void user::inputName(){
	cout<<"Please enter your Name: "<<endl;
	cin>> userName;
}

void user::inputNumbers(){
	for(int i=0; i<6; i++){
		cout << "Please enter number #" << i << ": ";
		int number;
		cin >> number;

		if(!cin){
			cout << "Error while getting input!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			i--;
		}
		else{
			//check if the number is already contained in our array
			bool isAlreadyEntered = false;
			for(int j=0; j<i; j++){
				if(numbers[j] == number){
					isAlreadyEntered = true;
					break;
				}
			}


			if(!isAlreadyEntered){
				if(number > 0 && number < 50){
					numbers[i] = number;
				}
				else{
					i--;
					cout << "Number was out of range!" << endl;
				}
			}
			else{
				i--;
				cout << "The number was already entered!" << endl;
			}
		}
	}
}