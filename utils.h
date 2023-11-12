#ifndef _UTILS_H_
#define _UTILS_H_

// Find the equal sign in the string. `-1` is returned if not found.
int findEq( char[] );

// Find the colon in the string. `1` is returned if found, `0` if not.
int findCol( char[] );

// Clears a[] into '\0'
void clearArray( char[], int );

#endif
