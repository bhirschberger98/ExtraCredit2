//Rational Arithmetic I
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
class Rational {
	// Declaration of overloaded stream insertion operator
	friend ostream & operator << (ostream &, Rational r);
private:
	int numerator, denominator;
public:
	// Constructor builds a rational number n/d
	Rational(int n, int d) :numerator(n), denominator(d) {
		reduce();
	}
	Rational operator+(Rational r2);
	Rational operator-(Rational r2);
	Rational operator*(Rational r2);
	Rational operator/(Rational r2);
private:
	// This member function transforms a rational number into
	// reduced form where the numerator and denominator have 1
	// as greatest common factor
	void reduce();
};
//************************************************************
// This member function transforms a rational number into *
// reduced form where the numerator and denominator have 1 *
// as greatest common factor. *
//************************************************************
void Rational::reduce() {
	bool negative = (numerator < 0) != (denominator < 0);
	numerator = abs(numerator);
	denominator = abs(denominator);
	int factor = 2;
	while (factor <= min(numerator, denominator)) {
		if (numerator % factor == 0 && denominator % factor == 0) {
			numerator = numerator / factor;
			denominator = denominator / factor;
			continue;
		}
		factor++;
	}
	if (negative)
		numerator = -numerator;
}
Rational Rational::operator+(Rational r2) {
	//Calculates sum and inserts it into the constructor of the Rational class
	Rational sum(numerator*r2.denominator + r2.numerator*denominator, denominator*r2.denominator);
	return sum;
}
Rational Rational::operator-(Rational r2) {
	//Calculates difference and inserts it into the constructor of the Rational class
	Rational difference(numerator*r2.denominator - r2.numerator*denominator, denominator*r2.denominator);
	return difference;
}
Rational Rational::operator*(Rational r2) {
	//Calculates product and inserts it into the constructor of the Rational class
	Rational product(numerator*r2.numerator, denominator*r2.denominator);
	return product;
}
Rational Rational::operator/(Rational r2) {
	//Calculates quotient and inserts it into the constructor of the Rational class
	Rational quotient(numerator*r2.denominator, denominator*r2.numerator);
	return quotient;
}

//************************************************
// Overloaded stream insertion operator *
//************************************************
ostream & operator << (ostream &out, Rational r) {
	out << r.numerator << "/" << r.denominator;
	return out;
}
int main() {
	int n, d;
	char x;
	cout << "Enter a fraction: ";
	cin >> n >> x >> d;
	Rational r1(n, d);
	cout << "Enter another fraction: ";
	cin >> n >> x >> d;
	Rational r2(n, d);
	cout << "---------------------------------------------------------" << endl;
	cout << "The sum of " << r1 << " and " << r2 << " is: " << r1 + r2 << endl;
	cout << "The difference of " << r1 << " and " << r2 << " is: " << r1 - r2 << endl;
	cout << "The product of " << r1 << " and " << r2 << " is: " << r1 * r2 << endl;
	cout << "The quotient of " << r1 << " and " << r2 << " is: " << r1 / r2 << endl;
	system("PAUSE");
	return 0;
}

