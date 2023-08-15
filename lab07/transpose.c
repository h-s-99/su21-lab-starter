// Copyright Huda Sajjad 2023
#include "transpose.h"
#include "stdio.h"

/* The naive transpose function as a reference. */
void transpose_naive(int n, int blocksize, int *dst, int *src) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            dst[y + x * n] = src[x + y * n];
        }
    }
}

/* Implement cache blocking below. You should NOT assume that n is a
 * multiple of the block size. */
void transpose_blocking(int n, int blocksize, int *dst, int *src) {
    // YOUR CODE HERE
    int subs = n/blocksize;
    int corner = n%blocksize;
    for (int countx = 0; countx < subs; countx++) {
        for (int county = 0; county < subs; county++) {
            for (int x = countx*blocksize; x < (countx*blocksize)+blocksize; x++) {
                for (int y = county*blocksize; y < (county*blocksize)+blocksize; y++) {
                    dst[y + x * n] = src[x + y * n];
                }
            }
        }
    }
    if (corner != 0) {
        for (int x = 0 ; x < n; x++) {
            for (int y = n-corner ; y < n; y++) {
                dst[y + x * n] = src[x + y * n];
            }
        }
        for (int x = n-corner ; x < n; x++) {
            for (int y = 0; y < n; y++) {
                dst[y + x * n] = src[x + y * n];
            }
        }
    }
}

