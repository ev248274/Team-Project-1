#include <iostream>
#include "Polynomial.h"
#include <string>

using namespace std;

int main() {
	Polynomial first;
	Polynomial second;
	Polynomial third;

	string first_p = "-x+5+x^2-10";
	string second_p = "5x-5x^-2+10-5x+x^2-0x";

	first.set_polynomial_string(first_p);  
	second.set_polynomial_string(second_p);
	
	first.output_term_list();
	second.output_term_list();

	third = first + second; 
	

	system("pause");
	return 0;
}