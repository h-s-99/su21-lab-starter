// Copyright 2023 Huda Sajjad
#include <stdio.h>

#define CSR_VAL 0x8000abcd00001234UL
#define ADDRESS 0x5300f000U

unsigned long int my_csr = CSR_VAL;

int main(void) {
    // (a) here:
    int val = 1;
    my_csr = my_csr | val;

    // (b) here:
    val = 0 << 2;
    int ll = 1 << 2;
    ll = ~ll;
    my_csr = my_csr & ll;
    my_csr = my_csr | val;

    // (c) here:
    for (int i = 8; i <= 15; i++) {
        if (i%4 == 0) {
            val = 0 << i;
        } else {
            val = 1 << i;
        }
        ll = 1 << i;
        ll = ~ll;
        my_csr = my_csr & ll;
        my_csr = my_csr | val;
    }

    // (d) here:
    int j = 16;
    for (int i = 12; i <= 27; i++) {
        int upd = ADDRESS >> i;
        upd = upd & 1;
        val = upd << j;
        if (j == 31) {
            ll = 1 << (j-1);
        } else {
            ll = 1 << j;
        }
        ll = ~ll;
        my_csr = my_csr & ll;
        my_csr = my_csr | val;
        j++;
    }

    printf("%lx \n", my_csr);

    return 0;
}
