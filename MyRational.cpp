
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include "MyRational.h"


using namespace std;

/**
 * Stores, displays, and manipulates rational numbers
 *
 * @author rwmeyer3
 * @version 19.08.2020
 */


 /**
  * Default Constructor initializes 0/1.
  * Rational number starts in simplified form.
  */
MyRational::MyRational() {
	simplified = true;
	numerator = 0;
	denominator = 1;
}

/**
 * Constructor that allows for choosing initial numerator and denominator upon creation.
 * Rational Number is not assumed to be in simplified form.
 *
 * @param num Numerator choosen
 * @param denom Denominator choosen
 * @throws invalid_argument when denom is 0
 */
MyRational::MyRational(int num, int denom) {
	simplified = false;
	numerator = num;
	if (denom == 0) {
		throw invalid_argument("Rational number is undefined when denominator is 0.");
	}
	else {
		denominator = denom;
	}

}

/**
 * Set new numerator value.
 * @param num New numerator
 */
void MyRational::setNumerator(int num) {
	numerator = num;
	simplified = false;
}

/**
 * Set new denominator value.
 * @param denom New denominator
 */
void MyRational::setDenominator(int denom) {
	if (denom == 0) {
		throw invalid_argument("Rational number is undefined when denominator is 0.");
	}
	else {
		denominator = denom;
	}
	simplified = false;
}

/**
 * Returns numerator value.
 * @return int numerator
 */
int MyRational::getNumerator() {
	return numerator;
}

/**
 * Returns denominator value.
 * @return int denominator
 */
int MyRational::getDenominator() {
	return denominator;
}

/**
 * Returns a string with the fraction representation of the rational number.
 * @return string fraction representation of rational number
 */
string MyRational::toString() {
	stringstream buffer;
	buffer << this->numerator << " / " << this->denominator << endl;
	return buffer.str();
}

/**
 * Returns a string with the fraction representation of the rational number and a statement of whether the fraction is confirmed to be in simplest form or not.
 * @return string fraction representation of rational number and simplified state
 */
string MyRational::toStringVerbose() {
	stringstream buffer;
	buffer << this->numerator << " / " << this->denominator << "endl" << "This Rational number is" << ((simplified) ? "" : " possibly not") << " in simplest terms." << endl;
	return buffer.str();
}

/**
 * Modifies the existing object in order to simnplify the numerator and denominator into simplest terms.
 * Nuemrator and Denominator are relatively prime and if the rational number is negative, then the numerator is negative.
 * Also returns a copy of the object for external use.
 *
 * @return MyRational a copy of this rational number in simplest terms
 */
MyRational MyRational::simplify() {
	int check = 2;
	while (check < numerator && check < denominator) {
		if (numerator % check == 0 && denominator % check == 0) {
			numerator /= check;
			denominator /= check;
		}
		++check;
	}
	if (denominator < 0) {
		denominator *= -1;
		numerator *= -1;

	}

	simplified = true;
	return *this;
}

/**
 * Calculates the sum of this rational number and another rational number to create a third, new rational number object.
 * this + second = sum
 * Values in the sum object are not simplified.
 *
 * @param second pointer to another rational number object
 * @return MyRational sum of two rational numbers
 */
MyRational MyRational::addRaw(MyRational* second) {
	int newDenom = this->getDenominator() * second->getDenominator();
	int newNum = this->getNumerator() * second->getDenominator() + second->getNumerator() * this->getDenominator();
	return MyRational(newNum, newDenom);
}

/**
 * Calculates the difference of this rational number and another rational number to create a third, new rational number object.
 * this - second = difference
 * Values in the difference object are not simplified.
 *
 * @param second pointer to another rational number object
 * @return MyRational difference of two rational numbers
 */
MyRational MyRational::subtractRaw(MyRational* second) {
	MyRational* neg = &MyRational(-1, 1);
	MyRational* negate = &(second->multiplyRaw(neg));
	MyRational output = this->addRaw(negate);
	delete(neg);
	delete(negate);
	return output;
}

/**
 * Calculates the product of this rational number and another rational number to create a third, new rational number object.
 * this * second = product
 * Values in the product object are not simplified.
 *
 * @param second pointer to another rational number object
 * @return MyRational product of two rational numbers
 */
MyRational MyRational::multiplyRaw(MyRational* second) {
	int newDenom = this->getDenominator() * second->getDenominator();
	int newNum = this->getNumerator() * second->getNumerator();
	return MyRational(newNum, newDenom);
}

/**
 * Calculates the quotient of this rational number and another rational number to create a third, new rational number object.
 * this / second = quotient
 * Values in the quotient object are not simplified.
 *
 * @param second pointer to another rational number object
 * @return MyRational quotient of two rational numbers
 */
MyRational MyRational::divideRaw(MyRational* second) {
	MyRational* invert = &(second->invert());
	MyRational output = this->multiplyRaw(invert);
	delete(invert);
	return output;
}

/**
 * Calculates the sum of this rational number and another rational number to create a third, new rational number object.
 * this + second = sum
 * Values in the sum object are simplified.
 *
 * @param second pointer to another rational number object
 * @return MyRational sum of two rational numbers
 */
MyRational MyRational::add(MyRational* second) {
	return this->addRaw(second).simplify();
}

/**
 * Calculates the difference of this rational number and another rational number to create a third, new rational number object.
 * this - second = difference
 * Values in the difference object are simplified.
 *
 * @param second pointer to another rational number object
 * @return MyRational difference of two rational numbers
 */
MyRational MyRational::subtract(MyRational* second) {
	return this->subtractRaw(second).simplify();
}

/**
 * Calculates the product of this rational number and another rational number to create a third, new rational number object.
 * this * second = product
 * Values in the product object are simplified.
 *
 * @param second pointer to another rational number object
 * @return MyRational product of two rational numbers
 */
MyRational MyRational::multiply(MyRational* second) {
	return this->multiplyRaw(second).simplify();
}

/**
 * Calculates the quotient of this rational number and another rational number to create a third, new rational number object.
 * this / second = quotient
 * Values in the quotient object are simplified.
 *
 * @param second pointer to another rational number object
 * @return MyRational quotient of two rational numbers
 */
MyRational MyRational::divide(MyRational* second) {
	return this->divideRaw(second).simplify();
}

/**
 * Swap numerator and denominator as if rased to the power of -1
 * @return MyRational inverted rational number
 */
MyRational MyRational::invert() {
	return MyRational(this->getDenominator(), this->getNumerator());
}

/**
 * Calculates the product of this rational number raised to an integer power to create a third, new rational number object.
 * this ^ pow = product
 * Values in the product object are not simplified.
 *
 * @param pow integer power
 * @return MyRational product a rational number raised to an integer power
 */
MyRational MyRational::powerRaw(int pow) {
	if (!pow) {
		return MyRational(1, 1);
	}
	int newNum = this->numerator;
	int newDenom = this->denominator;
	for (int i = 0; i < pow - 1; i++) {
		newNum *= this->numerator;
		newDenom *= this->denominator;
	}
	return MyRational(newNum, newDenom);
}

/**
 * Calculates the product of this rational number raised to an integer power to create a third, new rational number object.
 * this ^ pow = product
 * Values in the product object are simplified.
 *
 * @param pow integer power
 * @return MyRational product a rational number raised to an integer power
 */
MyRational MyRational::power(int pow) {
	return this->powerRaw(pow).simplify();
}

//int main() {
//	return 0;
//}
