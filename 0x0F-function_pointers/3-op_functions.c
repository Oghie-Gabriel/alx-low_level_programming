#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
* op_add - Returns sum of a and b
* @a:number 1
* @b:number 2
* Return: sum
*/

int op_add(int a, int b)
{
return (a + b);
}

/**
* op_sub- returns the difference of a and b
* @a:number 1
* @b:number 2
* Return: difference
*/

int op_sub(int a, int b)
{
return (a - b);
}

/**
* op_mul - returns the product of a and b
* @a:number1
* @b:number2
* Return:multiplication
*/

int op_mul(int a, int b)
{
return (a * b);
}

/**
* op_div - returns the result of the dividion of a and b
* @a:number1
* @b:number2
* Return:division
*/

int op_div(int a, int b)
{
return (a / b);
}

/**
* op_mod - returns the remainder of the division of a and b
* @a:number1
* @b:number2
* Return:remainder of division
*/

int op_mod(int a, int b)
{
return (a % b);
}
