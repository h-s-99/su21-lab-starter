// Copyright 2023 Huda Sajjad
#include <stdio.h>
#include "bit_ops.h"

/* Returns the Nth bit of X. Assumes 0 <= N <= 31. */
unsigned get_bit(unsigned x, unsigned n) {
    /* YOUR CODE HERE */
    unsigned upd = x >> n;
    upd = upd & 1;
    return upd; /* UPDATE WITH THE CORRECT RETURN VALUE*/
}

/* Set the nth bit of the value of x to v. Assumes 0 <= N <= 31, and V is 0 or 1 */
void set_bit(unsigned *x, unsigned n, unsigned v) {
    /* YOUR CODE HERE */
    unsigned val = v << n;
    unsigned ll = 1 << n;
    ll = ~ll;
    *x = *x & ll;
    *x = *x | val;
}

/* Flips the Nth bit in X. Assumes 0 <= N <= 31.*/
void flip_bit(unsigned *x, unsigned n) {
    /* YOUR CODE HERE */
    unsigned ll = 1 << n;
    ll = ~ll;
    *x = ~(*x ^ ll);
}

