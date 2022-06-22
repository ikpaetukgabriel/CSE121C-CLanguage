#include <stdio.h>
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
    return 0;
}
