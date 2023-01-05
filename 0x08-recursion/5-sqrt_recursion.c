#include "main.h"

/**
 * _sqrt_recursion_helper - helper function
 * @n: input number one
 * @i: input number two
 *
 * Return: return square root of a natural number
 */

int _sqrt_recursion_helper(int n, int i)
{
if (n <= 0)
	return (-1);
else if (i * i > n)
	return (-1);
else if (i * i == n)
	return (i);
return (_sqrt_recursion_helper(n, i + 1));
}

/**
 * _sqrt_recursion - square root of a natural number
 * @n: input number one
 *
 * Return: return square root of a natural number
 */

int _sqrt_recursion(int n)
{
return (_sqrt_recursion_helper(n, 1));
}
