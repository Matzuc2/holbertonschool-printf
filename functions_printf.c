#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <unistd.h>

/**
*print_int - print integer from args list
*@args: va_list args
*Return: the number of characters printed
*/

int print_int(va_list args)
{
	int count = 0;
	int x = 1;
	int res = va_arg(args, int);
	int min = -2147483648;

	if (res < 0)
	{
		_putchar('-');
		count++;
		if (res <= min)
			res = (min * -1) - 1;
		else
		res *= -1;
	}
	if (res == 0)
	{
		return (1);
	}
	while (res / (x * 10) > 0)
	{
		x *= 10;
		count++;
	}
	while ((res / x) > 0)
	{
		_putchar((res / x) + '0');
		res = res % x;
		x = x / 10;
		if (x == 0)
		{
			break;
		}
	}
		return (count);
}



/**
 * print_char - print character from args list
 * @args: va_list args
 * Return: the number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	if (c == '\0')
	{
		return (0);
	}
	_putchar(c);
	return (1);
}

/**
 * print_string - print string from args list
 * @args: va_list args
 * Return: the number of characters printed
 */
int print_string(va_list args)
{
	int i;
	char *str;
	int count = 0;


	str = va_arg(args, char*);
	if (str == NULL)
	{
		return (0);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
	_putchar(str[i]);
	count++;
	}
	return (count);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
