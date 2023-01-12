#include <stdlib.h>
#include <stdio.h>

/**
 * strLen - Function counts number of characters in a given string.
 *
 * @str: String to be counted.
 *
 * Return: Number of characters in given string.
 */
int strLen(char *str)
{
	int length = 0;

	while (*str++)
		length++;

	return (length);
}

/**
 * rmvLead - Funtion removes leading zeros from an integer stored in a string.
 *
 * @str: String to be fixed.
 *
 * Return: Pointer to first non-zero digit in string.
 */
int rmvLead(char *str)
{
	int countr = 0, length = strLen(str) - 1;

	while (length--)
		if (*(str + countr) == '0')
			countr++;

	return (countr);
}

/**
 * strAdd - Function that adds two or more numbers passed as strings in an
 *          array of strings, then saves the result as a string at given
 *          location in memory (result).
 *          NOTE: *Does no checks/validation. Verify data before passing it.
 *                *'6' - 48 = 6 ==> int value of an integer stored as char.
 *
 * @result: Location in memory where result would be stored (as a string).
 * @numv: Numbers to be added. An array of integers stored as strings.
 * @numc: Number of elements in numv array.
 * @length: Number of digits (chars) in each element in num1.
 *
 * Return: Number of characters in given string.
 */
char *strAdd(char *result, char **numv, int numc, int length)
{
	int add = 0, rem = 0, countr = 0, countr2 = numc;
	char *str;

	str = malloc(sizeof(char) * (length + 1));
	if (!result)
		exit(98);

	while (length--)
	{
		add = 0;
		countr2 = numc;
		while (countr2--)
			add += numv[countr2][length] - 48;
		add += rem;
		rem = 0;
		if (add >= 10)
		{
			*(str + countr++) = (add % 10) + 48;
			rem = add / 10;
		}
		else
			*(str + countr++) = add + 48;
	}

	if (rem)
		*(str + countr++) = rem + 48;

	while (countr > 1)
		if (*(str + countr - 1) == '0')
			countr--;
		else
			break;

	countr2 = 0;
	while (countr--)
		*(result + countr2++) = *(str + countr);
	*(result + countr2) = '\0';
	free(str);

	return (result);
}

/**
 * padding - Function that adds extra zeros to give a string a specific width.
 *           NOTE: *Does no checks/validation. Verify data before passing it.
 *
 * @result: Location in memory where result would be stored (as a string).
 * @width: Number of digits (chars) for width of result.
 * @leading: Number of leading zeros to add to result.
 *
 * Return: Number of characters in given string.
 */
void padding(char *result, int width, int leading)
{
	int length, countr = 0;
	char *str;

	str = malloc(sizeof(char) * (width + 1));
	if (!str)
		exit(98);

	length = strLen(result) + leading;
	countr = 0;
	if (length < width)
	{
		while (countr < width - length)
			*(str + countr++) = '0';

		*(str + countr) = '\0';
	}

	length -= leading;
	while (length--)
		*(str + countr++) = *(result + length);
	*(str + countr) = '\0';

	countr = 0;
	while (*(str + countr))
	{
		*(result + countr) = *(str + countr);
		countr++;
	}

	while (leading--)
		*(result + countr++) = '0';
	*(result + countr) = '\0';

	free(str);
}

/**
 * strMult - Function that multiplies two numbers passed as strings, and copies
 *           the result to the given string pointer.
 *           NOTE: *Does no checks/validation. Verify data before passing it.
 *                 *'6' - 48 = 6 ==> int value of an integer stored as char.
 *
 * @result: Location in memory where result would be stored (as a string).
 * @num1: An integer of single or multiple digits stored as a string.
 * @num2: A single-digit integer stored as a char.
 * @length: Number of digits (chars) in num1.
 *
 * Return: Number of characters in given string.
 */
void strMult(char *result, char *num1, char num2, int length)
{
	int mult;
	int rem = 0;
	int countr = 0;
	int size = length + 1;

	while (length--)
	{
		mult = (num2 - 48) * (*(num1 + length) - 48);
		mult += rem;
		rem = 0;

		if (mult >= 10)
		{
			*(result + countr++) = (mult % 10) + 48;
			rem = mult / 10;
		}
		else
			*(result + countr++) = mult + 48;
	}

	if (rem)
		*(result + countr++) = rem + 48;
	if (countr < size)
		*(result + countr++) = '0';
	*(result + countr) = '\0';
}

