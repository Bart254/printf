#include "main.h"

/**
 * specifier - handles conversion specifiers
 * @ap: copy of the position of ap
 * @format: pointer to string constant
 * Return: number of characters printed
 */
int specifier(va_list *ap, const char **format)
{
	int n_printed, e = 0;
	char ptr[6] = {'d', 'i', 'c', 's', 'b'};

	int (*f[5])(va_list *, const char **) = {p_int,
		p_int, p_char, p_str, p_bin};
	if (*(*format + 1) == '\0')
	{
		n_printed = -1;
		*format = *format + 1;
		return (n_printed);
	}
	else if (*(*format + 1) == '%')
	{
		*format = *format + 1;
		write(STDOUT_FILENO, "%", 1);
		*format = *format + 1;
		n_printed = 1;
		return (n_printed);
	}
	while (ptr[e])
	{
		if (*(*format + 1) == ptr[e])
		{
			*format = *format + 1;
			n_printed = f[e](ap, format);
			break;
		}
		e++;
	}
	if (ptr[e] == '\0')
	{
		write(STDOUT_FILENO, *format, 1);
		*format = *format + 1;
		n_printed = 1;
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
