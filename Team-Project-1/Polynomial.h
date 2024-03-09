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
		// Constructors
		Term();         // Default constrctor
		Term(int, int); // Creates a Term with given coefficent and exponent

		// Class-member functions.

		// Getters
		int get_coefficent() const;
		int get_exponent() const;

		// Setters
		void set_coefficent(const int);
		void set_exponent(const int);

		// Overloaded operators
		bool operator == (const Term&) const;     // Tests whether two Terms have equal exponents
		bool operator != (const Term&) const;     // Tests whether two Terms do not have equal exponents
		bool operator > (const Term&) const;      // Tests whether one Term is greater than the other
		bool operator < (const Term&) const;      // Tests whether one Term is less than the other
		Term operator + (const Term&) const;      // Adds two Terms with equal exponents
		const Term& operator = (const Term& rhs); // Deep-copy assignment operator

	private:
		// Data Fields
		int coefficent, exponent;
	};

	/* The list of Terms that make up the polynomial. */
	list<Term> term_list;

public:
	// Constructors
	Polynomial();
	Polynomial(const Polynomial&); // Copy constructor
	Polynomial(std::string); // Constructs a Polynomial with a given string

	// Destructor
	~Polynomial();

	// Class-member functions.
	void set_polynomial_from_string(std::string poly); // Initializes term_list with a string in polynomial format
	list<Term> get_polynomial(); // Returns term_list
	void output_term_list(); // Shows each Term inside term_list
	void swap(std::list<Term>::iterator, std::list<Term>::iterator); // Swaps two adjacent Terms in the Polynomial
	void sort(); // Sorts the Polynomial in decending exponent order
	void clear(); // Empties the Polynomial
	void combine(); // Adds coefficients with the same exponent (incomplete)

	// Overloaded operators
	const Polynomial& operator = (const Polynomial&);
	Polynomial operator + (const Polynomial&) const; // Adds two Polynomials together

	// Helper functions
	friend list<Term> gen_polynomial_as_list_from_string(std::string);
	friend std::ostream& operator << (std::ostream&, Polynomial&);
}; 


#endif
