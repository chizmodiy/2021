#pragma once
#include "line.h"
#define CIRCLE_H
#ifdef CIRCLE_H

typedef struct
{
	PLine l;
	double radius;
} Circle, * PCircle;

PCircle makeCircle(PLine l1);
void printCircle (PCircle c);
double sqCircle(PCircle c);
void deleteCircle(PCircle c);
#endif 
