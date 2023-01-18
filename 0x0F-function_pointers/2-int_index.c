#include <stdio.h>
#include <stdlib.h>
#include "function_pointers.h"

/**
* int_index - check description
* Description:function that searches for an integer
* @array:array
* @size:size
* @cmp:function to compare values
* Return: 0 or -1 if no element matches or size <= 0
*/

int int_index(int *array, int size, int (*cmp)(int))
{
int index = 0;
if (array == NULL || cmp == NULL)
return (-1);

for (; index < size; index++)
{
if (cmp(array[index]) != 0)
return (index);
}

return (-1);
}
