#include "main.h"

/**
 * _islower - check input char status (upper/lower).
 *
 * @c: - input char to be checked
 *
 * Return: 1 if case is lower, 0 otherwise.
 */

int _islower(int c)
{
	if (c > 'Z')
		return (1);
	else
		return (0);
}
