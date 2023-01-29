#include "main.h"

/**
 * p_bin - prints the binary form of a number
 * @ap: pointer to arguments
 * @format: pointer to string
 * Return: number of characters printed
 */
int p_bin(va_list *ap, const char **format)
{
	unsigned int i, c;
	int a, b, size = 0;
	char *buffer;
	char temp;

	i = va_arg(*ap, int);
	for (c = i; c > 0; c /= 2)
		size++;
	buffer = malloc(size);
	if (buffer == NULL)
		return (-1);
	for (a = 0; a < size; a++, i /= 2)
		buffer[a] = (i % 2) + '0';
	for (a = 0, b = size -1; b > a; b--, a++)
	{
		temp = buffer[a];
		buffer[a] = buffer[b];
		buffer[b] = temp;
	}
	write(STDOUT_FILENO, buffer, size);
	*format = *format + 1;
	return (size);
}
