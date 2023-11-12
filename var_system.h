#ifndef _VAR_SYSTEM_H_
#define _VAR_SYSTEM_H_

#define NAME_MAX_LENGTH 20
#define VAR_MAX_STORAGE 50

// Variable structure, stores the name and the value of the variable
struct Var {
	char name[NAME_MAX_LENGTH];
	long double datum;
};

// Variable system, by default, can store 50 variables. 
// `size` is the number of variables stored.
struct Varsys {
	struct Var vars[VAR_MAX_STORAGE];
	int size;
};

// Compare two strings and return 1 if they are equal, 0 if not
int cmpstr( char[], char[] );

// Initialize a variable system
void initVar( struct Varsys* );

// Reassign a variable or assign a new variable if not exists
void reassign( struct Varsys*, char[], long double );

// Find the variable in the variable system with name `a[]` and return its value
long double findVar( struct Varsys*, char[] );


#endif