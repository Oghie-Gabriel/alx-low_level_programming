#include "main.h"

/**
* main - prints _putchar followed by a new line
 * Return: Always 0 (Success)
*/
int main(void)
{

	char word[] = "_putchar";
	int counter;

	for (counter = 0; counter < 8; counter++)
{
		_putchar(word[counter]);

}
_putchar('\n');
return (0);
}
