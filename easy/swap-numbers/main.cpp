#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


void swap(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}

int main(int argc, char const *argv[])
{
	std::string line;
	std::ifstream file(argv[1]);
	while(getline(file, line))
	{
		if(!line.empty())
		{
			std::stringstream stream(line);
			std::string buffer;
			std::vector<std::string> words;
			while (stream >> buffer)
			{
				words.push_back(buffer);
			}
			for (auto &i : words)
			{
				swap(i[0], i[i.size() - 1]);
				std::cout << i << " ";
			}
		}
		std::cout << std::endl;
	}
	file.close();
	return 0;
}
