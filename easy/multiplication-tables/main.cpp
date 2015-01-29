/*
CHALLENGE DESCRIPTION:

Print out the grade school multiplication table upto 12*12
*/

#include <iostream>
#include <iomanip> 
int main(int argc, char const *argv[])
{
	for (int i = 1; i <= 12; ++i)
	{
		for (int j = 1; j <= 12; ++j)
		{	
			std::cout << std::setw(4) << std::right << i*j;
		}
		std::cout << std::endl;
	}
	return 0;
}