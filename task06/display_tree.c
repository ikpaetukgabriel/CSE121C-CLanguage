//
// Created by Gabriel Ikpaetuk on 7/18/22.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "person_utilities.h"
#include "display_tree.h"


/**
 * Helper function to print branches of the binary tree
 * @param ptr_trunk
 */
void showTrunks(struct Trunk *ptr_trunk)
{
    if (ptr_trunk == NULL) {
        return;
    }

    showTrunks(ptr_trunk->prev);
    printf("%s", ptr_trunk->str);
}

/**
 * prints Family Tree, treats it like a binary tree
 * @param ptr_person
 * @param prev
 * @param isLeft
 */
void printTree(struct person* ptr_person, struct Trunk *prev, bool isLeft)
{
    if (ptr_person == NULL) {
        return;
    }

    char prev_str[] = "          ";
    struct Trunk *trunk = malloc(sizeof(struct Trunk));
    trunk->prev = prev;
    strcpy(trunk->str, prev_str);

    printTree(ptr_person->father, trunk, true);

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
    printf("*%s, %c.\n", ptr_person->last_name, ptr_person->first_name[0]);

    if (prev) {
        strcpy(prev->str, prev_str);
    }
    strcpy(trunk->str, "         |");

    printTree(ptr_person->mother, trunk, false);
}