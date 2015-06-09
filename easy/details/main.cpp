#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main(int argc, char const *argv[])
{
	std::string line;
	std::ifstream file(argv[1]);
	while(getline(file, line))
	{
		if(!line.empty())
		{
			std::vector<std::string> details;
			char token = ',';
			std::string buffer;
			std::stringstream stream(line);
			while(getline(stream, buffer, token))
			{
				details.push_back(buffer);
			}
			int max = 99;
			int count = 0;
			for (auto &i : details)
			{
				for (auto &j : i)
				{
					if(j == '.')
					{
						count++;
					}
				}
				if(count < max)
				{
					max = count;
				}
				count = 0;
			}
			std::cout << max << std::endl;
		}
	}
	return 0;
}