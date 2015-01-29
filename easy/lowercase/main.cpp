/*
CHALLENGE DESCRIPTON:

Given a string write a program to convert it into lowercase.
*/
#include <iostream>
#include <cctype>
#include <fstream>
#include <cstdlib>

int main(int argc, char const *argv[])
{
	std::string line;
	std::ifstream file(argv[1]);
	while (getline(file, line)) 
	   {
	       if (!line.empty()) 
	       {
	       		for (int i = 0; i < line.length(); ++i)
	       		{
	       			line[i] = tolower(line[i]);
	       		}
	       		std::cout << line << std::endl;
	       }
	}
	return 0;
}
