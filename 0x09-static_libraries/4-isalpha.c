#include "main.h"

/**
 * _isalpha - check input char if it's an alphabet.
 *
 * @c: - input char to be checked
 *
 * Return: 1 if c is a letter, 0 otherwise.
 */

int _isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
