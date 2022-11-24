#include <string.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - prints the arguments passed
 * @format: syntax of argument
 * @(...)?: optional arguments
 *
 * Return: number of characters
 */
int _printf(const char *format, ...)
{
	char *str;
	char c;
	int n;
	va_list ap;

	va_start(ap, format);
	for (n = 0; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			for (format++; *format != '\0'; format++)
			{
				if (*format == 's')
				{
					str = va_arg(ap, char*);
					write(1, str, strlen(str));
					n += strlen(str);
					break;
				}
				if (*format == 'c')
				{
					c = va_arg(ap, int);
					write(1, &c, 1);
					n++;
					break;
				}
			}
		}
		else
		{
			write(1, format, 1);
			n++;
		}
	}
	return (n);
}
