#include "Polynomial.h"

#include <exception>
#include <iostream>
#include <sstream>

// Helper functions
/*
Makes a polynomial from a given string and returns it as a list of Terms
@param poly: The string to become a polynomail
@return: The Term list that represents the Polynomial
*/
list<Polynomial::Term> gen_polynomial_as_list_from_string(std::string poly) {
	Polynomial helpful_poly;
	helpful_poly.set_polynomial_from_string(poly);

	return helpful_poly.term_list;
}

// Constructors

// Default Constructor (Term)
Polynomial::Term::Term() : coefficent(0), exponent(0) {}

// Creates a Term with given coefficent and exponent
Polynomial::Term::Term(int coefficent, int exponent) : coefficent(coefficent), exponent(exponent) {}

// Default Constructor (Polynomial)
Polynomial::Polynomial() : term_list(NULL) {}

// Copy Constructor
Polynomial::Polynomial(const Polynomial& other) {
	clear();

	*this = other;
}

// Constructor with given Polynomial (Polynomial)
Polynomial::Polynomial(std::string poly) : term_list(gen_polynomial_as_list_from_string(poly)) {
	combine();
}


// Destructor
Polynomial::~Polynomial() { clear(); }

// Class-member functions

/*
Empties the Polynomial by deleting its Term list
*/
void Polynomial::clear() {
	while (!term_list.empty()) { term_list.pop_front(); }
}

/*
Combines all coefficients of like exponents inside of term_list
*/
void Polynomial::combine() {
	if (term_list.size() < 2) { throw std::exception("Trying to simplify a Polynomial with one or fewer terms"); }
	
	sort();
	
	Polynomial combined_poly;
	Term combined_left_term;
	bool combined_left_term_exists = false;

	auto it_left = term_list.begin();
	auto it_right = ++term_list.begin();

	while (it_right != term_list.end()) {
		// We should add them
		if (it_left->get_exponent() == it_right->get_exponent()) {
			// We still have the same Term, keep adding to the temp value
			if (combined_left_term_exists) {
				combined_left_term = combined_left_term + *it_right;

			}
			else {
				combined_left_term = *it_left + *it_right;

				combined_left_term_exists = true;

			}
		}
		// If their exponents are not equal
		else {
			if (combined_left_term_exists) {
				combined_poly.term_list.push_back(combined_left_term);

				combined_left_term_exists = false; // Stop combining /slash/ Stop pushing the finished Term
			}
			else {
				combined_poly.term_list.push_back(*it_left);
			}
		}

		++it_left;
		++it_right;
	}

	/* 
	After we reach the end, we either combined the last term with the second-to-last,
	or we already pushed the second-to-last term but exited the loop without adding the last term.

	So, either add the combined term to the list or the last term to the list.
	Depending on if the combined number exists.

	Note: The last term in the list would be where the left iterator ends, since the right iterator has to go
	one past the end to exit the loop
	*/
	if (combined_left_term_exists) {
		combined_poly.term_list.push_back(combined_left_term);
	}
	else {
		combined_poly.term_list.push_back(*it_left);
	}

	// Update our Polynomial
	*this = combined_poly;
}

/*
Swaps two adjacent Terms in the polynomial
@param first: The iterator that is sitting on the first Term
@param second: the iterator that is sitting on the Term directly after the first Term
*/
void Polynomial::swap(std::list<Term>::iterator first, std::list<Term>::iterator second) {
	Term& temp = *first;
	*first = *second;
	*second = temp;
}


/*
Sorts the Polynomial in descending exponent order (using a Bubble Sort implementation)
*/
void Polynomial::sort() {
	// .sort() wants to go from least to greatest, when we want to go from greatest to least
	// That's why we need to .reverse() it.
	term_list.sort();
	term_list.reverse();
}

