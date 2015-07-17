#ifndef _MACHINE_H_
#define _MACHINE_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "user.h"
using namespace std;

#define MIN_NUMBER 1
#define MAX_NUMBER 49

class machine {
private:
	bool ticketsEntered;
	bool numbersDrawn;
	int num[6];
	vector<user> userlist;
public:
	machine();

	bool areTicketsEntered();
	bool areNumbersDrawn();

	void enterTicket();
	void drawNumbers();
	void showResults();

	void resetMachine();
};


#endif