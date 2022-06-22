#include <stdio.h>

void display_binary(unsigned int num);

int main()
{
    char letter[5];
    printf("Enter a string: ");
    scanf("%s", letter);

    int i = 0;
    while (letter[i] != '\0')
    {
        printf("%X\n", letter[i]);
        i++;
    }
    unsigned int numberToConvert;
    printf("Enter a number to convert to binary: ");
    scanf("%u", numberToConvert);
    display_binary(numberToConvert);
    return 0;
}

void display_binary(unsigned int num)
{
    printf("%u\n", num);
};
