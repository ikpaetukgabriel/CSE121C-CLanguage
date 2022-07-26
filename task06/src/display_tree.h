//
// Created by Gabriel Ikpaetuk on 7/18/22.
//

#ifndef TASK06_DISPLAY_TREE_H
#define TASK06_DISPLAY_TREE_H

struct Trunk {
    char str[40];
    struct Trunk *prev;
};
void showTrunks(struct Trunk *ptr_trunk);
void printTree(struct person* ptr_person, struct Trunk *prev, bool isLeft);
#endif //TASK06_DISPLAY_TREE_H
