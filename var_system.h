#ifndef _VAR_SYSTEM_H_
#define _VAR_SYSTEM_H_

#include <string.h>

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
int cmpstr( char a[], char b[] ) {
	if (strlen( a ) != strlen( b )) return 0;
	int l;
	if (strlen( a ) < strlen( b )) l = strlen( a );
	else l = strlen( b );
	for (int i = 0; i < l; i++) {
		if (a[i] != b[i]) return 0;
	}
	return 1;
}

// Initialize a variable system
void initVar( struct Varsys* arr ) {
	for (int i = 0; i < VAR_MAX_STORAGE; i++) {
		clearArray( arr->vars[i].name, NAME_MAX_LENGTH );
		arr->vars[i].datum = 0.0;
	}
	arr->size = 0;
}

// Reassign a variable or assign a new variable if not exists
void reassign( struct Varsys* arr, char a[], long double dat ) {
	int assigned = 0; // Whether the variable exists and is re-assigned
	for (int i = 0; i < arr->size; i++) {
		if (cmpstr( a, arr->vars[i].name ) == 1) {
			arr->vars[i].datum = dat;
			assigned = 1;
			break;
		}
	}
	if (assigned == 0) { // If not, assign a new variable
		arr->vars[arr->size].datum = dat;
		for (int i = 0; i < strlen( a ); i++) arr->vars[arr->size].name[i] = a[i];
		arr->size++;
	}
}

// Find the variable in the variable system with name `a[]` and return its value
long double findVar( struct Varsys* arr, char a[] ) {
	for (int i = 0; i < arr->size; i++) {
		if (cmpstr( a, arr->vars[i].name ) == 1) return arr->vars[i].datum;
	}
	return 0.0;
}


#endif