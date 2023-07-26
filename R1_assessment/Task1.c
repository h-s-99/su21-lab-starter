// Copyright 2023 Huda Sajjad
#include <stdio.h>

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int num1, num2;
    printf("Enter number 1: ");
    scanf("%d", &num1);
    printf("Enter number 2: ");
    scanf("%d", &num2);
    printf("%s", "The numbers before swap are: ");
    printf("number1 = %d ", num1);
    printf("and number2 = %d \n", num2);
    swap(&num1, &num2);
    printf("%s", "The numbers after swap are: ");
    printf("number1 = %d ", num1);
    printf("and number2 = %d \n", num2);
    return 0;
}
