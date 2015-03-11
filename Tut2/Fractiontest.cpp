// Tut2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Fraction.h"
using namespace std;







//****************MAIN FUNCTION**************************************//

int _tmain(int argc, _TCHAR* argv[])
{

	Fraction frac1, frac2, result; // instantiate fraction objects
	int n, d;
	int a, b; // declare numerator and denominator variables
	cout << " Enter the numerator1: ";
	cin >> n;
	cout << endl;
	cout << " Enter the denomeratorS1: ";
	cin >> d; // enter the first fractions

	cout << " Enter the numerator2: ";
	cin >> a;
	cout << endl;
	cout << " Enter the denomerator2: ";
	cin >> b; // enter the first fractions
	frac1.setFraction(n, d); // set the values of the first fraction
	frac2.setFraction(a, b); // set the values of the first fraction

	result = frac1 + frac2; // add fractions
	frac1.print();
	cout << " + ";
	frac2.print(); // display fractions and results
	cout << " = ";
	result.print();
	cout << endl;

	result = frac1 - frac2; // subtract fractions
	frac1.print();
	cout << " - ";
	frac2.print(); // display fractions and results
	cout << " = ";
	result.print();
	cout << endl;

	result = frac1 * frac2; // multiply fractions
	frac1.print();
	cout << " * ";
	frac2.print(); // display fractions and results
	cout << " = ";
	result.print();
	cout << endl;

	result = frac1 / frac2; // divide fractions
	frac1.print();
	cout << " / ";
	frac2.print(); // display fractions and results
	cout << " = ";
	result.print();
	cout << endl;

	system("Pause");
	return 0;
}

