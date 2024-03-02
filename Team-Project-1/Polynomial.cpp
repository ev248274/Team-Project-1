#include "Polynomial.h"

// Constructors

// Default Constructor
Polynomial::Polynomial() : term_list(NULL) {}

// Class-member functions
	
// Getters

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
