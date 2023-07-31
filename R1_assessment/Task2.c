// Copyright 2023 Huda Sajjad
#include <stdio.h>

int mystrlen(char *str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

int main() {
    char str[100];
    int n;
    printf("Enter the string: ");
    scanf("%[^\n]s", str);
    n = mystrlen(str);
    printf("%s", "The numbers of bytes in the string are:");
    printf("%d \n", n);
    return 0;
}
