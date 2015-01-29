/*
CHALLENGE DESCRIPTION:

Write a program to determine the sum of the first 1000 prime numbers
*/

#include <iostream>
#include <cmath>

bool isPrime(int x) 
{
	//skips over 2
	if ( (x % 2 == 0) || (x < 2) )
	{
		return false;
	}
	else
	{
		for (int i = 3; i <= sqrt(x); ++i)
		{
			if (x % i == 0)
			{
	            return false;
			}
		}
		return true;
	}
	
}
int main(int argc, char const *argv[])
{	
	int count = 1;
	int sum = 2;
	int numToCheck = 1;
	while (count < 1000) 
	{
		if (isPrime(numToCheck))
		{
			sum += numToCheck;
			count++;
		}
		numToCheck++;
	}
	std::cout << sum << std::endl;
	return 0;
}
