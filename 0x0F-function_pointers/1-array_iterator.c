#include <stdio.h>
#include <stdlib.h>
#include "function_pointers.h"

/**
* array_iterator - check description
* Description: function that executes a function given as
* a parameter
* @array:array
* @size:size
* @action:function to be executed
*/

void array_iterator(int *array, size_t size, void (*action)(int))
{
if (array == NULL || action == NULL)
{
return;
}

while (size-- > 0)
{
action(*array);
array++;
}
}
