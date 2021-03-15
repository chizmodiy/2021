#pragma once
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define list_h
#ifdef list_h



typedef struct slist_item  list_item;

struct slist_item
{
	list_item* next_item;
	list_item* prev_item;
	int val;
};

list_item* make_list_item(int znach);
void delete_list_item(list_item* item);



typedef struct slist {
	list_item* first;
	list_item* last;
} list;

list* make_list(void);
void delete_list(list* sp);

int count_of_items(list* list);

void add_value_to_list(list* list, int value);
void add_value_to_list_by_index(list* list, int value, int index);

void print_list(list* list);
void print_list_reverse(list* list);

#endif // list_h
