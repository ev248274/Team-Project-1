#include "Polynomial.h"
#include <iostream>
#include <string>

/*

This test case is going to test the Polynomial class's .sort() function.

for s_1, we would expect it to become sorted from:

"-x+5+x^2-10"

to

"x^2-x+5-10"

The constant values (5 and -10) might swap places, since we are sorting exclusivly by the term's exponents.

I will run the program and see what we get...

We got:

"x^2-x-10+5"

Nice! As expected, they are ordered by their term's exponents. The constants are swapped but that isn't a surprise (or a problem).

--------------------

Let's try s_2.

The expected output would be:

"5x-5x^-2+10-5x+x^2-0x"

to

"x^2+0x-5x+5x+10-5x^-2"

Let's run it...

We got:

"x^2+0x-5x+5x+10-5x^-2"

Wonderful! The -0x changed into a 0x, but there is no such thing as negative 0, and adding or subtracting by 0 has the same result.

*/

using namespace std;

void test_case_1() {
	Polynomial test_poly;
	string s_1 = "-x+5+x^2-10";
	string s_2 = "5x-5x^-2+10-5x+x^2-0x";

	test_poly.set_polynomial_from_string(s_2);

	test_poly.sort();

	test_poly.output_term_list();
}