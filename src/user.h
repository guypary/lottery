#ifndef _USER_H_
#define _USER_H_

#include <string>
using namespace std;

class user{

private:
	string userName;
	int numbers[6];
public:
	string getName();
	int* getNumbers();

	void inputName();
	void inputNumbers();
};

#endif