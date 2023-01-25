#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * specifier - handles conversion specifiers
 * @ap: copy of the position of ap
 * @format: pointer to string constant
 * Return: number of characters printed
 */
int specifier(va_list *ap, const char **format)
{
	int n_printed = 0;
	char *buffer;
	char c;

	switch (*((*format) + 1))
	{
		case '\0':
			n_printed = -1;
			*format = *format + 1;
			break;
		case '%':
			buffer = "%";
			write(STDOUT_FILENO, buffer, 1);
			n_printed++;
			*format = *format + 2;
			break;
		case 'c':
			c = va_arg(*ap, int);
			write(STDOUT_FILENO, &c, 1);
			n_printed++;
			*format = *format + 2;
			break;
		case 's':
			buffer = va_arg(*ap, char *);
			if (buffer == NULL)
				buffer = "(null)";
			write(STDOUT_FILENO, buffer, strlen(buffer));
			n_printed = strlen(buffer);
			*format = *format + 2;
			break;
		default:
			write(STDOUT_FILENO, *format, 1);
			n_printed++;
			(*format) = (*format) + 1;
	}
	return (n_printed);
}


/**
 * _printf - prints the arguments passed
 * @format: syntax of argument
 * @(...)?: optional arguments
 *
 * Return: number of characters
 */
int _printf(const char *format, ...)
{
	int n = 0, check;
	va_list ap;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			check = specifier(&ap, &format);
			if (check == -1)
				return (check);
			n += check;
			continue;
		}
		write(STDOUT_FILENO, format, 1);
		n++;
		format = format + 1;
	}
	va_end(ap);
	return (n);
}
