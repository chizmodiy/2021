#include "list.h"
#include <stdlib.h>
#include <string.h>

CharListItem* createCharListItem(char value) {
    CharListItem* result = (CharListItem*)malloc(sizeof(CharListItem));

    if (NULL != result) {
        //bzero(result, sizeof(IntListElement));
        result->value = value;
        result->next = NULL;
        result->prev = NULL;
    }

    return result;
}

void deleteCharListItem(CharListItem* item) {
    if (NULL != item) {
        free(item);
    }
}

void printCharListElement(CharListItem* element) {
    if (NULL != element) {
        printf("%c", element->value);
    }
}

CharList* createCharList(void) {
    CharList* result = (CharList*)malloc(sizeof(CharList));

    if (NULL != result) {
        result->start = NULL;
        result->close = NULL;
        memset(result, 0, sizeof(CharList));
        result->count = 0;
    }

    return result;
}

void deleteCharList(CharList* list) {
    if (NULL == list) {
        return;
    }

    CharListItem* element = list->start;

    while (NULL != element) {
        CharListItem* tmp = element->next;
        deleteCharListItem(element);
        element = tmp;
    }

    free(list);
}

void printCharList(CharList* list) {

    if (NULL == list) {
        printf("Invalid a pointer to the list\n");
        return;
    }


    CharListItem* element = NULL;
    printf("[");
    for (element = list->start; element != list->close; element = element->next) {
        printCharListElement(element);
    }

    if (element != NULL) {
        printCharListElement(element);
    }

    printf("]\n");
}


int addCharValueToCharList(CharList* list, char value) {
    if (NULL == list || (list->start == NULL && list->start != list->close)) {
        return 0;
    }

    CharListItem* item = createCharListItem(value);
    if (NULL == item) {
        return 0;
    }

    if (NULL == list->start) {
        list->start = item;
        list->close = list->start;
        list->count++;
        return 1;

    }

    list->close->next = item;
    item->prev = list->close;
    list->close = item;
    list->count++;
    return list->count;
}
//!
void removeLastItemFromList(CharList* list) {
    if (NULL == list || (list->start == NULL && list->start != list->close)) {
        return;
    }

    if (NULL == list->start) {
        return;
    }

    // is single element list?
    if (list->start == list->close) {
        deleteCharListItem(list->start);
        list->start = NULL;
        list->close = NULL;
        list->count--;
        return;
    }

    CharListItem* toDelete = list->close;
    list->close = toDelete->prev;
    list->close->next = NULL;

    deleteCharListItem(toDelete);
    list->count--;
}

void removeAllItems(CharList* list) {
    while (list->start != NULL) {
        removeLastItemFromList(list);
    }
}
long SizeOfList(CharList* list) {
    if (list != NULL) {
        return list->count;
    }
    return NullPointerException;
}

int insertCharItemToCharListAtIndex(CharList* list, int index, char value) {
    if (NULL == list || (list->start == NULL && list->start != list->close)) {
        return 0;
    }
    long count = SizeOfList(list);
    if (count == index) {
        return addCharValueToCharList(list, value);
    }
    else if (index > count) {
        return 0;
    }
    CharListItem* element = createCharListItem(value);
    if (NULL == element) {
        return 0;
    }
    if (0 == index) {
        element->next = list->start;
        list->start->prev = element;
        list->start = element;
    }
    else {
        int current = 0;
        CharListItem* ex_element = list->start;
        for (; ex_element != NULL && current != index; ex_element = ex_element->next, current++);
        element->next = ex_element;
        element->prev = ex_element->prev;
        ex_element->prev = element;
        element->prev->next = element;
        list->count++;
    }
    return 1;
