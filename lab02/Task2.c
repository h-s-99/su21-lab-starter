// Copyright 2023 Huda Sajjad
#include <stdio.h>

int odd(int arr[], int n) {
    int tmp = 0;
    for (int i=0; i< n; i++) {
        tmp = arr[i]^tmp;
    }
    return tmp;
}

int main() {
    int arr[] = {12, 12, 14, 90, 14, 14, 14};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int tmp1 = odd(arr, arr_size);
    printf("%d\n", tmp1);
    return 0;
}
