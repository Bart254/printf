#include "main.h"

/**
 * p_str - prints string passed to construct
 * @format: string construct
 * @ap: pointer to arguments of function
 * Return: size of string
 */
int p_str(va_list *ap, const char **format)
{
	char *buffer;

	buffer = va_arg(*ap, char *);
	if (buffer == NULL)
		buffer = "(null)";
	write(STDOUT_FILENO, buffer, strlen(buffer));
	*format = *format + 1;
	return (strlen(buffer));
}


