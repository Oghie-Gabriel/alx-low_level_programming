#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - reserves a memory
 * @b: memory size
 * Return: pointer to the memory
 */
void *malloc_checked(unsigned int b)
{
	void *c;

	c = (void *)malloc(b);
	if (c == NULL)
	{
		exit(98);
	}

	return (c);
}
