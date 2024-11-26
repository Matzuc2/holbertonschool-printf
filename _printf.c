#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"
int _printf(const char *format, ...)
{
        va_list args;
        which_s which[] = {
        {"d", print_int},
        {"c", print_char},
        {"i", print_int},
        {"s", print_string},
        {NULL, NULL}
        };

        unsigned int i = 0;
        unsigned int j = 0;
        unsigned int count = 0;

        va_start(args, format);

        while (format && format[i] != '\0')
        {
        j = 0;
                if (format[i] == '%')
                {
                        while (which[j].w != NULL)
                        {
                                if (format[i + 1] == *(which[j].w))
                                {
                                        count += which[j].f(args);
                                        break;
                                }
                                j++;
                        }
                }
                 else if (i >= 1 && format[i - 1] == '%')
                {
                        i++;
                        continue;
                }
                else
                {      
                        _putchar(format[i]);
                        count++;
                }
        i++;
        }
        va_end(args);
        return (count);
}