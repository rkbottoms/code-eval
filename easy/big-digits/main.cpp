#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <unordered_map>
#include <array>


int main(int argc, char const *argv[])
{
	std::string line;
	std::ifstream file(argv[1]);
	while(getline(file, line))
	{
		if(!line.empty())
		{
			std::string output[6];
			std::vector<char> numbers;
			for(const auto &i : line)
			{
				if(isdigit(i))
				{
					numbers.push_back(i);
				}
			}
			std::unordered_map<char, std::array<std::string, 6>> big_digits;
			big_digits['0'] = {"-**--", "*--*-", "*--*-", "*--*-", "-**--", "-----"};
			big_digits['1'] = {"--*--", "-**--", "--*--", "--*--", "-***-", "-----"}; 
			big_digits['2'] = {"***--", "---*-", "-**--", "*----", "****-", "-----"}; 
			big_digits['3'] = {"***--", "---*-", "-**--", "---*-", "***--", "-----"}; 
			big_digits['4'] = {"-*---", "*--*-", "****-", "---*-", "---*-", "-----"}; 
			big_digits['5'] = {"****-", "*----", "***--", "---*-", "***--", "-----"}; 
			big_digits['6'] = {"-**--", "*----", "***--", "*--*-", "-**--", "-----"}; 
			big_digits['7'] = {"****-", "---*-", "--*--", "-*---", "-*---", "-----"}; 
			big_digits['8'] = {"-**--", "*--*-", "-**--", "*--*-", "-**--", "-----"}; 
			big_digits['9'] = {"-**--", "*--*-", "-***-", "---*-", "-**--", "-----"}; 

			for (const auto &j : numbers)
			{
				if(big_digits.count(j) > 0)
				{
					for (int k = 0; k < big_digits.at(j).size(); ++k)
					{
						output[k] += big_digits.at(j)[k];
					}
				}
			}
			for (const auto & x : output)
			{
				std::cout << x << std::endl;
			}
		}
	}
	return 0;
}
