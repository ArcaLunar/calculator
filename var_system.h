#ifndef _VAR_SYSTEM_H_
#define _VAR_SYSTEM_H_

#include <string.h>

#define NAME_MAX_LENGTH 20

struct Var {
	char name[NAME_MAX_LENGTH];
	long double datum;
};

struct Varsys {
	struct Var vars[50];
	int size;
};

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
	for (int i = 0; i < 50; i++) {
		clearArray( arr->vars[i].name, NAME_MAX_LENGTH );
		arr->vars[i].datum = 0.0;
	}
	arr->size = 0;
}

void reassign( struct Varsys* arr, char a[], long double dat ) {
	int assigned = 0;
	for (int i = 0; i < arr->size; i++) {
		if (cmpstr( a, arr->vars[i].name ) == 1) {
			arr->vars[i].datum = dat;
			assigned = 1;
			break;
		}
	}
	if (assigned == 0) {
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

int indexVar( char a[], int* cur, char v[] ) {
	for (int i = *cur; i < strlen( a ); i++) {
		int eq = 1;
		for (int j = i; j < strlen( v ); j++) {
			if (v[j - i] != a[j]) {
				eq = 0;
				break;
			}
		}
		if (eq == 1) {
			return i;
		}
	}
	return -1;
}

#endif