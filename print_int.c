#include "main.h"
#include <stdio.h>

/**
 * p_min - adds one to INT_MIN
 * @i: pointer to int
 * @min: int to min
 */
void p_min(int *i, int *min)
{
	*i = *i + 1;
	*min = 8;
}
/**
 * p_int - prints an integer to stdout
 * @ap: pointer to argument pointer
 * @format: pointer to string construct
 * Return: number of characters printed
 */
int p_int(va_list *ap, const char **format)
{
	int i, q, min = 0;
	char *buffer;
	char temp, sign = '+';
	size_t size = 0, e, r;

	i = va_arg(*ap, int);
	if (i == 0)
		size = 1;
	else if (i < 0)
	{
		if (i == INT_MIN)
			p_min(&i, &min);
		i = 0 - i;
		sign = '-';
		++size;
	}
	for (q = i; q > 0; q /= 10)
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
	if (min == 8)
		buffer[0] = 8 + '0';
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

