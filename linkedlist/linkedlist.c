#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"


errorCode append(linkedList **list, value newData, valueType dataTypeOfValue) {
    linkedList *temp = (linkedList *)malloc(sizeof(linkedList));
    
    if (!temp)
        return MEMORY_ALLOCATION_FAILED;

    temp->data = newData;
    temp->dataType = dataTypeOfValue;
    temp->addrOfNextNum = NULL;

    linkedList **ptrToNode = list;
    while (*ptrToNode) {
        ptrToNode = &(*ptrToNode)->addrOfNextNum;
    }

    *ptrToNode = temp;
    return SUCCESS;

    // if (!*list) {
    //     *list = temp;
    //     return SUCCESS;
    // }

    // linkedList *lastLinkedList = *list;
    // while (lastLinkedList->addrOfNextNum) {
    //     lastLinkedList = lastLinkedList->addrOfNextNum;
    // }
    // lastLinkedList->addrOfNextNum = temp;

    // return SUCCESS;
}

errorCode insertAt(linkedList **list, value newData, valueType dataTypeOfValue, int index) {
    linkedList *temp = (linkedList *)malloc(sizeof(linkedList));

    if (!temp)
        return MEMORY_ALLOCATION_FAILED;

    temp->data = newData;
    temp->dataType = dataTypeOfValue;

    linkedList **ptrToNode = list;
    while (*ptrToNode && index--) {
        ptrToNode = &(*ptrToNode)->addrOfNextNum;
    }
    
    if (index > 0) {
        free(temp);
        return INDEX_OUT_OF_RANGE;
    }

    temp->addrOfNextNum = *ptrToNode;
    *ptrToNode = temp;

    return SUCCESS;

    // if (index == 0) {
    //     temp->addrOfNextNum = *list;
    //     *list = temp;
    //     return SUCCESS;
    // }

    // linkedList *tempOfList = *list;
    // while (tempOfList && --index > 0) {
    //     tempOfList = tempOfList->addrOfNextNum;
    // }

    // if (index) {
    //     free(temp);
    //     return INDEX_OUT_OF_RANGE;
    // }

    // temp->addrOfNextNum = tempOfList->addrOfNextNum;
    // tempOfList->addrOfNextNum = temp;
    // return SUCCESS;

}

valueResult getValueAt(linkedList *list, int index) {
    valueResult result = { .error = true };

    if (!list || index < 0)
        return result;

    while (list && --index >= 0) {
        list = list->addrOfNextNum;
        if (!list)
            return result;
    }

    result.data = list->data;
    result.dataType = list->dataType;
    result.error = false;

    return result;
}

int len(linkedList *list) {
    int len = 0;
    while (list) {
        len += 1;
        list = list->addrOfNextNum;
    }
    return len;
}

void freeLinkedList(linkedList **list) {
    if (!*list)
        return;

    linkedList *temp;
    while (*list) {
        temp = *list;
        *list = (*list)->addrOfNextNum;
        free(temp);
    }
    *list = NULL;
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