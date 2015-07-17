#include <iostream>
#include "machine.h"
using namespace std;


int main(){
	int user_input = -1;

	machine m;

	while(user_input != 0){
		cout << "1: Enter ticket" << endl;
		cout << "2: Draw numbers" << endl;
		cout << "3: Show results" << endl;
		cout << "0: Exit" << endl;
		cin >> user_input;

		switch(user_input){
			case 1:
				if(!m.areNumbersDrawn()){
					m.enterTicket();
				}
				else cout << "Numbers were already drawn!" << endl;
				break;
			case 2:
				if(!m.areTicketsEntered()){
					cout << "No tickets were entered!" << endl;
				}
				else if(m.areNumbersDrawn()){
					cout << "Numbers were already drawn!" << endl;
				}
				else m.drawNumbers();
				break;
			case 3:
				if(m.areNumbersDrawn()){
					m.showResults();
					m.resetMachine();
				}
				else cout << "No numbers were drawn!" << endl;
				break;
		}
	}
	
	return 0;

}