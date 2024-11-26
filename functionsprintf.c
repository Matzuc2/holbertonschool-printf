#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"
#include <unistd.h>
/**
*print_int - print integer from args list
*@args: va_list args
*/
int print_int(va_list args)
{
int count = 0;
int res = va_arg(args, int);
   if (res < 0)
   {
		_putchar('-');
		res = -res;
   }
   if (res/10 > 0)
   {
		print_int(res/10);
   }
	_putchar(res%10 + '0');
	return (count);
}
/**
*print_float - print float from args list
*@args: va_list args
*/
int print_float(va_list args)
{
	_putchar(va_arg(args, double));
	return (1);
}
/**
 * print_char - print char from args list
 * @args: va_list args
*/
int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}
/**
*print_string - print string from args list
*@args: va_list args
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
int _putchar(char c)
{
	return (write(1, &c, 1));
}
int _pow_recursion(int x, int y)
{

	if (y < 0)
	{
		return (-1);
	}
	if (y == 0)
	{
		return (1);
	}
	return (x * _pow_recursion(x, y - 1));
}
