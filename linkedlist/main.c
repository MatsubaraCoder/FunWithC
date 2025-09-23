#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"
#include "utils.h"


int main() {
    linkedList *myList = NULL;

    value num1 = {.intNumber = 10};
    append(&myList, num1, INT);

    value num2 = {.intNumber = 11};
    append(&myList, num2, INT);

    value num3 = {.floatNumber = 12.5};
    insertAt(&myList, num3, FLOAT, 2);

    printLinkedList(myList);
    deleteAt(&myList, 0);
    printLinkedList(myList);

    printf("len: %d\n", len(myList));

    for (int i=-1; i<=len(myList); i++) {
        valueResult result = getValueAt(myList, i);
        if (result.error) {
            printf("INDEX OUT OF RANGE : %d\n", i);
        } else {
            printf("index: %d , ", i);
            if (result.dataType == INT)
                printf("%d\n", result.data.intNumber);
            else if (result.dataType == FLOAT)
                printf("%f\n", result.data.floatNumber);
        }
    }

    freeLinkedList(&myList);

    return 0;
}