//
// Created by Gabriel Ikpaetuk on 7/18/22.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "person_utilities.h"
#include "unique_person_id.h"

const char *get_gender_string(int enumVal) {
    if (enumVal == 0) return "Male";
    else return "Female";
}

enum gender get_gender_enum(char *str_gender) {
    if (strcmp("Male", str_gender) == 0) {
        return Male;
    }
    return Female;
}

int getUserInterfaceChoice() {
    int interface_choice;
    printf("---------------------------------------------\n");
    printf("  1. Add Root User\n"
           "  2. Display Root User Info\n"
           "  3. Edit Root User Information\n"
           "  4. Add Relatives\n"
           "  5. Display Relatives\n"
           "  6. Find Relative by Firstname and Lastname\n"
           "  7. Find Relative by Person ID\n"
           "  8. Edit Relative Information\n"
           "  9. See Number of relative added\n"
           "  0. Quit program\n");
    printf("---------------------------------------------\n");
    printf("Your choice: ");
    scanf("%d", &interface_choice);
    printf("\n");
    return interface_choice;
}


struct person *allocate_space_for_new_person() {
    return malloc(sizeof(struct person));
}

struct person *add_root_user(struct person *ptr_person_root_user) {
    if (ptr_person_root_user != NULL) {
        printf("Root user already exists!");
        return ptr_person_root_user;
    }
    ptr_person_root_user = allocate_space_for_new_person();
    populate_person_info(ptr_person_root_user, true);
    return ptr_person_root_user;
}

struct person *edit_root_user_info(struct person *ptr_person_root_user) {
    if (ptr_person_root_user == NULL) {
        printf("No root user found, add root user!\n");
        return ptr_person_root_user;
    }
    printf("Most current info: \n");
    display_person_info(ptr_person_root_user);
    printf("\n");
    printf("Edit info below: \n");
    populate_person_info(ptr_person_root_user, false);
    printf("***Successfully updated!*** \n");
    return ptr_person_root_user;
}

void populate_person_info(struct person *ptr_struct_person, bool is_a_new_person) {
    if (is_a_new_person) {
        ptr_struct_person->mother = NULL;
        ptr_struct_person->father = NULL;
        ptr_struct_person->spouse = NULL;
        // Might be a good idea, to free up the pointer space, not done though
        strcpy(ptr_struct_person->person_id, generate_unique_person_id());
    }

    printf("Enter the first name of the person: ");
    scanf("%s", ptr_struct_person->first_name);

    printf("Enter the last name of the person: ");
    scanf("%s", ptr_struct_person->last_name);

    char gender[7];
    do {
        printf("Enter the gender of the person: ");
        scanf("%s", gender);
        if (strcmp("Male", gender) == 0 || strcmp("Female", gender) == 0) break;
        printf("       Wrong input, enter 'Male' or 'Female' \n");
    } while (true);

    get_gender_enum(gender);
    ptr_struct_person->gender = get_gender_enum(gender);
}

void display_person_info(struct person *ptr_struct_person) {
    if (ptr_struct_person == NULL) {
        printf("Person not found!\n");
        return;
    }
    printf("Person information->\n");
    printf("Person ID: %s\n", ptr_struct_person->person_id);
    printf("Firstname: %s\n", ptr_struct_person->first_name);
    printf("Lastname: %s\n", ptr_struct_person->last_name);
    printf("Gender: %s\n", get_gender_string(ptr_struct_person->gender));
}

bool add_more_relatives(struct person *ptr_person) {
    int choice;
    do {
        printf("Do you want to add %s, %s relatives?\n", ptr_person->first_name, ptr_person->last_name);
        printf("Enter\n"
               "1 for yes\n"
               "2 for No\n"
               ": ");
        scanf("%d", &choice);
        printf("\n");
        if (choice == 1) return true;
        if (choice == 2) return false;

        printf("Wrong input, enter 1 or 2\n");
    } while (true);
}

struct person *add_relatives(struct person *ptr_person, int *ptr_num_of_relatives, const int ALLOWED_NUM_RELATIVES) {
    if (ptr_person == NULL) {
        printf("No root user found, add root user \n");
        return ptr_person;
    }

    if (*ptr_num_of_relatives > ALLOWED_NUM_RELATIVES) {
        printf("Number of Relatives exceeded \n");
        return ptr_person;
    }

    // Since both have to be added then, this works great!
    // There should not exist a person with NULL mother and NOT NULL father, based on the design,
    // If it ever happens, then the program will treat it like both are NULLs
    if (ptr_person->mother != NULL && ptr_person->father != NULL) {
        if (add_more_relatives(ptr_person->mother)) {
            add_relatives(ptr_person->mother, ptr_num_of_relatives, ALLOWED_NUM_RELATIVES);
        }
        if (add_more_relatives(ptr_person->father)) {
            add_relatives(ptr_person->father, ptr_num_of_relatives, ALLOWED_NUM_RELATIVES);
        }
        return ptr_person;
    }

    //   Mother
    struct person *mother = allocate_space_for_new_person();
    printf("Add %s, %s's Mother\n", ptr_person->last_name, ptr_person->first_name);
    populate_person_info(mother, true);
    printf("\n");
    ptr_person->mother = mother;
    (*ptr_num_of_relatives)++; // The value pointed at by ptr is incremented

    //   Father
    struct person *father = allocate_space_for_new_person();
    printf("Add %s, %s's Father\n", ptr_person->last_name, ptr_person->first_name);
    populate_person_info(father, true);
    printf("\n");
    ptr_person->father = father;
    (*ptr_num_of_relatives)++; // The value pointed at by ptr is incremented

    if (add_more_relatives(mother)) {
        add_relatives(mother, ptr_num_of_relatives, ALLOWED_NUM_RELATIVES);
    }
    if (add_more_relatives(father)) {
        add_relatives(father, ptr_num_of_relatives, ALLOWED_NUM_RELATIVES);
    }

    return ptr_person;
}

