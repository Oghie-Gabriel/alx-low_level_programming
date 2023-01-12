#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
char **createloop(char *, char *, int*, int, int);
int mul(bool, char *, int, int, int, int);
void add(char **, int);
char **invertptr(char **, int);
char **add_zeros(char **, int);
void print_res(char *);
int _putchar(char);

/**
 * main - program entry point
 * @argc: argv counter
 * @argv: argument passed
 * Return: 0 success
 */
int main(int argc, char *argv[])
{
	int ind1, ind2, n, *plen;
	char **mulptr, *str1, *str2;

	n = 0;
	plen = &n;
	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	str1 = strdup(argv[1]);
	str2 = strdup(argv[2]);
	ind1 = strlen(str1) - 1;
	ind2 = strlen(str2) - 1;
	mulptr = createloop(str1, str2, plen, ind1, ind2);
	add(mulptr, n);
	return (0);
}

/**
 * createloop - read numbers from the string
 * @str1: string 1
 * @str2: string 2
 * @plen: to keep counter of the pointers added
 * @ind1: index of str1
 * @ind2: index of str2
 * Return: pointer to pointers
 */
char **createloop(char *str1, char *str2, int *plen, int ind1, int ind2)
{
	int int1, int2, num1 = ind1, num2, rem = 0, count, mcount = 1;
	char *ptr, *ptr2, **mulptr;
	size_t len;
	bool isfirst = true;

	strlen(str1) > strlen(str2) ? (len = strlen(str1)) : (len = strlen(str2));
	mulptr = (char **)malloc(len * sizeof(char *));
	while (num1 >= 0)
	{
		ptr = (char *)malloc(sizeof(char));
		int1 = (int)(str1[num1]) - 48;
		count = 1, num2 = ind2;
		while (num2 >= 0)
		{
			int2 = (int)(str2[num2]) - 48;
			if (isfirst)
			{
				rem = mul(isfirst, ptr, int1, int2, rem, count);
				isfirst = false;
			}
			else
				rem = mul(isfirst, ptr, int1, int2, rem, count);
			count++;
			num2--;
		}
		if (rem > 0)
		{
			ptr2 = (char *)realloc(ptr, count);
			*(ptr2 + (count - 1)) = rem + '0';
			ptr = ptr2;
			rem = 0;
		}
		mulptr[mcount - 1] = ptr;
		mcount++;
		num1--;
	}
	*plen = mcount - 1;
	return (mulptr);
}

/**
 * mul - multiply 2 numbers
 * @isfirst: determines whether its the first multiplication or not
 * @ptr: char pointer to store results
 * @num1: first number
 * @num2: sec number
 * @rem: stores remeinder
 * @count: keep count of ptr index
 * Return: remeinder after mul
 */
int mul(bool isfirst, char *ptr, int num1, int num2, int rem, int count)
{
	char *ptr1;
	int num, mult;

	mult = num1 * num2;
	if (isfirst)
	{
		if (mult > 9)
		{
			*(ptr) = (mult % 10) + '0';
			return (mult / 10);
		}
		*(ptr) = mult + '0';
		return (0);
	}
	ptr1 = (char *)realloc(ptr, count);
	num = mult + rem;
	if (num > 9)
	{
		*(ptr1 + (count - 1)) = (num % 10) + '0';
		ptr = ptr1;
		return (num / 10);
	}
	*(ptr1 + (count - 1)) = num + '0';
	ptr = ptr1;
	return (0);
}

/**
 * add - add num tongether
 * @ptr: pointer to num pointers
 * @plen: pointer len
 */
void add(char **ptr, int plen)
{
	char **revptr, **invptr, *str1, *ptr1, *ptr2;
	int i, k = 0, n = 1, rem = 0, count = 1, ind, sum, num;
	bool isfirst = true;

	invptr = invertptr(ptr, plen);
	revptr = add_zeros(invptr, plen);
	ptr1 = (char *)malloc(sizeof(char));
	k = strlen(revptr[plen - 1]);
	while (k > 0)
	{
		sum = 0;
		for (i = 0; i < plen; i++)
		{
			str1 = revptr[i];
			ind = strlen(str1) - n;
			if (ind < 0)
				num = 0;
			else
				num = (int)str1[ind] - 48;
			sum += num;
		}
		sum += rem;
		if (isfirst)
		{
			ptr1[0] = (sum % 10) + '0';
			isfirst = false;
		}
		else
		{
			ptr2 = (char *)realloc(ptr1, count);
			ptr2[count - 1] = (sum % 10) + '0';
			ptr1 = ptr2;
		}
		rem = sum / 10;
		count++;
		n++;
		k--;
	}
	print_res(ptr1);
}

/**
 * invertptr - invert chars in a pointer
 * @ptr: pointer to char pointers
 * @plen: pointer length
 * Return: reversed char in pointers
 */
char **invertptr(char **ptr, int plen)
{
	char *ptr1, *str1;
	int i, j, len, len1 = 0;

	for (i = 0; i < plen; i++)
	{
		str1 = *(ptr + i);
		len = strlen(str1);
		ptr1 = (char *)malloc(len * sizeof(char));
		for (j = 0; j < len; j++)
		{
			ptr1[j] = str1[len - (1 + j)];
			len > len1 ? (len1 = len) : (len1 + 0);
		}
		ptr1[j] = '\0';
		*(ptr + i) = ptr1;
	}
	return (ptr);
}

/**
 * add_zeros - used to add zeros to pointers
 * @ptr: pointer to pointer
 * @plen: pointer len
 * Return: modified pointer of pointers
 */
char **add_zeros(char **ptr, int plen)
{
	char *ptr1, *ptr2;
	int i, j, len;

	for (i = 0; i < plen; i++)
	{
		ptr1 = ptr[i];
		len = strlen(ptr1);
		if (i > 0)
		{
			ptr2 = (char *)realloc(ptr1, len + i);
			for (j = 1; j <= i; j++)
			{
				ptr2[(len + j) - 1] = '0';
			}
			j = len + i;
			printf("i = %d\nprevlen: %d\nlen = %ld\nadd zero: %s\n", i, j, strlen(ptr2), ptr2);
			ptr[i] = ptr2;
		}
	}
	return (ptr);
}
/**
 * print_res - print the final result
 * @ptr: ptr holding the ans
 */
void print_res(char *ptr)
{
	int i, j;

	j = strlen(ptr) - 1;
	printf("string--> %s\n", ptr);
	for (i = j; i >= 0; i--)
		_putchar(ptr[i]);
}
