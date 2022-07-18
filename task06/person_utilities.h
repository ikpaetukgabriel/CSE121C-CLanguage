//
// Created by Gabriel Ikpaetuk on 7/18/22.
//

#ifndef TASK06_PERSON_UTILITIES_H
#define TASK06_PERSON_UTILITIES_H

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

struct person *add_root_user(struct person *ptr_person_root_user);

void display_person_info(struct person *ptr_struct_person);

struct person *edit_root_user_info(struct person *ptr_person_root_user);
#endif //TASK06_PERSON_UTILITIES_H
