#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[])
{
	std::string line;
	std::ifstream file(argv[1]);
	while(getline(file, line))
	{
		if(!line.empty())
		{
			int space = line.find_first_of(" ");
			std::string word = line.substr(0, space);
			std::string binary = line.substr(space + 1);
			for (int i = 0; i < binary.size(); ++i)
			{
				if (binary[i] == '1') { word[i] = toupper(word[i]); }
			}
			std::cout << word << std::endl; 
		}
	}
	file.close();
	return 0;
}
