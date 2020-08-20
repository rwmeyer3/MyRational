#ifndef MYRATIONAL_H
#define MYRATIONAL_H
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>


using namespace std;

class MyRational {
private:
	int numerator, denominator;
	bool simplified;
public:

	MyRational();

	MyRational(int num, int denom);

	void setNumerator(int num);

	void setDenominator(int denom);

	int getNumerator();

	int getDenominator();

	string toString();

	string toStringVerbose();

	MyRational simplify();

	MyRational addRaw(MyRational* second);

	MyRational subtractRaw(MyRational* second);

	MyRational multiplyRaw(MyRational* second);

	MyRational divideRaw(MyRational* second);

	MyRational add(MyRational* second);

	MyRational subtract(MyRational* second);

	MyRational multiply(MyRational* second);

	MyRational divide(MyRational* second);

	MyRational invert();

	MyRational powerRaw(int pow);

	MyRational power(int pow);
	
};

#endif

