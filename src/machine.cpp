#include <string>
#include "machine.h"
#include <cstdlib>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <vector>
using namespace std;

machine::machine(){
	ticketsEntered = false;
	numbersDrawn = false;
}

bool machine::areTicketsEntered(){
	return ticketsEntered;
}

bool machine::areNumbersDrawn(){
	return numbersDrawn;
}

void machine::enterTicket(){
	user u1;
	u1.inputName();
	u1.inputNumbers();

	userlist.push_back(u1);

	ticketsEntered = true;
}

void machine::drawNumbers(){

	vector<int> numberVector;
	for(int i=MIN_NUMBER; i<=MAX_NUMBER; i++){
		numberVector.push_back(i);
	}

	srand((unsigned)time(NULL));
	rand ();

	for( int i = 0 ; i < 6; i++ ){
		int randomNumber = (rand () % numberVector.size());
		num[i] = numberVector[randomNumber];
		numberVector.erase(numberVector.begin() + randomNumber);
	}

	for(int i=0; i<6; i++){
		cout << "#" << i << ": " << num[i] << endl; 
	}

	numbersDrawn = true;
}

void machine::showResults(){
	for(int i=0; i<userlist.size(); i++){
		user u = userlist[i];

		cout << "User: " << u.getName() << endl;

		int* drawnNumbers = num;
		int* userNumbers = u.getNumbers();

		/*for(int j=0; j<6; j++){
			cout << "#" << j << ": " << userNumbers[j] << endl;
		}*/

		for(int x = 0; x<6; x++){
			for(int y =x; y<6; y++){

				if(drawnNumbers[x] == userNumbers[y]){

				cout<< " Your guessed numbers are: "<< userNumbers[y] << endl;

			}


			}

		}
	}
}

void machine::resetMachine(){
	userlist.clear();
	ticketsEntered = false;

	for( int i = 0 ; i < 6; i++ ){
		num[i] = 0;
	}
	numbersDrawn = false;
}