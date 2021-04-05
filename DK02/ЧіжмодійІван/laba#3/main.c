#include <stdio.h>
#include "tree.h"

int main() {
    intTree* new_tree = createIntTree();

    insertIntValueToTree(new_tree, 15);
    insertIntValueToTree(new_tree, 2);
    insertIntValueToTree(new_tree, 89);
    insertIntValueToTree(new_tree, 56);
    insertIntValueToTree(new_tree, 13);
    insertIntValueToTree(new_tree, 8);
    insertIntValueToTree(new_tree, 43);
    insertIntValueToTree(new_tree, 3);

    printTree(new_tree->root);
    printf("\n");

    printf("Find node : %d\n", findValueInTree(new_tree, 89)->value);

    deleteValueFromTree(new_tree, 3);
    deleteValueFromTree(new_tree, 13);
    deleteValueFromTree(new_tree, 1);

    printTree(new_tree->root);
    printf("\n");

    deleteIntTree(new_tree);
