#include "main.h"
#include <stdlib.h>

/**
 * _calloc - reserve memory
 * @nmemb: memory elements
 * @size: size of a single element
 * Return: pointer ro memory NULL if otherwise
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = (void *)calloc(nmemb, size);
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}
