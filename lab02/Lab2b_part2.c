// Copyright 2023 Huda Sajjad
#include <stdio.h>

static inline int send() {
    return 5;
}

int main() {
    int a;
    a = send();
    printf("The integer recieved from the function is: %d\n", a);
    return 0;
}
