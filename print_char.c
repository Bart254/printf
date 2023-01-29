#include "main.h"

/**
 * p_char - prints characters to stdout
 * @format: pointer to string constant
 * @ap: copy of the position of ap
 * Return: Always 1
 */
int p_char(va_list *ap, const char **format)
{
	char c;

	c = va_arg(*ap, int);
	write(STDOUT_FILENO, &c, 1);
	*format = *format + 1;
	return (1);
}


