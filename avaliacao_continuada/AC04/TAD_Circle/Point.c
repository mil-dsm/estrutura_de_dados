// ESTE ARQUIVO JA ESTA PRONTO PARA USO, NAO MEXA NELE
#include <stdlib.h>
#include <math.h>
#include "Point.h"

struct point {
    double x;
    double y;
};

Point* create_point_default(void) {
    return create_point_with_coords(0, 0);
}

Point* create_point_with_coords(double x, double y) {
    Point *ptr = malloc(sizeof(Point));
    if(ptr != NULL) {
        ptr->x = x;
        ptr->y = y;
    }
    return ptr;
}

Point* free_point(Point *p) {
    free(p);
    return NULL;
}

ErrorType get_coords(const Point *p, double *x, double *y) {
    if(!p || !x || !y) {
        return ERROR_NULL_POINTER;
    }
    *x = p->x;
    *y = p->y;
    return ERROR_OK;
}

ErrorType get_x(const Point *p, double *x) {
    if(!p || !x) {
        return ERROR_NULL_POINTER;
    }
    *x = p->x;
    return ERROR_OK;
}

ErrorType get_y(const Point *p, double *y) {
    if(!p || !y) {
        return ERROR_NULL_POINTER;
    }
    *y = p->y;
    return ERROR_OK;
}

ErrorType set_x(Point *p, double x) {
    if(!p) {
        return ERROR_NULL_POINTER;
    }
    p->x = x;
    return ERROR_OK;
}

ErrorType set_y(Point *p, double y) {
    if(!p) {
        return ERROR_NULL_POINTER;
    }
    p->y = y;
    return ERROR_OK;
}

ErrorType set_coords(Point *p, double x, double y) {
    if(!p) {
        return ERROR_NULL_POINTER;
    }
    p->x = x;
    p->y = y;
    return ERROR_OK;
}

ErrorType distance_between_points(const Point *p, const Point *q, double *dist) {
    if(!p || !q || !dist) {
        return ERROR_NULL_POINTER;
    }
    double dx = p->x - q->x;
    double dy = p->y - q->y;
    *dist = sqrt(dx * dx + dy * dy);
    return ERROR_OK;
}

ErrorType point_copy(const Point *src, Point *dest) {
    if(!src || !dest) {
        return ERROR_NULL_POINTER;
    }
    dest->x = src->x;
    dest->y = src->y;
    return ERROR_OK;
}

ErrorType point_swap(Point *p, Point *q) {
    if(!p || !q) {
        return ERROR_NULL_POINTER;
    }
    Point aux = *p;
    *p = *q;
    *q = aux;
    return ERROR_OK;
}