#include "main.h"
#include <stdlib.h>

/**
 * array_range - create an array num
 * @min: min num
 * @max: max num
 * Return: pointer to the array
 */
int *array_range(int min, int max)
{
	int i, diff, *ptr;
	size_t t;

	if (min > max)
		return (NULL);
	diff = (max - min) + 1;
	t = (size_t)diff;
	ptr = (int *)malloc(t * sizeof(int));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i <= diff - 1)
	{
		*(ptr + i) = min + i;
		i++;
	}
	return (ptr);
}
