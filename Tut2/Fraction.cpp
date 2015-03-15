
#include "stdafx.h"
#include <iostream>
#include "Fraction.h" // include definition of class Fraction from Fraction.h
using namespace std;

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

void Fraction::add(Fraction lhs, Fraction rhs)
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


// overloaded >> operator
bool Fraction::operator>>(const Fraction &gr) const
{
	return gr << *this;
} // end function operator>>



// overloaded << operator
bool Fraction::operator<<(const Fraction &lr) const
{
	double thisVal = static_cast< double >(numerator) / denominator;
	double lrVal = static_cast< double >(lr.numerator) / lr.denominator;
	return thisVal < lrVal;
} // end function operator<<

