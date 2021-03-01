#pragma once
#ifndef HOMEWORKN2_ELLIPSE_H
#define HOMEWORKN2_ELLIPSE_H

#endif //HOMEWORKN2_ELLIPSE_H
#include "point.h"
typedef struct tag_ellipse {

    Point* f1;
    Point* f2;
    int a;
    int b;
    int focusDistance;

} Ellipse;

Ellipse* createByFocusesEllipse(Point* f1, Point* f2, int a, int b);
Ellipse* createByParametersEllipse(int a, int b);
Ellipse* createEllipseByCoords(int x1, int x2, int a, int b);
Ellipse* copyEllipse(Ellipse* l);
int isPointBelongsToEllipse(Point p, Ellipse e);
int isEqualEllipse(Ellipse* ellipse1, Ellipse* ellipse2);
double focusLenght(Ellipse* ellipse);
void deleteEllipse(Ellipse* ellipse);
void printEllipse(Ellipse* ellipse);
