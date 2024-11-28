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
	int count = 0, x = 1;

	int res = va_arg(args, int);

	if (res == 0)
	{
		_putchar('0');
		return (1);
	}

	if (res < 0)
	{
		_putchar('-');
		count++;
		if (res == -2147483648)
		{
			_putchar('2');
			res = 147483648;
			count++;
		}
		else
		{
			res = -res;
		}
	}

	while ((res / (x * 10)) > 0)
	{
		x *= 10;
	}


	while (x > 0)
	{
		_putchar((res / x) + '0');
		res %= x;
		x /= 10;
		count++;
	}
	return (count);
}


/**
* is_percent - Prints a percent sign to the output.
* @args: A variable argument list (va_list) from which an integer is consumed.
*
* Description: This function retrieves an integer from the variable argument
* list and prints a percent sign ('%') to the standard output. It returns
* 1 to indicate that the operation was successful.
*
* Return: Always returns 1.
*/
int is_percent(va_list args)
{
	(void)va_arg(args, int);
	_putchar('%');
	return (1);
}
/**
* print_char - print character from args list
* @args: va_list args
* Return: the number of characters printed
*/
int print_char(va_list args)
{
	char c = va_arg(args, int);

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
		str = "(null)";
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
