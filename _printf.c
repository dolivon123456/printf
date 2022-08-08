#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", 0-printf_str}, {"%c", 1-printf_char},
		{"%%", 3-printf_37},
		{"%i", 4-printf_int}, {"%d", 5-printf_dec}, {"%r", 6-printf_srev},
		{"%R", 7-printf_rot13}, {"%b", 8-printf_bin}, {"%u", 9-printf_unsigned},
		{"%o", 10-printf_oct}, {"%x", 11-printf_hex}, {"%X", 12-printf_HEX},
		{"%S", 13-printf_exclusive_string}, {"%p", 14-printf_pointer}
	};

	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
