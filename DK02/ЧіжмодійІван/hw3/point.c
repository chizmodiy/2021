#include "point.h"

PPoint makePoint(int x, int y)
{
	PPoint point = (PPoint)malloc(sizeof(Point));
	if (NULL != point)
	{
		point->x = x;
		point->y = y;
	}
	return point;
}

void deletePoint(PPoint p)
{
	if (NULL != p)
	{
		free(p);
	}
	return;
}

void printPoint(PPoint p)
{
	if (NULL != p)
	{
		printf("The point is: (%d;%d)", p->x, p->y);
	}
	return;
}

PPoint getPoint(void)
{
	int x=NULL, y=NULL;
	printf("Enter X:");
	scanf_s("%d", &x);
	printf("Enter Y:");
	scanf_s("%d", &y);
	if ((x == NULL) || (y == NULL))
	{
		return NULL;
	}
	PPoint result = makePoint(x, y);
	return result;
}
//num
int getNum(void)
{
	int i = 0;
	printf("Print the number:");
	scanf_s("%d", &i);
	if (i == NULL)
	{
		printf("You've entered the wrong symbol,\nPlease, enter only numbers.\n");
		return -1;
	}
	printf("You have just entered: %d\n", i);
	return i;
}
