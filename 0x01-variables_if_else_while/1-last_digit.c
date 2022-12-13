#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 * Return: Always 0 (Success)
*/
int main(void)

{

		int n; /* randomly generated number */
		int last_number; /* holds the last number from the generated number */

		srand(time(0));
		n = rand() - RAND_MAX / 2;
	
		last_number = n % 10;
		printf("Last digit of %d is %d", n, last_number);
		if (last_number > 5)
			printf(" and is greater than 5\n");
		else if (last_number < 6 && last_number != 0)
			printf(" and is less than 6 and not 0\n");
		else if (last_number == 0)
			printf(" and is 0\n")
		return (0);

}
