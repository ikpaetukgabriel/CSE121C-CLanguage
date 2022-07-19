#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "person_utilities.h"

int main() {
    int interface_choice;
    struct person *root_person = NULL;

    const int ALLOWED_NUMBER_OF_RELATIVES = 6;
    int num_of_relatives = 0;
    int *ptr_num_of_relatives = &num_of_relatives;

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
            root_person = add_relatives(root_person, ptr_num_of_relatives, ALLOWED_NUMBER_OF_RELATIVES);
            continue;
        }

        if (interface_choice == 5) {
            display_family_tree(root_person);
            continue;
        }

        if (interface_choice == 6) {
            find_relative(root_person);
            printf("\n");
            continue;
        }

        if (interface_choice == 7) {
            printf("Number of relatives added: %d\n", *ptr_num_of_relatives);
            printf("Space for Number of relatives left: %d\n", ALLOWED_NUMBER_OF_RELATIVES - (*ptr_num_of_relatives));
            continue;
        }

        printf("Bye, thanks for using the family tree Application!\n");
        break;

    } while (true);
    return 0;
}


