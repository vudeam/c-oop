#include <stdio.h>

#include "new.h"
#include "Object.h"
#include "Set.h"
#include "list.h"


void list_print(const struct Node * list);

int main(void) {
	int data = 0xF00DBABA;
	int data1 = 0xF00DBABA + 1;
	int data2 = 0xF00DBABA + 2;
	int data3 = 0xF00DBABA + 3;

	struct Node * list = node_create(&data);

	list_append(&list, &data1);
	data++;
	list_append(&list, &data2);
	data++;
	list_append(&list, &data3);
	data++;

	list_print(list);

	/*
	void * s = new(Set);
	void * a = add(s, new(Object));
	void * b = add(s, new(Object));
	void * c = new(Object);
	
	if (contains(s, a) && contains(s, b))
		puts("ok");

	if (contains(s, c))
		puts("contains?");

	if (differ(a, add(s, a)))
			puts("differ?");
	
	if (contains(s, drop(s, a)))
		puts("drop?");

	delete(drop(s, b));
	delete(drop(s, c));
	*/

	puts("\n");

	return 0;
}

void list_print(const struct Node * list) {
	printf("len=%zu\n", list_length(list));
	/*for (size_t i = 0; i < list_length(list); i++) {
		const struct Node * element = list_node_at(list, i);
		printf("[%zu] %x (%p)", i, *(int *)element, (void *)element);
	}*/
	const struct Node * buf = list;
	for (size_t i = 0;
			 buf;
			 buf = buf->next, i++) {
		printf("[%zu] %x (%p)\n", i, *(int *)buf->data, (void *)buf);
	}
}

