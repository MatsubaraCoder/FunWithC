#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

typedef union {
    int intNumber;
    float floatNumber;
} value;

typedef enum {
    INT,
    FLOAT
} valueType;

typedef struct linkedList {
    value data;
    valueType dataType;
    struct linkedList *addrOfNextNum;
} linkedList;

typedef struct {
    value data;
    valueType dataType;
    bool error;
} valueResult;

typedef enum {
    SUCCESS,
    INDEX_OUT_OF_RANGE,
    MEMORY_ALLOCATION_FAILED
} errorCode;


errorCode append(linkedList **list, value newData, valueType dataTypeOfValue);
errorCode insertAt(linkedList **list, value newData, valueType dataTypeOfValue, int index);
valueResult getValueAt(linkedList *list, int index);
int len(linkedList *list);
void freeLinkedList(linkedList **list);
void printLinkedList(linkedList *list);

#endif