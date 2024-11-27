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
	{"s", print_string}, {NULL, NULL}};
	unsigned int i = 0, j = 0, count = 0;

	va_start(args, format);

	for (; format && format[i] != '\0'; i++)
	{
	j = 0;
	if (format[i] == '%')
	{
		for (; which[j].w != NULL; j++)
		{
			if (format[i + 1] == *(which[j].w))
			{
				count += which[j].f(args);
				i++;
				break;
			}
			else if ((which[j + 1].w) == NULL)
			{
				count += _putchar(format[i]) + _putchar(format[i + 1]);
				i++;
				break;
			}
		}
	}
	else
	{
		count += _putchar(format[i]);
	}
	}
	va_end(args);
	return (count);
}

