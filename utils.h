#ifndef _UTILS_H_
#define _UTILS_H_

// Clears a[] into '\0'
void clearArray( char a[], int size ) {
	for(int i = 0; i < size; i++)
		a[i] = '\0';
}

#endif
