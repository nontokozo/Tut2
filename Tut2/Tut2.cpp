// Tut2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Fraction
{
public:
	Fraction(int num, int den);  // default constructor

	void setFraction(int a, int b);
	int getFraction(); // get values from the user


	// function declaraction

	int add();
	int subtract();
	int multiply();
	int divide();
	int print();

	~Fraction();

private:
	int numerator;
	int denominator;

	
};

Fraction::Fraction(int num =1, int den=1)
{
	numerator = num;
	denominator = den;
}

Fraction::~Fraction()
{
}





int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

