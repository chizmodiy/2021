#include "tree.h"
#include <stdlib.h>

static void deleteNode(DoubleNode* aNode);
static DoubleNode* createDoubleNodeWithDOUBLEValue(double aValue);
static DoubleNode* getSuccessor(DoubleTree* tree, DoubleNode* toDelete);
static void show_bouble_value(DoubleNode* node);

DoubleTree* createDoubleTree(void)
{
	DoubleTree* NEWTree = (DoubleTree*)malloc(sizeof(DoubleTree));

	if (NULL != NEWTree)
	{
		NEWTree->root = NULL;
		NEWTree->count = 0;
	}

	return NEWTree;
}

void DeleteTree(DoubleTree* aTree)
{
	if (NULL != aTree)
	{
		deleteNode(aTree->root);
		free(aTree);
	}
}

void includeNewItemToTree(DoubleTree* aTree, double aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	DoubleNode* theNode = createDoubleNodeWithDOUBLEValue(aValue);
	if (NULL == theNode)
	{
		return;
	}

	if (NULL == aTree->root)
	{
		aTree->root = theNode;
		aTree->count++;
	}
	else
	{
		DoubleNode* theCurrent = aTree->root;
		DoubleNode* theParent = NULL;

		while (1)     //ПОШУК БАТЬКІВСЬКО ВУЗЛА
		{
			theParent = theCurrent;

			if (aValue < theCurrent->value)
			{
				theCurrent = theCurrent->leftChild;
				if (NULL == theCurrent)
				{
					theParent->leftChild = theNode;
					break;
				}
			}
			else
			{
				theCurrent = theCurrent->rightChild;
				if (NULL == theCurrent)
				{
					theParent->rightChild = theNode;
					break;
				}
			}
		}

		aTree->count++;
	}
}

DoubleNode* findNodeWithDOUBLEValue(DoubleTree* aTree, double aValue)
{
	DoubleNode* theCurrentNode = NULL;

	if (NULL != aTree && NULL != aTree->root)
	{
		theCurrentNode = aTree->root;
		while (aValue != theCurrentNode->value)
		{
			theCurrentNode = (aValue < theCurrentNode->value)
				? theCurrentNode->leftChild
				: theCurrentNode->rightChild;

			if (NULL == theCurrentNode)
			{
				printf("Node don't find");
				break;
			}
		}
	}

	return theCurrentNode;
}

void deleteNodeWithValue(DoubleTree* aTree, double aValue) {


	if (NULL == aTree || NULL == aTree->root) {  //	ПЕРЕВІРЯЄМО ВХІДНІ ДАННІ
		return;
	}

	DoubleNode* theCurrent = aTree->root;
	DoubleNode* theParent = aTree->root;


	while (aValue != theCurrent->value) {        // ЗНАХОДИМО НОДУ , ЯКУ ПОТРІБНО ВІДШУКАТИ , ЯКЩО НЕ ЗНАЙШЛИ ТО ВИДАЛЯЄМО 
		theParent = theCurrent;
		if (aValue < theCurrent->value) {
			theCurrent = theCurrent->leftChild;
		}
		else {
			theCurrent = theCurrent->rightChild;
		}

		if (NULL == theCurrent)
		{
			return;
		}
	}


	if (NULL == theCurrent->leftChild && NULL == theCurrent->rightChild) {     // ВИПАДОК КОЛИ НОДА ЛИСТОВА  , І ЇЇ МОЖНА ВИДАЛИТИ 
		if (aTree->root == theCurrent) {
			aTree->root = NULL;
		}
		else if (theParent->leftChild == theCurrent) {
			theParent->leftChild = NULL;
		}
		else {
			theParent->rightChild = NULL;
		}

		aTree->count--;
	}

	else if (NULL == theCurrent->rightChild)
	{
		if (aTree->root == theCurrent) {
			aTree->root = theCurrent->leftChild;
		}
		else if (theParent->leftChild == theCurrent) {
			theParent->leftChild = theCurrent->leftChild;
		}
		else {
			theParent->rightChild = theCurrent->rightChild;
		}
	}

	else if (NULL == theCurrent->leftChild)
	{  // ВИПАДОК КОЛИ ІСНУЄ ТІЛЬКИ ПРАВИЙ НАЩАДОК , І ВІН ПРИЄДНУЄТЬСЯ  ДО     PERENT-A

		if (aTree->root == theCurrent)
		{
			aTree->root = theCurrent->rightChild;
		}
		else if (theParent->rightChild == theCurrent)
		{
			theParent->rightChild = theCurrent->rightChild;
		}
		else
		{
			theParent->leftChild = theCurrent->leftChild;
		}
		aTree->count--;
	}

	else
	{
		DoubleNode* successor = getSuccessor(aTree, theCurrent);  //ВИПАДОК КОЛИ ІСНУЮТЬ ОБИДВІ НАЩАДКИ , ПОТІМ ПЕРЕВІРК АТОГО ЩО БАТЬКО = ROOT (ТАКОГО БУТИ НЕ МОЖЕ )
		if (aTree->root == successor) {
			aTree->root = NULL;
		}
		else if (theParent->leftChild == theCurrent) {  //ЯКЩО ЦЕ ЛІВИЙ НАЩАДОК , ТО ПІДКЛУЧАЄТЬСЯ САКСЕСОР
			theParent->leftChild = successor;
		}
		else if (theParent->rightChild == theCurrent)
		{
			theParent->rightChild = successor;
		}
		else
		{
			aTree->root = successor;
			theCurrent->leftChild = NULL;
			theCurrent->rightChild = NULL;
			aTree->count--;
		}

	}
	deleteNode(theCurrent);
}

void printTree(DoubleTree* aTree) 
{
	printf("Initial list\n");
	DoubleNode* item = aTree->root;
	show_bouble_value(item);

}




void show_bouble_value(DoubleNode* node) {
	if (node == NULL)
		return;
	printf("Number: %f\n", node->value);
	show_bouble_value(node->leftChild);
	show_bouble_value(node->rightChild);
}



void deleteNode(DoubleNode* aNode)
{
	if (NULL != aNode)
	{
		deleteNode(aNode->leftChild);
		deleteNode(aNode->rightChild);

		free(aNode);
	}
}

DoubleNode* createDoubleNodeWithDOUBLEValue(double aValue)
{
	DoubleNode* theNode = (DoubleNode*)malloc(sizeof(DoubleNode));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

DoubleNode* getSuccessor(DoubleTree* Atree, DoubleNode* aDelNode) {
	DoubleNode* TheSuccessParent = aDelNode;
	DoubleNode* successor = aDelNode;
	DoubleNode* TheCurrent = aDelNode->rightChild;

	while (NULL != TheCurrent) {
		TheSuccessParent = successor;
		successor = TheCurrent;
		TheCurrent = TheCurrent->leftChild;
	}

	if (successor != aDelNode->rightChild) {
		TheSuccessParent->leftChild = successor->rightChild;
		successor->rightChild = aDelNode->rightChild;
	}



	return successor;
}
