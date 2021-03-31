#pragma once

#ifndef list_h
#define list_h

#include <stdio.h>
#define NullPointerException (-3)
typedef struct tagCharListElement CharListItem;
struct tagCharListElement {
    char value;
    CharListItem* prev;
    CharListItem* next;
};

CharListItem* createCharListItem(char value);
void deleteCharListItem(CharListItem* element);
void printCharListElement(CharListItem* element);

typedef struct tagCharList {
    int count;
    CharListItem* start;
    CharListItem* close;
} CharList;

CharList* createCharList(void);
void deleteCharList(CharList* list);
void printCharList(CharList* list);
int addCharValueToCharList(CharList* list, char value);
void removeLastItemFromList(CharList* list);
void removeAllItems(CharList* list);
long SizeOfList(CharList* list);
int insertCharItemToCharListAtIndex(CharList* list, int index, char value);
#endif /* list_h */
