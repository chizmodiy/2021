#include "circle.h"

#define ARRAYS_H
#ifdef ARRAYS_H

typedef struct 
{
	PCircle *storage;
	long amountOfCircles;
} Array, * PArray;

PArray makeArrayCircles(int amount);
long setCircleAtIndex(PArray array, PCircle c, long index);
PCircle getCircleAtIndex(PArray array, int index);
void deleteArrayCircles(PArray array);
void printArrayCircles(PArray array);
long countOfArrays(PArray array);
void freeArrayCircles(PArray array);
//long realocateArrayOfCircles(int requestedCount, PArray array);
int setCirclesAtArray(PArray array);
#endif
