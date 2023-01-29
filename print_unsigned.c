#include "main.h"
#include <stdio.h>
/**
 * p_unsigned_int - writes unsigned int as decimal
 * @format: pointer format
 * @ap: pointer to arguments
 * Return: number of characters printed
 */
int p_unsigned_int(va_list *ap, const char **format)
{
	int size = 0, e, l;
	unsigned int i, c;
	char *buffer;
	char temp;

	i = va_arg(*ap, int);
	if (i == 0)
		size = 1;
	for (c = i; c > 0; c /= 10)
		size++;
	buffer = malloc(size);
	if (buffer == NULL)
		return (-1);
	for (e = 0; e < size; e++, i /= 10)
		buffer[e] = (i % 10) + '0';
	for (e = 0, l = size - 1; l > e; l--, e++)
	{
		temp = buffer[e];
		buffer[e] = buffer[l];
		buffer[l] = temp;
	}
	write(STDOUT_FILENO, buffer, size);
	*format = *format + 1;
	free(buffer);
	return (size);
}

/**
 * p_hex - prints unsigned int as hexadecimal
 * @ap: pointer to args
 * @format: pointer to strings
 * Return: size printed
 */
int p_hex(va_list *ap, const char **format)
{
	unsigned int i, c;
	int size = 0, e, l, h = 0;
	char *buffer;
	char temp;
	unsigned int num[7] = {10, 11, 12, 13, 14, 15};
	char letters[7] = {'a', 'b', 'c', 'd', 'e', 'f'};

	i = va_arg(*ap, int);
	if (i == 0)
		size = 1;
	for (c = i; c > 0; c /= 16)
		size++;
	buffer = malloc(size);
	if (buffer == NULL)
		return (-1);
	for (e = 0; e < size; e++, i /= 16)
	{
		if (i % 16 > 9)
		{
			for (h = 0; h < 6; h++)
			{
				if (i % 16 == num[h])
					buffer[e] = letters[h];
			}
		}
		else
			buffer[e] = i % 16 + '0';
	}
	for (e = 0, l = size - 1; l > e; e++, l--)
	{
		temp = buffer[e];
		buffer[e] = buffer[l];
		buffer[l] = temp;
	}
	write(STDOUT_FILENO, buffer, size);
	*format = *format + 1;
	free(buffer);
	return (size);
}
/**
 * p_HEX - prints unsigned int as hexadecimal in capital
 * @ap: pointer to args
 * @format: pointer to strings
 * Return: size printed
 */
int p_HEX(va_list *ap, const char **format)
{
	unsigned int i, c;
	int size = 0, e, l, h = 0;
	char *buffer;
	char temp;
	unsigned int num[7] = {10, 11, 12, 13, 14, 15};
	char letters[7] = {'A', 'B', 'C', 'D', 'E', 'F'};

	i = va_arg(*ap, int);
	if (i == 0)
		size = 1;
	for (c = i; c > 0; c /= 16)
		size++;
	buffer = malloc(size);
	if (buffer == NULL)
		return (-1);
	for (e = 0; e < size; e++, i /= 16)
	{
		if (i % 16 > 9)
		{
			for (h = 0; h < 6; h++)
			{
				if (i % 16 == num[h])
					buffer[e] = letters[h];
			}
		}
		else
			buffer[e] = i % 16 + '0';
	}
	for (e = 0, l = size - 1; l > e; e++, l--)
	{
		temp = buffer[e];
		buffer[e] = buffer[l];
		buffer[l] = temp;
	}
	write(STDOUT_FILENO, buffer, size);
	*format = *format + 1;
	free(buffer);
	return (size);
}

/**
 * p_octal - prints unsigned int as octal
 * @ap: pointer to args
 * @format: pointer to strings
 * Return: size printed
 */
int p_octal(va_list *ap, const char **format)
{
	unsigned int i, c;
	int size = 0, e, l;
	char *buffer;
	char temp;

	i = va_arg(*ap, int);
	if (i == 0)
		size = 1;
	for (c = i; c > 0; c /= 8)
		size++;
	buffer = malloc(size);
	if (buffer == NULL)
		return (-1);
	for (e = 0; e < size; e++, i /= 8)
		buffer[e] = (i % 8) + '0';
	for (e = 0, l = size - 1; l > e; e++, l--)
	{
		temp = buffer[e];
		buffer[e] = buffer[l];
		buffer[l] = temp;
	}
	write(STDOUT_FILENO, buffer, size);
	*format = *format + 1;
	free(buffer);
	return (size);
}

