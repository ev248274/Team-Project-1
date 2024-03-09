#include "Polynomial.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
	
	Polynomial first;
	Polynomial second;
	Polynomial third;

	string first_p;
	string second_p;

	cout << "Hello! In this program, you can add two polynomials together." << endl;
	cout << endl;
	cout << "When inputing a polynomial, please use this notation:" << endl;
	cout << "\"x+5+x^2-10\"" << endl;
	cout << endl;

	cout << "Please enter the first polynomial: " << endl;
	cin >> first_p; // x+5+x^2-10
	cout << endl;
	cout << "Enter the second polynomial: " << endl;
	cin >> second_p; // 5x-5x^-2+10-5x+x^2-0x
	cout << endl;

	first.set_polynomial_from_string(first_p);
	second.set_polynomial_from_string(second_p);

	third = first + second;
	third.sort();
	third.combine();

	cout << "-----------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "The sum of ( " << first << " ) and ( " << second << " ) is:" << endl;
	cout << endl;
	cout << third << endl;
	cout << endl;
	
	system("pause");
	return 0;
}