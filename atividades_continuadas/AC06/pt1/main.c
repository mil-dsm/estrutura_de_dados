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

        // -------- clone l --------
        else if(strcmp(token, "clone") == 0) {
            int l = atoi(strtok(NULL, " "));
            vector_push_back(&listas, list_clone(listas.data[l]));
        }

        // -------- concat l1 l2 --------
        else if(strcmp(token, "concat") == 0) {
            int l1 = atoi(strtok(NULL, " "));
            int l2 = atoi(strtok(NULL, " "));
            listas.data[l1] = list_concatenar(listas.data[l1], listas.data[l2]);
            listas.data[l2] = NULL;
        }

        // -------- remove x l --------
        else if(strcmp(token, "remove") == 0) {
            int x = atoi(strtok(NULL, " "));
            int l = atoi(strtok(NULL, " "));
            listas.data[l] = list_remove_todos(listas.data[l], x);
        }

        // -------- equals l1 l2 --------
        else if(strcmp(token, "equals") == 0) {
            int l1 = atoi(strtok(NULL, " "));
            int l2 = atoi(strtok(NULL, " "));
            if(list_sao_iguais(listas.data[l1], listas.data[l2]))
                printf("listas iguais\n");
            else
                printf("listas diferentes\n");
        }

        // -------- different l1 l2 --------
        else if(strcmp(token, "different") == 0) {
            int l1 = atoi(strtok(NULL, " "));
            int l2 = atoi(strtok(NULL, " "));
            if(list_sao_diferentes(listas.data[l1], listas.data[l2]))
                printf("listas diferentes\n");
            else
                printf("listas iguais\n");
        }

        // -------- reverse l --------
        // else if(strcmp(token, "reverse") == 0) {
        //     int l = atoi(strtok(NULL, " "));
        //     listas.data[l] = list_reverter(listas.data[l]);
        // }

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
                printf("\n");
            }
        }

        else {
            printf("comando inexistente\n");
        }
    }

    return 0;
}