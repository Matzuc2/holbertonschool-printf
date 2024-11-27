#ifndef VARIADIC
#define VARIADIC
#include <stdarg.h>

/**
* struct which - Structure to define a format specifier and its corresponding
* function
* @w: The format specifier character (e.g., 'c' for char, 's' for string)
* @f: Pointer to the function that handles the specified format
*
* Description: This structure is used to map a format specifier to its
* corresponding
* function in the custom printf implementation. Each format specifier character
* is
* associated with a function that knows how to handle and print the
* corresponding
* data type.
*/
typedef struct which
{
		char *w;

		int (*f)(va_list args);
} which_s;

int _printf(const char *format, ...);

int print_int(va_list args);
int print_float(va_list args);
int print_char(va_list args);
int print_string(va_list args);
int _putchar(char c);

#endif
