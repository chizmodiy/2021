#include"list.h"
#include<stdio.h>



list_item* make_list_item(int znach)
{
	list_item* item = (list_item*)malloc(sizeof(list_item));
	if (item != NULL)
	{
		memset(item, 0, sizeof(list_item));
		item->val = znach;
	}

	return item;
}


void delete_list_item(list_item* item)
{
	if (NULL != item)
		free(item);
}




list* make_list(void)
{
	list* sp = (list*)malloc(sizeof(list));
	if (sp != NULL)
		memset(sp, 0, sizeof(list));
	return sp;
}

void delete_list(list* sp)
{
	if (NULL == sp)
		return;
	list_item* el = sp->first;
	while (el != sp->last)
	{
		list_item* mask = el->next_item;
		delete_list_item(el);
		el = mask;
	}
	free(sp);
}

void add_value_to_list(list* list, int value)
{
	if ((list->first == NULL && list->first != list->last))
		return;
	list_item* item = make_list_item(value);
	if (item == NULL)
		return;
	if (list->first == NULL)
	{
		list->first = item;
		list->last = list->first;
	}
	list->last->next_item = item;
	item->prev_item = list->last;
	list->last = item;
}

int count_of_items(list* list)
{
	if (list == NULL)
		return 0;
	int count = 0;
	for (list_item* elem = list->first; elem != NULL; elem = elem->next_item, count++);

	return count;
}

void add_value_to_list_by_index(list* list, int value, int index)
{
	if (list == NULL || (list->first == NULL && list->first != list->last))
		return;
	int count = count_of_items(list);

	if (count == index)
		return add_value_to_list(list, value);
	else
		if (index > count)
			return;
	list_item* item = make_list_item(value);
	if (item == NULL)
		return;
	if (index == 0)
	{
		item->next_item = list->first;
		list->first->prev_item = item;
		list->first = item;
	}
	else
	{
		int cur = 0;
		list_item* ex_item = list->first;
		for (; ex_item != NULL && cur != index; ex_item = ex_item->next_item)
			cur++;
		item->next_item = ex_item;
		item->prev_item = ex_item->prev_item;
		ex_item->prev_item = item;
		item->prev_item->next_item = item;
	}
}


void print_list(list* list)
{
	if (list == NULL)
	{
		printf("Invalid a pointer to the list\n");
		return;
	}
	printf("[");
	list_item* item = NULL;
	for (item = list->first; item != list->last; item = item->next_item)
	{
		printf("%d", item->val);
		printf(", ");
	}
	if (item != NULL)
	{
		printf("%d", item->val);
	}
	printf("]\n");
}


void print_list_reverse(list* list)
{
	if (list == NULL)
	{
		printf("Invalid a pointer to the list\n");
		return;
	}
	printf("[");
	list_item* item = NULL;
	for (item = list->last; item != list->first ; item = item->prev_item)
	{
		printf("%d", item->val);
		printf(", ");
	}
	if (item != NULL)
	{
		printf("%d", item->val);
	}
	printf("]\n");

}
