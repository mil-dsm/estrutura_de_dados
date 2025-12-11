// ------------------------------------------------
// NAO MEXA NESSE ARQUIVO, ELE JA ESTA FINALIZADO
// ------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Vector.h"

#define MAX_LINE 2000

int main() {
    Vector *myvec = vector_create();

    if (!myvec) {
        fprintf(stderr, "Erro: não foi possível criar o vetor.\n");
        return 1;
    }

    char line[MAX_LINE];

    while (true) {
        if (!fgets(line, sizeof(line), stdin))
            break;

        // remover \n
        line[strcspn(line, "\n")] = '\0';

        char comando[MAX_LINE];
        strcpy(comando, "");

        // tokenização
        char *token = strtok(line, " ");
        if (token)
            strcpy(comando, token);

        // exit
        if (strcmp(comando, "exit") == 0) {
            printf("$exit\n");
            break;
        }

        // front
        else if (strcmp(comando, "front") == 0) {
            printf("$front\n");
            int value;
            ErrorType err = vector_front(myvec, &value);
            if (err == ERROR_OK) {
                printf("%d\n", value);
            } else {
                printf("fail: empty vector\n");
            }
        }

        // back
        else if (strcmp(comando, "back") == 0) {
            printf("$back\n");
            int value;
            ErrorType err = vector_back(myvec, &value);
            if (err == ERROR_OK) {
                printf("%d\n", value);
            } else {
                printf("fail: empty vector\n");
            }
        }

        // removeall v
        else if (strcmp(comando, "removeall") == 0) {
            token = strtok(NULL, " ");
            if (!token) continue;
            int v = atoi(token);
            printf("$removeall %d\n", v);
            vector_remove_all(myvec, v);
        }

        // insertat v k
        else if (strcmp(comando, "insertat") == 0) {
            char *t1 = strtok(NULL, " ");
            char *t2 = strtok(NULL, " ");
            if (!t1 || !t2) continue;

            int v = atoi(t1);
            int k = atoi(t2);

            printf("$insertat %d %d\n", v, k);

            ErrorType err = vector_insert(myvec, (size_t)k, v);
            if (err == ERROR_OUT_OF_BOUNDS) {
                printf("fail: index out of range\n");
            }
        }

        // removeat k
        else if (strcmp(comando, "removeat") == 0) {
            char *t1 = strtok(NULL, " ");
            if (!t1) continue;

            int k = atoi(t1);
            printf("$removeat %d\n", k);

            ErrorType err = vector_erase(myvec, (size_t)k);
            if (err == ERROR_OUT_OF_BOUNDS) {
                printf("fail: index out of range\n");
            }
        }

        // pushback v1 v2 ... vk
        else if (strcmp(comando, "pushback") == 0) {
            printf("$pushback ");

            token = strtok(NULL, " ");
            while (token) {
                int v = atoi(token);
                printf("%d ", v);
                vector_push_back(myvec, v);
                token = strtok(NULL, " ");
            }
            printf("\n");
        }

        // print
        else if (strcmp(comando, "print") == 0) {
            printf("$print\n");
            size_t n = vector_size(myvec);
            for (size_t i = 0; i < n; i++) {
                int v;
                vector_get(myvec, i, &v);
                printf("%d ", v);
            }
            printf("\n");
        }

        // size
        else if (strcmp(comando, "size") == 0) {
            printf("$size\n");
            printf("%zu\n", vector_size(myvec));
        }

        // copy
        else if (strcmp(comando, "copy") == 0) {
            printf("$copy\n");
            Vector *cvec = vector_create();
            ErrorType err = vector_copy(myvec, cvec);
            if(err != ERROR_OK) {
                printf("fail: not possible to copy\n");
            } else {
                size_t n = vector_size(cvec);
                if(n >= 1) vector_pop_back(cvec);
                printf("copy vector after popback: ");
                for (size_t i = 0; i < vector_size(cvec); i++) {
                    int v;
                    vector_get(cvec, i, &v);
                    printf("%d ", v);
                }
                printf("\n");
                cvec = vector_free(cvec);
            }                
        }

        // comando inexistente
        else {
            printf("comando inexistente\n");
        }
    }

    vector_free(myvec);
    return 0;
}