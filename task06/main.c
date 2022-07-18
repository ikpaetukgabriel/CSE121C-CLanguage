#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <uuid/uuid.h>

enum gender {
    Male, Female
};

struct person {
    char person_id[37];
    char first_name[20];
    char last_name[20];
    enum gender gender;
    struct person *mother;
    struct person *father;
    struct person *spouse;
};

const char *get_gender_string(int enumVal);

enum gender get_gender_enum(char *str_gender);

int getUserInterfaceChoice();

struct person *allocate_space_for_new_person();

void populate_person_info(struct person *ptr_struct_person, bool is_a_new_person);

char *generate_unique_person_id();

struct person *add_root_user(struct person *ptr_person_root_user);

void display_person_info(struct person *ptr_struct_person);


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
        if(strcmp("Male", gender) == 0 || strcmp("Female", gender) == 0) break;
        printf("       Wrong input, enter 'Male' or 'Female' \n");
    } while (true);

    get_gender_enum(gender);
    ptr_struct_person->gender = get_gender_enum(gender);
}

void display_person_info(struct person *ptr_struct_person) {
    printf("Person information->\n");
    printf("Person ID: %s\n", ptr_struct_person->person_id);
    printf("Firstname: %s\n", ptr_struct_person->first_name);
    printf("Lastname: %s\n", ptr_struct_person->last_name);
    printf("Gender: %s\n", get_gender_string(ptr_struct_person->gender));
}

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