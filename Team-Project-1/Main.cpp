#include <iostream>
#include "Polynomial.h"
#include <string>

using namespace std;

int main() {
	Polynomial first;
	Polynomial second;

	first.set_polynomials();  // Enter into console: −x+5+x^2−10 
	second.set_polynomials(); // Enter into console: 5x−5x^−2+10−5x+x^2-0x
	
	first.output_term_list();
	second.output_term_list();
	

	system("pause");
	return 1;
}