#include "main.h"
#include <string.h>
#include <stdlib.h>
/**
 * string_nconcat - join 2 strings together
 * @s1: string 1
 * @s2: string 2
 * @n: size to copy
 * Return: pointer to the final string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str, *str1, *str2;
	unsigned int i, len1, len2;

	str1 = strdup(s1);
	str2 = strdup(s2);
	len1 = strlen(str1);
	len2 = strlen(str2);
	if (str1 == NULL)
		str1 = "";
	if (str2 == NULL)
		str2 = "";
	if (n >= len2)
	{
		str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
		for (i = 0; i < (len1 + len2); i ++)
		{
			if (i < len1)
				*(str + i) = str1[i];
			else
				*(str + i) = str2[i - len1];
		}
		*(str + i) = '\0';
		return (str);
	}
	strncat(str1, str2, n);
	return (str1);
}
