#include<stdio.h>
#include "arrays.h"

// arrays standart functions
PArray makeArrayCircles(int amount)
{
	PArray arC = (PArray)malloc(sizeof(Array));
	if (NULL != arC && 0!=amount)
	{
		arC->amountOfCircles = (amount > 0) ? amount : 1;
		arC->storage = (PCircle*)malloc(sizeof(Circle) * arC->amountOfCircles);
		memset(arC->storage, 0, sizeof(PCircle) * arC->amountOfCircles);
	}
	return arC;
}

void freeArrayCircles(PArray array)
{
	if (NULL != array)
	{
		free(array);
	}
}

void deleteArrayCircles(PArray array)
{
	if (NULL != array)
	{
		if (NULL != array->storage)
		{
			for (int i=0; i < array->amountOfCircles-1; i++)
				deleteCircle(array->storage[i]);
		}
		free(array);
	}
}

void printArrayCircles(PArray array)
{
	if (NULL != array)
	{
		for (int i = 0; i < array->amountOfCircles; i++)
		{
			if (array->storage[i] != 0)
			{
				printCircle(array->storage[i]);
			}
			else
			{
				printf("NULL");
			}
			if (i < (array->amountOfCircles - 1))
			{
				printf(",");
			}
		}
	}
	printf("\n");
}

long countOfArrays(PArray array)
{
	if (NULL == array)
	{
		printf("Error, invalid amount of circles");
		return -1;
	}
	return array->amountOfCircles;
}

//	setter	/	getter
int setCirclesAtArray(PArray array)
{
	if (NULL == array)
		return -1;
	for (int i = 0; i < array->amountOfCircles; i++)
	{
		PCircle c = makeCircle(makeLine(getPoint(), getPoint()));
		setCircleAtIndex(array, c, i);
	}
	return 0;
}

long setCircleAtIndex(PArray array, PCircle c, long index)
{
	if (NULL == array || index < 0)
	{
		printf("Error, invalid amount of circles");
		return -1;
	}
	if (index >= array->amountOfCircles)
	{
		if (-1 == realocateArrayOfCircles(index + 1, array))
		{
			return -1;
		}
	}
	array->storage[index] = c;
	return index;
}

long setCircleAtTheEnd(PArray array, PCircle c)
{
	if (NULL == array)
	{
		printf("Error, invalid amount of circles");
		return -1;
	}
	if (NULL == array)
		array->storage[array->amountOfCircles-1] = c;
	else
	{
		if (-1 == realocateArrayOfCircles(array->amountOfCircles, array))
		{
			return -1;
		}
	}
	array->storage[array->amountOfCircles] = c;
	array->amountOfCircles++;
	return array->amountOfCircles;
}
PCircle getCircleAtIndex(PArray array, int index)
{
	if (NULL == array || index < 0 || index>= array->amountOfCircles)
	{
		printf("Error, invalid amount of circles");
		return NULL;
	}
	return array->storage[index];
}

//realocate
long realocateArrayOfCircles(long requestedCount, PArray array)
{
	if (array->amountOfCircles >= requestedCount)
	{
		return array->amountOfCircles;
	}
	long count = requestedCount+1;
	//array->amountOfCircles = requestedCount+1;
	PCircle* newArray = (PCircle*)malloc(sizeof(PCircle)*count);
	if (NULL == newArray)
	{
		printf("Error, can't realocate");
		return -1;
	}
	memset(newArray, '0', sizeof(PCircle) * count);
	memcpy(newArray, array->storage, sizeof(PCircle) * array->amountOfCircles);
	free(array->storage);
	array->storage = count;
	return count;
}
