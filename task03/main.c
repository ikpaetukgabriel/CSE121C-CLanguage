#include <stdio.h>
#include <stdbool.h>

void display_binary(unsigned int num);

void bitwise_factory(unsigned int first_operand, unsigned int second_operand);

int main() {
    char letter[5];
    printf("Enter a string (without space): ");
    scanf("%s", letter);

    int i = 0;
    while (letter[i] != '\0') {
        printf("%X\n", letter[i]);
        i++;
    }
    unsigned int number_to_convert;
    printf("Enter a number to convert to binary: ");
    scanf("%u", &number_to_convert);
    display_binary(number_to_convert);
    printf("\n");

    unsigned int first_operand;
    unsigned int second_operand;
    printf("For bitwise operation\n");
    printf("Enter first operand(number): ");
    scanf("%u", &first_operand);
    printf("Enter second operand(number): ");
    scanf("%u", &second_operand);
    printf("********* Bitwise Results *********\n");
    bitwise_factory(first_operand, second_operand);
    return 0;
}

void display_binary(unsigned int num) {
    unsigned int tester;
    bool sean_a_one = false; // To avoid printing leading zeros
    for (unsigned int shift_position = 31; shift_position < -1; shift_position--) {
        // To check the value of a current bit, you bitwise and it with the bit 1
        // Repeat the same process for each bit in the 31 to 0 position,
        tester = num & (1 << shift_position);
        // continue to the next iteration if
        // it is not a one
        // and the current position is not a zero
        // and a 1 has not been seen
        if ((tester == 0) && (shift_position != 0) && (!sean_a_one)) {
            continue;
        }
        if (tester > 0) {
            printf("1");
            sean_a_one = true; // Zeros after this can now be printed
        } else {
            printf("0");
        }
    }
}

void bitwise_factory(unsigned int first_operand, unsigned int second_operand) {
    printf("First operand: %u\n", first_operand);
    display_binary(first_operand);
    printf("\n");
    printf("Second operand: %u\n", second_operand);
    display_binary(second_operand);
    printf("\n");

    unsigned int bitwise_and_result = first_operand & second_operand;
    printf("Result of %d & %d: ", first_operand, second_operand);
    display_binary(bitwise_and_result);
    printf("\n");

    unsigned int bitwise_or_result = first_operand | second_operand;
    printf("Result of %d | %d: ", first_operand, second_operand);
    display_binary(bitwise_or_result);
    printf("\n");

    unsigned int not_first_operand = ~first_operand;
    printf("Result of ~%d: ", first_operand);
    display_binary(not_first_operand);
    printf("\n");

    unsigned int not_second_operand = ~second_operand;
    printf("Result of ~%d: ", second_operand);
    display_binary(not_second_operand);
    printf("\n");
}