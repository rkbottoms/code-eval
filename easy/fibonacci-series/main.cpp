subl/*
The Fibonacci series is defined as: F(0) = 0; F(1) = 1; F(n) = F(n-1) + F(n-2) when n>1. Given a positive integer 'n', print out the F(n).
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int fib(int n)
{
	unsigned int cache[50] = {0};
	cache[0] = 0;
	cache[1] = 1;
	if (n == 0)
	{
		return cache[0];
	}
	if (n == 1)
	{
		return cache[1];
	}
	else
	{
		int x = cache[n];
		if (x == 0)
		{
			x = fib(n-1) + fib(n-2);
			cache[n] = x;
		}
		return x;
	}
}
int main(int argc, const char *argv[])
{
	std::string line;
	std::ifstream file(argv[1]);
	int fibonacci;
	while(getline(file, line))
	{
		if(!line.empty())
		{
			int n = std::stoi(line);
			fibonacci = fib(n);
			std::cout << fibonacci << std::endl;
		}

	}
	file.close();
	return 0;
}	