#pragma once
#ifndef tree_h
#define tree_h

#include <stdio.h>

typedef struct tagNode
{
	double value;
	struct tagNode* leftChild;
	struct tagNode* rightChild;
} DoubleNode;

typedef struct tagTree
{
	DoubleNode* root;
	int count;
} DoubleTree;

DoubleTree* createDoubleTree(void);
void DeleteTree(DoubleTree* aTree);
void includeNewItemToTree(DoubleTree* aTree, double aValue);
DoubleNode* findNodeWithDOUBLEValue(DoubleTree* aTree, double aValue);
void deleteNodeWithValue(DoubleTree* aTree, double aValue);
void printTree(DoubleTree* aTree);


#endif
