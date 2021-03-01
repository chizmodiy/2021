#include<stdio.h>
#include "point.h"
#include <stdlib.h>

Point  *createPoint(int x, int y)
 {
    Point *point = (Point *)malloc(sizeof(Point));   //виділення памяті для функції 
    if (NULL != point) 
    {
        point->x = x;
        point->y = y;            //створення функції що заповнює значення x , y і записує їх  в Point
    }

    return point;
}

void deletePoint(Point *p) {
    if (NULL != p) {  //перевірка та звільнення памяті
        free(p);
    }
}

void printPoint(Point *p) {
    if (NULL == p) {    
        return;
    }

    printf("(%d, %d)", p->x, p->y); //друкує значення , які були занесені а createPoint
}

Point *copyPoint(Point *p) {
    if (NULL == p) {
        return NULL;
    }

    return createPoint(p->x, p->y); // функція створює копію createPoint
}

int isEqualPoints(Point *lp, Point *rp) {
    if (NULL == lp || NULL == rp) {
        return 0;
    }

    return (lp == rp || (lp->x == rp->x && lp->y == rp->y)) ? 1 : 0;  // перевірка на рівність точок
}
