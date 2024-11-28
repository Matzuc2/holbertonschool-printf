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

    // Cas particulier pour 0
    if (res == 0)
    {
        _putchar('0');
        return (1);
    }

    // Gestion des nombres négatifs
    if (res < 0)
    {
        _putchar('-');
        count++;
        if (res == -2147483648) // Cas spécial INT_MIN
        {
            _putchar('2'); // Affiche le premier chiffre de INT_MIN
            res = 147483648; // Reste du nombre à traiter
            count++;
        }
        else
        {
            res = -res; // Conversion normale pour les autres nombres négatifs
        }
    }

    // Calcul du facteur multiplicatif (x = 10^n, où n est le nombre de chiffres - 1)
    while ((res / (x * 10)) > 0)
    {
        x *= 10;
    }

    // Affichage des chiffres un par un
    while (x > 0)
    {
        _putchar((res / x) + '0'); // Affiche le chiffre courant
        res %= x;                  // Reste à traiter
        x /= 10;                   // Réduit le facteur
        count++;
    }

    return (count); // Retourne le nombre total de caractères affichés
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
	int c = va_arg(args, int);

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
