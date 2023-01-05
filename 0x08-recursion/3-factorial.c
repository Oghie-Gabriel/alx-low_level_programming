#include "main.h"

/**
 * factorial - factorials of a given number
 * @n: input for a number
 *
 * Return: returns factorial of the given number
 */

int factorial(int n)
{
if (n < 0)
	return (-1);
else if (n == 0)
	return (1);
return (n * factorial(n - 1));
}
