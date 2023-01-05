#include "main.h"

/**
 * _pow_recursion - power of x raised to y
 * @x: input number one
 * @y: input number two
 *
 * Return: returns value of x raised to the power of y
 */

int _pow_recursion(int x, int y)
{
if (y < 0)
	return (-1);
else if (y != 0)
	return (x * _pow_recursion(x, y - 1));
return (1);
}
