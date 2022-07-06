#include <stdio.h>

int find_minimum(int *ptr_a, int *ptr_b);

int main() {
    int first_num = 0;
    int second_number = 0;
    printf("Before function call: first number is %d and second number is %d\n", first_num, second_number);
    printf("The minimum value is %d\n", find_minimum(&first_num, &second_number));
    printf("After function call: first number is %d and second number is %d\n", first_num, second_number);
    return 0;
}

int find_minimum(int *ptr_a, int *ptr_b) {
    printf("Enter the value of the first number: ");
    scanf("%d", ptr_a);

    printf("Enter the value of the second number: ");
    scanf("%d", ptr_b);

    if (*ptr_b < *ptr_a) return *ptr_b;
    return *ptr_a;
}
