#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct account {
    int account_number;
    char name[20];
    float account_balance;
    struct account *ptr_acc;
};

struct account *allocate_space_for_new_account();

void populate_account_info(struct account *struct_account, bool is_a_new_account);

void display_account_info(struct account *ptr_struct_account);

void display_all_account_info(struct account *ptr_struct_account_head);

struct account *find_account_by_account_number(struct account *ptr_struct_account_head);

struct account *add_a_new_account(struct account *ptr_struct_account_head);

void update_an_existing_account(struct account *ptr_struct_account_head);

int display_menu();

int main() {
    int menu_choice;
    struct account *ptr_head = NULL;

    do {
        menu_choice = display_menu();
        printf("\n");
        // Quits the menu
        if (menu_choice == 0) {
            printf("Bye\n");
            break;
        }
        // Displays all the account details
        if (menu_choice == 2) {
            display_all_account_info(ptr_head);
            continue;
        }
        // Finds account by account number and displays it
        if (menu_choice == 3) {
            struct account *search_result = find_account_by_account_number(ptr_head);
            search_result == NULL ? printf("Account not found.\n") : display_account_info(search_result);
            printf("\n");
            continue;
        }
        // Finds account by account number and update it
        if (menu_choice == 4) {
            update_an_existing_account(ptr_head);
            printf("\n");
            continue;
        }

        ptr_head = add_a_new_account(ptr_head);
        printf("\n");
    } while (true);



//    free up the memory used by the record.
//    free(ptr_first_account);

    return 0;
}

void populate_account_info(struct account *struct_account, bool is_a_new_account) {
    if (is_a_new_account) {
        struct_account->ptr_acc = NULL;
    }
    printf("Enter the account number: ");
    scanf("%d", &struct_account->account_number);

    printf("Enter the name of the account: ");
    scanf("%s", struct_account->name);

    printf("Enter the balance in the account: ");
    scanf("%f", &struct_account->account_balance);
}

void display_account_info(struct account *ptr_struct_account) {
    printf("Account information->\n");
    printf("number: %d\n", ptr_struct_account->account_number);
    printf("name: %s\n", ptr_struct_account->name);
    printf("balance: $%lg\n", ptr_struct_account->account_balance);
}

int display_menu() {
    int menu_choice;
    printf("  1. Add account\n"
           "  2. Display all accounts\n"
           "  3. Find account\n"
           "  4. Change account\n"
           "  0. Quit program\n");
    printf("Your choice: ");
    scanf("%d", &menu_choice);
    return menu_choice;
}

struct account *allocate_space_for_new_account() {
    // Dynamically allocate memory using malloc to be used to store one bank account record
    return malloc(sizeof(struct account));
}

struct account *find_account_by_account_number(struct account *ptr_struct_account_head) {
    int account_number;
    printf("Enter the account number to find: ");
    scanf("%d", &account_number);

    struct account *current_account = ptr_struct_account_head;
    while (current_account != NULL) {
        if (current_account->account_number == account_number) {
            return current_account;
        }
        current_account = current_account->ptr_acc;
    }
    return NULL;
}

void display_all_account_info(struct account *ptr_struct_account_head) {
    struct account *current_account = ptr_struct_account_head;
    while (current_account != NULL) {
        display_account_info(current_account);
        printf("\n");
        current_account = current_account->ptr_acc;
    }
}

struct account *add_a_new_account(struct account *ptr_struct_account_head) {
    if (ptr_struct_account_head == NULL) {
        ptr_struct_account_head = allocate_space_for_new_account();
        populate_account_info(ptr_struct_account_head, true);
        return ptr_struct_account_head;
    }

    struct account *ptr_new_account = allocate_space_for_new_account();
    populate_account_info(ptr_new_account, true);

    struct account *current_account = ptr_struct_account_head;
    while (current_account->ptr_acc) {
        current_account = current_account->ptr_acc;
    }
    current_account->ptr_acc = ptr_new_account;
    return ptr_struct_account_head;
}

void update_an_existing_account(struct account *ptr_struct_account_head) {
    struct account *search_result = find_account_by_account_number(ptr_struct_account_head);
    if (search_result == NULL) {
        printf("Account not found.\n");
        return;
    }
    display_account_info(search_result);
    printf("\n");
    printf("Now enter the new account information.\n");
    populate_account_info(search_result, false);
}