#include <stdio.h>
#include <stdlib.h>

int find_minimum(int *ptr_a, int *ptr_b);

struct account
{
    int account_number;
    char name[20];
    float account_balance;
    struct account *ptr_acc; // not used in this task, used in task05
};

void get_account_info(struct account *ptr_struct_account);

void display_account_info(struct account *ptr_struct_account);

int main()
{
    int first_num = 0;
    int second_number = 0;
    printf("Before function call: first number is %d and second number is %d\n", first_num, second_number);
    printf("The minimum value is %d\n", find_minimum(&first_num, &second_number));
    printf("After function call: first number is %d and second number is %d\n\n", first_num, second_number);

    //    Dynamically allocate memory using malloc to be used to store one bank account record
    struct account *ptr_first_account = malloc(sizeof(struct account));
    get_account_info(ptr_first_account);
    display_account_info(ptr_first_account);

    //    free up the memory used by the record.
    free(ptr_first_account);

    return 0;
}

int find_minimum(int *ptr_a, int *ptr_b)
{
    printf("Enter the value of the first number: ");
    scanf("%d", ptr_a);

    printf("Enter the value of the second number: ");
    scanf("%d", ptr_b);

    if (*ptr_b < *ptr_a)
        return *ptr_b;
    return *ptr_a;
}

void get_account_info(struct account *struct_account)
{
    printf("Enter the account number: ");
    scanf("%d", &struct_account->account_number);

    printf("Enter the name of the account: ");
    scanf("%s", struct_account->name);

    printf("Enter the balance in the account: ");
    scanf("%f", &struct_account->account_balance);
}

void display_account_info(struct account *ptr_struct_account)
{
    printf("Account information:\n");
    printf("number %d\n", ptr_struct_account->account_number);
    printf("name %s\n", ptr_struct_account->name);
    printf("balance $%lg\n", ptr_struct_account->account_balance);
}