#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20

typedef struct {
	int id;
	char name[NAME_LEN];
} Person;

typedef struct node {
	void* obj;
	struct node* next;
} GenericNode;

typedef struct {
	GenericNode* root;
	GenericNode* current;
	int idx;
} GenericList;

GenericList* generic_list_new() {
	GenericList* list = calloc(sizeof(GenericList), 1);
	list->root = NULL; // Eigentlich durch calloc schon gewährleistet!
	list->current = NULL; // ..
	list->idx = 0; // ..
	return list;
}

void generic_list_append(GenericList* list, void* object) {
	if(list == NULL || object == NULL) {
		// TODO: Fehler melden
		return;
	}

	if(list->root == NULL) {
		list->root = calloc(sizeof(GenericNode), 1);
		list->current = list->root;
	} else {
		GenericNode *new = calloc(sizeof(GenericNode), 1);
		list->current->next = new;
		list->current = list->current->next;
	}

	list->current->obj = object;
}

void generic_list_print(GenericList* list, void printfunction(void*)) {
	if(list == NULL || printfunction == NULL) {
		printf("ERROR: list or printfunction is NULL\n");
		return;
	}

	GenericNode *ptr = list->root;
	while(ptr != NULL) {
		printfunction(ptr->obj);
		ptr = ptr->next;
	}
}

GenericList* generic_list_free(GenericList* list, void free_ptr(void*)) {
	if(list == NULL) {
		return list;
	}

	GenericNode *ptr = list->root;
	while(ptr != NULL) {
		GenericNode *tmp = ptr;
		ptr = ptr->next;
		if(free_ptr != NULL) {
			free_ptr(tmp->obj);
		}
		free(tmp);
	}
	free(list);
	return NULL;
}

void person_print(void* ptr) {
	Person* p = (Person*)ptr;
	printf("Person: %d, %s\n", p->id, p->name);
}

int main() {
	char tmp[NAME_LEN] = {0};
	int idx = 0;
	GenericList* l = generic_list_new();

	while(strncmp(tmp, "END\n", NAME_LEN) != 0) {
		fgets(tmp, NAME_LEN, stdin);

		Person* p = calloc(sizeof(Person), 1);
		p->id = idx++;
		strncpy(p->name, tmp, NAME_LEN);

		generic_list_append(l, p);
	}

	generic_list_print(l, person_print);

	l = generic_list_free(l, free);
	// Denn danach ist l nach dem free NULL

	return 0;
}