/*
Outputs each term into console
*/
void Polynomial::output_term_list() {
	int count = 1;
	for (auto it = term_list.begin(); it != term_list.end(); ++it) {
		std::cout << "term " << count << ": " << std::endl;
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
@param poly: string poly in polynomial format
*/
void Polynomial::set_polynomial_from_string(std::string poly) {
	bool next_num_is_negative   = false; // The next number should be negative
	bool make_this_num_negative = false;
	bool write_to_exponent      = false; // Should the characters go into the exponent part of our Term?
	bool end_of_current_num     = false;
	bool move_to_next_term      = false;
	bool prev_char_was_x        = false;
	bool prev_char_was_carrot   = false;
	std::string current_num_str = "";
	int current_num_int;
	char current_char;
	Term current_term;
	std::stringstream converter;


	for (std::string::iterator it = poly.begin(); it != poly.end(); ++it) {
		current_char = *it;

		// If next_num_is_negative is already true -> then this num is the one that needs to be negative!
		if (next_num_is_negative) {
			make_this_num_negative = true;
			next_num_is_negative   = false;
		}

		// Addition
		if (current_char == '+') {
			end_of_current_num   = true;
			move_to_next_term    = true; // The Term is finished if we reach a '+' symbol

			if (prev_char_was_x) { 
				// Then this is an exponent
				write_to_exponent = true;
				// If 'x' just happened, the coefficent was just flushed, so we know we have an empty string -> just put one (1) inside it
				current_num_str.push_back('1');
			}
			// The previous character is no longer 'x'
			prev_char_was_x = false;

		}
		// Subtraction
		else if (current_char == '-') {
			end_of_current_num   = true;
			next_num_is_negative = true;

			if (prev_char_was_x) {
				// Then we know that we need a one (1) in the exponent for 'x'
				write_to_exponent = true;
				current_num_str.push_back('1');
				prev_char_was_x = false;
			}

			// The only possible thing the previous character could be then, is just a number
			if (!(prev_char_was_x || prev_char_was_carrot)) {
				move_to_next_term = true; // The previous Term was a constant, place it in the Polynomial
			}

		}
		// Variable ('x')
		else if (current_char == 'x') {
			end_of_current_num = true;
			prev_char_was_x    = true;

			// If we hit an 'x' with no numbers before it, we assume the coefficent to be one (1)
			if (current_num_str.empty()) { current_num_str.push_back('1'); }
		}
		// Exponent ('^')
		else if (current_char == '^') {
			write_to_exponent    = true;
			prev_char_was_x      = false;
			prev_char_was_carrot = true;
		}
		// The character is a number
		else {
			current_num_str.push_back(current_char);

			// The new previous is now the number that was push_back() onto the string
			prev_char_was_x      = false;
			prev_char_was_carrot = false;
		}

		// This number is finished AND it exists
		if (end_of_current_num && (!current_num_str.empty())) {
			// For some reason, std::stoi(current_num_str) is not working
			// So I used a stringstream instead to convert the string into an int
			converter << current_num_str;
			converter >> current_num_int;
			converter.clear();

			current_num_str = ""; // Reset for next number

			// Check if we need to switch the sign
			if (make_this_num_negative) {
				current_num_int = -current_num_int;
				make_this_num_negative = false; // Reset for next number
			}

			// Exponent
			if (write_to_exponent) {
				current_term.set_exponent(current_num_int);
				write_to_exponent = false; // Reset for next number

				end_of_current_num = false;
				move_to_next_term  = true;  // The exponent will always come last. After it, move on
			}
			// Coefficent
			else {
				current_term.set_coefficent(current_num_int);
				current_term.set_exponent(0); // Reset exponent

				end_of_current_num = false;

			}

			// This Term is finished
			if (move_to_next_term) {
				term_list.push_back(current_term);

				move_to_next_term = false;
			}
		}
		// It would have been the end of the number/Term, but there is no number
		else { 
			end_of_current_num = false;
			move_to_next_term  = false;
		}
	}

	// Last character was 'x'
	if (prev_char_was_x) {
		// We need to add the exponent to the Term (which is 1) then push it into the list
		current_num_str = "";
		current_num_str.push_back('1');
		converter << current_num_str;
		converter >> current_num_int;
		converter.clear();

		current_term.set_exponent(current_num_int);

		term_list.push_back(current_term);

		prev_char_was_x = false; // Avoid false-positive in following if-statements
		current_num_str = "";    // Avoid false-positive in following if-statements

	}

	// If the string still has a number in it
	if (!current_num_str.empty()) {
		converter << current_num_str;
		converter >> current_num_int;

		//current_num_int = std::stoi(current_num_str); // Convert string to an integer

		if (write_to_exponent) {
			current_term.set_exponent(current_num_int);
		}
		else if (prev_char_was_x){
			current_term.set_coefficent(current_num_int);
			current_term.set_exponent(1); // There is no more numbers, so the exponent must be one (1)
		}
		// Constant value at the end
		else {
			current_term.set_coefficent(current_num_int);
			current_term.set_exponent(0);

		}
		term_list.push_back(current_term);
	}
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
Tests whether two Terms do not have equal exponents
@param other: the other Term
@return: true if both Term's exponents are NOT equal, otherwise return false
*/
bool Polynomial::Term::operator != (const Term& other) const {
	return !(*this == other);
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
Deep-copy assignment operator (Term)
*/
const Polynomial::Term& Polynomial::Term::operator = (const Term& rhs) {
	// Avoid self assignment
	if (this != &rhs) {
		// No dynamic data to copy
		// Copy static data
		coefficent = rhs.coefficent;
		exponent   = rhs.exponent;
		// No dynamic data to copy
	}

	// return
	return *this;
}

/*
Adds two Terms with equal exponents
@param other: the other Term
@return: a sum of *this Term and the other Term
*/
Polynomial::Term Polynomial::Term::operator + (const Term& other) const {
	if (*this != other) { throw std::exception("Attempting to add Terms with unequal exponents"); }

	Term result(coefficent + other.coefficent, exponent);

	return result;
}

/*
Deep-copy assignment operator (Polynomial)
*/
const Polynomial& Polynomial::operator = (const Polynomial& rhs) {
	// Avoid self assignment
	if (this != &rhs) {
		// Delete dynamic data
		clear();
		// No static data to copy
		// Copy dynamic data
		for (auto it = rhs.term_list.begin(); it != rhs.term_list.end(); ++it) { term_list.push_back(*it); }
	}

	// return
	return *this;
}

/*
Overloads the + operator for the Polynomial class : Adds two Polynomials together
@param other: The other Polynomial
@return: A Polynomial that is the result of adding the two Polynomials together
*/
Polynomial Polynomial::operator + (const Polynomial& other) const {
	Polynomial result; // The Polynomial after the addition

	auto it_right = other.term_list.begin(); // iterator for the right Polynomial
	auto it_left  = term_list.begin();       // iterator for left Polynomial

	// Go through as much of the left Polynomial's Terms as possible
	while (it_left != term_list.end()) {
		// There are no more values in the right Polynomial to compare to
		if (it_right == other.term_list.end()) { break; }

		// Both Term's exponents are equal
		if (it_left->get_exponent() == it_right->get_exponent()) {
			result.term_list.push_back(*it_left + *it_right);

			++it_right;
			++it_left;
		}
		// Left side's exponent is greater
		else if (it_left->get_exponent() > it_right->get_exponent()) {
			result.term_list.push_back(*it_left);

			++it_left;
		}
		// Right side's exponent is greater
		else {
			result.term_list.push_back(*it_right);

			++it_right;
		}
	}

	// We have some extra Terms in left Polynomial
	while (it_left != term_list.end()) {
		result.term_list.push_back(*it_left);

		++it_left;
	}

	// We have some extra Terms in the right Polynomial
	while (it_right != other.term_list.end()) {
		result.term_list.push_back(*it_right);

		++it_right;
	}

	return result;
}