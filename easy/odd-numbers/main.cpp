#include <iostream>

int main(int argc, char const *argv[])
{
	for (int i = 1; i < 100; ++i)
	{
		if (i & 1)
		{
			std::cout << i << std::endl;
		}
	}
	return 0;
}