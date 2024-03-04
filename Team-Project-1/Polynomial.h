#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <list>

using std::list;

class Polynomial {
public:
	// Constructors
	Polynomial();

	// Class-member functions.

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

};


#endif
