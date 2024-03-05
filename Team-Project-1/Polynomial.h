#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <list>
#include <string>

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
	void set_polynomials(); // Initializes term_list
	void output_term_list(); // Shows each Term inside term_list
	void sort(); // Sorts term_list in decreasing order
	void combine(); // Adds coefficients with the same exponent

	// Overloaded operators
	list<Term> operator + (const Polynomial&) const; // Adds two Polynomials together
};


#endif
