#include "Polynomial.h"
#include <iostream>
#include <string>

/*

This test case is going to test the overloaded '+' operator.

for the first polynomial, we expect an output of:

"First Polynomial: -3x^7+2x^7-83x^12+30"

and we got:

"First Polynomial: -3x^7+2x^7-83x^12+30"

The actual output is correct!

Next, we're going to test the second polynomial. We should get an output of:

"Second Polynomial: 45x^2-8x+0x-0x^-3"

Let's see the actual result:

"Second Polynomial: 45x^2-8x+0x-0x^-3"

The actual result is good! Now for the real test; Adding them both together, sorting, and combining. We should get the following result:

"Printing result: -83x^12-x^7+45x^2-8x+30"

Notice how it should get rid of the "+0x-0x^-91". Let's see what we actually get.

"Printing result: -83x^12-1x^7+45x^2-8x^1+30"

Looking at the actual result and comparing with the expected result, we can see a few key differences.

The "-x^7" is now "-1x^7", but those are the same thing, so nothing to worry about. Another difference is that "-8x" is now "-8x^1".

As with the previous term, this isn't that big of a deal as they are both the same thing.

*/

using namespace std;

void test_case_2() {
	Polynomial test_poly;
	Polynomial test_poly_2;
	Polynomial result;

	string s_1 = "-3x^7+2x^7-83x^12+30";
	string s_2 = "45x^2-8x+0x-0x^-3";


	test_poly.set_polynomial_from_string(s_1);
	test_poly_2.set_polynomial_from_string(s_2);

	cout << "First Polynomial: " << s_1 << endl;
	cout << "Second Polynomial: " << s_2 << endl;

	test_poly.sort();
	test_poly_2.sort();
	result = test_poly + test_poly_2;
	result.sort();
	result.combine();
	cout << "Printing result: " << result << endl;
}