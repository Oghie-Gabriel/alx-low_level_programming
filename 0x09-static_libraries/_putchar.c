#include <unistd.h>

/**
 * _putchar - Writes the character c to stdout
 * @c: the character to print 
 *
 * Return: on success 
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
