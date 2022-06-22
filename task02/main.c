#include <stdio.h>

int main() {
    //    Question one
    int firstNumber;
    int secondNumber;

    printf("Input first number: ");
    scanf("%d", &firstNumber);

    printf("Input second number: ");
    scanf("%d", &secondNumber);

    if (firstNumber > secondNumber) {
        printf("Maximum: %d, Minimum: %d \n", firstNumber, secondNumber);
    } else if (firstNumber < secondNumber) {
        printf("Maximum: %d, Minimum: %d \n", secondNumber, firstNumber);
    } else {
        printf("The two numbers are equal \n");
    }

    printf("\n");
    //    Question Two
    int itemNumber;
    printf("**********************\n");
    printf("    Menu (Item ID)     \n");
    printf("**********************\n");
    printf("Enter 1 for:  Bread\n");
    printf("Enter 2 for:  Milk\n");
    printf("Enter 3 for:  Cheese\n");
    printf("Enter 4 for:  Candy\n");
    printf("Enter 5 for:  Toy\n");
    printf("**********************\n");

    printf("Enter item ID: ");
    scanf("%d", &itemNumber);

    printf("You choose to buy -> ");
    switch (itemNumber) {
        case 1:
            printf("bread\n");
            break;

        case 2:
            printf("milk\n");
            break;

        case 3:
            printf("cheese\n");
            break;

        case 4:
            printf("candy\n");
            break;

        case 5:
            printf("toy\n");
            break;

            // operator doesn't match any case constant +, -, *, /
        default:
            printf("an item with an id : %d that does not exist in the system.\n", itemNumber);
    }

    printf("\n");
    // Question Three
    int day;
    int age;
    printf("************************\n");
    printf("        Weekdays        \n");
    printf("************************\n");
    printf("Enter 1 for:  Sunday\n");
    printf("Enter 2 for:  Monday\n");
    printf("Enter 3 for:  Tuesday\n");
    printf("Enter 4 for:  Wednesday\n");
    printf("Enter 5 for:  Thursday\n");
    printf("Enter 6 for:  Friday\n");
    printf("Enter 7 for:  Saturday\n");
    printf("************************\n");
    printf("Enter a number representing the day of the week: ");
    scanf("%d", &day);
    printf("Enter child's age: ");
    scanf("%d", &age);

    // Sunday to Thursday
    if (day >= 1 && day <= 5) {
        if (age >= 0 && age <= 5) {
            printf("Child bedtime: 7pm");
        } else if (age >= 6 && age <= 10) {
            printf("Child bedtime: 8pm");
        } else if (age >= 11 && age <= 17) {
            printf("Child bedtime: 9pm");
        } else {
            printf("Age out of range");
        }
    }
        // Friday
    else if (day == 6) {
        if (age >= 0 && age <= 5) {
            printf("child bedtime: 7pm");
        } else if (age >= 6 && age <= 10) {
            printf("child bedtime: 9pm");
        } else if (age >= 11 && age <= 17) {
            printf("child bedtime: 12am");
        } else {
            printf("Age out of range");
        }
    }
        // Saturday
    else if (day == 7) {
        if (age >= 0 && age <= 5) {
            printf("child bedtime: 7pm");
        } else if (age >= 6 && age <= 10) {
            printf("child bedtime: 9pm");
        } else if (age >= 11 && age <= 17) {
            printf("child bedtime: 11pm");
        } else {
            printf("Age out of range");
        }
    }
    // Out of day range
    else {
        printf("You entered a day that does not exist");
    }
    return 0;
}
