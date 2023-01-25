#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * p_int - prints an integer to stdout
 * @ap: pointer to argument pointer
 * @format: pointer to string construct
 * Return: number of characters printed
 */
int p_int(va_list *ap, const char **format)
{
	int i, q;
	char *buffer;
	char temp;
	char sign = '+';
	size_t size = 0, e, r;

	i = va_arg(*ap, int);
	if (i < 0)
	{
		i = 0 - i;
		sign = '-';
		size++;
	}
	if (i != 0)
	{
		for (q = i; q > 0; q /= 10)
			size++;
	}
	else
		size++;
	buffer = malloc(size);
	if (buffer == NULL)
		return (-1);
	for (e = 0; e < size; e++, i /= 10)
	{
		if (e == size - 1 && sign == '-')
			buffer[e] = '-';
		else
			buffer[e] = i % 10 + '0';
	}
	for (e = 0, r = size - 1; r > e; r--, e++)
	{
		temp = buffer[e];
		buffer[e] = buffer[r];
		buffer[r] = temp;
	}
	write(STDOUT_FILENO, buffer, size);
	*format = *format + 1;
	free(buffer);
	return (size);
}

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

/**
 * specifier - handles conversion specifiers
 * @ap: copy of the position of ap
 * @format: pointer to string constant
 * Return: number of characters printed
 */
int specifier(va_list *ap, const char **format)
{
	int n_printed, e = 0;
	char ptr[5] = {'d', 'i', 'c', 's'};

	int (*f[4])(va_list *, const char **) = {p_int,
		p_int, p_char, p_str};
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
