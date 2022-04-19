#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>

/**
  * print_eight - function to print to base 8
  * @format: the string to manipulate
  * @var: the list object to manipulate
  * Return: if argument is NULL, return pointer
  */
char *print_eight(char *format, va_list *var)
{
	char *formatEnd;
	unsigned long int number = 0;
	unsigned long int i = 0;
	char printNum[20];
	char *convert = "012345678";

	number = va_arg(*var, unsigned int);
	/* perhaps we should exit here instead as printf wouldn't compile */
	formatEnd = malloc(sizeof(*formatEnd) * (_strlen(format) + 1));
	if (formatEnd == NULL)
		return (NULL);
	while (number > 7)
	{
		*(printNum + i) = *(convert + (number % 8));
		i++;
		number = number / 8;
	}
	*(printNum + i) = *(convert + (number % 8));
	i++;
	*(printNum + i) = '\0';
	rev_string(printNum);
	_strcpy(formatEnd, format);
	_strcpy(format, printNum);

	format = format + _strlen(printNum);
	if (_strlen(formatEnd) > 2)
		_strcpy(format, formatEnd + 2);

	free(formatEnd);
	return (format);
}
