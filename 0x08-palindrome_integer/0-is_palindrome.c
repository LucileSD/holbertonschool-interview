#include "palindrome.h"

/**
* is_palindrome - check if an integer is a palindrome
* @n: the long unsigned integer
* Return: 1 if is a palindrome 0 otherwise
*/
int is_palindrome(unsigned long n)
{
	unsigned long reverse = 0, original = n;

	while (n > 0)
	{
		reverse = reverse * 10 + n % 10;
		n /= 10;
	}
	return (reverse == original);
}
