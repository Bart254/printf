#include <string.h>
#include <stdarg.h>
#include <unistd.h>

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
	int n = 0;
	va_list ap;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			n += specifier(&ap, &format);
			continue;
		}
		write(STDOUT_FILENO, format, 1);
		n++;
		format = format + 1;
	}
	va_end(ap);
	return (n);
}
