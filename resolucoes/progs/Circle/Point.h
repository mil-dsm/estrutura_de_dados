#include <stdbool.h>

typedef struct Point Point;

Point* create_point(double x, double y);
void free_point(Point *p);
bool get_x(Point *p, double *out_var);
bool get_y(Point *p, double *out_var);
void set_x(Point *p, double x);
void set_y(Point *p, double y);
double distance(Point *p1, Point *p2);