#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <list>
#include <string>
#include <iostream>


using std::list;

class Polynomial {

private:
	/* A term in the polynomal. */
	class Term {
	public:
		// Class-member functions.

		// Getters
		int get_coefficent() const;
		int get_exponent() const;

		// Setters
		void set_coefficent(const int);
		void set_exponent(const int);

		// Overloaded operators
		bool operator == (const Term&) const; // Tests whether two Terms have equal exponents
		bool operator > (const Term&) const; // Tests whether one Term is greater than the other
		bool operator < (const Term&) const; // Tests whether one Term is less than the other

	private:
		// Data Fields
		int coefficent, exponent;
	};

	/* The list of Terms that make up the polynomial. */
	list<Term> term_list;
public:
	// Constructors
	Polynomial();

	// Class-member functions.
	void set_polynomial_string(std::string poly); // Initializes term_list with a string in polynomial format (completed)
	void set_polynomial_list(list<Term> lst); // Initializes term_list with another list<Term> variable (incomplete)
	list<Term> get_polynomial(); // Returns term_list (completed)
	void output_term_list(); // Shows each Term inside term_list (completed)
	void sort(); // Sorts term_list in decreasing order (incomplete)
	void combine(); // Adds coefficients with the same exponent (incomplete)


	// Overloaded operators
	Polynomial operator + (const Polynomial&) const; // Adds two Polynomials together (incomplete)
}; 


#endif
