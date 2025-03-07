#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"


void lfsr_calculate(uint16_t *reg) {
    // Extract the individual bits (0, 2, 3, 5)
    uint16_t x_0 = (*reg >> 0) & 1;
    uint16_t x_2 = (*reg >> 2) & 1;
    uint16_t x_3 = (*reg >> 3) & 1;
    uint16_t x_5 = (*reg >> 5) & 1;
    
    // XOR all four bits to get the new leftmost bit
    uint16_t x_xor = x_0 ^ x_2 ^ x_3 ^ x_5;
    
    // Shift the register right by 1 bit
    *reg = *reg >> 1;
    
    // Put the new bit into the leftmost position (bit 15)
    x_xor = x_xor << 15;
    
    // Combine the new leftmost bit with the shifted register
    *reg = x_xor | *reg;
}


