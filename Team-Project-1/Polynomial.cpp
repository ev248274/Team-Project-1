#include "Polynomial.h"


// Constructors

// Default Constructor
Polynomial::Polynomial() : term_list(NULL) {}

// Class-member functions

/*
Combines all coefficients of like exponents inside of term_list
*/
void Polynomial::combine() {
	// ***FIXME***
}

/*
Sorts term_list in decreasing order
*/
void Polynomial::sort() {
	// ***FIXME***
}

/*
Outputs each term into console
*/
void Polynomial::output_term_list() {
	int count = 1;
	for (auto it = term_list.begin(); it != term_list.end(); ++it) {
		std::cout << "\nterm " << count << ": " << std::endl;
		std::cout << "Value of coefficient: " << (*it).get_coefficent() << std::endl;
		std::cout << "Value of exponent: " << (*it).get_exponent() << "\n" << std::endl;
		count += 1;
	}
}

// Getters

/*
Returns term_list's value
@return: term_list
*/
list<Polynomial::Term> Polynomial::get_polynomial() { return term_list; }

/*
Returns the term's coefficent's value
@return: coefficent value
*/
int Polynomial::Term::get_coefficent() const { return coefficent; }

/*
Returns the term's get_exponent's value
@return: get_exponent value
*/
int Polynomial::Term::get_exponent() const { return exponent; }

// Setters

/*
Sets the coefficent to the given value
@param value: the value to change the coefficent to
*/
void Polynomial::Term::set_coefficent(const int value) { coefficent = value; }

/*
Sets the exponent to the given value
@param value: the value to change the exponent to
*/
void Polynomial::Term::set_exponent(const int value) { exponent = value; }

/*
Initializes term_list
@param lst: set term_list equal to list<Term> lst
*/
void Polynomial::set_polynomial_list(list<Term> lst) {
	// ***FIXME***
}

/*
Initializes term_list
@param poly: string poly in polynomial format
*/
void Polynomial::set_polynomial_string(std::string poly) {
	list<std::string> poly_sep;
	std::string sep;
	std::string c;
	std::string e;
	bool passed_x = false; // distinguishes between initializing c values (when false) and e values (when true)
	Term term;

	poly.insert(0, 1, 'F'); // 'F' is the out of bounds test case for the front
	poly.push_back('B'); // 'B' is the out of bounds test case for the back
	for (std::string::iterator it = poly.begin(); it != poly.end(); ++it) { // separates each term as a string and stores into poly_sep
		if (*it == 'F') { continue; }
		else if (*(it + 1) == 'B') { sep += *it; poly_sep.push_back(sep); break; }
		if ((*it != '+') && (*it != '-')) { sep += *it; }
		else if (*it == '+') { poly_sep.push_back(sep); sep = ""; }
		if (*it == '-') {
			if (*(it - 1) == '^') { sep += *it; }
			else { poly_sep.push_back(sep); sep = "-"; }
		}
	}
	for (auto it = poly_sep.begin(); it != poly_sep.end(); ++it) { // finds coefficients and exponents from poly_sep and stores them inside of term_list
		c = "";
		e = "";
		passed_x = false;
		if (term.get_coefficent() != 0) { term.set_coefficent(0); }
		if (term.get_exponent() != 0) { term.set_exponent(0); }
		(*it).insert(0, 1, 'F');
		(*it).push_back('B');
		for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
			if (*it2 == 'F') { continue; }
			if (!passed_x) {
				if (*it2 == 'B') { break; }
				else if (*it2 != 'x') {
					c.push_back(*it2);
				}
				else {
					if (*(it2 + 1) == 'B') { e = "1"; }
					if (*(it2 - 1) == 'F') { c = "1"; }
					if (*(it2 - 1) == '-') { c = "-1"; }
					passed_x = true;
				}
			}
			else if (*it2 == '^') { continue; }
			else if (*it2 != 'B') { e.push_back(*it2); }
			else if (*it2 == 'B') { break; }
			if (*(it2 + 1) == 'B' && !passed_x) { e = "0"; } // tests for coefficients with exponent of 0
		}
		if (c == "0" || c == "-0") { continue; } // tests for "0x" and "-0x"
		else if (c == "" && e == "") { continue; } // tests for empty spaced terms
		else {
			term.set_coefficent(std::stoi(c));
			term.set_exponent(std::stoi(e));
			term_list.push_back(term); // pushes term onto term_list
		}
	}
	sort();
	combine();
}

/*
Overloads the == operator for the Term class : Tests whether two Terms have equal exponents
@param other: the other Term
@return: true if both Term's exponents are equal, otherwise return false
*/
bool Polynomial::Term::operator == (const Term& other) const {
	return exponent == other.exponent ? true : false;
}

/*
Overloaded the > operator for the Term class :
@param other: the other Term
@return: true if the this Term is greater than the other Term
*/
bool Polynomial::Term::operator > (const Term& other) const {
	return exponent > other.exponent ? true : false;
}

/*
Overloaded the < operator for the Term class :
@param other: the other Term
@return: true if the this Term is less than the other Term
*/
bool Polynomial::Term::operator < (const Term& other) const {
	return exponent < other.exponent ? true : false;

}

/*
Overloads the + operator for the Polynomial class : Adds two Polynomials together
@param other: other Polynomials' address
@return: Polynomial with instantiated list<Term>
*/
Polynomial Polynomial::operator + (const Polynomial& other) const {
	Polynomial result;
	list<Term> r;
	Term t;

	// ***FIXME***

	return result;
}