#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <map>

#include "MyInterpreter.h"

using namespace std;

string MyInterpreter::parse(string input)
{
	if (input.find_last_of('(') != -1) {
		int start = input.find_last_of('(');
		int end = input.find(')', start+1);
		input = input.replace(start, end - start, parse(input.substr(start, end)));
	}


}

bool MyInterpreter::readNextLine()
{
	string command;
	string commandArr[7];
	cin >> command;
	
	


	outputNextLine(compute(commandArr));
	return false;
}

void MyInterpreter::outputNextLine(MyRational ans)
{
	cout << "ans = " << ans.toString() << endl;
}

MyRational MyInterpreter::compute(string inputStream[])
{
	return MyRational();
}


