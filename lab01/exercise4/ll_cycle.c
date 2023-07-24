// Copyright 2023 Huda Sajjad
#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* TODO: Implement ll_has_cycle */
    if (head == NULL) return 0;
    struct node *slowptr = head;
    struct node *fastptr = head;
    if (head->next->next == NULL) return 0;
    while (fastptr->next != NULL && fastptr->next->next != NULL) {
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
            if (fastptr == slowptr) {
                return 1;
            }
    }
    return 0;
}
