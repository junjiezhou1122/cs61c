#include <stdio.h>
#include "bit_ops.h"

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(unsigned x,
                 unsigned n) {

    return (x >> n) & 1;

    // Returning -1 is a placeholder (it makes
    // no sense, because get_bit only returns 
    // 0 or 1)
    return -1;
}
// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(unsigned * x,
    unsigned n,
    unsigned v) {
        if (v == 0) {
        // Clear the nth bit by ANDing with the complement of a mask
        *x = *x & ~(1 << n);
        } else {
        // Set the nth bit by ORing with a mask
        *x = *x | (1 << n);
        }
}
// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
void flip_bit(unsigned * x,
              unsigned n) {
    unsigned t = get_bit(*x, n);
    if (t == 0) {
        set_bit(x, n, 1);
    } else {
        set_bit(x, n, 0);
    }
}

