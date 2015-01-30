/*
Print out the sum of integers read from a file.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main(int argc, char const *argv[])
{
	std::string line;
	std::ifstream file;
	file.open(argv[1]);
	int sum = 0;
	while (getline(file, line)) 
   	{
       		if (!line.empty())
       		{
			int temp = std::stoi(line);
			sum += temp;
       		}
	}
	std::cout << sum << std::endl;
  	file.close();
	return 0;
}
