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

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (format && format[i] != '\0')
	{
		j = 0;
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			while (which[j].w != NULL)
			{
				if (format[i + 1] == *(which[j].w))
				{
					count += which[j].f(args);
					i++;
					break;
				}
				else if ((which[j + 1].w) == NULL)
				{
					count += _putchar(format[i]);
				}
			j++;
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
	i++;
	}
	va_end(args);
	return (count);
}

