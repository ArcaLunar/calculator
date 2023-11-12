#ifndef _EXPRESSION_CALC_H_
#define _EXPRESSION_CALC_H_

struct Varsys;
struct dataStack;

// Convert a char[] into double
long double parseDouble( char[] );

// Get next double number or variable from string
// `arr` is the variable system that stores variable information
// `a` is the string to be parsed
// `cur` is the current index of the string,
// such that and `a[cur]` is the first character in the number or variable to be parsed
// Anything between two operators must be a number or a variable(skipping spaces and semicolons)
long double getNextDouble( char[], int*, struct Varsys* );

// Calculate the answer, given the reverse Polish expression
long double calculate( struct dataStack* );

// Parse the string into reverse Polish expression
// Also replace the variables with their values and directly push to stack
long double parseCalc( char[], struct Varsys* );

#endif
