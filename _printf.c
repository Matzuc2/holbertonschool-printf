#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 *
 * Return: number of characters printed (excluding the null byte used to end
 * output to strings)
 */
int _printf(const char *format, ...)
{
    va_list args;
    which_s which[] = {{"d", print_int}, {"c", print_char}, {"i", print_int},
                       {"s", print_string}, {"%", is_percent}, {NULL, NULL}};
    unsigned int i = 0, j = 0, count = 0;

    if (format == NULL)
        return (-1); // Vérifie si format est NULL

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%') // Détecte un spécificateur
        {
            if (format[i + 1] == '\0') // Si % est le dernier caractère
            {
                va_end(args);
                return (-1); // Retourne une erreur
            }

            for (j = 0; which[j].w != NULL; j++)
            {
                if (format[i + 1] == *(which[j].w)) // Spécificateur trouvé
                {
                    count += which[j].f(args);
                    i++; // Ignore le caractère suivant '%'
                    break;
                }
            }

            if (which[j].w == NULL) // Aucun spécificateur correspondant trouvé
            {
                count += _putchar('%');    // Affiche le '%'
                count += _putchar(format[i + 1]); // Affiche le caractère inconnu
                i++; // Ignore le caractère suivant '%'
            }
        }
        else
        {
            count += _putchar(format[i]); // Affiche un caractère normal
        }
        i++;
    }

    va_end(args);
    return (count);
}


