#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "person_utilities.h"

int main() {
    int interface_choice;
    struct person *root_person = NULL;

    do {
        interface_choice = getUserInterfaceChoice();
        if (interface_choice == 1) {
            root_person = add_root_user(root_person);
            printf("\n");
            continue;
        }

        if (interface_choice == 2) {
            display_person_info(root_person);
            continue;
        }

        if (interface_choice == 3) {
            root_person = edit_root_user_info(root_person);
            continue;
        }

        if (interface_choice == 4) {
            continue;
        }

        if (interface_choice == 5) {
            continue;
        }

        if (interface_choice == 6) {
            continue;
        }

        if (interface_choice == 7) {
            continue;
        }

        if (interface_choice == 8) {
            continue;
        }

        printf("Bye, thanks for using the family tree Application!\n");
        break;

    } while (true);
    return 0;
}


