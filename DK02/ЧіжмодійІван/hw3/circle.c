#include "circle.h"

PCircle makeCircle(PLine l1)
{
	double radius1 = lenghtLine(l1);
	if (l1 == NULL)
	{
		return NULL;
	}
	if (radius1 <= 0)
	{
		printf("\nThe radius is 0 or less");
		return NULL;
	}
	PCircle c = (PCircle)malloc(sizeof(Circle));
	if (c != NULL)
	{
		c->l = l1;
		c->radius = radius1;
	}
	return c;
}
void printCircle(PCircle c)
{
	if (c == NULL)
	{
		return;
	}
	printf("\nThe circle Center is: ");
	printPoint(c->l->B);
	printf("\nThe second point is: ");
	printPoint(c->l->A);
	printf("\nCircle radius is: %0.2f", lenghtLine(c->l));
	printf("\nCircle square is: %f", sqCircle(c));
	return;
}
double sqCircle(PCircle c)
{
	if (c != NULL)
	{
		double sq = (22 / (double)7)*(c->radius)* (c->radius);
		return sq;
	}
	return -1;
}
void deleteCircle(PCircle c)
{
	if (c != NULL)
	{
		deleteLine(c->l);
		free(c);
	}
	return;
}
