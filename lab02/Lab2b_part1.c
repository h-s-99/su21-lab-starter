// Copyright 2023 Huda Sajjad
#include <stdio.h>
#include <string.h>

struct student {
    char name[40];
    int id;
    int age;
};

int main() {
    struct student first;
    printf("Enter name of the student ");
    scanf("%[^\n]s", first.name);
    printf("Enter ID of the student ");
    scanf("%d", &first.id);
    printf("Enter age of the student ");
    scanf("%d", &first.age);
    printf("The name, id and age of the student are as follows \n Name:%s" , first.name);
    printf("\n ID:%d", first.id);
    printf("\n Age:%d", first.age);
    return 0;
}
