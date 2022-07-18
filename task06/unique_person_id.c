//
// Created by Gabriel Ikpaetuk on 7/18/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <uuid/uuid.h>
#include "unique_person_id.h"

char *generate_unique_person_id() {
    //    Generate a UUID in binary format, so it has to be unparsed
    uuid_t binary_uuid;
    //    uuid_unparse() doesn't allocate memory for itself, so
    //    malloc(). 37 is the length of a UUID (36 characters), plus '\0'.
    uuid_generate_random(binary_uuid);

    //    Produces a UUID string at uuid consisting of capital letters.
    char *unparsed_uuid = malloc(37);
    uuid_unparse_upper(binary_uuid, unparsed_uuid);
    printf("%s\n", unparsed_uuid);

    return unparsed_uuid;
}