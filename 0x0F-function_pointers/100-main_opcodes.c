#include "function_pointers.h"
#include <stdio.h>
#include <stdlib.h>

/**
* main - main function
* @argc:no of arguments
* @argv: array
*
* Return:1
*/

int main(int argc, char *argv[])
{
int i, n;

int (*address)(int, char **) = main;
unsigned char p;

if (argc != 2)
{
printf("Error\n");
exit(1);
}
n = atoi(argv[1]);
if (n < 0)
{
printf("Error\n");
exit(2);
}
for (i = 0; i < n; i++)
{
p = *(unsigned char *)address;
printf("%.2x", p);

if (i == n - 1)
continue;
printf(" ");
address++;
}
printf("\n");
return (0);
}