/**
 * isInt - Checks that a given string contains only a single integer value.
 *
 * @str: String to be checked.
 *
 * Return: 1 if string is a positive integer,
 *        -1 if string is a negative integer,
 *         0 on failure.
 */
int isInt(char *str)
{
	int status = 0;
	int signer = 1;

	if (*str == '-')
	{
		signer = -1;
		str++;
	}

	while (*str)
	{
		status = 1 * signer;

		if (*str < '0' || *str++ > '9')
			return (0);
	}

	return (status);
}

/**
 * start - Function that calls the other functions in the program after main.
 *         This function only exists because ALX (Betty) has a restriction of
 *         <= 40 lines per function, so the main function below was split here.
 *         NOTES: *len[1 || 2] == strLen of corresponding argv string (number).
 *                *len[0] == strLen() of bigger number.
 *                *len[3] == id of bigger number:  1 or 2  ==> argv[1 || 2].
 *                *len[4] == id of smaller number: 1 or 2  ==> argv[1 || 2].
 *                *len[5] == strLen() of smaller number.
 *                *len[9] == Max length of result == len[1] + len[2].
 *
 * @argv: Arguments vector (array of strings of passed arguments).
 * @len: Array of integers from size checks on argv (See chart in NOTES above).
 * @isSigned: Determines if the final result would be a negative integer.
 */
void start(char *argv[], int len[10], int isSigned)
{
	int countr = 0;
	char *result, **tmpStr;

	tmpStr = malloc(sizeof(char *) * len[5]);
	if (!tmpStr)
		exit(98);

	while (countr < len[5])
	{
		tmpStr[countr] = malloc(sizeof(char) * (len[9] + 1));
		if (!tmpStr[countr])
		{
			while (countr--)
				free(tmpStr[countr]);
			free(tmpStr);
			exit(98);
		}
		countr++;
	}

	countr = len[5];
	while (countr--)
	{
		strMult(tmpStr[countr], argv[len[3]], argv[len[4]][countr], len[0]);
		padding(tmpStr[countr], len[9], (len[5] - countr - 1));
	}

	result = malloc(sizeof(char) * (len[9] + 1));
	if (!result)
		exit(98);
	result = strAdd(result, tmpStr, len[5], len[9]);

	if (isSigned)
		printf("-");
	printf("%s\n", result);

	free(result);
	while (len[5]--)
		free(tmpStr[len[5]]);
	free(tmpStr);
}

/**
 * main - Program that multiplies two positive numbers in base 10/decimal
 *        passed as arguments from the commandline. If argc != 3 or either
 *        argument != integer, print Error and exit with a status of 98.
 *        NOTES: *len[1 || 2] == strLen of corresponding argv string (number).
 *               *len[0] == strLen() of bigger number.
 *               *len[3] == id of bigger number:  1 or 2  ==> argv[1 || 2].
 *               *len[4] == id of smaller number: 1 or 2  ==> argv[1 || 2].
 *               *len[5] == strLen() of smaller number.
 *               *len[9] == Max length of result == len[1] + len[2].
 *
 * @argc: Number of arguments passed to program from CL.
 * @argv: Arguments vector (array of strings of passed arguments).
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	int len[10], isSigned = 0;

	if (argc != 3 || !isInt(argv[1]) || !isInt(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}

	if (isInt(argv[1]) < 0 && isInt(argv[2]) < 0)
		argv[1]++, argv[2]++;
	else if (isInt(argv[1]) < 0)
		isSigned = '-', argv[1]++;
	else if (isInt(argv[2]) < 0)
		isSigned = '-', argv[2]++;

	argv[1] += rmvLead(argv[1]);
	argv[2] += rmvLead(argv[2]);

	len[1] = strLen(argv[1]);
	len[2] = strLen(argv[2]);
	len[0] = len[1];
	len[3] = 1;
	len[4] = 2;
	if (len[2] > len[1])
	{
		len[0] = len[2];
		len[3] = 2;
		len[4] = 1;
	}

	len[5] = len[1] + len[2] - len[0];
	len[9] = len[1] + len[2];

	start(argv, len, isSigned);

	return (0);
}
