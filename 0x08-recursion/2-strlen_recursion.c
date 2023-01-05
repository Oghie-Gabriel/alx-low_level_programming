#include "main.h"

/**
 * _strlen_recursion - length of the given string
 * @s: a pointer for input string
 *
 * Return: return length of the string
 */

int _strlen_recursion(char *s)
{
unsigned int len = 0;
if (*s != '\0')
{
len = 1 + _strlen_recursion(s + 1);
}
return (len);
}
