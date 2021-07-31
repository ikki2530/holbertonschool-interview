#include "holberton.h"
#include <stdio.h>
/**
 * compare - function to compare
 * @s1: first string
 * @s2: second string
 * @ast: flag for asterisk
 *
 * Return: int
*/
int compare(char *s1, char *s2, int ast)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s2 == '*')
		return (compare(s1, s2 + 1, ++ast));
	else if (*s1 != *s2 && ast > 0)
	{
		if (*s1 != '\0')
			return (compare(s1 + 1, s2, ast));
		return (0);
	}
	else if (*s1 != *s2 && ast == 0)
		return (0);
	else if (*s1 == *s2 && ast > 0)
	{
		if (compare(s1 + 1, s2 + 1, 0) == 1)
			return (compare(s1 + 1, s2 + 1, ast));
		return (compare(s1 + 1, s2, ast));
	}
	else if (*s1 == *s2 && ast == 0)
		return (compare(s1 + 1, s2 + 1, 0));
	return (-1);
}
/**
* wildcmp - function that compares two strings with recursion
* @s1: first string
* @s2: second string
*
* Return: returns 1 if the strings can be
* considered identical, otherwise return 0
*/
int wildcmp(char *s1, char *s2)
{
	int ast = 0;

	return (compare(s1, s2, ast));
}
