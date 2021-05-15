#pragma once
#include <stdio.h>
#include <stdlib.h>
#define POINT_H
#ifdef POINT_H

typedef struct
{
	int x;
	int y;
}Point, *PPoint;

PPoint makePoint(int x, int y);
void deletePoint(PPoint p);
void printPoint(PPoint p);
PPoint getPoint(void);
//num
int getNum(void);
#endif 
