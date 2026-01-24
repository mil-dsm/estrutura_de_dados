#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "Point.h"

typedef struct Circle Circle;

Circle* create_circle(double radius, const Point *center);

void setRadius(Circle *c, double r);

void setCenterByCoords(Circle *c, double x, double y);

void setCenterByPoint(Circle *c, const Point *p);

double getRadius(const Circle *c);

Point* getCenter(const Circle *c);

double area(const Circle *c);

bool contains(const Circle *c, const Point *p);

#endif