#include <stdio.h>
#include "variadic_functions.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int num = 12;
    /*float pi = 3.14;*/
    /*char a = 'P';*/
    char *t = "Mathieu";
    _printf("the number is %d\n", num);
    /*_printf("the number pi is equal to %d alors alors alors", num);*/
    /*_printf("the number is %f", pi);
    _printf("hello %c", a);*/
    _printf("hello my name is %s", t);
    return (0);
}