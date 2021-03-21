#include<stdio.h>
#include"list.h"

int main()
{
	make_list();
	int* new_list = make_list_item(4);
	
	add_value_to_list(new_list, 61);
	add_value_to_list(new_list, 7);
	add_value_to_list(new_list, 27);
	print_list(new_list);
	print_list_reverse(new_list);
	print_list(new_list);
	print_list_reverse(new_list);
	delete_list(new_list);

}
