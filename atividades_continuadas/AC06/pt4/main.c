// ESTE ARQUIVO JA ESTA PRONTO, NAO MEXA NELE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.h"

// Vetor dinâmico simples
typedef struct {
    Node **data;
    size_t size;
} Vector;

// Inicializa vetor
void vector_init(Vector *v) {
    v->data = NULL;
    v->size = 0;
}

// Adiciona uma lista nova no final
void vector_push_back(Vector *v, Node *list) {
    v->data = realloc(v->data, (v->size + 1) * sizeof(Node*));
    v->data[v->size] = list;
    v->size++;
}

// Libera todas as listas
void vector_clear(Vector *v) {
    for(size_t i = 0; i < v->size; i++) {
        list_free(v->data[i]);
    }
    free(v->data);
    v->data = NULL;
    v->size = 0;
}

int main() {
    Vector listas;
    vector_init(&listas);

    char comando[300];

    while (true) {

        if(!fgets(comando, sizeof(comando), stdin))
            break;

        // Remove \n
        comando[strcspn(comando, "\n")] = 0;

        printf("$%s\n", comando);

        char *token = strtok(comando, " ");

        if(token == NULL)
            continue;

        // -------- exit --------
        if(strcmp(token, "exit") == 0) {
            vector_clear(&listas);
            break;
        }

        // -------- create --------
        else if(strcmp(token, "create") == 0) {
            vector_push_back(&listas, list_create());
        }

        // -------- size l --------
        else if(strcmp(token, "size") == 0) {
            int l = atoi(strtok(NULL, " "));
            printf("size list %d: %zu\n", l, list_size(listas.data[l]));
        }

        // -------- varredura l --------
        else if(strcmp(token, "varredura") == 0) {
            int l = atoi(strtok(NULL, " "));
            listas.data[l] = list_varredura(listas.data[l]);
        }

        // -------- bubblesort l --------
        else if(strcmp(token, "bubblesort") == 0) {
            int l = atoi(strtok(NULL, " "));
            listas.data[l] = list_bubblesort(listas.data[l]);
        }

        // -------- addFront l a1 a2 ... --------
        else if(strcmp(token, "addFront") == 0) {
            int l = atoi(strtok(NULL, " "));
            char *p = NULL;
            while((p = strtok(NULL, " ")) != NULL) {
                int val = atoi(p);
                listas.data[l] = list_push_front(listas.data[l], val);
            }
        }

        // -------- addBack l a1 a2 ... --------
        else if(strcmp(token, "addBack") == 0) {
            int l = atoi(strtok(NULL, " "));
            char *p = NULL;
            while((p = strtok(NULL, " ")) != NULL) {
                int val = atoi(p);
                listas.data[l] = list_push_back(listas.data[l], val);
            }
        }

        // -------- show --------
        else if(strcmp(token, "show") == 0) {
            for(size_t i = 0; i < listas.size; i++) {
                printf("lista %zu: ", i);
                list_print(listas.data[i]);
            }
        }

        else {
            printf("comando inexistente\n");
        }
    }

    return 0;
}