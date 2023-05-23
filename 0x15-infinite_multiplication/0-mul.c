#include "holberton.h"

/**
* _isdigit - function to check if an element is a digit or not
* @c: the lement to test
* Return: 1 if is a number 0 otherwise
*/
int _isdigit(char *c)
{
	while (*c)
	{
		if (*c < '0' || *c > '9')
			return (0);
		c++;
	}

	return (1);
}

/**
* length - function to calculate the length of a number
* @number: the number which we wanr the length
* Return: a number
*/
long int length(long int number)
{
	long int digits = 1;

	while (number >= 10)
	{
		number /= 10;
		digits++;
	}
	return (digits);
}

/**
* main - function to multiply to number
* @argc: argument count
* @argv: argument value
* Return: 1 if function finished
*/
int main(int argc, char *argv[])
{
	long int num1, num2, i, index, result = 0;
	long int len = 0;
	char error[] = "Error\n";
	long int *num;

	if (argc < 3 || _isdigit(argv[1]) == 0 || _isdigit(argv[2]) == 0)
	{
		for (i = 0; i < 6; i++)
			_putchar(error[i]);
		exit(98);
	}
	else
	{
		num1 = atol(argv[1]);
		num2 = atol(argv[2]);
		result = num1 * num2;
		len = length(result);
		num = malloc(len * sizeof(int));
		for (i = 0; result > 0; i++)
		{
			num[i] = result % 10;
			result = result / 10;
		}
		for (index = i - 1; index >= 0; index--)
		{
			_putchar(48 + num[index]);
		}
		_putchar('\n');
		free(num);
	}
	return (1);
}
