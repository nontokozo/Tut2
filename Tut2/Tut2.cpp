// Tut2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//***********************DEFINITION OF CLASS FRACTION*************************//
class Fraction
{
public:

	Fraction();  // default constructor function header

	Fraction(int, int); // non default constructor function header

	void reduce(); // reduce fraction function header

	void setFraction(int, int); // set the fraction function header

	void getFraction(int&, int&); // get the fraction function header

	void print(); // print fraction function header

	int add();

	int subtract();

	int multiply();

	int divide();

	

	~Fraction();

	friend const Fraction operator + (const Fraction& lhs, const Fraction& rhs); // + operator overloaded function header
	friend const Fraction operator - (const Fraction& lhs, const Fraction& rhs); // - operator overloaded function header
	friend const Fraction operator * (const Fraction& lhs, const Fraction& rhs); // * operator overloaded function header
	friend const Fraction operator / (const Fraction& lhs, const Fraction& rhs); // / operator overloaded function header


private:
	// private data members
	int numerator;
	int denominator;

	
};// end of class Fraction

//************************************MEMBER FUNCTIONS FOR CLASS FRACTION***********************//


Fraction::Fraction() // default constructor function
	: numerator(0), denominator(1) // set numerator to 0 and denominator to 1
{ }

Fraction::Fraction(int n, int d) // non default constructor function
{
	numerator = n; // set private values to parameters coming in
	denominator = d;
	reduce(); // reduce the fraction
}



Fraction::~Fraction()
{
}

void Fraction::reduce() // reduce fraction function
{
	int gcf; // greatest common factor variable
	bool finished = false;
	if (denominator == 0)
		denominator = 1; // set denominator to 1 if 0
	if (numerator < 0 && denominator < 0) // set both to positive if both negative
	{
		numerator = -numerator;
		denominator = -denominator;
	}
	if (numerator > 0 && denominator < 0) // change negative from denominator to numerator
	{
		numerator = -numerator;
		denominator = -denominator;
	}

	if (abs(numerator) > abs(denominator)) // set gcf to larger of denominator / numerator
		gcf = abs(denominator);
	else
		gcf = abs(numerator);

	while (!finished && gcf >= 2)
	{
		if (numerator % gcf == 0 && denominator % gcf == 0) // find greatest common factor
		{
			numerator = numerator / gcf;
			denominator = denominator / gcf; // reduce by dividing by greatest common factor
			finished = true;
		}
		gcf--;
	}
}

void Fraction::setFraction(int n, int d) // set fraction function
{
	numerator = n; // set private data members to incoming parameters
	denominator = d;
	reduce(); // reduce the fraction
}

void Fraction::getFraction(int &n, int &d) // get fraction function
{
	n = numerator;
	d = denominator; // set outgoing parameters to private data member values
	reduce(); // reduce the fraction
}

void Fraction::print() // display the fraction function
{
	cout << numerator << "/" << denominator;
}

const Fraction operator + (const Fraction& lhs, const Fraction& rhs) // + overloaded operator function
{
	Fraction temp;
	temp.denominator = lhs.denominator * rhs.denominator; // find common denominator
	temp.numerator = lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator; // add fractions
	temp.reduce(); // reduce fractions
	return temp; // return result
}

const Fraction operator - (const Fraction& lhs, const Fraction& rhs) // - overloaded operator function
{
	Fraction temp;
	temp.denominator = lhs.denominator * rhs.denominator; // find common denominator
	temp.numerator = lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator; // subtract fractions
	temp.reduce(); // reduce fractions
	return temp; // return result
}

const Fraction operator * (const Fraction& lhs, const Fraction& rhs) // * overloaded operator function
{
	Fraction temp;
	temp.numerator = lhs.numerator * rhs.numerator; // multiply fractions
	temp.denominator = lhs.denominator * rhs.denominator;
	temp.reduce(); // reduce fractions
	return temp; // return results
}

const Fraction operator / (const Fraction& lhs, const Fraction& rhs) // / overloaded operator function
{
	Fraction temp;
	temp.numerator = rhs.denominator * lhs.numerator; // divide fractions
	temp.denominator = rhs.numerator * lhs.denominator;
	temp.reduce(); // reduce results
	return temp; // return results
}






int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

