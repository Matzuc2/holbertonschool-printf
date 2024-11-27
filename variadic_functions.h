#ifndef VARIADIC
#define VARIADIC
#include <stdarg.h>
typedef struct which
{
        char *w;
        int (*f)(va_list args);
}which_s;
int _printf(const char *format, ...);
int print_int(va_list args);
int print_float(va_list args);
int print_char(va_list args);
int print_string(va_list args);
int _pow_recursion(int x, int y);
int _putchar(char c);
#endif