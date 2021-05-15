#pragma once
#include "point.h"
#include <math.h>

 #define LINE_H
#ifdef LINE_H

typedef struct
{
	PPoint A;
	PPoint B;
} Line, *PLine;

PLine makeLine(PPoint p1, PPoint p2);
void printLine(PLine l);
double lenghtLine(PLine l);
void deleteLine(PLine l);
#endif 
