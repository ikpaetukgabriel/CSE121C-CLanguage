//
// Created by Gabriel Ikpaetuk on 7/18/22.
//
#include "unique_person_id.h"

int current_id = 1000;
int *ptr_current_id = &current_id;
int generate_unique_person_id() {
    int id = *ptr_current_id;
    return id;
}