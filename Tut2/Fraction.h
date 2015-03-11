
#ifndef FRACTION_H
#define FRACTION_H
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

	void add(Fraction, Fraction);

	void subtract(Fraction, Fraction);

	void multiply(Fraction, Fraction);

	void divide(Fraction, Fraction);



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



#endif