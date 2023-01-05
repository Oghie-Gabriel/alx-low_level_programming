#include "main.h"
#include <string.h>

/**
 * is_palindrome_helper - helper function
 * @s: a pointer for input string
 * @l: input number one
 * @e: input number two
 *
 * Return: return 1 if a palindrome otherwise 0
 */
int is_palindrome_helper(char *s, int l, int e)
{
if (l >= e)
{
return (1);
}
else if (s[l] == s[e])
{
return (is_palindrome_helper(s, l + 1, e - 1));
}
return (0);
}

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: a pointer input
 *
 * Return: return 1 is a palindrome otherwise 0
 */

int is_palindrome(char *s)
{
int l, e;
l = 0;
e = strlen(s) - 1;
return (is_palindrome_helper(s, l, e));
}
