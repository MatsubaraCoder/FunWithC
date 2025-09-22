#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"


int main() {
    linkedList *myList = NULL;

    value num1 = {.intNumber = 10};
    append(&myList, num1, INT);

    value num2 = {.intNumber = 11};
    append(&myList, num2, INT);

    value num3 = {.floatNumber = 12.5};
    insertAt(&myList, num3, FLOAT, 0);

    printLinkedList(myList);

    printf("len: %d\n", len(myList));

    valueResult result = getValueAt(myList, 3);
    if (result.error) {
        printf("error\n");
    } else {
        if (result.dataType == INT)
            printf("%d\n", result.data.intNumber);
        else if (result.dataType == FLOAT)
            printf("%f\n", result.data.floatNumber);
    }

    freeLinkedList(&myList);

    return 0;
}