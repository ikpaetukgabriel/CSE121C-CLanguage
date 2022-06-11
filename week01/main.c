#include <stdio.h>
#include <string.h>

int main() {
    char characterSample = 'G';
    short shortSample = 4;
    int integerSample = 2000;
    long longSample = 123498765;

    printf("Size of char: %zu, Value: %c bytes\n", sizeof(characterSample), characterSample);
    printf("Size of : %zu, Value: %hi bytes\n", sizeof(shortSample), shortSample);
    printf("Size int: %zu, Value: %d bytes\n", sizeof(integerSample), integerSample);
    printf("Size long: %zu, Value: %ld bytes\n", sizeof(longSample), longSample);

    float sampleFloat;
    printf("Enter a floating point number: ");
    scanf("%f", &sampleFloat);

    //    show as scientific notation
    printf("You entered -> %e\n", sampleFloat);
    //    show as fixed point
    printf("You entered -> %f\n", sampleFloat);
    //    show as shortest representation
    printf("You entered -> %g\n", sampleFloat);

    struct account {
        char name[20];
        int accountNumber;
        double accountBalance;
    };

    struct account checking;

    //    To copy the content into the array, you need to use strcpy() from string.h
    strcpy(checking.name, "Adam Young");
    checking.accountNumber = 123456;
    checking.accountBalance = 1234.56;

    printf("Account name: %s, size: %zu\n", checking.name, sizeof(checking.name));
    printf("Account number : %d, size: %zu\n", checking.accountNumber, sizeof(checking.accountNumber));
    printf("Account balance: %lg, size: %zu\n", checking.accountBalance, sizeof(checking.accountBalance));

    printf("Total size of the structure: %zu\n", sizeof(checking));

    return 0;
}