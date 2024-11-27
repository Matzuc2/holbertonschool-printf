#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <unistd.h>
/**
*print_int - print integer from args list
*@args: va_list args
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
	if (res <= min)
		res = min;
	else
	res *= -1;
}
while((res / (x*10)) > 0)
{
    x*= 10;
    count++;
}
while ((res / x) > 0)
{
    _putchar((res / x) + '0');
    res = res % x;
    x = x/10;
    if (x == 0)
    {
        break;
    }
}
    return (count);
}
/*if(res > 10)
{
    _putchar((res / x )+ '0');
    _putchar((res % x )+ '0');
}*/

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
