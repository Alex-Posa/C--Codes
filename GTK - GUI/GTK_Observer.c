#include <stdio.h>
#include <stdlib.h>

typedef struct _function_node {
    void (*function_pointer)(char*);
    char* data;
    struct _function_node* next;
} FunctionNode;

typedef struct _component {
    FunctionNode* root;
    FunctionNode* head;
    char *name;
} Component;

Component* component_new(char* name) {
    Component* c = calloc(sizeof(Component), 1);
    c->name = name;
    return c;
}

void component_register(Component* c, void (*function_pointer)(char*), char* data) {
    if(c == NULL || function_pointer == NULL) {
        return;
    }

    FunctionNode* n = calloc(sizeof(FunctionNode), 1);
    n->function_pointer = function_pointer;
    n->data = data;

    if(c->root == NULL) {
        c->root = n;
        c->head = n;
    } else if(c->head == NULL) {
        printf("ERROR: Head is null while root has value\n");
        return;
    } else {
        c->head->next = n;
        c->head = n;
    }
}

void component_fire_event(Component* c) {
    if(c == NULL || c->root == NULL) {
        return;
    }

    FunctionNode* tmp = c->root;
    while(tmp != NULL) {
        tmp->function_pointer(tmp->data);
        tmp = tmp->next;
    }
}

void component_free(Component* c) {
    if(c == NULL) {
        return;
    }

    FunctionNode* tmp = c->root;
    FunctionNode* ptr;
    while(tmp != NULL) {
        ptr = tmp;
        tmp = tmp->next;
        free(ptr);
    }
    free(c);
}

// Unsere Observer-Funktion
void on_event(char* data) {
    printf("on_event: %s\n", data);
}

// Eine weitere Observer-Funktion
void on_event2(char* data) {
    printf("on_event2: %s\n", data);
}

int main() {
    // Komponente initialisiern
    Component* c = component_new("Komponente 1");
    // Ereignisbehandlungsfunktionen registrieren
    component_register(c, &on_event, "Beispieltext");
    component_register(c, &on_event, "Beispieltext2");
    component_register(c, &on_event2, "Beispieltext3");
    // Ereignis auslösen
    component_fire_event(c);
    // Komponente löschen
    component_free(c);
}
