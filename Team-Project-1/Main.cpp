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

	cout << "Enter first polynomial: " << endl;
	cin >> first_p; // x+5+x^2-10
	cout << "Enter second polynomial: " << endl;
	cin >> second_p; // 5x-5x^-2+10-5x+x^2-0x

	first.set_polynomial_from_string(first_p);
	second.set_polynomial_from_string(second_p);

	third = first + second;
	third.sort();
	third.combine();

	cout << "\nFirst and second polynomials added together:\n-----------------------\n" << third << endl;
	
	system("pause");
	return 0;
}