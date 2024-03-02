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

	private:
		// Data Fields
		int coefficent, exponent;
	};

	/* The list of Terms that make up the polynomial. */
	list<int> term_list;

};


#endif
