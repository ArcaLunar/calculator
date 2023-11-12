#include "var_system.h"

#include <string.h>
#include "utils.h"

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

void initVar( struct Varsys* arr ) {
	for (int i = 0; i < VAR_MAX_STORAGE; i++) {
		clearArray( arr->vars[i].name, NAME_MAX_LENGTH );
		arr->vars[i].datum = 0.0;
	}
	arr->size = 0;
}

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

long double findVar( struct Varsys* arr, char a[] ) {
	for (int i = 0; i < arr->size; i++) {
		if (cmpstr( a, arr->vars[i].name ) == 1) return arr->vars[i].datum;
	}
	return 0.0;
}