#include "main.h"
#include <stdlib.h>

/**
 * _realloc - realocate prev pointer to a new pointer
 * @ptr: old ptr
 * @old_size: ptr size
 * @new_size: new ptr size
 * Return: new pointer address or NULL if othewise
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *nptr;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL && new_size > 0)
	{
		nptr = (void *)malloc(new_size);
		return (nptr);
	}
	nptr = (void *)realloc(ptr, new_size);
	if (nptr == NULL)
		return (NULL);
	return (nptr);
}
