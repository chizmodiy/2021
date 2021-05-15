#include <stdio.h>
#include "arrays.h"

int main(void)
{
	PPoint p1 = getPoint();
	PPoint p2 = getPoint();
	PLine l = makeLine(p1, p2);
	PCircle c = makeCircle(l);
	Circle c1 = { 0 };
	printf("Enter the number of circles:\n ");
	PArray array = makeArrayCircles(getNum());
	printf("Put the circles into the array\n The first point is for the center\n");
	setCirclesAtArray(array);
	printf("Add another Circle into array(realocate)\n");
	setCircleAtTheEnd(array, c);
	setCircleAtTheEnd(array, &c1);
	printArrayCircles(array);
	//freeArrayCircles(array);
	deleteArrayCircles(array);
	printCircle(c);
}
