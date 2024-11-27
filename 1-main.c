#include <stdio.h>
#include "main.h"

int main(void)
{
    int count;
    int aaah = -2147483645;

    // Test avec une chaîne de format NULL
    _printf("allo %d\n", aaah);
    count = _printf(NULL);
    printf("Count (NULL format): %d\n", count);

    // Test avec un spécificateur de format non reconnu
    count = _printf("Hello %k World!\n");
    printf("Count (unrecognized specifier): %d\n", count);

    // Test avec un spécificateur sans argument correspondant
    count = _printf("Number: %d\n");
    printf("Count (missing argument for specifier): %d\n", count);

    // Test avec un argument supplémentaire non utilisé
    count = _printf("Hello World!\n", 42);
    printf("Count (extra argument): %d\n", count);

    // Test avec un caractère d'échappement pourcentage sans spécificateur
    count = _printf("Just a percent sign: %%\n");
    printf("Count (percent sign): %d\n", count);

    // Test avec des arguments corrects
    count = _printf("Character: %c, String: %s, Integer: %d\n", 'A', "Test", 123);
    printf("Count (correct usage): %d\n", count);

    count = _printf("Numbers: %d, %d, %d\n", 42, 13, 7);
    printf("Count (multiple integers): %d\n", count);

    count = _printf("Characters: %c, %c, %c\n", 'A', 'B', 'C');
    printf("Count (multiple characters): %d\n", count);

    count = _printf("Mixed: %c and %d are great!\n", 'X', 99);
    printf("Count (mixed): %d\n", count);

    count = _printf("Results: %d points for player %c and bonus: %d%%!\n", 150, 'A', 10);
    printf("Count (complex format): %d\n", count);

    return 0;
}