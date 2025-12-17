// -------------------------------------------------------
// Nao mexa neste arquivo! Ele ja esta pronto para usar.
// -------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Point.h"
#include "Circle.h"

#define MAX_CMD 128

// ===============================
// Vetor dinâmico de círculos
// ===============================
typedef struct {
    Circle **data;
    int size;
    int capacity;
} CircleArray;

void init_array(CircleArray *arr) {
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

void push_circle(CircleArray *arr, Circle *c) {
    if (arr->size == arr->capacity) {
        arr->capacity = arr->capacity == 0 ? 2 : arr->capacity * 2;
        arr->data = realloc(arr->data, arr->capacity * sizeof(Circle*));
    }
    arr->data[arr->size++] = c;
}

Circle* get_circle(CircleArray *arr, int idx) {
    if (idx < 0 || idx >= arr->size) return NULL;
    return arr->data[idx];
}

void clear_array(CircleArray *arr) {
    for(int i = 0; i < arr->size; i++) {
        free(arr->data[i]);
    }
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

// ===============================
// Função principal
// ===============================
int main() {
    CircleArray circulos;
    init_array(&circulos);

    char cmd[MAX_CMD];

    while (1) {
        if (!fgets(cmd, sizeof(cmd), stdin)) break;

        // remover \n
        cmd[strcspn(cmd, "\n")] = '\0';

        // tokenização simples
        char *tokens[8];
        int ntok = 0;
        char *tok = strtok(cmd, " ");
        while (tok && ntok < 8) {
            tokens[ntok++] = tok;
            tok = strtok(NULL, " ");
        }

        if (ntok == 0) continue;

        // comandos
        if (strcmp(tokens[0], "exit") == 0) {
            clear_array(&circulos);
            break;
        }
        else if (strcmp(tokens[0], "cria") == 0 && ntok == 4) {
            double raio = atof(tokens[1]);
            double x = atof(tokens[2]);
            double y = atof(tokens[3]);
            Circle *c = circle_create(x, y, raio);
            push_circle(&circulos, c);
        }
        else if (strcmp(tokens[0], "imprime") == 0 && ntok == 2) {
            int idx = atoi(tokens[1]);
            Circle *c = get_circle(&circulos, idx);
            if (c) {
                double x, y, radius;
                circle_get_center(c, &x, &y);
                circle_get_radius(c, &radius);
                printf("[raio:%.2f, X:%.2f, Y:%.2f]\n", radius, x, y);
            } else
                printf("indice invalido\n");
        }
        else if (strcmp(tokens[0], "imprime_todos") == 0) {
            for (int i = 0; i < circulos.size; ++i) {
                Circle *c = circulos.data[i];
                double x, y, radius;
                circle_get_center(c, &x, &y);
                circle_get_radius(c, &radius);
                printf("[%d] raio:%.2f, X:%.2f, Y:%.2f\n", i, radius, x, y);
            }
        }
        else if (strcmp(tokens[0], "getx") == 0 && ntok == 2) {
            int idx = atoi(tokens[1]);
            Circle *c = get_circle(&circulos, idx);
            double x, y;
            circle_get_center(c, &x, &y);
            if (c) printf("X: %.2f\n", x);
            else printf("indice invalido\n");
        }
        else if (strcmp(tokens[0], "gety") == 0 && ntok == 2) {
            int idx = atoi(tokens[1]);
            Circle *c = get_circle(&circulos, idx);
            double x, y;
            circle_get_center(c, &x, &y);
            if (c) printf("Y: %.2f\n", y);
            else printf("indice invalido\n");
        }
        else if (strcmp(tokens[0], "setx") == 0 && ntok == 3) {
            int idx = atoi(tokens[1]);
            double x = atof(tokens[2]);
            Circle *c = get_circle(&circulos, idx);
            if (c) circle_set_xcenter(c, x);
            else printf("indice invalido\n");
        }
        else if (strcmp(tokens[0], "sety") == 0 && ntok == 3) {
            int idx = atoi(tokens[1]);
            double y = atof(tokens[2]);
            Circle *c = get_circle(&circulos, idx);
            if (c) circle_set_ycenter(c, y); 
            else printf("indice invalido\n");
        }
        else if (strcmp(tokens[0], "getarea") == 0 && ntok == 2) {
            int idx = atoi(tokens[1]);
            Circle *c = get_circle(&circulos, idx);
            double area;
            circle_area(c, &area);
            if (c) printf("area: %.2f\n", area);
            else printf("indice invalido\n");
        }
        else if (strcmp(tokens[0], "getraio") == 0 && ntok == 2) {
            int idx = atoi(tokens[1]);
            Circle *c = get_circle(&circulos, idx);
            double radius;
            circle_get_radius(c, &radius);
            if (c) printf("raio: %.2f\n", radius);
            else printf("indice invalido\n");
        }
        else if (strcmp(tokens[0], "getcentro") == 0 && ntok == 2) {
            int idx = atoi(tokens[1]);
            Circle *c = get_circle(&circulos, idx);
            double x, y;
            circle_get_center(c, &x, &y);
            if (c) printf("centro: (%.2f, %.2f)\n", x, y);
            else printf("indice invalido\n");
        }
        else if (strcmp(tokens[0], "setraio") == 0 && ntok == 3) {
            int idx = atoi(tokens[1]);
            double r = atof(tokens[2]);
            Circle *c = get_circle(&circulos, idx);
            if (c) circle_set_radius(c, r);
            else printf("indice invalido\n"); 
        }
        else if (strcmp(tokens[0], "setcentro") == 0 && ntok == 4) {
            int idx = atoi(tokens[1]);
            double x = atof(tokens[2]);
            double y = atof(tokens[3]);
            Circle *c = get_circle(&circulos, idx);
            if (c) circle_set_center(c, x, y);
            else printf("indice invalido\n");
        }
        else if (strcmp(tokens[0], "interior") == 0 && ntok == 4) {
            int idx = atoi(tokens[1]);
            double x = atof(tokens[2]);
            double y = atof(tokens[3]);
            Circle *c = get_circle(&circulos, idx);
            if (c) {
                Point *p = create_point_with_coords(x, y);
                bool interior = false;
                circle_contains(c, p, &interior);
                printf("%s\n", interior ? "true" : "false");
                free_point(p);
            }
            else printf("indice invalido\n");
        }
        else {
            printf("comando inexistente\n");
        }
    }

    return 0;
}