#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
//#include <map>
#include "MyRational.h"


using namespace std;

class MyInterpreter {
private:
	//map<string, MyRational> workspace;

	string parse(string input);

public:
	bool readNextLine();

	void outputNextLine(MyRational);

	MyRational compute(string inputStream[]);
};

#endif