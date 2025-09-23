#include <stdio.h>
#include "utils.h"
#include "linkedlist.h"

int len(linkedList *list) {
    int len = 0;
    while (list) {
        len += 1;
        list = list->addrOfNextNum;
    }
    return len;
}

void printLinkedList(linkedList *list) {
    if (list) {
        linkedList *temp = list;
        while (temp) {
            if (temp->dataType == INT) {
                printf("%d -> ", temp->data.intNumber);
            } else if (temp->dataType == FLOAT) {
                printf("%f -> ", temp->data.floatNumber);
            }
            temp = temp->addrOfNextNum;
        }
        printf("NULL\n");
    }
}