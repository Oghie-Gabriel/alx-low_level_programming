#include "main.h"

/**
 * is_prime - helper function
 * @n: input number one
 * @i: input number two
 *
 * Return: return a prime number
 */

int is_prime(int n, int i)
{
if (i < n)
{
if (n % i == 0)
	return (0);
return (is_prime(n, i + 1));
}
return (1);
}

/**
 * is_prime_number - check if a number is prime or not
 * @n: input number
 *
 * Return: return 1 if the input number is prime otherwise return 0
 */

int is_prime_number(int n)
{
if (n <= 1)
	return (0);
return (is_prime(n, 2));
}
