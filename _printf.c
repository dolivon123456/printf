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
		{"%%", 2-printf_37},
		{"%i", 3-printf_int}, {"%d", 4-printf_decimal}, {"%r", 5-printf_srev},
		{"%R", 6-printf_rot13}, {"%b", 7-printf_bin}, {"%u", 8-printf_unsign},
		{"%o", 9-printf_octal}, {"%x", 10-printf_hexa}, {"%X", 11-printf_hex},
		{"%S", 12-printf_exstr}, {"%p", 13-printf_pointer}
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
