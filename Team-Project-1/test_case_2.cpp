#include "Polynomial.h"
#include <iostream>
#include <string>

/*

<<<<<<< Updated upstream
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

=======
This test case is going to test the Polynomial class's .combine() function.

The .combine() function requires that the Polynomial's Terms are sorted from highest to lowest exponent.

Given a sorted (often by using .sort()) Polynomial, the .combine() function will augment the Term list of the
Polynomial to be in reduced form. 
Meaning if there are multiple Terms with the exponent 2, it will combine them all into a single Term that is mathmatically equivalent.

Ex. 2x^2+x^2 = 3x^2

We are testing if the input:

x^3+x^3+x^3+x^2+x^1-2x^1

Will become:

3x^3+x^2-x^1

----------------------
       Result
----------------------

The input:

x^3+x^3+x^3+x^2+x^1-2x^1

Has become:

3x^3+x^2-x^1

Great! Our predictions were correct!
>>>>>>> Stashed changes

*/

using namespace std;

void test_case_2() {
	Polynomial test_poly;
<<<<<<< Updated upstream
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
=======
	string s_1 = "x^3+x^3+x^3+x^2+x^1-2x^1";

	// Testing string 1 (s_1)
	test_poly.set_polynomial_from_string(s_1);

	cout << "test_poly's term_list before the combine:" << endl << endl;

	test_poly.combine();

	cout << "test_poly's term_list after the combine:" << endl;
	cout << test_poly << endl << endl;
>>>>>>> Stashed changes
}