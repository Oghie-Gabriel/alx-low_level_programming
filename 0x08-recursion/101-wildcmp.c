#include "main.h"

/**
 * wildcmp - compare two strings
 * @s1: a pointer for input one
 * @s2: a pointer for input two
 *
 * Return: returns 1 or 0
 */

int wildcmp(char *s1, char *s2)
{
if (*s1 == '\0' && *s2 == '\0')
	return (1);
else if (*s1 == *s2)
	return (wildcmp(s1 + 1, s2 + 1));
else if (*s2 == '*')
{
if (*(s2 + 1) == '*')
	return (wildcmp(s1, s2 + 1));
else if (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1))
	return (1);
}
return (0);
}
