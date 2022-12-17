#include "main.h"

/**
 * print_triangle - Prints a triangle followed by new line
 *@size: variable
 * Return: Always 0
 */
void print_triangle(int size)
{
int count, i;
count = 0;
if (size > 0)
{
while (count < size)
{
i = size;
while (i > count + 1)
{
i--;
_putchar(' ');
}
while (i > 0)
{
_putchar('#');
i--;
}
count++;
_putchar('\n');
}
}
else
{
_putchar('\n');
}
}
