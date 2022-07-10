#include <stdio.h>
#include <stdlib.h>

struct account {
    int account_number;
    char name[20];
    float account_balance;
    struct account *ptr_acc;
};

void get_account_info(struct account *ptr_struct_account);

void display_account_info(struct account *ptr_struct_account);

int main() {
//    Dynamically allocate memory using malloc to be used to store one bank account record
    struct account *ptr_first_account = malloc(sizeof(struct account));
    get_account_info(ptr_first_account);
    display_account_info(ptr_first_account);

//    free up the memory used by the record.
    free(ptr_first_account);

    return 0;
}

void get_account_info(struct account *struct_account) {
    printf("Enter the account number: ");
    scanf("%d", &struct_account->account_number);

    printf("Enter the name of the account: ");
    scanf("%s", struct_account->name);

    printf("Enter the balance in the account: ");
    scanf("%f", &struct_account->account_balance);
}

void display_account_info(struct account *ptr_struct_account) {
    printf("Account information:\n");
    printf("number %d\n", ptr_struct_account->account_number);
    printf("name %s\n", ptr_struct_account->name);
    printf("balance $%lg\n", ptr_struct_account->account_balance);
}