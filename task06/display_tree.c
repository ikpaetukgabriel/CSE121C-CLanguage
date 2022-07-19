//
// Created by Gabriel Ikpaetuk on 7/18/22.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "person_utilities.h"
#include "display_tree.h"


// Helper function to print branches of the binary tree
void showTrunks(struct Trunk *p)
{
    if (p == NULL) {
        return;
    }

    showTrunks(p->prev);
    printf("%s",p->str);
}

void printTree(struct person* root, struct Trunk *prev, bool isLeft)
{
    if (root == NULL) {
        return;
    }

    char prev_str[] = "          ";
    struct Trunk *trunk = malloc(sizeof(struct Trunk));
    trunk->prev = prev;
    strcpy(trunk->str, prev_str);

    printTree(root->father, trunk, true);

    if (!prev) {
        strcpy(trunk->str, "—————————");
    }
    else if (isLeft)
    {
        strcpy(trunk->str, ".—————————");
        strcpy(prev_str,"         |");
    }
    else {
        strcpy(trunk->str, "`—————————");
        stpcpy(prev->str, prev_str);
    }

    showTrunks(trunk);
    printf("*%s, %c.\n", root->last_name, root->first_name[0]);

    if (prev) {
        strcpy(prev->str, prev_str);
    }
    strcpy(trunk->str, "         |");

    printTree(root->mother, trunk, false);
}