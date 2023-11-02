#ifndef _EXPRESSION_CALC_H_
#define _EXPRESSION_CALC_H_

#include <string.h>
#include <math.h>

#include "utils.h"
#include "stack.h"
#include "char_operate.h"

long double parseDouble(char a[]) {
    long double ans = 0.0; // Store final answer
    long double multiplier = 10.0;
    
    int index_of_decimal_point = 0; // Find out the index of the decimal point. (or equals to strlen(a) if integer)
    for(; index_of_decimal_point < strlen(a); index_of_decimal_point++)
        if(a[index_of_decimal_point] == '.') break;
    
    // Calculate integer part
    int index = 0;
    while(index < index_of_decimal_point) ans = ans * multiplier + 1.0 * (a[index++] - '0'); 

    // Calculate decimal part
    index = strlen(a) - 1;
    long double after_point = 0.0;
    multiplier = 0.1;
    while(index > index_of_decimal_point) after_point = after_point * multiplier + 1.0 * (a[index--] - '0');
    
    ans += after_point;
    return ans;
}

long double getNextDouble(char a[], int* cur) {
    int index = 0;
    int i;
    char target[MAXN];
    clearArray(target, MAXN);
    for(i = *cur; i < strlen(a); i++) {
        if(a[i] == ' ') continue;
        if(!(a[i] >= '0' && a[i] <= '9' || a[i] == '.')) break;
        target[index++] = a[i];
    }
    *cur = i;
    return parseDouble(target);
}

long double calculate(struct dataStack *a) {
    struct dataStack tmp;
    initData(&tmp);
    for(int i = 0; i < a->top; i++) {
        if(a->aux[i] == 1) pushData(&tmp, a->data[i]);
        else {
            long double a1 = popData(&tmp);
            long double a2 = popData(&tmp);
            pushData(&tmp, 
        }
    }
}

#endif