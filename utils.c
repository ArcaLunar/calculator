#include "utils.h"

#include <string.h>

int findEq( char a[] ) {
	for (int i = 0; i < strlen( a ); i++) {
		if (a[i] == '=') return i;
	}
	return -1;
}

int findCol( char a[] ) {
	if (a[strlen( a ) - 1] == ';') return 1;
	else return 0;
}

void clearArray( char a[], int size ) {
	for (int i = 0; i < size; i++)
		a[i] = '\0';
}