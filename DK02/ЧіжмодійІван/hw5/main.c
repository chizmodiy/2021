#include <stdio.h>
#include "doubleTree.h"

int main() {

	DoubleNode* tree = createDoubleTree();

	includeNewItemToTree(tree, 1);
	includeNewItemToTree(tree, 3.342);
	includeNewItemToTree(tree, 1.78);
	includeNewItemToTree(tree, 2.71);
	includeNewItemToTree(tree, 3.243);
	includeNewItemToTree(tree, 0.86);
	includeNewItemToTree(tree, 0.8);
	includeNewItemToTree(tree, 0.24);
	includeNewItemToTree(tree, 0.3);
	printf("\n");
	printTree(tree);
	deleteNodeWithValue(tree, 3,243);
	printf("\n");
	printTree(tree);

	DeleteTree(tree);

	return 0;
}
