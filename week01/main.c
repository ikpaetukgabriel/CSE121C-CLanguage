#include <stdio.h>

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
    printf("You entered -> %e\n", sampleFloat);
    return 0;
}