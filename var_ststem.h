#ifndef _VAR_SYSTEM_H_
#define _VAR_SYSTEM_H_

#include <string.h>

#define NAME_MAX_LENGTH 20

struct Var {
	char name[NAME_MAX_LENGTH];
	long double datum;
};

void initVar( struct Var* arr, int size ) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < NAME_MAX_LENGTH; j++) arr[i].name[j] = '\0';
		arr[i].datum = 0.0;
	}
}

void reassign( struct Var* arr, int size, char a[], long double dat ) {
	for (int i = 0; i < size; i++) {
		if (strcmp( arr[i].name, a ) == 0) {
			arr[i].datum = dat;
			break;
		}
	}
}

long double findVar( struct Var* arr, int size, char a[] ) {
	for (int i = 0; i < size; i++) {
		if (strcmp( arr[i].name, a ) == 0) return arr[i].datum;
	}
	return 0.0;
}

int indexVar( char a[], int *cur, char v[] ) {
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